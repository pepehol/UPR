#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#include "configure.h"
#include "utils.h"
#include "colorPalete.h"
#include "shape.h"
#include "tga.h"

void checkRequiredParam(
    int *argc,
    char *argv[],
    char **picFile,
    char **fileConf,
    int *width,
    int *height)
{
    /*
    If it is less than or equal to nine parameters, exit the program.
    Required pameters:
    0        1 2            3 4         5 6          7       8
    program -o nameOutFile -w widthPix -h heightPix -f/r,c,t char * /int[]
    Mandatory parameters and at least one parameter for the drawing object or
    configuration file.
     */
    if (*argc < REQUIRED_NUM_PARAMS)
        callStderrExit(ERROR_INPUT, 1);

    // Duplicate parameter.
    int countFpic = 0;
    int countW = 0;
    int countH = 0;
    int countFconf = 0;
    int countP = 0;

    for (int i = 0; i < REQUIRED_NUM_PARAMS; i++)
    {
        if (strcmp(argv[i], PARAM_OUT_FILE) == 0)
        {
            *picFile = argv[i + 1];
            countFpic++;
        }
        else if (strcmp(argv[i], PARAM_WIDTH_PIC) == 0)
        {
            *width = atoi(argv[i + 1]);
            countW++;
        }
        else if (strcmp(argv[i], PARAM_HEIGHT_PIC) == 0)
        {
            *height = atoi(argv[i + 1]);
            countH++;
        }
        else if (strcmp(argv[i], PARAM_IN_FILE) == 0)
        {
            *fileConf = argv[i + 1];
            countFconf++;
        }
        else if (
            ((strcmp(argv[i], PARAM_RECTANGLE) == 0) ||
             (strcmp(argv[i], PARAM_TRIANGLE) == 0) ||
             (strcmp(argv[i], PARAM_CIRCLE) == 0)) &&
            (i >= 7))
            countP++;
    }

    // The main parameter must be one at a time.
    if (!((countFpic == 1) && (countW == 1) && (countH == 1)))
        callStderrExit(ERROR_MISS_MAIN_PAR, 1);

    // Duplicate parameters.
    if ((countFpic > 1) || (countW > 1) || (countH > 1) || (countFconf > 1))
        callStderrExit(ERROR_DUPLICATE, 1);

    if ((countFpic + countW + countH + countFconf + countP) < 4)
        callStderrExit(ERROR_INPUT, 1);

    // Check the values of the main inputs. -o, -h, -w.
    if (*picFile == NULL)
        callStderrExit(ERROR_PARAM_O, 1);
    else if (strstr(*picFile, TGA_EXTENSIONS) == NULL)
        callStderrExit(ERROR_PARAM_O, 1);

    if (*width == 0)
        callStderrExit(ERROR_PARAM_W, 1);

    if (*height == 0)
        callStderrExit(ERROR_PARAM_H, 1);
}

char **readParamFromFile(char *fileName, int *param)
{
    FILE *f = fopen(fileName, "rt");

    if (!f)
    {
        fprintf(stderr, "%s%s%s", "Vstupni soubor \"", fileName,
                "\" neexistuje.\n");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    int fSize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *pString = NULL;
    pString = (char *)malloc(fSize + 1);
    ALLOCTEST(pString);

    fread(pString, fSize, 1, f);
    pString[fSize] = 0;

    // I don't know how many parameter will be in file. 1 or 1000?
    // First count parameters in file.
    int numParams = 0;
    for (int i = 0; i < fSize; i++)
    {
        if ((pString[i] == ASCI_NEW_LINE) || (pString[i] == ASCI_SPACE))
            numParams++;
    }

    *param = numParams;

    char **pArray;
    pArray = malloc(numParams * sizeof(char *));
    ALLOCTEST(pArray);

    int startParams = 0;
    numParams = 0;
    for (int i = 0; i < fSize; i++)
    {
        if (pString[i] == ASCI_NEW_LINE || pString[i] == ASCI_SPACE)
        {
            pArray[numParams] = (char *)malloc(((i - startParams) + 1) * sizeof(char));
            ALLOCTEST(pArray[numParams]);

            char loader[(i - startParams) + 1];

            for (int j = 0; j < (i - startParams); j++)
            {
                loader[j] = pString[(startParams + j)];
            }

            loader[(i - startParams)] = '\0';

            strcpy(pArray[numParams], loader);

            numParams++;
            startParams = i + 1;
        }
    }

    free(pString);

    fclose(f);

    return pArray;
}

int main(int argc, char *argv[])
{
    // Load required parameters.
    char *picFileOut = NULL;
    char *fileConf = NULL;
    int picWidth = 0;
    int picHeight = 0;

    checkRequiredParam(&argc, argv, &picFileOut, &fileConf, &picWidth,
                       &picHeight);

    // Check if it is a configuration from a file. (parameter -f).
    char **pObjectsArr;
    int numParams = 0;

    if (fileConf != NULL)
    {
        pObjectsArr = readParamFromFile(fileConf, &numParams);
    }
    else
    {
        numParams = argc - CONF_PARAMS;
        pObjectsArr = &argv[CONF_PARAMS];
    }

    printf("VYSTUPNI NAZEV: %s\n", picFileOut);
    printf("KONF. SOUBRO: %s\n", fileConf);
    printf("POCET PARAMETRU: %d\n", numParams);
    printf("SIRKA: %d\n", picWidth);
    printf("VYSKA: %d\n", picHeight);

    TGAImage *tga = TGAnew(picWidth, picHeight, &RGBA_BLACK);

    for (int i = 0; i < numParams; i++)
    {
        printf("%s\n", pObjectsArr[i]);

        if (strcmp(pObjectsArr[i], PARAM_RECTANGLE) == 0)
        {
            int *pRec = NULL;

            // x  y  w  h  r  g  b  a
            //[0, 1, 2, 3, 4, 5, 6, 7]
            pRec = transArrCharToInt(pObjectsArr[i + 1], ',', PARAM_RECTANGLE_NUM);

            if (pRec == NULL)
                callStderrExit(ERROR_WRONG_CONF_REC, 1);

            Rectangle rect = {
                .x1 = pRec[0],
                .y1 = pRec[1],
                .x2 = pRec[0] + pRec[2],
                .y2 = pRec[1] + pRec[3],
            };

            checkRectangle(&rect, picWidth, picHeight);

            RGBA rectRGBA;

            if (checkRGBA(pRec, PARAM_RECTANGLE_NUM) == 0)
            {
                rectRGBA.red = pRec[4];
                rectRGBA.green = pRec[5];
                rectRGBA.blue = pRec[6];
                rectRGBA.alpha = pRec[7];
            }
            else
                callStderrExit(ERROR_RGBA, 1);

            TGAdrawRect(tga, &rectRGBA, &rect);

            free(pRec);
            pRec = NULL;
        }
        else if (strcmp(pObjectsArr[i], PARAM_CIRCLE) == 0)
        {
            int *pTria = NULL;

            pTria = transArrCharToInt(pObjectsArr[i + 1], ',', PARAM_CIRCLE_NUM);

            if (pTria == NULL)
                callStderrExit(ERROR_WRONG_CONF_CIR, 1);

            Circle circle = {
                .x = pTria[0],
                .y = pTria[1],
                .radius = pTria[2],
            };

            checkCircle(&circle, picWidth, picHeight);

            RGBA circleRGBA;

            if (checkRGBA(pTria, PARAM_CIRCLE_NUM) == 0)
            {
                circleRGBA.red = pTria[3];
                circleRGBA.green = pTria[4];
                circleRGBA.blue = pTria[5];
                circleRGBA.alpha = pTria[6];
            }
            else
                callStderrExit(ERROR_RGBA, 1);

            TGAdrawCircle(tga, &circleRGBA, &circle);

            free(pTria);
            pTria = NULL;
        }
        else if (strcmp(pObjectsArr[i], PARAM_TRIANGLE) == 0)
        {
        }
    }

    TGAwriteFile(tga, picFileOut);

    // Time to clear.
    if (fileConf != NULL)
    {
        for (int i = 0; i < numParams; i++)
        {
            free(pObjectsArr[i]);
        }
        free(pObjectsArr);
    }

    TGAfree(tga);

    return 0;
}
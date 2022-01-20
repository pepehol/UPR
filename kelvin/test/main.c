#include <stdlib.h>
#include <stdio.h>

void fileSaveMatrix(const char *name, int *matrix, const int rows, const int cols)
{

    FILE *f = NULL;

    f = fopen(name, "wt");

    if (!f)
    {
        fprintf(stderr, "Unable to open file!\n");
        exit(-15);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fprintf(f, "%d ", matrix[i * cols + j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

void fileExist(const char *name)
{
    FILE *f = NULL;

    f = fopen(name, "rt");

    // 3_missing_input
    // $ ./main matrix_6wz.txt output.txt
    // exit code: 2
    if (!f)
    {
        fprintf(stderr, "%s%s%s", "Vstupni soubor \"", name, "\" neexistuje.");
        exit(2);
    }

    fclose(f);
}

int *fileLoadSizeMatrix(const char *name)
{
    int *sizeMatrix = NULL;
    sizeMatrix = (int *)malloc(2 * sizeof(int));
    if (!sizeMatrix)
        return NULL;

    FILE *f = NULL;

    f = fopen(name, "rt");

    fscanf(f, "%d %d", &sizeMatrix[0], &sizeMatrix[1]);

    fclose(f);

    return sizeMatrix;
}

int * fileLoadMatrix(const char *name, const int len)
{
    int * matrix = NULL;
    matrix = (int *) malloc(len * sizeof(int));
    if (!matrix) return NULL;

    FILE * f = NULL;

    f = fopen(name, "rt");

    // Velikost matice preskocime.
    int i = 0;
    int j = 0;
    fscanf(f, "%d %d", &i, &j);

    for (int i = 0; i < len; i++)
    {
        fscanf(f, "%d", &matrix[i]);
    }

    fclose(f);

    return matrix;
}


int main(int argc, char *argv[])
{

    // 2_no_args
    // $ ./main
    // exit code: 1
    if (argc == 1)
    {
        fprintf(stderr, "Chybi cesta k vstupnimu a vystupnimu souboru.\n");
        exit(1);
    }

    // char *inputFile = "1.matrix1.txt";
    char *inputFile = argv[1];

    fileExist(inputFile);

    int *sizeMatrix = NULL;

    sizeMatrix = fileLoadSizeMatrix(argv[1]);

    int *matrix = NULL;
    matrix = fileLoadMatrix(inputFile, (sizeMatrix[0] * sizeMatrix[1]));

    int *matrixSwitch = NULL;
    matrixSwitch = (int *) malloc((sizeMatrix[0] * sizeMatrix[1]) * sizeof(int));
    if (!matrixSwitch) return -1;

    // Prehozeni matic.
    for (int i = 0; i < sizeMatrix[0]; i++)
    {
        for (int j = 0; j < sizeMatrix[1]; j++)
        {
            matrixSwitch[j * sizeMatrix[0] + i] = matrix[i * sizeMatrix[1] + j];
        }
    }

    fileSaveMatrix(argv[2], matrixSwitch, sizeMatrix[1], sizeMatrix[0]);


    free(sizeMatrix);
    free(matrix);
    free(matrixSwitch);

    return 0;
}
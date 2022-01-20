#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_max(int *res, int a, int b)
{
    if (a > b)
        *res = a;
    else
        *res = b;
}

void swap(int *a, int *b)
{
    int auxiliaryVar = *a;

    *a = *b;
    *b = auxiliaryVar;
}

void processTheArray(int *array, int len, int *sum, int *max, float *avg)
{
    for (int i = 0; i < len; i++)
    {
        *sum = *sum + array[i];
        if (*max < array[i])
            *max = array[i];
    }

    *avg = (float)*sum / (float)len;
}

int getNumberFromArr(int *array, int len, int value)
{
    for (int i = 0; i < len; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

void bubbleSort(int *array, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void printArr(int *array, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void reverseArr(int *array, int len)
{
    int *auxiliaryArr = NULL;
    auxiliaryArr = (int *)malloc(len * sizeof(int));
    // if(!auxiliaryArr) return -1; // Zde si pohlidat jestli OS opravdu nam
    // priradil volnou pamet na halde.

    for (int i = len; i >= 0; i--)
        auxiliaryArr[len - i] = array[i];

    for (int j = 0; j < len; j++)
        array[j] = auxiliaryArr[j];

    free(auxiliaryArr);
}

void copyArr8(int *array1, int len1, int *array2, int len2)
{
    if (len1 != len2 || len1 > len2)
        printf("Prvni pole nelze kopirovat do druheho pole.\n");
    else
    {
        for (int i = 0; i < len2; i++)
            array2[i] = array1[i];
    }
}

int main()
{
    //     /* 1.
    //     Funkci, která přijme adresu na int (pomocí ukazatele) a dvě čísla a
    //     nastaví paměť na dané adrese na větší ze zadaných čísel. */

    //     int res;
    //     set_max(&res, 7, 6);
    //     printf("set_max = %d \n", res);

    //     /* 2.
    //     Funkci, která přijme dva ukazatele a prohodí hodnoty proměnných,
    //     na které ukazují.*/

    //     int a = 5, b = 6;
    //     printf("a = %d, b = %d\n", a, b);
    //     swap(&a, &b);
    //     printf("a = %d, b = %d\n", a, b);

    //     /* 3.
    //     Funkci, která přijme pole (ukazatel na int) a počet prvků v poli,
    //     a vrátí součet čísel v poli, největší číslo v poli a průměrnou hodnotu
    //     čísel v poli. Vytvořte parametry datového typu ukazatele pro návrat více
    //     hodnot z funkce. */

    //     int sumOfAll = 0;
    //     int maxElement = 0;
    //     float average = 0;

    //     int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    //     processTheArray(array, 10, &sumOfAll, &maxElement, &average);

    //     printf("sum of all = %d\n", sumOfAll);
    //     printf("max element = %d\n", maxElement);
    //     printf("average = %.1f\n", average);

    //     /* 4.
    //     Funkci, která přijme pole a prvek a vrátí pozici, na kterém se prvek v
    //     daném poli nachází. Pokud prvek v poli vůbec není, vraťte z funkce -1. */

    //     int arrTest[4] = {3, 4, 1, 2};
    //     int searchElement = 5;
    //     int positionElement = getNumberFromArr(arrTest, 4, searchElement);
    //     printf("Pozice %d je %d.\n", searchElement, positionElement);

    //     /* 5.
    //     Funkci, která přijme pole a seřadí jeho hodnoty od nejmenší po největší.
    //     Můžete použít například algoritmus Bubble sort
    //     (https://en.wikipedia.org/wiki/Bubble_sort). */

    // #define ARR_LEN 7
    //     int arrUnsorted[ARR_LEN] = {3, 1, 2, 0, 22, 12, 5};

    //     printArr(arrUnsorted, ARR_LEN);
    //     bubbleSort(arrUnsorted, ARR_LEN);
    //     printArr(arrUnsorted, ARR_LEN);

    //     /* 6.
    //     Program, který načte od uživatele číslo n. Poté naalokujte paměť o velikosti
    //     n intů a načtěte ze vstupu n čísel, které postupně uložte do vytvořeného
    //     pole. Vypište součet načteného pole. */
    //     /*
    //         int arrLen6 = 0;
    //         printf("Zadejte velikost pole, ktere mam naalokovat = ");
    //         scanf("%d", &arrLen6);
    //         printf("\n");

    //         int* array6 = NULL;
    //         array6 = (int *)malloc(arrLen6 * sizeof (int));
    //         if(!array6)
    //             return -1;

    //         int inpValue6 = 0;
    //         for (int i = 0; i < arrLen6; i++)
    //         {
    //             printf("Vlozte prvek naalokovaneho pole = ");
    //             scanf("%d", &inpValue6);
    //             array6[i] = inpValue6;
    //             printf("\n");
    //         }

    //         printArr(array6, arrLen6);

    //         free(array6);
    //      */
    //     /* 7.
    //     Funkci, která přijme pole a "obrátí ho" (první prvek se stane posledním
    //     prvkem, druhý prvek se stane předposledním prvkem atd.). */

    // #define ARR_LEN7 6
    //     int arr7[ARR_LEN7];
    //     for (int i = 0; i < ARR_LEN7; i++)
    //         arr7[i] = i;

    //     printf("Prehazeni prvku v poli.\n");
    //     printArr(arr7, ARR_LEN7);
    //     reverseArr(arr7, ARR_LEN7);
    //     printArr(arr7, ARR_LEN7);

    // /* 8.
    // Funkci, která přijme dvě pole a zkopíruje prvky prvního pole do druhého
    // pole. */
    // #define ARR_LEN81 5
    //     int arr81[ARR_LEN81] = {0};
    // #define ARR_LEN82 6
    //     int arr82[ARR_LEN82] = {[0 ...(ARR_LEN82 - 1)] = 5};

    //     printf("Prvni pole - ");
    //     printArr(arr82, ARR_LEN82);

    //     printf("Druhe pole - ");
    //     printArr(arr81, ARR_LEN81);

    //     copyArr8(arr82, ARR_LEN82, arr81, ARR_LEN81);

    //     printf("Po operaci prohozeni poli.\n");

    //     printf("Prvni pole - ");
    //     printArr(arr82, ARR_LEN82);

    //     printf("Druhe pole - ");
    //     printArr(arr81, ARR_LEN81);

    int arr[4] = {10, 11, 12, 13};
    int(*ptr)[4];
    ptr = arr;

    printf("%d\n", ptr[0]);
    return 0;
}
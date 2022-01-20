#include <stdio.h>
#include <stdlib.h>

int* createIntArray(const int len)
{
    int* array = NULL;
    array = (int *)malloc(len * sizeof (int));
    return array;
}

void loadIntArray(int * array, const int len)
{
    int numInTheField = 0;
    for (int i = 0; i < len; i++)
    {
        scanf("%d ", &numInTheField);
        array[i] = numInTheField;
    }
}

void printIntArray(int * array, const int len)
{
    for (int i = 0; i < len; i++)
    {
        if ((array[i] % 2) == 0)
        {
            printf("%d even\n", array[i]);
        }
        else
        {
            printf("%d odd\n", array[i]);
        }
    }
}

int main()
{
    int arrayLen = 0;
    scanf("%d ", &arrayLen);

    int * buf = NULL;
    buf = createIntArray(arrayLen);
    loadIntArray(buf, arrayLen);

    printIntArray(buf, arrayLen);

    free(buf);
    return 0;
}
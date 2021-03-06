#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define VEC_LEN 10

float * softmax(const float * array, const int len) 
{
    float * outputVector = NULL;
    float sumOfAll = 0.0;

    assert(array && len > 0);

    outputVector = (float*) malloc(VEC_LEN * sizeof(float));
    if(!outputVector) return NULL;

    for (int i = 0; i < len; i++)
    {
        sumOfAll += exp(array[i]);
    }

    for (int i = 0; i < len; i++)
    {
        outputVector[i] = exp(array[i]) / sumOfAll;
    }

    return outputVector;
}

int argmax(const float * array, const int len) 
{
    float softmaxMax = 0;
    int softmaxInd = 0;
    for (int i = 0; i < len; i++) 
    {
        if (softmaxMax <= array[i]) 
        {
            softmaxMax = array[i];
            softmaxInd = i;
        }
    }
    return softmaxInd;
}

int main()
{
    int vectorNumber = 0;
    float * vectorInput = (float*) malloc(VEC_LEN * sizeof(float));
    float * vectorSoftmax = NULL;
    int result = 0;

    scanf("%d ", &vectorNumber);

    for (int i = 0; i < vectorNumber; i++) 
    {
        for (int j = 0; j < VEC_LEN; j++) 
        {
            scanf("%f ", &vectorInput[j]);
        }
        vectorSoftmax = softmax(vectorInput, VEC_LEN);
        result = argmax(vectorSoftmax, VEC_LEN);

        printf("%d ", result);
        for (int k = 0; k < VEC_LEN; k++) 
        {
            printf("%.4f ", vectorSoftmax[k]);
        }
        free(vectorSoftmax);
        printf("\n");
    }

    free(vectorInput);

    return 0;
}
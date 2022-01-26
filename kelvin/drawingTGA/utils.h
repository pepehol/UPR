#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "configure.h"

#define ALLOCTEST(x) if ((!x)) utils_out_of_memory(__FILE__, __LINE__)

void utils_out_of_memory(const char *filename, const int lineno);
int * transArrCharToInt(char *s, char d, const int number);
void callStderrExit(char *s, int t);
void printIntArray(int *arr, int num);


#endif
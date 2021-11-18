#include <stdio.h>
#include <string.h>

#define LOW_UPPER_CHAR 32
#define UPPER_START 65
#define UPPER_END 90

void uppercase(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        // Priklad uziti interpunkcniho znamenka.
        if (str[i] == ' ')
        {
            printf(" ");
        }
        else
        {
            printf("%c", str[i] - LOW_UPPER_CHAR);
        }
    }
    printf("\n");
}

void replace(char str[], char replace)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (replace == str[i])
        {
            printf("X");
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

void encrypt(char str[], int cipher)
{
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i] + cipher);
    }
    printf("\n");
}

void decrypt(char str[], int cipher)
{
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i] - cipher);
    }
    printf("\n");
}

void strequal(char str[], char str1[])
{
    int result = 0;
    result = strcmp(str, str1);

    if (result == 0)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}

void strequal_ignorecase(char str[], char str1[])
{
    int localStrLen = strlen(str);
    char localStr[localStrLen];

    for (int i = 0; i < localStrLen; i++)
    {
        if (str[i] <= UPPER_END && str[i] >= UPPER_START)
        {
            localStr[i] = str[i] + LOW_UPPER_CHAR;
        }
        else
        {
            localStr[i] = str[i];
        }
    }

    int localStrLen1 = strlen(str1);
    char localStr1[localStrLen1];

    for (int j = 0; j < localStrLen1; j++)
    {
        if (str1[j] <= UPPER_END && str1[j] >= UPPER_START)
        {
            localStr1[j] = str1[j] + LOW_UPPER_CHAR;
        }
        else
        {
            localStr1[j] = str1[j];
        }
    }

    strequal(localStr1, localStr);
}

int main()
{
    char str[] = {"hello"};

    uppercase(str);
    replace(str, 'l');

    char str1[] = {"abc"};
    char str2[] = {"bcd"};

    encrypt(str1, 1);
    decrypt(str2, 1);

    strequal("ahoj", "ahoj");               // 1
    strequal("ahoj", "aho");                // 0
    strequal_ignorecase("AhOJ", "ahoj");    // 1

    return 0;
}
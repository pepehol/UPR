#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define LOW_UPPER_CHAR 32
#define UPPER_START 65
#define UPPER_END 90

#define NUMBER_START 48
#define NUMBER_END 57

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
    int strLen = strlen(str);
    char strHelper[strLen + 1];
    memset(strHelper, 0, strLen + 1);

    for (int i = 0; i < strLen; i++)
    {
        if (str[i] <= UPPER_END && str[i] >= UPPER_START)
        {
            strHelper[i] = str[i] + LOW_UPPER_CHAR;
        }
        else
        {
            strHelper[i] = str[i];
        }
    }
    // printf("%s\n", strHelper);

    strLen = strlen(str1);
    char strHelper1[strLen + 1];
    memset(strHelper1, 0, strLen + 1);

    for (int j = 0; j < strLen; j++)
    {
        if (str1[j] <= UPPER_END && str1[j] >= UPPER_START)
        {
            strHelper1[j] = str1[j] + LOW_UPPER_CHAR;
        }
        else
        {
            strHelper1[j] = str1[j];
        }
    }
    // printf("%s\n", strHelper1);

    strequal(strHelper, strHelper1);
}

void palindrom(char str[])
{
    int strLen = strlen(str);
    char reverseStr[strLen + 1];
    memset(reverseStr, 0, strLen + 1);

    for (int i = strLen; i >= 0; i--)
    {
        reverseStr[(strLen - i)] = str[i - 1];
    }

    strequal(str, reverseStr);
}

void calc_histogram(char str[], int histogram[])
{
    int strLen = strlen(str);
    char strOnlyOneChar[strLen + 1];
    memset(strOnlyOneChar, 0, strLen + 1);


    int indexOnlyOne = 0;
    bool sameChar = false;
    bool diffChar = false;
    for (int i = 0; i < strLen; i++)
    {
        for (int j = 0; j <= indexOnlyOne; j++)
        {
            if (str[i] != strOnlyOneChar[j])
            {
                diffChar = true;
            }

            if (str[i] == strOnlyOneChar[j])
            {
                sameChar = true;
                break;
            }
        }
        if (diffChar == true && sameChar == false)
        {
            strOnlyOneChar[indexOnlyOne] = str[i];
            indexOnlyOne++;
            diffChar = false;
            sameChar = false;
        }
        else if (sameChar == true)
        {
            diffChar = false;
            sameChar = false;
        }
    }

    printf("%s \n", strOnlyOneChar);

    int countChar = 0;
    for (int i = 0; i < indexOnlyOne; i++)
    {
        for (int j = 0; j < strLen; j++)
        {
            if (strOnlyOneChar[i] == str[j])
                countChar++;
        }
        printf("histogram['%c'] == %d \n", strOnlyOneChar[i], countChar);
        countChar = 0;
    }
}

/* Sefovo reseni */
void print_histogram1(int histogram[], const int histogram_len)
{
    for(int i = 0; i < histogram_len; i++)
    {
        if(histogram[i])
        {
            printf("histogram['%c']=%d\n", (char)i, histogram[i]);
        }
    }
}

void calc_histogram1(char str[], int histogram[], const int histogram_len)
{
    memset(histogram, 0, histogram_len);

    for (int i = 0; i < strlen(str); i++)
    {
        if((int)str[i] < histogram_len)
        {
            histogram[str[i]]++;
        }
    }
}
/* Sefovo reseni */

int convert(char strNum[])
{
    int number = 0;
    int strNumLen = strlen(strNum);
    for (int i = 0; i < strlen(strNum); i++)
    {
        if (strNum[i] >= NUMBER_START && strNum[i] <= NUMBER_END)
        {
            number = number + ((strNum[i] - '0') * pow(10, (strNumLen - i) - 1));
        }
        else
            return 0;
    }
    return number;
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
    strequal_ignorecase("ahoj", "AhOj");    // 1

    palindrom("anna");

    int histogram[255] = {};
    calc_histogram("aabacc", histogram);

    int histogram1[255] = {0};
    calc_histogram1("aabacc", histogram, 255);
    print_histogram1(histogram, 255);

    printf("%d \n", convert("5"));
    printf("%d \n", convert("123"));

    return 0;
}
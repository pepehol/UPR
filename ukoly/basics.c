#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int myAbs(int num)
{
    if (num >= 0)
        return num;
    else
        return -num;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void printToTerminal(char inp[])
{
    if (strcmp(inp, "radek") == 0)
    {
        for (int i = 0; i < 13; i++)
            printf("x");
        printf("\n");
    }
    if (strcmp(inp, "sloupec") == 0)
    {
        for (int i = 0; i < 5; i++)
            printf("x\n");
    }
    if (strcmp(inp, "ctverec") == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int i = 0; i < 4; i++)
                printf("x");
            printf("\n");
        }
    }
    if (strcmp(inp, "duty_ctverec") == 0)
    {
        char hollowSqr[4][5] = {"xxxx\n",
                                "x  x\n",
                                "x  x\n",
                                "xxxx\n"};
        printf("%s", hollowSqr);
    }
    if (strcmp(inp, "diagonala") == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                printf("x\n");
                continue;
            }
            for (int j = 0; j < i; j++)
                printf(" ");
            printf("x\n");
        }
    }
    if (strcmp(inp, "trojuhelnik") == 0)
    {
        int trg = 8;
        int top = trg / 2;
        int leftRight = top;

        for (int i = 0; i < trg / 2; i++)
        {
            for (int j = 0; j < trg; j++)
            {
                if (i > 0)
                {
                    if (j == leftRight + i)
                    {
                        printf("x");
                        continue;
                    }
                    if (j == leftRight - i)
                    {
                        printf("x");
                        continue;
                    }
                }
                else
                {
                    if (j == top)
                    {
                        printf("x");
                        continue;
                    }
                }
                printf(" ");
            }
            printf("\n");
        }
        for (int k = 0; k < trg + 1; k++)
            printf("x");
        printf("\n");
    }
}

int main()
{
    /*
    Program, který vypíše pouze sudá čísla v rozsahu [0, 100]
*/

    // int end = 100;
    // int counter = 0;
    // while(counter <= 100) {
    //     if (counter % 2 == 0) {
    //         printf("%d\n", counter);
    //     }
    //     counter++;
    // }

    /* 
    Funkci, která vrátí absolutní hodnotu parametru
*/

    // printf("%d\n", myAbs(5));
    // printf("%d\n", myAbs(0));
    // printf("%d\n", myAbs(-1));

    /*
    Funkci, která vypočte faktoriál parametru
*/

    // printf("%d\n", factorial(0));
    // printf("%d\n", factorial(1));
    // printf("%d\n", factorial(4));
    // printf("%d\n", factorial(5));

    /*
    Funkci, která vrátí n-té Fibonacciho číslo
*/

    // printf("%d\n", fibonacci(0));
    // printf("%d\n", fibonacci(1));
    // printf("%d\n", fibonacci(2));
    // printf("%d\n", fibonacci(3));
    // printf("%d\n", fibonacci(4));
    // printf("%d\n", fibonacci(5));
    // printf("%d\n", fibonacci(6));

    /*
        Hru "guessing game"
    Hra vygeneruje náhodné číslo. Uživatel bude opakovaně hádat číslo, program mu 
    napíše, jestli je jeho tip moc velký nebo moc malý. Jakmile uživatel uhádne 
    číslo, tak program skončí.
*/

    // // inicializace náhodného generátoru
    // srand(time(NULL));

    // // Náhodné číslo bude v intervalu <0, 200>
    // int max = 201;
    // int rnd = rand() % max;
    // int num = 0;

    // printf("Hadame cislo do max %d\n", max);

    // do {
    //     scanf("%d", &num);
    //     if (num > rnd)
    //         printf("Zadane cislo je mensi nez hledane.\n");
    //     if (num < rnd)
    //         printf("Zadane cislo je vetsi nez hledane.\n");
    // } while (rnd != num);

    /*
    Program, který načte od uživatele dvě čísla a matematický operátor 
    (+, -, *, /) a vypíše výsledek zadané operace.
*/
    // int x, y;
    // scanf("%d %d", &x, &y);
    // printf("Operace + = %d\n", x + y);
    // printf("Operace - = %d\n", x - y);
    // printf("Operace * = %d\n", x * y);
    // printf("Operace / = %.2f\n", (float) x / (float) y);

    /*
    Program, který vypočte dostupnost služby za rok v procentech (např. 99,9).
    Pro kontrolu můžete použít např. SLA Calculator
*/

    // float hoursYear = 365 * 24;
    // float x;
    // printf("Zadejte smluvený uptime (např. 99.9)\n ");
    // scanf("%f", &x);
    // printf("Služba bude nedostupná maximálně %.4f hodin.\n", (float) hoursYear * ((100 - x) / 100));

    /*
    Program, který bude postupně načítat ze vstupu čísla, dokud uživatel
    nezadá 0. Program poté vypíše součet všech zadaných čísel.
*/

    // float total = 0;
    // float helper = 0;
    // do {
    //     scanf("%f", &helper);
    //     total = total + helper;
    // } while (helper != 0);
    // printf("Celkovy soucet %.2f\n", total);

    /*
    Program, který 10 000x hodí kostkou (vygeneruje náhodné číslo v rozsahu
    [1, 6]) a poté vypíše průměrnou hodnotu všech vygenerovaných hodnot.
*/

    // srand(time(NULL));
    // int max = 7;
    // int rnd = 0;
    // int maxStep = 10000;
    // int avg = 0;
    // for (int i = 0; i < maxStep; i++) {
    //     rnd = rand() % max;
    //     avg = avg + rnd;
    // }
    // printf("Prumer z %d hodu je = %f\n", maxStep, (float) (avg / maxStep));

    /*
    Program, který nejprve načte od uživatele PIN (4 číslice). Poté bude 
    opakovaně vyzývat uživatele k zadání PINu. Pokud uživatel zadá 3x 
    nesprávný PIN, vypište chybovou hlášku a ukončete program.
*/

    // printf("Zadejte PIN (4 cisla)\n");
    // int pin = 0;
    // scanf("%d", &pin);
    // if (pin < 1000 || pin > 9999){
    //     printf("Zadany Pin musi mit ctyri cislice.\n");
    //     return 1;
    // }

    // int checkPin = 0;
    // for (int i = 0; i < 3; i++) {
    //     printf("Zadejte PIN pro overeni.\n");
    //     scanf("%d", &checkPin);
    //     if (checkPin == pin){
    //         printf("PIN v poradku.\n");
    //         return 0;
    //     }
    // }
    // printf("Spatne zadany PIN, ukoncuji a nahlasuji tuto aktivitu.\n");

    /*
    Funkce, které budou vykreslovat různé geometrické obrazce na výstup
    # řádek
    xxxxxxxxxxxxx

    # sloupec
    x
    x
    x
    x
    x

    # čtverec
    xxxx
    xxxx
    xxxx
    xxxx

    # dutý čtverec
    xxxx
    x  x
    x  x
    xxxx

    # diagonálu
    x
     x
      x
       x
        x

    # trojúhelník
        x
       x x
      x   x
     x     x
    xxxxxxxxx
*/

    char buf[20] = "";
    scanf("%20s", buf);
    printToTerminal(buf);

    return 0;
}
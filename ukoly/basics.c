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
        int side = 10;
        for (int i = 0; i < side; i++)
        {
            for (int i = 0; i < side; i++)
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
    Program, kter?? vyp????e pouze sud?? ????sla v rozsahu [0, 100]
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
    Funkci, kter?? vr??t?? absolutn?? hodnotu parametru
*/

    // printf("%d\n", myAbs(5));
    // printf("%d\n", myAbs(0));
    // printf("%d\n", myAbs(-1));

    /*
    Funkci, kter?? vypo??te faktori??l parametru
*/

    // printf("%d\n", factorial(0));
    // printf("%d\n", factorial(1));
    // printf("%d\n", factorial(4));
    // printf("%d\n", factorial(5));

    /*
    Funkci, kter?? vr??t?? n-t?? Fibonacciho ????slo
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
    Hra vygeneruje n??hodn?? ????slo. U??ivatel bude opakovan?? h??dat ????slo, program mu
    nap????e, jestli je jeho tip moc velk?? nebo moc mal??. Jakmile u??ivatel uh??dne
    ????slo, tak program skon????.
*/

    // // inicializace n??hodn??ho gener??toru
    // srand(time(NULL));

    // // N??hodn?? ????slo bude v intervalu <0, 200>
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
    Program, kter?? na??te od u??ivatele dv?? ????sla a matematick?? oper??tor
    (+, -, *, /) a vyp????e v??sledek zadan?? operace.
*/
    // int x, y;
    // scanf("%d %d", &x, &y);
    // printf("Operace + = %d\n", x + y);
    // printf("Operace - = %d\n", x - y);
    // printf("Operace * = %d\n", x * y);
    // printf("Operace / = %.2f\n", (float) x / (float) y);

    /*
    Program, kter?? vypo??te dostupnost slu??by za rok v procentech (nap??. 99,9).
    Pro kontrolu m????ete pou????t nap??. SLA Calculator
*/

    // float hoursYear = 365 * 24;
    // float x;
    // printf("Zadejte smluven?? uptime (nap??. 99.9)\n ");
    // scanf("%f", &x);
    // printf("Slu??ba bude nedostupn?? maxim??ln?? %.4f hodin.\n", (float) hoursYear * ((100 - x) / 100));

    /*
    Program, kter?? bude postupn?? na????tat ze vstupu ????sla, dokud u??ivatel
    nezad?? 0. Program pot?? vyp????e sou??et v??ech zadan??ch ????sel.
*/

    // float total = 0;
    // float helper = 0;
    // do {
    //     scanf("%f", &helper);
    //     total = total + helper;
    // } while (helper != 0);
    // printf("Celkovy soucet %.2f\n", total);

    /*
    Program, kter?? 10 000x hod?? kostkou (vygeneruje n??hodn?? ????slo v rozsahu
    [1, 6]) a pot?? vyp????e pr??m??rnou hodnotu v??ech vygenerovan??ch hodnot.
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
    Program, kter?? nejprve na??te od u??ivatele PIN (4 ????slice). Pot?? bude
    opakovan?? vyz??vat u??ivatele k zad??n?? PINu. Pokud u??ivatel zad?? 3x
    nespr??vn?? PIN, vypi??te chybovou hl????ku a ukon??ete program.
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
    Funkce, kter?? budou vykreslovat r??zn?? geometrick?? obrazce na v??stup
    # ????dek
    xxxxxxxxxxxxx

    # sloupec
    x
    x
    x
    x
    x

    # ??tverec
    xxxx
    xxxx
    xxxx
    xxxx

    # dut?? ??tverec
    xxxx
    x  x
    x  x
    xxxx

    # diagon??lu
    x
     x
      x
       x
        x

    # troj??heln??k
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
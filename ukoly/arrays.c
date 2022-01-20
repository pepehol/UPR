#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

void printArr(int * array, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void fill_array(int *array, int len, int start, int increment)
{
    for (int i = 0; i < len; i++)
    {
        array[i] = start + (increment * i);
    }
}

int num_count(int *array, int len, int num)
{
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (array[i] == num)
            counter++;

    }
    return counter;
}

int in_interval(int *array, int len, int from, int to)
{
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (array[i] <= to && array[i] >= from)
            counter++;
    }
    return counter;
}

double avg(int *array, int len)
{
    int sumOfAll = 0;
    for (int i = 0; i < len; i++)
        sumOfAll = sumOfAll + array[i];

    return (double) sumOfAll / (double) len;
}

void min_max(int *array, int len, int *min, int *max)
{
    *min = array[0];
    *max = array[0];

    for (int i = 0; i < len; i++)
    {
        if (array[i] >= *max)
            *max = array[i];
        if (array[i] <= *min)
            *min = array[i];
    }
}

void swap(int* a, int* b)
{
    int auxiliaryVar = *a;

    *a = *b;
    *b = auxiliaryVar;
}

void array_reverse(int *array, int len)
{
    for (int i = 0; i < (len / 2); i++)
        swap(&array[i], &array[(len - i) - 1]);
}

int dot(int *a, int *b, int len)
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        result = result + (a[i] * b[i]);
    }
    return result;
}

void counting_sort(int *array, int len)
{
    #define COUNTER 10
    int * counts = NULL;
    counts = (int *)malloc(COUNTER * sizeof (int));
    // if(!auxiliaryArr) return -1; // Zde si pohlidat jestli OS opravdu nam
    // priradil volnou pamet na halde.
    memset(counts, '\0', COUNTER * sizeof (int));

    for(int i = 0; i < len; i++)
        counts[array[i]]++;

    printf("Vyskyt prvku v poli - ");
    printArr(counts, COUNTER);

    printf("Setrizene pole - ");
    for(int i = 0; i < COUNTER; i++)
    {
        if (counts[i] != 0)
            for (int j = 0; j < counts[i]; j++)
                printf("%d ", i);
    }
    printf("\n");

    free(counts);
}

void print_matrix(int* matrix, int rows, int cols)
{
    int cnt = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[cnt]);
            cnt++;
        }
        printf("\n");
    }
}

void print_img(int* matrix, int rows, int cols)
{
    int cnt = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(matrix[cnt] != 0)
                printf("x");
            else
                printf(" ");
            cnt++;
        }
        printf("\n");
    }
}

void LineBres (int x1, int y1, int x2, int y2, int * array)
// předpoklady: x1 < x2, |y2-y1| < |x2-x1|
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int D = 2 * dy - dx;
    int inc0 = 2 * dy;
    int inc1 = 2 * (dy - dx);
    array[x1 * y1] = 1;
    while (x1 < x2)
    {
        if (D <= 0)
            D += inc0;
        else
        {
            D += inc1;
            y1++;
        }
        x1++;
        array[x1 * y1] = 1;
    }
}

void draw_star(int* matrix, int rows, int cols)
{
    int x = 0;
    int y = 0;

    int middleX = cols / 2;
    int middleY = rows / 2;

    int maxX = (cols - 1);
    int minY = 0;

    printf("middle x = %d, midlle y = %d\n", middleX, middleY);

    for (int i = 0; i < (rows * cols); i++)
    {

        if (x == middleX)
        {
            matrix[i] = 1;
        }

        if (y == middleY)
        {
            matrix[i] = 1;
        }

        if (x == y)
        {
            matrix[i] = 1;
        }

        if (x == maxX && y == minY)
        {
            matrix[i] = 1;
            maxX--;
            minY++;
        }

        x++;

        if (x == (cols))
        {
            x = 0;
            y++;
        }
    }
}

#define PUT_PIXEL(i, val)   \
{                           \
    printf("%c", val);      \
    matrix[i] = val;        \
}

void draw_star_z(int* matrix, int rows, int cols)
{
    int x, y = -1;
    float k = (float)cols / (float)rows;
    float f_y1, f_y2;

    for(int i = 0; i < (rows * cols); i++)
    {
        x = i % rows;
        if(!x)
        {
            y++;
            printf("\n");
        }

        f_y1 = k * ((float)x);
        f_y2 = k * ((float)(rows - x - 1));

        if(y == (cols / 2)
           || x == (rows / 2)
           || y == (int)f_y1
           || y == (int)f_y2)
        {
           PUT_PIXEL(i, 'X');
        }
        else
        {
           PUT_PIXEL(i, ' ');
        }
    }
}

void matrix_mul_scalar(int* matrix, int rows, int cols, int k)
{
    for (int i = 0; i < (rows * cols); i++)
    {
        matrix[i] = matrix[i] * k;
    }
}

int* matrix_mul_vec(int* matrix, int rows, int cols, int *vec, int len)
{
    int * result = NULL;

    result = (int *)malloc(len * sizeof (int));

    // if (!result) return -1;

    int auxiliaryResult = 0;
    int counterVec = 0;
    int counterRes = 0;
    for (int i = 0; i < (cols * rows); i++)
    {
        auxiliaryResult = auxiliaryResult + (matrix[i] * vec[counterVec]);

        if (counterVec == 2)
        {
            result[counterRes] = auxiliaryResult;
            counterRes++;
            auxiliaryResult = 0;
            counterVec = 0;
        }
        else
            counterVec++;
    }
    return result;
}

int main()
{

    /*
    1.
    fill_array - naplnění pole

    void fill_array(int *array, int len, int start, int increment);

    Funkce naplní pole array čísly zvětšující se po increment a 
    začínající od start.

    Zavolání fill_array(nums, 6, 10, 5) naplní pole čísly: 
        10, 15, 20, 25, 30, 35.
    */

    int nums[6] = {0};
    printArr(nums, 6);
    fill_array(nums, 6, 10, 5);
    printArr(nums, 6);

    /*
    2.
    num_count - počet výskytů čísla

    int num_count(int *array, int len, int num);

    Funkce num_count projde celé pole a spočítá počet výskytu čísla num.
    */

    #define ARR_LEN2 10 
    int arr2[ARR_LEN2] = {1, 2, 3, 4, 5, 1, 2, 3, 7, 8};

    int find2 = 7;
    int count2 = num_count(arr2, ARR_LEN2, find2);

    printf("Prvek %d se vyskytuje %dx v poli\n", find2, count2);

    /*
    3.
    in_interval - počet čísel v daném intervalu

    int in_interval(int *array, int len, int from, int to);
    Oproti předchozí funkci se bude počítat počet čísel, která náleží do 
    intervalu <from, to>.
    */

    #define ARR_LEN3 10
    int arr3[ARR_LEN3] = {1, 2, 3, 4, 5, 1, 2, 3, 7, 8};
    int from = 1;
    int to = 3;

    int count3 = in_interval(arr3, ARR_LEN3, from, to);

    printf("Prveky %d, %d se vyskytuje %dx v poli\n", from, to, count3);

    /*
    4.
    avg - průměrná hodnota pole

    double avg(int *array, int len);

    Funkce spočítá součet všech prvků v poli a následně vrátí tento součet 
    podělený počtem prvků, čímž získáme průměrnou hodnotu. Při dělení nesmíme
    zapomenout na přetypování alespoň jednoho operandu na typ double,
    jinak by docházelo k celočíselnému dělení.
    */

    #define ARR_LEN4 10
    int arr4[ARR_LEN4] = {1, 2, 3, 4, 5, 1, 2, 3, 7, 8};

    double average = avg(arr4, ARR_LEN4);

    printf("Prumerna hodnota vstupniho pole je %.2f\n", average);

    /*
    5.
    min_max - minimální a maximální hodnota v poli

    void min_max(int *array, int len, int *min, int *max);

    Ve funkci si nastavíme index minimální a maximální hodnoty na nultý prvek.
    Parametr min je pointer, a je tedy nutné přistupovat k hodnotě pomoci
    dereference - *min, protože výraz min obsahuje jen adresu,
    kde je minimální index uložen. Následně budeme procházet pole a pokud bude
    hodnota aktuálního prvku menší než hodnota prvku na dosud nalezeném indexu,
    nastavíme index na aktuální.
    */

    #define ARR_LEN5 10
    int arr5[ARR_LEN5] = {1, 2, 3, 4, 5, 1, 2, 3, 7, 8};

    int min5;
    int max5;

    min_max(arr5, ARR_LEN5, &min5, &max5);

    printf("Min prvek %d a max prvek %d\n", min5, max5);

    /*
    6.
    array_reverse - převrácení pole

    void array_reverse(int *array, int len);

    Pole projdeme pomoci cyklu do jeho půlky a budeme vždy prohazovat prvky z
    obou konců. Pokud bychom projeli celé pole, tak bychom v druhé půlce
    přehazovali prvky na jejích původní místo.

    Přehození dvou prvků nemůžeme udělat najednou, tak si musíme například
    prvek z levého konce uložit do proměnné a následně do toho prvku zapsat
    hodnotu z pravého konce. Poté lze uložit hodnotu z proměnné do pravého 
    konce. Alternativně také můžeme využít funkci void swap(int *a, int *b) z
    příkladu pointers.
    */

    #define ARR_LEN6 10
    int arr6[ARR_LEN6] = {1, 2, 3, 4, 5, 1, 2, 3, 7, 8};

    printArr(arr6, ARR_LEN6);

    array_reverse(arr6, ARR_LEN6);

    printArr(arr6, ARR_LEN6);

    /*
    7.
    dot - skalární součin (dot product)

    int dot(int *a, int *b, int len);
    */

    #define ARR_LEN7 3
    int a7[ARR_LEN7] = {1, 3, -5};
    int b7[ARR_LEN7] = {4, -2, -1};

    int result = dot(a7, b7, ARR_LEN7);

    printf("Vysledek skalarniho soucinu je %d\n", result);

    /*
    8.
    counting_sort - counting sort

    Counting sort algoritmus je vhodný pro seřazení pole, které nabývá menšího
    rozsahu hodnot. Pro každou možnou hodnotu pole si uchováváme čítač výskytů

    void counting_sort(int *array, int len, int from, int to);

    V prvním kroku naplníme pole náhodnými čísly od 0 do 10. Ve funkci counting
    sort si vytvoříme pole 10 čítačů, které vynulujeme např. pomocí for cyklu.
    Následně projdeme celé vstupní pole array a pro každý prvek inkrementujeme
    patřičný čítač. Při výskytu prvku 0 inkrementujeme nultý čítač, při
    výskytu 1 první čítač atd.

    Čítače jsou seřazený a obsahují počet výskytu jednotlivých čísel.
    Stačí tedy projít všechny čítače a zapsat tolik prvků, kolik je hodnota
    daného čítače.
    */

    #define ARR_LEN8 8
    int arr8[ARR_LEN8] = {1, 2, 3, 4, 5, 1, 2, 3};

    printf("Nesetrizene pole - ");
    printArr(arr8, ARR_LEN8);

    counting_sort(arr8, ARR_LEN8);

    /*
    9.
    print_matrix - vytisknutí matice

    void print_matrix(int* matrix, int rows, int cols);
    void print_img(int* matrix, int rows, int cols);

    Funkce projde matici po řádcích a sloupcích a vypíše jednotlivé prvky.
    V případě funkce print_img se vytisknou čísla jako znaky.
    */

    #define ARR_LEN9 15
    #define ROWS9 3
    #define COLS9 5
    int arr9[ARR_LEN9] = {1, 0, 2, 0, 3, 0, 4, 5, 6, 0, 7, 8, 9, 10, 11};

    print_matrix(arr9, ROWS9, COLS9);
    print_img(arr9, ROWS9, COLS9);

    /*
    10.
    draw_star - vykreslení hvězdice

    void draw_star(int* matrix, int rows, int cols);

    X    X    X
     X   X   X 
      X  X  X  
       X X X   
        XXX    
    XXXXXXXXXXX
        XXX    
       X X X   
      X  X  X  
     X   X   X 
    X    X    X

    Hvězdici můžeme vykreslit do pole pomocí jediného cyklu.
    */
    #define ROWS10 7
    #define COLS10 7

    int * matrix10 = NULL;

    matrix10 = (int *)malloc((ROWS10 * COLS10) * sizeof (int));
    if (!matrix10) return -1;

    memset(matrix10, '\0', (ROWS10 * COLS10) * sizeof (int));
    printf("LENGTH = %d\n", (ROWS10 * COLS10));

    draw_star(matrix10, ROWS10, COLS10);

    print_img(matrix10, ROWS10, COLS10);

    printf("\n");

    draw_star_z(matrix10, COLS10, ROWS10);

    printf("\n");

    free(matrix10);

    /*
    11.
    matrix_mul_scalar - násobení matice skalárem

    void matrix_mul_scalar(int* matrix, int rows, int cols, int k);

    Vytvořte funkci, která vynásobí každý prvek matice číslem k.
    */

    #define ROWS11 3
    #define COLS11 3

    int * matrix11 = NULL;

    matrix11 = (int *)malloc((ROWS11 * COLS11) * sizeof (int));
    if (!matrix11) return -1;

    printf("---\n");
    print_matrix(matrix11, ROWS11, COLS11);
    printf("---\n");

    memset(matrix11, '\0', (ROWS11 * COLS11) * sizeof (int));

    print_matrix(matrix11, ROWS11, COLS11);
    printf("---\n");

    matrix11[0] = 3;
    matrix11[1] = 5;
    matrix11[2] = 7;
    matrix11[3] = 1;
    matrix11[4] = 2;
    matrix11[5] = 8;
    matrix11[6] = 2;
    matrix11[7] = 3;
    matrix11[8] = 1;

    print_matrix(matrix11, ROWS11, COLS11);
    printf("\n");

    int k = 2;

    matrix_mul_scalar(matrix11, ROWS11, COLS11, k);

    print_matrix(matrix11, ROWS11, COLS11);
    printf("\n");

    free(matrix11);

    /*
    matrix_mul_vec - násobení matice vektorem

    int* matrix_mul_vec(int* matrix, int rows, int cols, int *vec, int len);
    */

    #define ROWS12 3
    #define COLS12 3

    int * matrix12 = NULL;

    matrix12 = (int *)malloc((ROWS12 * COLS12) * sizeof (int));
    if (!matrix12) return -1;

    matrix12[0] = 1;
    matrix12[1] = 2;
    matrix12[2] = 3;
    matrix12[3] = 4;
    matrix12[4] = 5;
    matrix12[5] = 6;
    matrix12[6] = 7;
    matrix12[7] = 8;
    matrix12[8] = 9;

    int * vector12 = NULL;

    vector12 = (int *)malloc(COLS12 * sizeof (int));
    if (!vector12) return -1;

    vector12[0] = 10;
    vector12[1] = 20;
    vector12[2] = 30;

    int * result12 = NULL;
    result12 = matrix_mul_vec(matrix12, ROWS12, COLS12, vector12, COLS12);

    print_matrix(result12, 1, COLS12);

    free(matrix12);
    free(vector12);
    free(result12);

    return 0;
}

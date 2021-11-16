#include <stdio.h>
#define arr_size 100

int main()
{
    int grade[4][3] = {
        {100, 86, 1},
        {85, 66, 2},
        {65, 51, 3},
        {50, 0, 4}
    };

    int arr_points[arr_size] = {0};
    int number_points = 0;
    int index = 0;  
    int err_scanf = 10;

    do {
        err_scanf = scanf("%d", &number_points);
        // printf("%d\n", err_scanf);
        if (err_scanf == 0) {
            arr_points[index] = -1;
            break;
        }
        arr_points[index] = number_points;
        index++;

    }
    while (number_points >= 0);

    index = 0;

    // for (int i = 0; i < arr_size; i++)
    //     printf("%i\n", arr_points[i]);

    do {
        number_points = arr_points[index];

        if (number_points <= grade[0][0] && number_points >= grade[0][1])
            printf("%d\n", grade[0][2]);
        else if ((number_points <= grade[1][0] && number_points >= grade[1][1]))
            printf("%d\n", grade[1][2]);
        else if ((number_points <= grade[2][0] && number_points >= grade[2][1]))
            printf("%d\n", grade[2][2]);
        else if ((number_points <= grade[3][0] && number_points >= grade[3][1]))
            printf("%d\n", grade[3][2]);
        else if (number_points > grade[0][0])
            printf("NA\n");
        
        index++;
    }
    while (number_points >= 0);


    return 0;
}

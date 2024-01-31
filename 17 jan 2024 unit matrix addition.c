#include <stdio.h>

int scan()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1 || value <= -1)
    {
        printf("Invalid input. Enter a positive integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    return value;
}

int scan2()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1 || (value > 3 || value < 0) )
    {
        printf("Invalid input. Enter a positive integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    return value;
}

int main()
{
    int matrix1[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int n, i, small_ele;

    printf("How many time you want to perform the unit matrix addition operation?\n");
    n = scan();
    int operation[n];

    printf("Enter the size of the operational matrix it can not be greater than 3\n");
    for (i = 0; i < n; i++)
    {
        printf("operation %d: ", i + 1);
        operation[i] = scan2();
    }

    for (i = 0; i < n; i++)
    {
        for (size_t row = 0; row < operation[i]; row++)
        {
            for (size_t column = 0; column < operation[i]; column++)
            {
                matrix1[row][column]++;
            }
        }
    }

    printf("Updated array is\n");
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
            printf("%d ", matrix1[i][j]);

        printf("\n");
    }

    small_ele = operation[0];
    for (i = 0; i <= n; i++)
    {
        small_ele = small_ele >= operation[i] ? operation[i] : small_ele;
    }

    printf("The highest number is %d and it's frequency is  %d ", n, small_ele * small_ele);

    return 0;
}

// 598
// hw - insertion sort

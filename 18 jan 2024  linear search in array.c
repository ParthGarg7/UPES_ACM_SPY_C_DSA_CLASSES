/*

sorting -

bubble
insertion
selection
quick
merge

searching -

linear
binary

*/

/*
linear search - unsorted array

time complexity - O(n)
space complexity - O(1)

traverse the array one by one element each time and also search the element at same time

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int size, choice, value, i;

    printf("How many elements you want to enter in the array\n");
    scanf("%d", &size);

    int array[size];

    printf("Enter 1 for auto generated array\n");
    printf("Enter 2 for manually entering element\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        srand(time(NULL));
        for (i = 0; i < size; i++)
            array[i] = rand() % 100;
    }
    break;

    case 2:
    {
        for (i = 0; i < size; i++)
        {
            printf("Enter element %d\n", i + 1);
            scanf("%d", &array[i]);
        }
    }
    break;

    default:
        printf("\nInvalid choice");
        break;

    }

    printf("Enter the element you want to enter\n");
    scanf("%d", &value);

    printf("\tThe array is\n\t");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);

    for (i = 0; i < size; i++)
    {
        if (value == array[i])
        {
            printf("\nElement found at location %d", i + 1);
            break;
        }
    }

    if (i == size)
    {
        printf("\nelement not found");
    }

    return 0;
}

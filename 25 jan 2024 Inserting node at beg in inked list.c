#include <stdio.h>
#include <stdlib.h>

// creation of structure of linked list
struct node
{
    int data;
    struct node *next;
} *head, *new_node, *temp;

// for taking a integer value as input
int scan()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Enter a valid integer\n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

// Inserting node at beg in linked list
int main()
{
    // declaring variables used in different section of code
    int value, count, counter;
    char choice;

    counter = 0;

    head = NULL;
    temp = head;

    printf("Hi this is a program of Insertion of node in the starting of the singly linked list\n\n");

    // infinite loop which will break when user wants
    while (1)
    {

        printf("There are currently %d node in the list\n", counter);

        // for printing the current status odf list
        printf("Here is the current list\n");
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        // Giving user choice to insert
        printf("\nDo you want to insert a node\n");
        printf("Enter y/Y for yes and n/N for no\n");

        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            // taking the data from user
            printf("Enter the data you want to enter in the node\n");
            value = scan();

            // allocating memory to the new node
            new_node = (struct node *)malloc(sizeof(struct node));

            // assigning values in the node
            new_node->data = value;
            new_node->next = NULL;

            counter++;

            printf("\n\nnode %d is created\n", counter);

            // if allocation is fail
            if (new_node == NULL)
            {
                printf("Memory is full Can't insert the node\n");
                return 1;
            }
            // Creation of 1st node
            else if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                temp = new_node;   // method 2
                temp->next = head; // new_node->next = head;
                head = temp;       // head = new_node;
            }
        }
        else
            break;
    }

    // for printing the linked list
    printf("This is the final list\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Free the allocated memory for each node
    temp = head;
    while (temp != NULL)
    {
        struct node *next_node = temp->next;
        free(temp);
        temp = next_node;
    }

    return 0;
}

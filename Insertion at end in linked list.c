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
        printf("Invalid input. Please enter a integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

// Program for insertion at end in the linked list
int main()
{
    // declaring variables used in different section of code
    int value, count, counter;
    char choice;

    counter = 0;

    head = NULL;
    temp = head;

    printf("Hi this is a program of Insertion of node in the ending of the linked list\n\n");

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
        printf("\nDo you want to insert a node?\n");
        printf("Press y or Y for yes and N or n for no\n");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y')
        {
            // taking the data from user
            printf("Enter the data you want to enter in the node\n");
            value = scan();

            //Allocating memory to the new node
            new_node = (struct node *)malloc(sizeof(struct node));

            // assigning values in the node
            new_node->data = value;
            new_node->next = NULL;

            counter++;

            printf("\n\nnode %d is created\n", counter);

            if (new_node == NULL)
            {
                printf("Memory is full can't insert\nThank you");
            }
            else if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                // Traverse to the end of the list
                temp = head;
                while (temp->next != NULL) // method 2
                    temp = temp->next;     // temp->next = newnode;
                                           // temp = newnode

                // Link the new node to the end of the list
                temp->next = new_node;
            }
        }
        else
            break;
    }

    // for printing the linked list
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

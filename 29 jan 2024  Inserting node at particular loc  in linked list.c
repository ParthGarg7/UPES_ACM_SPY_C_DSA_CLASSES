#include <stdio.h>
#include <stdlib.h>

// basic structure of a single linked list
struct node
{
    int data;
    struct node *next;
} *head, *new_node, *temp, *tnext;

// for getting positive integer as input
int scan()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid option enter a integer\n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

// for making sure the node number taken is valid
int node_number(int num)
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1 || value < 0 || value > num)
    {
        printf("Enter a valid node number\n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

int main()
{
    head = NULL;

    // declaring variables used in different section of code
    int value, count, counter;
    char choice;

    counter = 0;

    printf("Hi this is a program of Insertion of node after a particular node in the singly linked list\n\n");

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
        printf("\n\nDo you want to insert a node?\n");
        printf("press Y/y for yes\n");

        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            // allocating memory to new node
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->next = NULL;

            printf("Enter the value you want to insert\n");
            value = scan();

            // assigning data in new node
            new_node->data = value;
            counter++;

            printf("\n\nnode %d is created\n", counter);

            // if allocation is fail
            if (new_node == NULL)
            {
                printf("Memory is full\ncan not insert\n");
                return 1;
            }
            // creation of new node
            else if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            // joining the second node in list
            else if (head->next == NULL)
            {
                head->next = new_node;
            }
            else
            {
                printf("After which node you want to insert the new node\n");
                count = node_number(counter);

                temp = head;
                for (int i = 1; i < count; i++)
                    temp = temp->next;

                new_node->next = temp->next;
                temp->next = new_node;
            }
        }
        else
        {
            break;
        }
    }

    // printing the final list
    printf("\nThis is the final list\n");
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
        tnext = temp->next;
        free(temp);
        temp = tnext;
    }

    return 0;
}
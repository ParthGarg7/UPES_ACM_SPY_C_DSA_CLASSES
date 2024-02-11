/*

point 1 - linked list is a linear data structure
point 2 - it is of 3 type - singly , doubly , circular (doubly circular is also possible)
point 3 - 2 ways of creation - 1st - array  2nd - structure + pointers

structure of a singular inked list
struct node
{
   int data ;
   struct node* next;
}

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void approach1()
{
    // brut force approach for a linked list
    struct node head;
    struct node node1;
    struct node node2;
    struct node node3;
    struct node node4;
    struct node node5;

    // giving data and connecting nodes
    head.data = 0;
    head.next = &node1;

    node1.data = 1;
    node1.next = &node2;

    node2.data = 2;
    node2.next = &node3;

    node3.data = 3;
    node3.next = &node4;

    node4.data = 4;
    node4.next = &node5;

    node5.data = 5;
    node5.next = NULL;

    // a temp pointer to traverse through the list
    struct node *temp = &head;

    // for printing the data in the nodes
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int approach2()
{
    struct node *head, *one, *temp;
    head = (struct node *)malloc(sizeof(struct node));
    one = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->next = one;
    one->data = 10;
    one->next = NULL;
    temp = head; // for traversing data through nodes...
    for (int i = 0; i < 2; i++)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    free(head);
    free(one);

    struct node *head, *one, *temp;
}

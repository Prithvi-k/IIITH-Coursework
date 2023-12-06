#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void createLinkedList(Node **h)
{
    int data, choice;
    Node *newElement, *lastElement;

    do
    {
        printf("Enter Number: ");
        scanf("%d", &data);
        newElement = (Node *)malloc(sizeof(Node));
        newElement->data = data;
        newElement->next = NULL;
        if (*h == NULL)
        {
            *h = newElement;
        }
        else
        {
            lastElement->next = newElement;
        }
        lastElement = newElement;
        printf("Enter 1 to contiue, 0 otherwise");
        scanf("%d", &choice);
    } while (choice != 0);
}

void printLinkedList(Node *l)
{
    while (l != NULL)
    {
        if (l->next != NULL)
        {
            /* code */
            printf("%d => ", l->data);
        }
        else{
        printf("%d\n", l->data);
        }
        l = l->next;
    }
}

void findElementAtGivenIndex(int n, Node *l)
{
    int i = n;
    while (n > 0)
    {
        if (l->next == NULL)
        {
        printf("\nExceeded length!!\n");
        printf("Length of Linked List is only %d!\n", (i - n + 1));
        return;
        }

        l = l->next;
        n--;
    }
    printf("Data at index %d is %d\n", i, l->data);
    return;  
}

void findElement(int n, Node *l)
{
    int index = 0;
    while (l != NULL)
    {
        if (l->data == n)
        {
        printf("Element found at index %d\n", index);
        return;
        }
        index++;
        l = l->next;
    }
    printf("Element not in list!!\n");
}

void appendData(int n, Node *l)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = n;
    new->next = NULL;
    if (l == NULL)
    {
        l = new;
    }
    else
    {
        Node *i = l;
        while (i->next != NULL)
        {
        i = i->next;
        }
        i->next = new;
    }
    printf("Appended element!\n");
    printLinkedList(l);
}

int main()
{
   Node *head = NULL;
   
   createLinkedList(&head);
   printLinkedList(head);

   int index, find, append;
//    printf("Enter number to find: ");
//    scanf("%d", &tfind);
//    findElement(find, head);

//    printf("Enter index: ");
//    scanf("%d", &index);
//    findElementAtGivenIndex(index, head);

   printf("Enter element to append: ");
   scanf("%d", &append);
   appendData(append, head);
}
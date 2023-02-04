// Compile: gcc 23_linked_list_main.c
#include "23_linked_list.h"

LinkedList createEmptyLinkedList()
{
    return NULL;
}

// Append a new node to the end of the linked list
LinkedList append(Customer *c, LinkedList l)
{
    // Create a new node
    Node *n = (Node *)malloc(sizeof(struct Node));
    // Assign the customer to the node
    n->data = c;
    // Assign the next pointer to NULL
    n->next = NULL;

    Node *i = l;

    if (i == NULL) // We have this check because we are using the same function to append to the end of the linked list and to create a new linked listiiS
    {
        // If the linked list is empty, return the new node
        return n;
    }
    else
    {
        while (i->next != NULL)
        {
            // Traverse the linked list until the last node is found
            i = i->next;
        }
        // Assign the next pointer of the last node to the new node
        i->next = n;
        return l;
    }
}

void printLinkedList(LinkedList l)
{
    while (l != NULL)
    {
        printf("%s\t%d\n", l->data->name, l->data->phone_no);
        l = l->next;
    }
}

Customer *customerAtSpecificIndex(int i, LinkedList l)
{
    while (i > 0)
    {
        l = l->next;
        i--;
    }
    return l->data;
}

int main(int argc, char const *argv[])
{
    Customer *c = (Customer *)malloc(sizeof(Customer));
    c->phone_no = 123;
    strcpy(c->name, "Alice");

    LinkedList l = NULL;
    createEmptyLinkedList();
    l = append(c, l);

    c = (Customer *)malloc(sizeof(Customer));
    c->phone_no = 456;
    strcpy(c->name, "Bob");

    l = append(c, l);

    printLinkedList(l);
    printf("\n");
    int index = 1;
    c = customerAtSpecificIndex(index, l);
    printf("Customer at index %d:\n%s\t%d\n", index, c->name, c->phone_no);
    return 0;
}
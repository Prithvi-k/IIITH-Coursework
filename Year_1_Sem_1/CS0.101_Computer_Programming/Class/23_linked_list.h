#include "21a_srms_funcs.c"

typedef struct Node
{
    // Contains a pointer to a Customer
    Customer *data;
    // Contains a pointer to the next node
    struct Node *next;
} Node;

typedef Node *LinkedList;

LinkedList createEmptyLinkedList();

LinkedList append(Customer *c, LinkedList l);

void printLinkedList(LinkedList l);

Customer *customerAtSpecificIndex(int i, LinkedList l);
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    long long int data;
    struct node *next;
} node;

void attach_node_with_data(node *curr, long long int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    curr->next = new_node;
}

long long int get_product(node *head)
{
    long long int product = 1;
    node *curr = head;
    while (curr != NULL)
    {
        product *= curr->data;
        curr = curr->next;
    }
    return product;
}

long long int get_product_assembly(node *head);


int main()
{

    long long int vals[10] = {0};
    
    // taking input
    printf("Enter 10 values: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%lld", &vals[i]);
    }

    // creating a linked list with 10 nodes with data from vals
    node *head = (node *)malloc(sizeof(node));
    head->data = vals[0];
    head->next = NULL;
    node *curr = head;

    for (int i = 2; i <= 9; i++)
    {
        attach_node_with_data(curr, vals[i - 1]);
        curr = curr->next;
    }

    long long int garbage = 500;

    // attach the last node
    attach_node_with_data(curr, vals[9]);

    // print the relevant sizes
    // printf("Size of long long int: %lu\n", sizeof(long long int));
    // printf("Size of node pointer: %lu\n", sizeof(node *));
    // printf("Size of each node: %lu\n", sizeof(node));

    // use the get_product function to get the product of all the values in the linked list
    long long int product = product = get_product(head);
    printf("Product of all the values in the linked list: %lld\n", product);

    long long int product_assembly = get_product_assembly(head);
    printf("Product of all the values in the linked list (assembly code): %lld\n", product_assembly);
    
    // freeing the memory allocated to the linked list
    curr = head;
    while (curr != NULL)
    {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Customer
{
    char name[100];
    int phone_number;
} Customer;

typedef struct Receipt
{
    int customer_index;
    int item_count;
    int total_price;
    int payment_method;
} Receipt;

typedef struct Database
{
    Customer customers[100];
    Receipt receipts[1000];
    int customer_count;
    int receipt_count;
} Database;

int find_customer_by_phone_no(int phone_number, Database *db);

int add_customer(char *name, int mobile_number, Database *db);

Receipt *add_receipt(int customer, int item_count, int total_price, int payment_method, Database *db);

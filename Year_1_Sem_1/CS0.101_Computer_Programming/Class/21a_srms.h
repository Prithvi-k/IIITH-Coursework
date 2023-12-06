// Common header file for both read and write
// Helps us to avoid code duplication
// and also helps us to keep the code organized
// Changes in the header file will be reflected in both the files
/* Only keeps common structs/header files */
/* Doesn not keep functions -> in seperate .c file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef enum PayMode
{
    Cash,
    Card,
    UPI,
} PayMode;

// Defines a struct to take in customer data
typedef struct Customer
{
    char name[100]; // Customer name
    int phone_no;   // Phone number is an integer
} Customer;

typedef struct Item
{
    char name[100]; // Item name
    int price;      // Price of Item
    int quantity;   // Quantity of Item
} Item;

typedef struct Receipt
{
    time_t time;
    float value;
    int customer_index;
    PayMode mode;
    int payment_mode;
    int item_count;

} Receipt;

typedef struct Database
{
    Customer customers[100];
    Receipt receipts[1000];
    int customer_count;
    int receipt_count;
} Database;

int find_customer_by_phone_no(int phone, Database *db);

int add_customer(char *name, int phone_no, Database *db);

Receipt *add_receipt(int value, int number_of_items, PayMode payment_mode, int c, Database *db);

void total_revenue_on_a_particular_day(int day, int month, int year, Database *db);
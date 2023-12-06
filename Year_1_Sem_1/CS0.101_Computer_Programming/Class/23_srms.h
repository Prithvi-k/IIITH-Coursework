#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 150
#define MAX_CUSTOMERS 100
#define MAX_RECIEPTS 1000

typedef struct Customer
{
    char name[MAX_NAME_LEN];
    int phone_no;
} Customer;

typedef enum PayMode
{
    Cash = 0,
    Card = 1,
    UPI = 2
} PayMode;

typedef struct Reciept
{
    time_t time;
    float value;
    int customer_index;
    PayMode mode;
} Reciept;

typedef struct Database
{
    Customer customers[MAX_CUSTOMERS];
    Reciept reciepts[MAX_RECIEPTS];
    int customer_count;
    int reciept_count;
} Database;

int find_customer_by_phone_no(int phone, Database *db);

int add_customer(char *name, int phone_no, Database *db);

Reciept *add_reciept(int value, int c, PayMode mode, Database *db);
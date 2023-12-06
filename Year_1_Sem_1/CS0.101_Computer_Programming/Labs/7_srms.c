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


int find_customer_by_phone_no(int phone, Database *db)
{
    int cust = -1;
    for (int i = 0; i < db->customer_count; i++)
    {
        if (phone == db->customers[i].phone_no)
        {
            cust = i;
            break;
        }
    }
    return cust;
}

int add_customer(char *name, int phone_no, Database *db)
{
    Customer *c = &(db->customers[db->customer_count++]); // for pointer, we use `->` instead of `.` to access elements
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return ((db->customer_count) - 1);
}

Receipt *add_receipt(int value, int number_of_items, PayMode payment_mode, int c, Database *db)
{
    time_t now = time(NULL);
    Receipt *r = &(db->receipts[db->receipt_count++]);
    r->customer_index = c;
    r->value = value;
    r->time = now;
    r->payment_mode = payment_mode;
    r->item_count = number_of_items;
    return r;
}

void total_revenue_on_a_particular_day(int day, int month, int year, Database *db)
{
    int total_revenue = 0, count = 1;
    for (int i = 0; i < db->receipt_count; i++)
    {
        struct tm *time = localtime(&db->receipts[i].time);
        if (time->tm_mday == day && time->tm_mon == (month - 1) && time->tm_year == (year - 1900))
        {
            total_revenue += db->receipts[i].value;
            printf("%d. Customer Name: %s\t Receipt Value: %0.1f\n", count, db->customers[db->receipts[i].customer_index].name, db->receipts[i].value);
            count++;
        }
    }
    printf("Total Revenue on %d/%d/%d: %d\n", day, month, year, total_revenue);
}

int main()
{
    Database db;
    db.customer_count = db.receipt_count = 0;
    // int i = UPI;

    FILE *f_customers = fopen("customers.bin", "r");
    if (f_customers != NULL)
    {
        fread(&db.customer_count, sizeof(int), 1, f_customers);
        fread(db.customers, sizeof(Customer), db.customer_count, f_customers);
        fclose(f_customers);
    }

    FILE *f_reciepts = fopen("receipts.bin", "r");
    if (f_reciepts != NULL)
    {
        fread(&db.receipt_count, sizeof(int), 1, f_reciepts);
        fread(db.receipts, sizeof(Receipt), db.receipt_count, f_reciepts);
        fclose(f_reciepts);
    }

    while (true)
    {

        printf("-------------------------------------------------------------------\n"
               "Store receipt Management System\n"
               "-------------------------------------------------------------------\n"
               "\tOptions: 0 New Receipt | 1 New Customer | 2 Reciepts by Customer \n"
               "\tStats: %d Customers | %d Reciepts\n"
               "-------------------------------------------------------------------\n"
               "Enter Option: ",
               db.customer_count, db.receipt_count);

        int option;
        scanf("%d", &option);

        int p, v, m;
        Customer *c = NULL;
        char name[100];
        switch (option)
        {
        case 0:
            printf("Enter Customer Phone: ");
            scanf("%d", &p);
            c = find_customer_by_phone_no(p, &db);
            if (c == NULL)
            {
                printf("(New Customer) Name: ");
                scanf("%s", name);
                c = add_customer(name, p, &db);
            }
            printf("Payment Mode (0 for Cash, 1 for Card, 2 for UPI): ");
            scanf("%d", &m);
            printf("receipt Amount: ");
            scanf("%d", &v);
            add_reciept(v, c, m, &db);
            break;

        case 1:
            printf("Enter Customer Phone: ");
            scanf("%d", &p);
            c = find_customer_by_phone_no(p, &db);
            if (c == NULL)
            {
                printf("(New Customer) Name: ");
                scanf("%s", name);
                c = add_customer(name, p, &db);
            }
            break;

        case 2:
            // input a phone nom
            printf("Enter Customer Phone: ");
            scanf("%d", &p);
            c = find_customer_by_phone_no(p, &db);

            // print out all reicepts curresponding to that customer.
            printf("No.\tValue\n"
                   "--------------------------\n");
            for (int i = 0; i < db.receipt_count; i++)
            {

                if (db->customers[db.receipts[i].customer_index] == c)
                {
                    printf("%d\t%f\n", i, db.receipts[i].value);
                }
            }

            printf("----------------------\n");
            break;

        case 9:
            f_customers = fopen("customers.bin", "r");
            fwrite(&db.customer_count, sizeof(int), 1, f_customers);
            fwrite(db.customers, sizeof(Customer), db.customer_count, f_customers);
            fclose(f_customers);

            f_reciepts = fopen("receipts.bin", "r");
            fwrite(&db.receipt_count, sizeof(int), 1, f_reciepts);
            fwrite(db.receipts, sizeof(Receipt), db.receipt_count, f_reciepts);
            fclose(f_reciepts);
            return 0;

        default:
            break;
        }
    }

    return 0;




}
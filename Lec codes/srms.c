#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct Reciept
{
    time_t time;
    float value;
    Customer *customer;
    int payment_mode;
    PayMode mode;
} Reciept;

typedef struct Database
{
    Customer customers[100];
    Reciept reciepts[1000];
    int customer_count;
    int reciept_count;
} Database;

// Find a customer with `phone` as the phone number in database `db`
// If no such customer exists, returns NULL
Customer *find_customer_by_phone_no(int phone, Database *db)
{
    Customer *cust = NULL;
    for (int i = 0; i < db->customer_count; i++)
    {
        if (phone == db->customers[i].phone_no)
        {
            cust = &(db->customers[i]);
            break;
        }
    }
    return cust;
}

Customer *add_customer(char *name, int phone_no, /* PayMode mode ,*/ Database *db)
{
    Customer *c = &(db->customers[db->customer_count++]); // for pointer, we use `->` instead of `.` to access elements
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return c;
}

Reciept *add_reciept(int value, Customer *c, Database *db)
{
    time_t now = time(NULL);
    Reciept *r = &(db->reciepts[db->reciept_count++]);
    r->customer = c;
    r->value = value;
    r->time = now;
    return r;
}

int main()
{

    Database db;
    db.customer_count = db.reciept_count = 0;

    while (true)
    {

        // system("@cls||clear"); // clears the screen

        printf("-------------------------------------------------------------------\n"
               "Store Reciept Management System\n"
               "-------------------------------------------------------------------\n"
               "\tOptions: 0 New Receipt\n"
               "\t         1 New Customer\n"
               "\t         2 Receipts by Customer\n"
               "\t         3 Total Amount by Customer\n"
               "\t         4 Total Revenue on a particular day\n"
               "\tStats: %d Customers | %d Reciepts\n"
               "-------------------------------------------------------------------\n"
               "Enter Option: ",
               db.customer_count, db.reciept_count);

        int option;
        scanf("%d", &option);

        int p, v;
        char random;
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
            printf("Reciept Amount: ");
            scanf("%d", &v);
            add_reciept(v, c, &db);
            break;

        case 1:
            printf("Enter Customer Phone: ");
            scanf("%d", &p);
            if (c == NULL)
            {
                printf("(New Customer) Name: ");
                scanf("%s", name);
                c = add_customer(name, p, &db);
            }
            break;

        case 2:
            printf("Enter Customer Phone: ");
            scanf("%d", &p);
            c = find_customer_by_phone_no(p, &db);
            if (c == NULL)
            {
                printf("Customer not found\n");
            }
            else
            {
                printf("Reciepts for %s\n", c->name);
                for (int i = 0; i < db.reciept_count; i++)
                {
                    if (db.reciepts[i].customer == c)
                    {
                        printf("\t%d\t%0.1f\t%s\n", i, db.reciepts[i].value, c->name);
                    }
                }
            }
            scanf("%c", &random);
            break;

        case 3:
            int sum = 0;

            printf("Enter Customer Phone: ");
            scanf("%d", &p);
            c = find_customer_by_phone_no(p, &db);
            if (c == NULL)
            {
                printf("Customer not found\n");
            }
            else
            {
                printf("Reciepts for %s\n", c->name);
                for (int i = 0; i < db.reciept_count; i++)
                {
                    if (db.reciepts[i].customer == c)
                    {
                        sum += db.reciepts[i].value;
                    }
                }
                printf("Total Amount: %d\n", sum);
            }

        case 4:
            int sum1 = 0;
            printf("Enter Date: ");
            scanf("%d", &p);
            for (int i = 0; i < db.reciept_count; i++)
            {
                if (db.reciepts[i].time == p)
                {
                    sum1 += db.reciepts[i].value;
                }
            }
            printf("Total Amount: %d\n", sum1);
            break;

        default:
            break;
        }
    }

    return 0;
}
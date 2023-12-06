#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct Customer
{
    char name[100];
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
    Customer *customer;
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

Customer *add_customer(char *name, int phone_no, Database *db)
{
    Customer *c = &(db->customers[db->customer_count++]);
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return c;
}

Reciept *add_reciept(int value, Customer *c, PayMode mode, Database *db)
{
    time_t now = time(NULL);
    Reciept *r = &(db->reciepts[db->reciept_count++]);
    r->customer = c;
    r->value = value;
    r->time = now;
    r->mode = mode;
    return r;
}

int main(int argc, char const *argv[])
{

    Database db;
    db.customer_count = db.reciept_count = 0;
    // int i = UPI;

    FILE *f_customers = fopen(argv[1], "r");
    if (f_customers != NULL)
    {
        fread(&db.customer_count, sizeof(int), 1, f_customers);
        fread(db.customers, sizeof(Customer), db.customer_count, f_customers);
        fclose(f_customers);
    }

    FILE *f_reciepts = fopen(argv[2], "r");
    if (f_reciepts != NULL)
    {
        fread(&db.reciept_count, sizeof(int), 1, f_reciepts);
        fread(db.reciepts, sizeof(Reciept), db.reciept_count, f_reciepts);
        fclose(f_reciepts);
    }

    while (true)
    {

        printf("-------------------------------------------------------------------\n"
               "Store Reciept Management System\n"
               "-------------------------------------------------------------------\n"
               "\tOptions: 0 New Receipt | 1 New Customer | 2 Reciepts by Customer \n"
               "\tStats: %d Customers | %d Reciepts\n"
               "-------------------------------------------------------------------\n"
               "Enter Option: ",
               db.customer_count, db.reciept_count);

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
            printf("Reciept Amount: ");
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
            for (int i = 0; i < db.reciept_count; i++)
            {

                if (db.reciepts[i].customer == c)
                {
                    printf("%d\t%f\n", i, db.reciepts[i].value);
                }
            }

            printf("----------------------\n");
            break;

        case 9:
            f_customers = fopen(argv[1], "w");
            fwrite(&db.customer_count, sizeof(int), 1, f_customers);
            fwrite(db.customers, sizeof(Customer), db.customer_count, f_customers);
            fclose(f_customers);

            f_reciepts = fopen(argv[2], "w");
            fwrite(&db.reciept_count, sizeof(int), 1, f_reciepts);
            fwrite(db.reciepts, sizeof(Reciept), db.reciept_count, f_reciepts);
            fclose(f_reciepts);
            return 0;

        default:
            break;
        }
    }

    return 0;
}
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
    PayMode mode;
    int payment_mode;
    int item_count;
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
    Customer *c = &(db->customers[db->customer_count++]);
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return c;
}

Reciept *add_reciept(int value, int number_of_items, PayMode payment_mode, Customer *c, Database *db)
{
    time_t now = time(NULL);
    Reciept *r = &(db->reciepts[db->reciept_count++]);
    r->customer = c;
    r->value = value;
    r->time = now;
    r->payment_mode = payment_mode;
    r->item_count = number_of_items;
    return r;
}

void total_revenue_on_a_particular_day(int day, int month, int year, Database *db)
{
    int total_revenue = 0, count = 1;
    for (int i = 0; i < db->reciept_count; i++)
    {
        struct tm *time = localtime(&db->reciepts[i].time);
        if (time->tm_mday == day && time->tm_mon == (month - 1) && time->tm_year == (year - 1900))
        {
            total_revenue += db->reciepts[i].value;
            printf("%d. Customer Name: %s\t Receipt Value: %0.1f\n", count, db->reciepts[i].customer->name, db->reciepts[i].value);
            count++;
        }
    }
    printf("Total Revenue on %d/%d/%d: %d\n", day, month, year, total_revenue);
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

        int p, v, i, mode, day, month, year;
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
            printf("Mode of payment: ");
            scanf("%d", &mode);
            printf("Number of Items: ");
            scanf("%d", &i);
            add_reciept(v, i, mode, c, &db);
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
                char *modes[] = {"Cash", "Card", "UPI"};

                for (int i = 0; i < db.reciept_count; i++)
                {
                    if (db.reciepts[i].customer == c)
                    {
                        printf("\t%d. %0.1f\t%d\t%s\n", (i + 1), db.reciepts[i].value, db.reciepts[i].item_count, modes[db.reciepts[i].payment_mode]);
                    }
                    scanf("%c", &random);
                    break;
                }
            }
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
            break;

        case 4:
            int sum1 = 0;
            printf("Enter Date: ");
            scanf("%d/%d/%d", &day, &month, &year);
            total_revenue_on_a_particular_day(day, month, year, &db);
            break;

        default:
            break;
        }
    }

    return 0;
}
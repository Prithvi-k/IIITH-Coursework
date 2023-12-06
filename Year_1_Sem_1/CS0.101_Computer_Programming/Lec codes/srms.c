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
    Customer *customer;
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
    Customer *c = &(db->customers[db->customer_count++]); // for pointer, we use `->` instead of `.` to access elements
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return c;
}

Receipt *add_receipt(int value, int number_of_items, PayMode payment_mode, Customer *c, Database *db)
{
    time_t now = time(NULL);
    Receipt *r = &(db->receipts[db->receipt_count++]);
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
    for (int i = 0; i < db->receipt_count; i++)
    {
        struct tm *time = localtime(&db->receipts[i].time);
        if (time->tm_mday == day && time->tm_mon == (month - 1) && time->tm_year == (year - 1900))
        {
            total_revenue += db->receipts[i].value;
            printf("%d. Customer Name: %s\t Receipt Value: %0.1f\n", count, db->receipts[i].customer->name, db->receipts[i].value);
            count++;
        }
    }
    printf("Total Revenue on %d/%d/%d: %d\n", day, month, year, total_revenue);
}

int main()
{

    Database db;
    db.customer_count = db.receipt_count = 0;

    while (true)
    {

        // system("@cls||clear"); // clears the screen

        printf("-------------------------------------------------------------------\n"
               "Store Receipt Management System\n"
               "-------------------------------------------------------------------\n"
               "\tOptions: 0 New Receipt\n"
               "\t         1 New Customer\n"
               "\t         2 Receipts by Customer\n"
               "\t         3 Total Amount by Customer\n"
               "\t         4 Total Revenue on a Particular Day\n"
               "\tStats: %d Customers | %d Receipts\n"
               "-------------------------------------------------------------------\n"
               "Enter Option: ",
               db.customer_count, db.receipt_count);

        int option;
        scanf("%d", &option);

        int phone_number, receipt_value, i, mode, day, month, year;
        char random;
        Customer *c = NULL;
        char name[100];
        switch (option)
        {
        case 0:
            printf("Enter Customer Phone: ");
            scanf("%d", &phone_number);
            c = find_customer_by_phone_no(phone_number, &db);
            if (c == NULL)
            {
                printf("(New Customer) Name: ");
                scanf("%s", name);
                c = add_customer(name, phone_number, &db);
            }
            printf("Receipt Amount: ");
            scanf("%d", &receipt_value);
            printf("Mode of payment: ");
            scanf("%d", &mode);
            printf("Number of Items: ");
            scanf("%d", &i);
            add_receipt(receipt_value, i, mode, c, &db);
            break;

        case 1:
            printf("Enter Customer Phone: ");
            scanf("%d", &phone_number);
            if (c == NULL)
            {
                printf("(New Customer) Name: ");
                scanf("%s", name);
                c = add_customer(name, phone_number, &db);
            }
            break;

        case 2:
            printf("Enter Customer Phone: ");
            scanf("%d", &phone_number);
            c = find_customer_by_phone_no(phone_number, &db);
            if (c == NULL)
            {
                printf("Customer not found\n");
            }
            
            else
            {
                printf("Receipts for %s\n", c->name);
                char *modes[] = {"Cash", "Card", "UPI"};

                printf("Serial No. Value\tItems\tMode\tCustomer\n");
                for (int i = 0; i < db.receipt_count; i++)
                {
                    if (db.receipts[i].customer == c)
                    {
                        if (db.receipts[i].payment_mode == 0)
                        {
                            printf("\t%d. %0.1f\t%d\t%s\t%s\n", (i + 1), db.receipts[i].value, db.receipts[i].item_count, modes[db.receipts[i].payment_mode], c->name);
                        }
                        else if (db.receipts[i].payment_mode == 1)
                        {
                            printf("\t%d. %0.1f\t%d\t%s\t%s\n", (i + 1), db.receipts[i].value, db.receipts[i].item_count, modes[db.receipts[i].payment_mode], c->name);
                        }
                        else if (db.receipts[i].payment_mode == 2)
                        {
                            printf("\t%d. %0.1f\t%d\t%s\t%s\n", (i + 1), db.receipts[i].value, db.receipts[i].item_count, modes[db.receipts[i].payment_mode], c->name);
                        }
                    }
                }
                scanf("%c", &random);
                break;
            }
        case 3:
            int sum = 0;

            printf("Enter Customer Phone: ");
            scanf("%d", &phone_number);
            c = find_customer_by_phone_no(phone_number, &db);
            if (c == NULL)
            {
                printf("Customer not found\n");
            }
            else
            {
                printf("Receipts for %s\n", c->name);
                for (int i = 0; i < db.receipt_count; i++)
                {
                    if (db.receipts[i].customer == c)
                    {
                        sum += db.receipts[i].value;
                    }
                }
                printf("Total Amount: %d\n", sum);
            }

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

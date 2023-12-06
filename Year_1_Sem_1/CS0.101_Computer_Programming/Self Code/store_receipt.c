#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Customer
{
    char name[100];
    int phone_number;
} Customer;

/* typedef struct Payment_Method
{
    Cash = 0;
    Card;
    UPI;
} Payment_Method; */

typedef struct Receipt
{
    Customer *customer;
    int item_count;
    int total_price;
    // Payment_Method mode;
    int payment_method;
} Receipt;

typedef struct Database
{
    Customer customers[100];
    Receipt receipts[1000];
    int customer_count;
    int receipt_count;
} Database;

Customer *find_customer_by_phone_no(int phone_number, Database *db)
{
    Customer *cust = NULL;
    for (int i = 0; i < db->customer_count; i++)
    {
        if (phone_number == db->customers[i].phone_number)
        {
            cust = &(db->customers[i]);
            break;
        }
    }
    return cust;
}

Customer *add_customer(char *name, int mobile_number, Database *db)
{
    Customer *cust = &(db->customers[db->customer_count]);
    strcpy(cust->name, name);
    cust->phone_number = mobile_number;
    db->customer_count++;
    return cust;
}

Receipt *add_receipt(Customer *customer, int item_count, int total_price, int payment_method, Database *db)
{
    Receipt *receipt = &(db->receipts[db->receipt_count]);
    receipt->customer = customer;
    receipt->item_count = item_count;
    receipt->total_price = total_price;
    receipt->payment_method = payment_method;
    db->receipt_count++;
    return receipt;
}

int main()
{
    Database db;
    db.customer_count = 0;
    db.receipt_count = 0;

    while (true)
    {
        printf("-------------------------------------------------------\n"
               "Store Receipt Manager System\n"
               "-------------------------------------------------------\n"
               "Stats:\n"
               "Customers: %d\tReceipts: %d\n"
               "1. Add Customer\n"
               "2. Add Receipt\n"
               "3. Print Customer Details\n"
               "4. Print Receipts by Customer\n"
               "5. Print Receipts by Payment Method\n"
               "-------------------------------------------------------\n"
               "Select an option: ",
               db.customer_count, db.receipt_count);

        int option;
        scanf("%d", &option);

        Customer *c = NULL;

        switch (option)
        {
        case 1:
            printf("Enter Customer Name: ");
            char name[100];
            scanf("%s", name);
            printf("Enter Customer Phone Number: ");
            int phone_number;
            scanf("%d", &phone_number);
            c = add_customer(name, phone_number, &db);
            break;

        case 2:
            printf("Enter Customer Phone Number: ");
            scanf("%d", &phone_number);
            c = find_customer_by_phone_no(phone_number, &db);
            if (c == NULL)
            {
                printf("Enter Customer Name: ");
                scanf("%s", name);
                c = add_customer(name, phone_number, &db);
            }
            printf("Enter Receipt Value: ");
            int receipt_value;
            scanf("%d", &receipt_value);
            printf("Enter Payment Method: \n"
                   "1. Cash\n"
                   "2. Card\n"
                   "3. UPI\n");
            int payment_method;
            scanf("%d", &payment_method);
            printf("Enter Number of Items: ");
            int item_count;
            scanf("%d", &item_count);
            add_receipt(c, item_count, receipt_value, (payment_method - 1), &db);
            break;

        case 3:
            printf("Enter Customer Phone Number: ");
            scanf("%d", &phone_number);
            c = find_customer_by_phone_no(phone_number, &db);
            if (c == NULL)
            {
                printf("Customer not found!\n");
            }
            else
            {
                printf("Customer Name: %s\n", c->name);
                printf("Customer Phone Number: %d\n", c->phone_number);
            }
            break;

        case 4:
            printf("Enter Customer Phone Number: ");
            scanf("%d", &phone_number);
            c = find_customer_by_phone_no(phone_number, &db);
            if (c == NULL)
            {
                printf("Customer not found!\n");
            }
            else
            {
                char *payment_modes[] = {"Cash", "Card", "UPI"};
                printf("Receipts for %s:\n", c->name);
                printf("No. Items\tTotal Price\tPayment Method\n");
                for (int i = 0; i < db.receipt_count; i++)
                {
                    if (db.receipts[i].customer == c)
                    {
                        if (db.receipts[i].payment_method == 0)
                        {
                            printf("%d.     %d\t        %d\t           %s\n", i, db.receipts[i].item_count, db.receipts[i].total_price, payment_modes[db.receipts[i].payment_method]);
                        }
                        else if (db.receipts[i].payment_method == 1)
                        {
                            printf("%d.     %d\t        %d\t           %s\n", i, db.receipts[i].item_count, db.receipts[i].total_price, payment_modes[db.receipts[i].payment_method]);
                        }
                        else if (db.receipts[i].payment_method == 2)
                        {
                            printf("%d.     %d\t        %d\t           %s\n", i, db.receipts[i].item_count, db.receipts[i].total_price, payment_modes[db.receipts[i].payment_method]);
                        }
                    }
                }
            }
            break;

        case 5:
            printf("Enter Payment Method: \n"
                   "1. Cash\n"
                   "2. Card\n"
                   "3. UPI\n");
            scanf("%d", &payment_method);
            char *payment_modes[] = {"Cash", "Card", "UPI"};
            int total_items = 0, total_value = 0;
            printf("Receipts for %s:\n", payment_modes[(payment_method - 1)]);
            printf("No. of Items\tTotal Price\tPayment Method\n");
            for (int i = 0; i < db.receipt_count; i++)
            {
                if (db.receipts[i].payment_method == (payment_method - 1))
                {
                    total_items += db.receipts[i].item_count;
                    total_value += db.receipts[i].total_price;
                }
            }
            printf("          %d\t        %d\t          %s\n", total_items, total_value, payment_modes[(payment_method - 1)]);
            break;

        default:
            break;
        }
    }
    return 0;
}
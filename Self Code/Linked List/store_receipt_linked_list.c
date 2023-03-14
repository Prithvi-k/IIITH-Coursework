#include "store_receipt.h"

int main(int argc, const char *argv[])
{
    Database db;
    db.customer_count = 0;
    db.receipt_count = 0;

    FILE *customer_file_read, *receipt_file_read;

    if (customer_file_read != NULL)
    {
    customer_file_read = fopen("customers.bin", "r");
    fread(&(db.customer_count), sizeof(int), 1, customer_file_read);
    fread(db.customers, sizeof(Customer), db.customer_count, customer_file_read);
    fclose(customer_file_read);
    }

    if (receipt_file_read != NULL)
    {
    receipt_file_read = fopen("receipts.bin", "r");
    fread(&(db.receipt_count), sizeof(int), 1, receipt_file_read);
    fread(db.receipts, sizeof(Receipt), db.receipt_count, receipt_file_read);
    fclose(receipt_file_read);
    }

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
               "9. Save Data to file\n"
               "-------------------------------------------------------\n"
               "Select an option: ",
               db.customer_count, db.receipt_count);

        int option;
        scanf("%d", &option);

        int customer = 0;

        switch (option)
        {
        case 1:
            printf("Enter Customer Name: ");
            char name[100];
            scanf("%s", name);
            printf("Enter Customer Phone Number: ");
            int phone_number;
            scanf("%d", &phone_number);
            customer = add_customer(name, phone_number, &db);
            break;

        case 2:
            printf("Enter Customer Phone Number: ");
            scanf("%d", &phone_number);
            customer = find_customer_by_phone_no(phone_number, &db);
            if (customer == -1)
            {
                printf("Enter (New) Customer Name: ");
                scanf("%s", name);
                customer = add_customer(name, phone_number, &db);
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
            add_receipt(customer, item_count, receipt_value, (payment_method - 1), &db);
            break;

        case 3:
            printf("Enter Customer Phone Number: ");
            scanf("%d", &phone_number);
            customer = find_customer_by_phone_no(phone_number, &db);
            if (customer == -1)
            {
                printf("Customer not found!\n");
            }
            else
            {
                printf("Customer Name: %s\n", db.customers[customer].name);
                printf("Customer Phone Number: %d\n", db.customers[customer].phone_number);
            }
            break;

        case 4:
            printf("Enter Customer Phone Number: ");
            scanf("%d", &phone_number);
            customer = find_customer_by_phone_no(phone_number, &db);
            if (customer == -1)
            {
                printf("Customer not found!\n");
            }
            else
            {
                char *payment_modes[] = {"Cash", "Card", "UPI"};
                printf("Receipts for %s:\n", db.customers[customer].name);
                printf("No. Items\tTotal Price\tPayment Method\n");
                for (int i = 0; i < db.receipt_count; i++)
                {
                    if (db.receipts[i].customer_index == customer)
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
        
        case 9:
            FILE *customer_file, *receipt_file;

            customer_file = fopen("customers.bin", "w");
            receipt_file = fopen("receipts.bin", "w");

            fwrite(&(db.customer_count), sizeof(int), 1, customer_file);
            fwrite(db.customers, sizeof(Customer), db.customer_count, customer_file);

            fwrite(&(db.receipt_count), sizeof(int), 1, receipt_file);
            fwrite(db.receipts, sizeof(Receipt), db.receipt_count, receipt_file);

            fclose(customer_file);
            fclose(receipt_file);
            return 0;

        default:
            break;
        }
    }
    return 0;
}
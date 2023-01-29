#include "21_srms_file.h"

int find_customer_by_phone_no(int phone_no, Database *db)
{
    int cust = -1;
    for (int i = 0; i < db->customer_count; i++)
    {
        if (phone_no == db->customers[i].phone_no)
        {
            cust = &(db->customers[i]);
            break;
        }
    }
    return cust;
}

int add_customer(char *name, int mobile_number, Database *db)
{
    Customer *cust = &(db->customers[db->customer_count]);
    strcpy(cust->name, name);
    cust->phone_no = mobile_number;
    db->customer_count++;
    return db->customer_count - 1;
}

Receipt *add_receipt(int customer_index, int item_count, int value, int payment_mode, Database *db)
{
    Receipt *receipt = &(db->receipts[db->receipt_count]);
    receipt->customer_index = customer_index;
    receipt->item_count = item_count;
    receipt->value = value;
    receipt->payment_mode = payment_mode;
    db->receipt_count++;
    return receipt;
}

int main()
{
    Database db;
    db.customer_count = 0;
    db.receipt_count = 0;

    // Load database db from file srms.txt
    FILE *srms_customer_file_read;
    srms_customer_file_read = fopen("/home/prithvi/Documents/CPro/Class/srms_customer_file.bin", "r");
    FILE *srms_receipt_file_read;
    srms_receipt_file_read = fopen("/home/prithvi/Documents/CPro/Class/srms_receipt_file.bin", "r");

    fread(&db.customer_count, sizeof(int), 1, srms_customer_file_read);
    fread(db.customers, sizeof(Customer), db.customer_count, srms_customer_file_read);

    fread(&db.receipt_count, sizeof(int), 1, srms_receipt_file_read);
    fread(db.receipts, sizeof(Receipt), db.receipt_count, srms_receipt_file_read);

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

        int c = -1;

        switch (option)
        {
        case 1:
            printf("Enter Customer Name: ");
            char name[100];
            scanf("%s", name);
            printf("Enter Customer Phone Number: ");
            int phone_no;
            scanf("%d", &phone_no);
            c = add_customer(name, phone_no, &db);
            break;

        case 2:
            printf("Enter Customer Phone Number: ");
            scanf("%d", &phone_no);
            c = find_customer_by_phone_no(phone_no, &db);
            if (c == NULL)
            {
                printf("Enter Customer Name: ");
                scanf("%s", name);
                c = add_customer(name, phone_no, &db);
            }
            printf("Enter Receipt Value: ");
            int receipt_value;
            scanf("%d", &receipt_value);
            printf("Enter Payment Method: \n"
                   "1. Cash\n"
                   "2. Card\n"
                   "3. UPI\n");
            int payment_mode;
            scanf("%d", &payment_mode);
            printf("Enter Number of Items: ");
            int item_count;
            scanf("%d", &item_count);
            add_receipt(c, item_count, receipt_value, (payment_mode - 1), &db);
            break;

        case 3:
            printf("Enter Customer Phone Number: ");
            scanf("%d", &phone_no);
            c = find_customer_by_phone_no(phone_no, &db);
            if (c == NULL)
            {
                printf("Customer not found!\n");
            }
            else
            {
                printf("Customer Name: %s\n", c->name);
                printf("Customer Phone Number: %d\n", c->phone_no);
            }
            break;

        case 4:
            printf("Enter Customer Phone Number: ");
            scanf("%d", &phone_no);
            c = find_customer_by_phone_no(phone_no, &db);
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
                    if (db.customers[db.receipts[i].customer_index].name == c)
                    {
                        if (db.receipts[i].payment_mode == 0)
                        {
                            printf("%d.     %d\t        %d\t           %s\n", i, db.receipts[i].item_count, db.receipts[i].value, payment_modes[db.receipts[i].payment_mode]);
                        }
                        else if (db.receipts[i].payment_mode == 1)
                        {
                            printf("%d.     %d\t        %d\t           %s\n", i, db.receipts[i].item_count, db.receipts[i].value, payment_modes[db.receipts[i].payment_mode]);
                        }
                        else if (db.receipts[i].payment_mode == 2)
                        {
                            printf("%d.     %d\t        %d\t           %s\n", i, db.receipts[i].item_count, db.receipts[i].value, payment_modes[db.receipts[i].payment_mode]);
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
            scanf("%d", &payment_mode);
            char *payment_modes[] = {"Cash", "Card", "UPI"};
            int total_items = 0, total_value = 0;
            printf("Receipts for %s:\n", payment_modes[(payment_mode - 1)]);
            printf("No. of Items\tTotal Price\tPayment Method\n");
            for (int i = 0; i < db.receipt_count; i++)
            {
                if (db.receipts[i].payment_mode == (payment_mode - 1))
                {
                    total_items += db.receipts[i].item_count;
                    total_value += db.receipts[i].value;
                }
            }
            printf("          %d\t        %d\t          %s\n", total_items, total_value, payment_modes[(payment_mode - 1)]);
            break;

        case 9:

            // Save database db to file srms.txt

            FILE *srms_customer_file = fopen("/home/prithvi/Documents/CPro/Class/srms_customer_file.bin", "w");
            FILE *srms_receipt_file = fopen("/home/prithvi/Documents/CPro/Class/srms_receipt_file.bin", "w");

            fwrite(&db.customer_count, sizeof(int), 1, srms_customer_file);
            fwrite(db.customers, sizeof(Customer), db.customer_count, srms_customer_file);

            fwrite(&db.receipt_count, sizeof(int), 1, srms_receipt_file);
            fwrite(db.receipts, sizeof(Receipt), db.receipt_count, srms_receipt_file);

            printf("Database saved to file!\n");

            fclose(srms_customer_file);
            fclose(srms_receipt_file);
            break;

        default:
            break;
        }
    }
    return 0;
}
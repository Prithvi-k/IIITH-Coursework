#include "srms.h"

int main(int argc, char const *argv[])
{

    // printf("argc value is %d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("argv[%d] value is %s\n", i, argv[i]);
    // }

    Database db;
    db.customer_count = db.reciept_count = 0;

    // Problem 1
    // Read from argv[1] and argv[2] and populate the database db

    FILE *f_customers = fopen(argv[1], "r");

    if (f_customers != NULL)
    {
        fread(&(db.customer_count), sizeof(int), 1, f_customers);
        fread(db.customers, sizeof(Customer), db.customer_count, f_customers);
        fclose(f_customers);
    }

    // printf("read customers\n");

    FILE *f_reciepts = fopen(argv[2], "r");
    if (f_reciepts != NULL)
    {
        fread(&(db.reciept_count), sizeof(int), 1, f_reciepts);
        fread(db.reciepts, sizeof(Reciept), db.reciept_count, f_reciepts);

        fclose(f_reciepts);
    }

    while (true)
    {

        // system("@cls||clear"); // clears the screen

        printf("-------------------------------------------------------------------\n"
               "Store Reciept Management System\n"
               "-------------------------------------------------------------------\n"
               "\tOptions: 0 New Receipt | 1 New Customer | 2 Reciepts by Customer | 9 Save and Exit \n"
               "\tStats: %d Customers | %d Reciepts\n"
               "-------------------------------------------------------------------\n"
               "Enter Option: ",
               db.customer_count, db.reciept_count);

        int option;
        scanf("%d", &option);

        int p, v, m;
        int c = -1;
        char name[MAX_NAME_LEN];
        switch (option)
        {
        case 0:
            printf("Enter Customer Phone: ");
            scanf("%d", &p);
            c = find_customer_by_phone_no(p, &db);
            if (c == -1)
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
            if (c == -1)
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

                if (db.reciepts[i].customer_index == c)
                {
                    printf("%d\t%f\n", i, db.reciepts[i].value);
                }
            }

            printf("----------------------\n");

        case 9:

            // Problem 2
            // write code for save and exit
            // writes the dbase of customers and reciepts to
            // customers.bin and reciepts.bin

            FILE *f_customers = fopen(argv[1], "w");
            fwrite(&(db.customer_count), sizeof(int), 1, f_customers);
            fwrite(db.customers, sizeof(Customer), db.customer_count, f_customers);
            fclose(f_customers);

            FILE *f_reciepts = fopen(argv[2], "w");
            fwrite(&(db.reciept_count), sizeof(int), 1, f_reciepts);
            fwrite(db.reciepts, sizeof(Reciept), db.reciept_count, f_reciepts);
            fclose(f_reciepts);
            return 0;

        default:
            break;
        }
    }

    return 0;
}
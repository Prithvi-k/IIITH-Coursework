// Compile with 21_srms.c
#include "21_srms.h"

int main()
{

    Database db;
    db.customer_count = db.receipt_count = 0;

    int a = add_customer("Alice", 12345, &db);

    add_receipt(500, 4, Card, a, &db);
    add_receipt(200, 1, UPI, a, &db);
    add_receipt(150, 2, Cash, a, &db);

    int b = add_customer("Tom", 2468, &db);

    add_receipt(300, 3, UPI, b, &db);
    add_receipt(230, 5, UPI, b, &db);
    add_receipt(150, 2, Cash, b, &db);

    FILE *customer_file = fopen("/home/prithvi/Documents/CPro/Class/customers.bin", "w");
    FILE *receipt_file = fopen("/home/prithvi/Documents/CPro/Class/receipts.bin", "w");

    // fwrite takes in a pointer to the data, size of each element,
    // number of elements, and the file pointer
    // fwrite enters data in binary format
    // fwrite stores data in the same format as it is stored in memory

    // To store data of one single customer
    /* fwrite(a, sizeof(Customer), 1, customer_file); */

    // First, we need to write customer count
    // Helps us to read the data back
    fwrite(&db.customer_count, sizeof(int), 1, customer_file);

    // To store data of all customers
    fwrite(db.customers, sizeof(Customer), db.customer_count, customer_file);

    // To store data of receipt count
    fwrite(&db.receipt_count, sizeof(int), 1, receipt_file);

    // To store data of all receipts
    fwrite(db.receipts, sizeof(Receipt), db.receipt_count, receipt_file);

    // Close/Save the file
    fclose(customer_file);

    return 0;
}
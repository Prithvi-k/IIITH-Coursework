#include "21_srms.h"

int main()
{

    Database db;
    db.customer_count = db.receipt_count = 0;

    FILE *customer_file = fopen("/home/prithvi/Documents/CPro/Class/customers.bin", "r");
    FILE *receipt_file = fopen("/home/prithvi/Documents/CPro/Class/receipts.bin", "r");

    // Read the number of customers (needed to find the size of the array)
    fread(&db.customer_count, sizeof(int), 1, customer_file);

    // Read the customers
    fread(db.customers, sizeof(Customer), db.customer_count, customer_file);

    // Read the number of receipts (needed to find the size of the array)
    fread(&db.receipt_count, sizeof(int), 1, receipt_file);

    // Read the receipts
    fread(db.receipts, sizeof(Receipt), db.receipt_count, receipt_file);

    // Print the customers
    for (int i = 0; i < db.customer_count; i++)
    {
        printf("Customer %d:\nName:         %s,\nPhone Number: %d\n", i + 1, db.customers[i].name, db.customers[i].phone_no);
    }

    // Print all the receipts
    /* for (int i = 0; i < db.receipt_count; i++)
    {
        printf("\nReceipt %d:\nValue:    %0.1f,\nTime:     %sPayment Mode: %d\n", i + 1, db.receipts[i].value, ctime(&db.receipts[i].time), db.receipts[i].payment_mode);
    } */

    // Print recepts with customer name (Problem with using pointers)
    /* for (int i = 0; i < db.receipt_count; i++)
    {
        printf("\nReceipt %d:\nCustomer Name: %s\nValue:    %0.1f,\nTime:     %sPayment Mode: %d\n", i + 1, db.receipts[i].customer->name, db.receipts[i].value, ctime(&db.receipts[i].time), db.receipts[i].payment_mode);
    } */
    // Segmentation Fault (Problem with using pointers)
    // In the write function, we are writing the address of the customer in the
    // receipt
    //
    // But in the read function, we are reading the customer data into the
    // customer array which stores the customer data in a different address
    //
    // The address of the customer in the receipt is not the same as the
    // address of the customer as in the previous program
    //
    // So, we get a segfault

    // Print receipts with customer name (Correct way)
    for (int i = 0; i < db.receipt_count; i++)
    {
        printf("\nReceipt %d:\nCustomer Name: %s\nValue:    %0.1f,\nTime:     %sPayment Mode: %d\n", i + 1, db.customers[db.receipts[i].customer_index].name, db.receipts[i].value, ctime(&db.receipts[i].time), db.receipts[i].payment_mode);
    }

    fclose(customer_file);

    return 0;
}
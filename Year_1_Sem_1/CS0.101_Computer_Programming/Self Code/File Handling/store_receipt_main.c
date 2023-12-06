#include "store_receipt.h"

int find_customer_by_phone_no(int phone_number, Database *db)
{
    int customer = -1;
    for (int i = 0; i < db->customer_count; i++)
    {
        if (phone_number == db->customers[i].phone_number)
        {
            customer = i;
            break;
        }
    }
    return customer;
}

int add_customer(char *name, int mobile_number, Database *db)
{
    Customer *cust = &(db->customers[db->customer_count++]);
    strcpy(cust->name, name);
    cust->phone_number = mobile_number;
    return ((db->customer_count) - 1);
}

Receipt *add_receipt(int customer, int item_count, int total_price, int payment_method, Database *db)
{
    Receipt *receipt = &(db->receipts[db->receipt_count]);
    receipt->customer_index = customer;
    receipt->item_count = item_count;
    receipt->total_price = total_price;
    receipt->payment_method = payment_method;
    db->receipt_count++;
    return receipt;
}
// Seperate file for functions
// Needs to be compiled with 21_srms_data_write.c (at the same time)
// (or any other file that uses these functions)

#include "21_srms.h"

int find_customer_by_phone_no(int phone, Database *db)
{
    int cust = -1;
    for (int i = 0; i < db->customer_count; i++)
    {
        if (phone == db->customers[i].phone_no)
        {
            cust = db->receipts;
            break;
        }
    }
    return cust;
}

int add_customer(char *name, int phone_no, Database *db)
{
    Customer *c = &(db->customers[db->customer_count++]); // for pointer, we use `->` instead of `.` to access elements
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return ((db->customer_count) - 1);
}

Receipt *add_receipt(int value, int number_of_items, PayMode payment_mode, int c, Database *db)
{
    time_t now = time(NULL);
    Receipt *r = &(db->receipts[db->receipt_count++]);
    r->customer_index = c;
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
            printf("%d. Customer Name: %s\t Receipt Value: %0.1f\n", count, db->customers[db->receipts[i].customer_index].name, db->receipts[i].value);
            count++;
        }
    }
    printf("Total Revenue on %d/%d/%d: %d\n", day, month, year, total_revenue);
}
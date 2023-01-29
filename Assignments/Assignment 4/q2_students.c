#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_HOSTEL_ADDRESS_LENGTH 50

typedef enum Age
{
    Age_17 = 17,
    Age_18,
    Age_19,
    Age_20,
    Age_21,
    Age_22
} Age;

typedef struct Student
{
    char name[MAX_NAME_LENGTH];
    Age age;
    int roll_no;
    char email[MAX_EMAIL_LENGTH];
    char hostel_address[MAX_HOSTEL_ADDRESS_LENGTH];
} Student;

void add_student(Student students[], int n, char name[], Age age, int roll_no, char email[], char hostel_address[])
{
    strcpy(students[n].name, name);
    students[n].age = age;
    students[n].roll_no = roll_no;
    strcpy(students[n].email, email);
    strcpy(students[n].hostel_address, hostel_address);
}

void print_students_with_age_19(Student students[], int n)
{
    int flag = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i].age == Age_19)
        {
            if (flag == 0)
            {
                flag++;
                printf("Students of age 19 are: \n");
            }
            count++;
            printf("%d. %s\n", count, students[i].name);
        }
    }
    if (flag == 0)
    {
        printf("No students are of age 19.\n");
    }
}

void print_students_with_email_starting_with_I_or_T(Student students[], int n)
{
    int flag = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i].email[0] == 'I' || students[i].email[0] == 'i' || students[i].email[0] == 'T' || students[i].email[0] == 't')
        {
            if (flag == 0)
            {
                flag++;
                printf("Students with email starting with I or T are: \n");
            }
            count++;
            printf("%d. %s\n", count, students[i].name);
            printf("   Email: %s\n", students[i].email);
        }
    }
    if (flag == 0)
    {
        printf("No students with email starting with I or T are found.\n");
    }
}

void student_email_available(Student students[], int n)
{
    int flag = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(students[i].email, "-") != 0)
        {
            if (flag == 0)
            {
                flag++;
                printf("Students with email are: \n");
            }
            count++;
            printf("%d. Name = %s,\n", count, students[i].name);
            printf("   Age = %d,\n", students[i].age);
            printf("   Roll No. = %d,\n", students[i].roll_no);
            printf("   Email = %s,\n", students[i].email);
            printf("   Hostel Address = %s\n", students[i].hostel_address);
        }
    }
    if (flag == 0)
    {
        printf("No students with email are found.\n");
    }
}

int main()
{
    Student students[MAX_STUDENTS];
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char name[50], email[50], hostel_address[50];
        int roll_no, age;
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", name);
        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &age);
        printf("Enter the roll no. of student %d: ", i + 1);
        scanf("%d", &roll_no);
        printf("Enter the email of student %d: ", i + 1);
        scanf("%s", email); // enter "-" if email is not available
        printf("Enter the hostel address of student %d: ", i + 1);
        scanf("%s", hostel_address);
        add_student(students, i, name, age, roll_no, email, hostel_address);
    }

    printf("\n");
    print_students_with_age_19(students, n);
    printf("\n");
    print_students_with_email_starting_with_I_or_T(students, n);
    printf("\n");
    student_email_available(students, n);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char email[100];
    int roll_no;
    int marks[3];
} student;

int main()
{
    FILE *student_file;
    student_file = fopen("Assignments/Assignment 4/students.bin", "r");
    if (student_file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    int n;

    fread(&n, sizeof(int), 1, student_file);
    student *students = (student *)malloc(n * sizeof(student));
    fread(students, sizeof(student), n, student_file);

    for (int i = 0; i < n; i++)
    {
        printf("Email: %s\nRoll Number: %d\nAssignment 1: %d\nAssignment 2: %d\nAssignment 3: %d\n", students[i].email, students[i].roll_no, students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("\n");
    }

    return 0;
}
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
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    student *students = (student *)malloc(n * sizeof(student));

    for (int i = 0; i < n; i++)
    {
        printf("Enter email of student %d: ", i + 1);
        scanf("%s", students[i].email);
        printf("Enter roll number of student %d: ", i + 1);
        scanf("%d", &students[i].roll_no);
        printf("Enter Assignment 1 marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks[0]);
        printf("Enter Assignment 2 marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks[1]);
        printf("Enter Assignment 3 marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks[2]);
    }

    FILE *student_file;
    student_file = fopen("Assignments/Assignment 4/students.bin", "w");
    if (student_file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fwrite(&n, sizeof(int), 1, student_file);
    fwrite(students, sizeof(student), n, student_file);

    fclose(student_file);

    return 0;
}
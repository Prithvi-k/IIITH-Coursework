#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define NUMBER_OF_ASSIGNMENTS 3
#define FILE_NAME "students.bin"

typedef struct student
{
    char email[MAX_EMAIL_LENGTH];
    int roll_no;
    int marks[NUMBER_OF_ASSIGNMENTS];
} student;

int main()
{
    FILE *student_file;
    student_file = fopen(FILE_NAME, "r");

    if (student_file == NULL)
    {
        printf("No previously saved student data!\n");
        printf("Creating new students.bin file");
    }
    else
    {
        int num, choice;
        fread(&num, sizeof(int), 1, student_file);
        student *student_list = (student *)malloc(num * sizeof(student));
        fread(student_list, sizeof(student), num, student_file);
        for (int i = 0; i < num; i++)
        {
            printf("Email: %s\nRoll Number: %d\nAssignment 1: %d\nAssignment 2: %d\nAssignment 3: %d\n", student_list[i].email, student_list[i].roll_no, student_list[i].marks[0], student_list[i].marks[1], student_list[i].marks[2]);
            printf("\n");
        }
        printf("Enter 0 to write new data\nEnter 1 to exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Exiting...\n");
            fclose(student_file);
            free(student_list);
            return 0;
        }
        else
        {
            printf("\nOverwriting data...\n");
        }
        fclose(student_file);
    }

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

    printf("\nWritng data to file!\n");

    FILE *student_file_write;
    student_file_write = fopen(FILE_NAME, "w");
    if (student_file_write == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fwrite(&n, sizeof(int), 1, student_file_write);
    fwrite(students, sizeof(student), n, student_file_write);

    printf("Data written to file!\n\n");
    printf("Now reading data from file!\n\n");
    fclose(student_file_write);

    FILE *student_file_read;
    student_file_read = fopen(FILE_NAME, "r");
    int num_students;
    fread(&num_students, sizeof(int), 1, student_file_read);
    student *also_students = (student *)malloc(num_students * sizeof(student));
    fread(also_students, sizeof(student), num_students, student_file_read);

    for (int i = 0; i < num_students; i++)
    {
        printf("Email: %s\nRoll Number: %d\nAssignment 1: %d\nAssignment 2: %d\nAssignment 3: %d\n", also_students[i].email, also_students[i].roll_no, also_students[i].marks[0], also_students[i].marks[1], also_students[i].marks[2]);
        printf("\n");
    }

    printf("\nAll data read from file!\n");
    printf("Now closing file!\n");
    fclose(student_file_read);

    return 0;
}
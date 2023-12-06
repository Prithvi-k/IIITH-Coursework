#include <stdio.h>
#include <string.h>

typedef enum Gender
{   
    // No way to get back value of key
    // Need to use switch case 
    Woman = 0,
    Man = 1,
    Transgender = 2,
    NonBinary = 3,
    PreferNoResponse = 4
} Gender;

typedef struct Person
{
    char name[100];
    int age;
    Gender gender;
} Person;

void print_person(Person p)
{
    char gender[20];
    switch (p.gender)
    {
    case Man:
        strcpy(gender, "Man");
        break;

    case Woman:
        strcpy(gender, "Woman");
        break;
    case Transgender:
        strcpy(gender, "Transgender");
        break;
    case NonBinary:
        strcpy(gender, "NonBinary");
        break;
    case PreferNoResponse:
        strcpy(gender, "PreferNoResponse");
        break;
    default:
        break;
    }

    printf("Name: %s\nAge: %d\nGender: %s\n", p.name, p.age, gender);
}

int main()
{
    Person p = {.name = "John Doe", .age = 25, .gender = Man};
    print_person(p);
    return 0;
}
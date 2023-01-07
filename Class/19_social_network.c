#include <stdio.h>
#include <string.h>

enum RelStatus
{
    NotMentioned,
    Single,
    Engaged,
    Married
};

struct Person
{
    char name[100];
    int age;
    enum RelStatus status;
    int count_friends;
    struct Person *friends[5];
};

typedef struct SocialNet
{
    struct Person members[100];
    int size
} SocialNet;

int main()
{
    SocialNet sn;
    sn.size = 0;

    strcpy(sn.members[0].name, "Alice");
    sn.members[0].age = 24;
    strcpy(sn.members[1].name, "Bob");
    sn.members[1].age = 21;
    strcpy(sn.members[2].name, "Charlie");
    sn.members[2].age = 27;
    strcpy(sn.members[3].name, "Dale");
    sn.members[3].age = 28;
    strcpy(sn.members[4].name, "Earl");
    sn.members[4].age = 30;

    sn.members[0].friends[0] = {0, 1};
    

    return 0;
}
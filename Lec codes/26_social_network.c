
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Person
{
    char name[100];
    int age;
    int count_friends;
    struct Person *friends[5];
};

typedef struct SocialNet
{
    struct Person members[100];
    int size;
} SocialNet;

void print_person(struct Person p)
{
    printf(
        "----------------------------------------------\n"
        "Name: %s\tAge: %d\nFriends: \t",
        p.name, p.age);
    for (int i = 0; i < p.count_friends; i++)
    {
        printf("%s ", (p.friends[i])->name);
    }
    printf("\n");
}

struct Person *find_person(char *name1, SocialNet *sn)
{
    struct Person *p = NULL;
    for (int i = 0; i < sn->size; i++)
    {
        if (strcmp(sn->members[i].name, name1) == 0)
        {
            p = &(sn->members[i]);
        }
    }
    return p;
}

/* struct Person add_member()
{
    struct Person p;
    printf("Enter Name: ");
    scanf("%s", &p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter the friends of p:")
    p.count_friends = 0;
    return p;
} */

bool check_mutual_friends(char *name1, char *name2, SocialNet *sn)
{
    struct Person *p1 = find_person(name1, sn);
    struct Person *p2 = find_person(name2, sn);

    // Check if p1 and p2 they have mutual friends
    // If they have mutual friends, return true
    // Otherwise, return false

    int flag = 0;

    /*
    NEED TO IMPLEMENT!!!!

    Code doesn't account for p1 and p2 having the different number of friends.
    For example, if p1 has 2 friends and p2 has 3 friends, the code will still
    check for mutual friends between p1 and p2. This is because the code
    doesn't check for the number of friends of p1 and p2. It only checks if
    the friends of p1 and p2 are the same.
     */

    for (int i = 0; i < p1->count_friends; i++)
    {
        for (int j = 0; j < p2->count_friends; j++)
        {
            if (p1->friends[i] == p2->friends[j])
            {
                flag++;
                if (flag == 1)
                {
                    printf("%s and %s have mutual friends:\n", name1, name2);
                }
                printf("%d. %s\n", flag, p1->friends[i]->name);
            }
        }
    }
    if (flag > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    SocialNet sn;
    sn.size = 0;

    strcpy(sn.members[0].name, "Alice");
    sn.members[0].age = 24;
    strcpy(sn.members[1].name, "Bob");
    sn.members[1].age = 22;
    strcpy(sn.members[2].name, "Charlie");
    sn.members[2].age = 28;
    strcpy(sn.members[3].name, "Dale");
    sn.members[3].age = 26;
    strcpy(sn.members[4].name, "Earl");
    sn.members[4].age = 30;
    sn.size = 5;

    sn.members[0].friends[0] = &sn.members[1]; // Bob is a friend of Alice
    sn.members[0].friends[1] = &sn.members[3]; // Dale is a friend of Alice
    sn.members[0].friends[2] = &sn.members[4]; // Earl is a friend of Alice
    sn.members[0].count_friends = 3;           // Alice has 2 friends

    sn.members[1].friends[0] = &sn.members[0]; // Alice is a friend of Bob
    sn.members[1].count_friends = 1;           // Bob has 1 friend

    sn.members[2].friends[0] = &sn.members[1]; // Bob is a friend of Charlie
    sn.members[2].friends[1] = &sn.members[3]; // Dale is a friend of Charlie
    sn.members[2].count_friends = 2;           // Charlie has 1 friend

    while (true)
    {
        // system("@cls||clear"); // clears the screen

        printf("-------------------------------------------------------------------\n"
               "Social Network\n"
               "-------------------------------------------------------------------\n"
               "\tOptions: 0 View All Members\n"
               "\t         1 Check Mutual Friends\n"
               "\tStats: %d Members\n"
               "-------------------------------------------------------------------\n"
               "Enter Option: \n",
               sn.size);

        int option;
        scanf("%d", &option);

        char name1[100], name2[100];

        switch (option)
        {
        case 0:
            for (int i = 0; i < 5; i++)
            {
                print_person(sn.members[i]);
            }
            break;

        case 1:
        {
            printf("Enter first person's name: ");
            scanf("%s", name1);
            printf("Enter second person's name: ");
            scanf("%s", name2);
            printf("\n");

            bool result = check_mutual_friends(name1, name2, &sn);
            if (result)
            {
            }
            else
            {
                printf("%s and %s do not have mutual friends\n", name1, name2);
            }
        }

        default:
            break;
        }
    }

    return 0;
}

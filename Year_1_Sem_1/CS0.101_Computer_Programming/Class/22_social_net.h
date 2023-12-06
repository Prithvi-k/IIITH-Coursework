
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FRIENDS 5
#define MAX_MEMBERS 100
#define MAX_NAME_LEN 100

struct Person {
    char name[MAX_NAME_LEN];
    int age;
    int count_friends;
    struct Person *friends[MAX_FRIENDS];
};

typedef struct SocialNet {
    struct Person members[MAX_MEMBERS];
    int size;
} SocialNet;

void print_person(struct Person p);

void print_network(SocialNet *sn);

struct Person * find_person(char* name1, SocialNet *sn);

void setup_ABCDE_network(SocialNet *sn);

// check if q is at a distance <= degree from p
bool check_degree_of_seperation(struct Person* p, struct Person* q, int degree);
#include "Class/22_social_net.h"

void print_person(struct Person p) {
    printf("%s\t\t%d \t", p.name, p.age);
    for(int i = 0; i < p.count_friends; i++) {
        printf("%s, ", (p.friends[i])->name);
    }
    printf("\n");
}

void print_network(SocialNet *sn) {
    printf(
        "----------------------------------------------\n"
        "Name\t\tAge \tFriends\n"
        "----------------------------------------------\n");
    for (int i=0;i <5; i++) {
        print_person(sn->members[i]);
        
    }
    printf("----------------------------------------------\n");

}

struct Person * find_person(char* name1, SocialNet *sn) {
    struct Person* p = NULL;
    for(int i = 0; i < sn->size; i++) {
        if (strcmp(sn->members[i].name, name1) == 0) {
            p = &(sn->members[i]);
        }
    }
    return p;
}


void setup_ABCDE_network(SocialNet *sn) {

    strcpy(sn->members[0].name, "Alice");
    sn->members[0].age = 24;
    strcpy(sn->members[1].name, "Bob");
    sn->members[1].age = 22;
    strcpy(sn->members[2].name, "Charlie");
    sn->members[2].age = 28;
    strcpy(sn->members[3].name, "Dale");
    sn->members[3].age = 26;
    strcpy(sn->members[4].name, "Earl");
    sn->members[4].age = 30;
    sn->size=5;
    
    sn->members[0].friends[0] = &(sn->members[3]);
    sn->members[0].friends[1] = &(sn->members[4]);
    sn->members[0].count_friends=2;

    sn->members[1].friends[0] = &(sn->members[0]);
    sn->members[1].count_friends=1;

    sn->members[2].friends[0] = &(sn->members[3]);
    sn->members[2].friends[1] = &(sn->members[1]);
    sn->members[2].count_friends=2;
    sn->members[3].friends[0] = &(sn->members[0]);
    sn->members[3].friends[1] = &(sn->members[4]);
    sn->members[3].friends[2] = &(sn->members[2]);
    sn->members[3].count_friends=3;
    sn->members[4].friends[0] = &(sn->members[0]);
    sn->members[4].friends[1] = &(sn->members[3]);
    sn->members[4].count_friends=2;

}



bool check_degree_of_seperation(struct Person* p, struct Person* q, int degree) {
    if (degree < 0) {
        return false;
    }

    if ( degree == 1) {
        if (p == q) {
            return true;
        } else {
            for (int i = 0; i < p->count_friends; i ++) {
                if (p->friends[i] == q) {
                    return true;
                }
            }
        }
        return false;

    } else if (p==q) {
        return true;
    } else {
        bool is_within_degree = false;
        for (int i = 0; i < p->count_friends; i++) {
            is_within_degree = is_within_degree || check_degree_of_seperation(p->friends[i], q, degree-1);
        }
        return is_within_degree;
    }

}
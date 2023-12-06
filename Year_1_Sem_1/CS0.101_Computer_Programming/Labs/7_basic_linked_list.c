#include <stdio.h>
#include <stdlib.h>

typedef struct srms {
    char* name;
    int age;
    struct srms* nex;
}srms;

srms * recursivelyPrintElementAtIndex(srms* root, int traversed, int k){
    if (root == NULL)
        return root;
    if (traversed == k)
        printf("%s %d\n", root->name, root->age);
    else
        recursivelyPrintElementAtIndex(root->nex, traversed + 1, k);
}


int main() {
    int q;
    scanf("%d", &q);
    srms* root;
    root = (srms*)(malloc(sizeof(struct srms)));
    root->nex = NULL;

    srms* back;
    back = root;

    for (int i = 0; i < q; i++) {
        int tp;
        scanf("%d", &tp);

        if (tp == 1) {
            srms* temp;
            temp = (srms*)(malloc(sizeof(struct srms)));
            temp->name = (char*)malloc(sizeof(char) * 5);
            temp->nex = NULL;
            scanf("%s", temp->name);
            scanf("%d", &(temp->age));
            back->nex = temp;
            back = temp;
        } else{
            int k;
            scanf("%d", &k);
            // srms* ptr = root;
            // int cnt = 0;
            // while (ptr->nex != NULL) {
            //     ptr = ptr->nex;
            //     cnt++;
            //     if (cnt == k)
            //         break;
            // }
            // if (cnt == k)
            //     printf("%s %d\n", ptr->name, ptr->age);
            // else
            //     printf("Element not added yet\n");
            srms* ans = recursivelyPrintElementAtIndex(root, 0, k);
            if (ans != NULL)
                {printf("%s %d\n", ans->name, ans->age);}
            else
                {printf("Element not added yet\n");}
        }
    }

    return 0;
}
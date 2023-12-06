#include <stdio.h>
#include <stdlib.h>

typedef struct srms {
    char*name;
    int age;
}srms;

int comp1(const void* a, const void* b)
{
    return (((srms*)a)->age - ((srms*)b)->age);
}

int main()
{
    srms db[3];
    int n = 3;
    for (int i = 0; i < n; i++)
    {
        db[i].name = (char*)malloc(20 * sizeof(char));
        scanf("%s", db[i].name);
        scanf("%d", &db[i].age);
    }
    
    // sorts in ascending order by default
    qsort(db, n, sizeof(db[0]), comp1);

    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", db[i].name, db[i].age);
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int fact(int k)
{
    return k == 1 ? 1 : k * fact(k - 1);
}

// Type Perm for storing Permutation.
// A Permutation will be array of integers
// we will use the address of the first element to represent the permutation
// Hence the Perm type is an alias to int*
typedef int *Perm;

// Type PermList for storing list of all permutations
// A PermList will be an array of Perms
// We will use the address of the first element to represent the list of permutations.
// Hence the PermList type is an alias to Perm*
typedef Perm *PermList;

PermList create_perm_list(int k)
{
    int fk = fact(k);
    // create a PermList, which can hold factorial(k) Perms
    PermList M = (int **)malloc(sizeof(Perm) * fk);
    for (int i = 0; i < fk; i++)
    {
        M[i] = (int *)malloc(sizeof(int) * k);
    }
    return M;
}

void destroy_perm_list(PermList A, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(A[i]);
    }
    free(A);
}

void print_perm(Perm A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insert_copy_perm(Perm A, int size, int pos, Perm B)
{
    for (int i = 0; i <= size; i++)
    {
        if (i < pos)
        {
            B[i] = A[i];
        }
        else if (i == pos)
        {
            B[i] = size + 1;
        }
        else
        {
            B[i] = A[i - 1];
        }
    }
}

/*
A permutation is represented by type Perm ( same as int* ).
A list of permutations is represented by PermList (same as int**).
The function should return the list of all permutations of numbers from 1 .. k.
Pseudo code
    - M := empty list
    - A := perm(k-1)
    - for each permutation a in M:
        - for each position p from 0 to k
            - p' = insert k at position p in a
            - add p' to A
    - Base case: if k = 1 return list of only 1 permutation
*/

PermList perm(int k)
{
    PermList M = create_perm_list(k);
    if (k == 1)
    { // base case
        M[0][0] = 1;
    }
    else
    {                             // recursive case
        PermList A = perm(k - 1); // recursive call
        int t = fact(k - 1);
        int c = 0;
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < k; j++)
            {
                insert_copy_perm(A[i], k - 1, j, M[c]);
                c++;
            }
        }
        destroy_perm_list(A, k - 1);
    }
    return M;
}

int main()
{
    int k = 3;
    PermList M = perm(k);
    int fk = fact(k);
    for (int i = 0; i < fk; i++)
    {
        print_perm(M[i], k);
    }
    return 0;
}

#include <stdio.h>

void copy_array(int *A, int start, int end, int *B)
{
    for (int i = start; i < end; i++)
    {
        B[i - start] = A[i];
    }
}

void merge(int *L, int sL, int *R, int sR, int *A)
{
    // A is the final sorted array
    // L is the left array with size sL
    // R is the right array with size sR
    int l = 0, r = 0, c = 0;
    // l is the index of L
    // r is the index of R
    // c is the index of A

    while (c <= sL + sR - 1)
    {
        if (r == sR) // R is empty
        {
            A[c++] = L[l++];
            continue;
        }

        if (l == sL) // L is empty
        {
            A[c++] = R[r++];
            continue;
        }

        if (L[l] < R[r]) // Element at index l of L is smaller than element at index r of R
        {
            A[c++] = L[l++];
        }
        else if (L[l] >= R[r]) // Element at index r of R is smaller than element at index l of L
        {
            A[c++] = R[r++];
        }
    }
}

void sort(int *A, int len)
{
    if (len == 1)
    {
        return;
    }
    else
    {
        int mid = len / 2;
        int L[mid], R[len - mid];
        copy_array(A, 0, mid, L);
        copy_array(A, mid, len, R);
        sort(L, mid);
        sort(R, len - mid);
        merge(L, mid, R, len - mid, A);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    sort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

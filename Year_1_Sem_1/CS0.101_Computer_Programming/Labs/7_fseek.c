#include <stdio.h>

int main()
{
    FILE *fp = fopen("Labs/7_fseek.txt", "r+");
    if (fp == NULL)
    {
        printf("Error opening file");
        return -1;
    }

    int A[7], i, p = 0;
    while (fscanf(fp, "%d", &i) != EOF)
    {
        A[p] = i;
        p++;
    }
    p--;

    // rewind(fp);
    // rewind takes file pointer as argument and sets the file pointer to the start of the file
    // fseek(fp, 0, SEEK_CUR);
    fseek(fp, -5, SEEK_CUR);
    // fseek takes 3 arguments
    // 1. file pointer
    // 2. offset
    // 3. SEEK_SET, SEEK_CUR, SEEK_END
    // SEEK_SET: start of file
    // SEEK_CUR: current position
    // SEEK_END: end of file

    // for (int j = 6; j > 0; j--)
    // {
    //     fprintf(fp, "%d ", A[j]);
    // }

    // int challenge = 0;
    while (p >= 0)
    {
        fprintf(fp, "%d ", A[p]);
        p--;
        // if (challenge == 2)
        // {
        //     break;
        // }
        // challenge++;        
    }
    
    
    return 0;
}
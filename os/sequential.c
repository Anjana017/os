#include <stdio.h>
 void main()
 {
    int n, flag[50], len[20], start[20], t[20], bno[20][20];
    int blockalloc[50] = {0};
    printf("Enter no.of files:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the starting block of file.%d : ", i + 1);
        scanf("%d", &start[i]);
        printf("Enter length of file%d : ", i + 1);
        scanf("%d", &len[i]);
        flag[i] = 1;
        for (int j = start[i]; j < start[i] + len[i]; j++)
            if (blockalloc[j] == 1)
            {
                printf("Block.%d already allocated\n", j);
                flag[i] = 0;
                break;
            }
        if (flag[i])
        {
            for (int j = start[i]; j < start[i] + len[i]; j++)
            {
                blockalloc[j] = 1;
            }
            t[i] = start[i];
            for (int j = 0; j < len[i]; j++)
                bno[i][j] = t[i]++;
            printf("File allocated successfully\n");
        }
    }
    printf("FileNo\tStart\tlength\n");
    for (int i = 0; i < n; i++)
        if (flag[i])
            printf("%d\t\t %d \t\t%d\n", i + 1, start[i], len[i]);
    int choice, search;
    do
    {
        printf("\nEnter file No:");
        scanf("%d", &search);
        if (flag[search - 1])
        {
            printf("File No : %d\n", search);
           printf("Length : %d\n", len[search - 1]);           
           printf("blocks occupied:");
            for (int i = 0; i < len[search - 1]; i++)
                printf("%4d", bno[search - 1][i]);
        }
        else
            printf("File%d not allocated \n", search);
        printf("\nDo you want to search more (1/0) : ");
        scanf("%d", &choice);
    } while (choice);
 }
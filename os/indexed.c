#include <stdio.h>

struct file {
    char fname[10];   // File name
    int index;        // Index block number
    int size;         // Number of blocks required
    int block[10];    // Array of blocks for the file
} f[10];

int main() {
    int n, allocated[10] = {0};  // Array to track allocated blocks (0 = free, 1 = allocated)

    // Input number of files
    printf("Enter the number of files: ");
    scanf("%d", &n);

    // Input details for each file
    for (int i = 0; i < n; i++) {
        printf("Enter the file name: ");
        scanf("%s", f[i].fname);

        // Input the index block
    retry_index:
        printf("Enter the index block: ");
        scanf("%d", &f[i].index);

        if (allocated[f[i].index]) {  // Check if index block is already allocated
            printf("Block %d is already allocated. Try another block.\n", f[i].index);
            goto retry_index;  // Retry entering the index block
        }
        allocated[f[i].index] = 1;  // Mark the index block as allocated

        f[i].block[0] = f[i].index;  // Store the index block

        // Input the number of blocks required
        printf("Enter the number of blocks required: ");
        scanf("%d", &f[i].size);

        // Input the blocks
        for (int j = 1; j <= f[i].size; j++) {
        retry_block:
            printf("Enter block number %d: ", j);
            scanf("%d", &f[i].block[j]);

            if (allocated[f[i].block[j]]) {  // Check if block is already allocated
                printf("Block %d is already allocated. Try another block.\n", f[i].block[j]);
                goto retry_block;  // Retry entering the block
            }

            allocated[f[i].block[j]] = 1;  // Mark the block as allocated
        }

        // Display the block linkage for each file
        printf("\nFile: %s\n", f[i].fname);
        printf("Index Block: %d\n", f[i].block[0]);
        printf("Blocks: ");
        for (int j = 1; j <= f[i].size; j++) {
            printf("%d", f[i].block[j]);
            if (j < f[i].size) {
                printf(" ---> ");
            }
        }
        printf("\n");
    }

    // Display final file allocation details
    printf("\nFile\tIndex\tSize\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\n", f[i].fname, f[i].index, f[i].size);
    }

    return 0;
}

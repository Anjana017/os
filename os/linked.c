#include <stdio.h>

struct file {
    char fname[10];  // File name
    int start;       // Start block
    int size;        // Number of blocks
    int block[10];   // Array of block indices
} f[10];

int main() {
    int i, j, n;
    int allocated[10] = {0}; // Track allocated blocks (0 = free, 1 = allocated)

    printf("Enter the number of files: ");
    scanf("%d", &n);

    // Input for each file
    for (i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", f[i].fname);

        printf("Enter the start block: ");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start; // Store start block

        printf("Enter the number of blocks required: ");
        scanf("%d", &f[i].size);

        allocated[f[i].start] = 1; // Mark start block as allocated

        printf("Enter the block numbers:\n");
        for (j = 1; j <= f[i].size; j++) {
            int block;
        retry: // Label for retrying if block is already allocated
            scanf("%d", &block);

            if (allocated[block] == 1) {
                printf("Block %d is already allocated. Enter a different block:\n", block);
                goto retry; // Retry with a different block number
            }

            f[i].block[j] = block; // Store the block number
            allocated[block] = 1;  // Mark the block as allocated
        }
    }

    // Display the file allocation details
    printf("\nFile\tStart\tSize\tBlocks\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);

        for (j = 1; j <= f[i].size - 1; j++) {
            printf("%d--->", f[i].block[j]);
        }
        printf("%d\n", f[i].block[f[i].size]); // Print the last block without arrow
    }

    return 0;
}

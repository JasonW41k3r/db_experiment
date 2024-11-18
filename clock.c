// This is a program to simulate the clock algorithm of DB buffer replacement policy
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int buffer_size = 0; // Size of the buffer
    int n = 0;           // Number of read operations
    int opt_count = 0;   // Number of operations

    // Input buffer size
    printf("Enter the buffer size: ");
    scanf("%d", &buffer_size);

    // Dynamically allocate memory for the buffer
    int *buffer = (int *)malloc((buffer_size + 1) * sizeof(int));
    if (buffer == NULL) {
        printf("Memory allocation failed for buffer.\n");
        return -1;
    }

    // Initialize buffer
    for (int i = 0; i <= buffer_size; i++) {
        buffer[i] = 0;
    }

    // Input the number of operations
    printf("Enter the number of operations: ");
    scanf("%d", &opt_count);

    for (int cnt = 0; cnt < opt_count; cnt++) {
        // Input the number of reads for this operation
        printf("Enter the number of reads: ");
        scanf("%d", &n);

        // Dynamically allocate memory for the current operation
        int *opt = (int *)malloc(n * sizeof(int));
        if (opt == NULL) {
            printf("Memory allocation failed for opt.\n");
            free(buffer); // Free the buffer before exiting
            return -1;
        }

        // Input the page numbers to read
        printf("Enter the read page numbers (from 1 to %d): ", buffer_size);
        for (int i = 0; i < n; i++) {
            scanf("%d", &opt[i]);
        }

        // Simulate the clock algorithm
        for (int i = 0; i < n; i++) {
            buffer[opt[i]] = 1; // Mark the page as recently used
        }

        // Find the first page to evict
        for (int i = 1; i <= buffer_size; i++) {
            if (buffer[i] == 0) {
                printf("Page %d will be evicted.\n", i);
                break;
            }
        }

        // Free memory for the current operation
        free(opt);
    }

    // Free memory for the buffer
    free(buffer);

    return 0;
}

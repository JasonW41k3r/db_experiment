// This is a program simulate the clock algorithm of DB buffer replacement policy
#include <stdio.h>
int main(void)
{
    int buffer_size = 0;
    int n = 0;
    int opt = 0;
    printf("Enter the buffer size: ");
    scanf("%d", &buffer_size);
    int buffer[buffer_size + 1];
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 0;
    }
    printf("Enter the number of operation: ");
    scanf("%d", &opt);
    for (int cnt = 0; cnt < opt; cnt++) {
        printf("Enter the number of read: ");
        scanf("%d", &n);
        int opt[n];
        printf("Enter the read page number(from 1 to %d): ", buffer_size);
        for (int i = 0; i < n; i++) {
            scanf("%d", &opt[i]);
        }
        for (int cnt = 0; cnt < n; cnt++) {
            buffer[opt[cnt]] = 1;
        }
        for (int cnt = 1; cnt <= buffer_size; cnt++) {
            if (buffer[cnt] == 0) {
                printf("Page %d will be evicted.\n", cnt);
                break;
            }
        }
    }
}
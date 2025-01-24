#include <stdio.h>

int main() {

    int i, j, limit;
    printf("Enter limit (1-9): ");
    scanf("%d", &limit);

    if (limit > 9) {
        printf("Error: Limit should not exceed 9.\n");
        return 1;
    }

    for (i = 1; i <= limit; i++) {
        for (j = 1; j <= limit - i; j++) {
            printf("*");
        }
        printf("%d", i);
        if (i != limit) {
            for (j = 1; j <= 2 * (i - 1); j++) {
                printf(" ");
            }
            printf("%d", i);
        } else {
            for (j = 1; j <= 2 * (i - 1); j++) {
                printf(" ");
            }
            printf("%d", i);
        }
        for (j = 1; j <= limit - i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
/*

This should printf

********11********
*******2  2*******
******3    3******
*****4      4*****
****5        5****
***6          6***
**7            7**
*8              8*
9                9

*/
#include <stdio.h>

int main() {
    int limit, i, j, k;

    // Code for Number 1
    printf("Enter the limit for Number 1: ");
    scanf("%d", &limit);

    if (limit > 9) {
        printf("Limit Exceeded\n");
    } else {
        for (i = 1; i <= limit; i++) {
            for (j = 1; j < i; j++) {
                printf("*");
            }
            printf("%d\n", i);
        }
    }

    // Code for Number 2
    printf("Enter limit for Number 2: ");
    scanf("%d", &limit);

    if (limit > 9) {
        printf("Limit Exceeded\n");
    } else {
        for (i = 1; i <= limit; i++) {
            for (j = limit; j > i; j--) {
                printf(" ");
            }
            for (k = 1; k < i; k++) {
                printf("*");
            }
            printf("%d", i);
            for (k = 1; k < i; k++) {
                printf("*");
            }
            printf("\n");
        }
    }

    // Code for Number 3
    printf("Enter limit for Number 3: ");
    scanf("%d", &limit);

    if (limit > 9) {
        printf("Limit Exceeded\n");
    } else {
        for (i = 1; i <= limit; i++) {
            for (j = 1; j < i; j++) {
                printf("*");
            }
            printf("%d", i);
            for (k = 1; k <= (limit - i) * 2; k++) {
                printf(" ");
            }
            printf("%d", i);
            for (j = 1; j < i; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    int i, j, k, limit;

    printf("Enter limit: ");
    scanf("%d", &limit);

    if (limit > 9) {
        printf("Limit Exceeded\n");
        return 1;
    }

    for (i = 1; i <= limit; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("%d", i);
        for (k = 1; k <= (limit - i) * 2; k++) {
            printf(" ");
        }
        printf("%d", i);
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

/*
This prints :
1                1
*2              2*
**3            3**
***4          4***
****5        5****
*****6      6*****
******7    7******
*******8  8*******
********99********

*/
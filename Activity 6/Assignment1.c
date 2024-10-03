#include <stdio.h>

int main() {
    int limit, i, j;

    printf("Enter the limit: ");
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

    return 0;
}

/*
This prints :

1
*2
**3
***4
****5
*****6
******7
*******8
********9


*/
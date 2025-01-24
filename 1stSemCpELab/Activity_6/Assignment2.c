#include <stdio.h>

int main() {
    int limit;
    int i, j, k;
    printf("Enter limit: ");
    scanf("%d", &limit);

    if (limit > 9) {
        printf("Limit Exceeded\n");
        return 1;
    }

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

    return 0;
}

/*
This prints: 

        1
       *2*
      **3**
     ***4***
    ****5****
   *****6*****
  ******7******
 *******8*******
********9********

*/
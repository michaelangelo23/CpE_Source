#include <stdio.h>

int main() {
    for (int i = 1; i <= 9; i++) {
        // Print leading spaces
        for (int j = 9; j > i; j--) {
            printf(" ");
        }
        // Print the number
        printf("%d", i);
        // Print asterisks
        for (int k = 1; k < i; k++) {
            printf("*");
        }
        // New line after each row
        printf("\n");
    }
    return 0;
}

/*
This should output:

        1
       2*
      3**
     4***
    5****
   6*****
  7******
 8*******
9********

*/
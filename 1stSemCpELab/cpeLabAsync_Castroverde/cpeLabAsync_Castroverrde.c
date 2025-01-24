/*
============================================================================
FILE : cpeLabAsync.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :

                            Just a review and
                         Practice of C Programming


      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-22-24 By: Mickel Angelo Castroverde
Description: practiced code and practice exercises
============================================================================
*/

// Practice exercise number 1
/*
#include <stdio.h>

int main()
{
    int numbers[5] = {3, 5, 7, 8, 90};
    int *ptr = numbers;

    for (int i = 0; i < 5; i++)
    {
        *(ptr + i) *= 10;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}

// practice exercise number 2

#include <stdio.h>

int main()
{
    char str[13] = "Hello World!";
    char *ptr = str;

    for (int i = 0; i < 13; i++)
    {
        printf("Character: %c, Address: %p\n", *(ptr + i), (ptr + i)); 
    }

    return 0;
}

// practice exercise number 3

#include <stdio.h>

void add(int *a, int *b, int *sum)
{
    *sum = *a + *b;
}

int main()
{
    int num1, num2, sum;

    printf("Input the first number: ");
    scanf("%d", &num1);

    printf("Input the second number: ");
    scanf("%d", &num2);

    add(&num1, &num2, &sum);

    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    return 0;
}

// practice exercise number 4 == for printinf od 2d array
#include <stdio.h>

int main() {
    int arr[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int (*ptr)[3] = arr;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Value at arr[%d][%d] = %d\n", i, j, *(*(ptr + i) + j));
        }
    }

    return 0;
}

// practice exercise number 5 == for adding 100 to the values of a 2D array

#include <stdio.h>

int main()
{
    int numArr[3][3] =
    {
        {1000, 1001, 1002},
        {2000, 2001, 2002},
        {3000, 3001, 3002}
    };

    int (*ptr)[3] = numArr;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            *(*(ptr + i) + j) += 100;
        }
    }

    for (int i = 0; i < 3; i++) // display the values of the 2D array
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Value at numArr[%d][%d] = %d\n", i, j, numArr[i][j]);
        }
    }

    return 0;
}

*/
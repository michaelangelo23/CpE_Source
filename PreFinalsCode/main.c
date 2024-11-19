/*
#include <stdio.h>

void getDayOfWeek(int *day);

int main()
{
    int day;
    int *ptr = &day;

    do
    {
        printf("Enter a number: ");
        scanf("%d", ptr);
        getDayOfWeek(ptr);
    }
    while (*ptr < 1 || *ptr > 7);

    return 0;
}

void getDayOfWeek(int *day)
{
    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    if (*day >= 1 && *day <= 7)
    {
        printf("Day of the week: %s\n", days[*day - 1]);
    }
    else
    {
        printf("Invalid input.\n");
    }
}


#include <stdio.h>

int main(void)
{
    int x, *p, *q;
    p = &x;
    q = p;

    x = 4; // initializing a value to x
    x = x + 3;
    *p = 8;

    *&x = *p + *q; // adding the *p and *q pointer
    x = *p * *q;   // multiplying *p and *q pointer

    return 0;

}

#include <stdio.h>

int main(void)
{
    int i1, i2; //  are integer variables.
    int *p1, *p2; //  pointers to integers.

    i1 = 5; // assigned the value 5.
    p1 = &i1;  // assigned the address of i1.
    i2 = *p1 / 2 + 10;  //calculated using the value pointed to by p1 (which is i1), divided by 2, and then adding 10.
    p2 = p1;  //assigned the same address as p1.

    printf("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i\n", i1, i2, *p1, *p2);

    return 0;
}

#include <stdio.h>

int main(void)
{
    int x[5] = {1, 2, 3, 4, 5};  //  array of integers initialized with the values {1, 2, 3, 4, 5}.
    int *p1;  // pointer to an integer.
    p1 = x; // p1 points to the first element of the array x
    p1++;   // p1 now points to the second element of the array x

    printf("\n%d", *p1); // Output the value pointed to by p1, which is 2

    x[2] = *p1 + p1[2]; // x[2] = 2 + 4 (p1[2] is the element 2 positions ahead of p1, which is x[3])

    printf("\n%d", x[2]); // Output the new value of x[2], which is 6

    return 0;
}



#include <stdio.h>

int main()
{
    int num1 = 10, num2 = 20,num3 = 30, num4 = 40, sum; // Adding two numbers using pointers
    int *p1, *p2, *p3, *p4;

    printf("Memory address of ptr1: %p\n", (void*)p1); // print the memory address of pointer 1
    printf("Memory address of ptr2: %p\n", (void*)p2); // print the memory address of pointer 2
    printf("Memory address of ptr1: %p\n", (void*)p3); // print the memory address of pointer 3
    printf("Memory address of ptr2: %p\n", (void*)p4); // print the memory address of pointer 4

    p1 = &num1;
    p2 = &num2;
    p3 = &num3;
    p4 = &num4;

    sum = *p1 + *p2;
    printf("Sum of %d and %d is %d\n", num1, num2, sum);

    int a = 5, b = 15; // Same pointer pointing to different data variables
    int *ptr;

    ptr = &a;
    printf("a: %d\n", *ptr);

    ptr = &b;
    printf("b: %d\n", *ptr);

    int c = 25;  // Different pointers pointing to the same data variable
    int *ptr1, *ptr2;

    ptr1 = &c;
    ptr2 = &c;

    printf("c: %d\n", *ptr1);
    printf("c: %d\n", *ptr2);

    printf("Memory address of ptr1: %p\n", (void*)p1); // print the memory address of pointer 1
    printf("Memory address of ptr2: %p\n", (void*)p2); // print the memory address of pointer 2
    printf("Memory address of ptr1: %p\n", (void*)p3); // print the memory address of pointer 3
    printf("Memory address of ptr2: %p\n", (void*)p4); // print the memory address of pointer 4

    return 0;

}


#include <stdio.h>

int main(void)
{
    int x[5] = {1, 2, 3, 4, 5}; // array of integers initialized with the values {1, 2, 3, 4, 5}.
    int *p1;

    p1 = x; // p1 points to the first element of the array x

    printf("Memory address of p1: %p\n", (void*)p1);  // Print the memory address of the pointer

    // p1++;   // p1 now points to the second element of the array x

    // printf("\n%d", *p1); // Output the value pointed to by p1, which is 2

    x[2] = *p1 + p1[1]; // x[2] = 2 + 4 (p1[1] is the element 1 position ahead of p1, which is x[3])

    // printf("\n%d\n", x[2]); // Output the new value of x[2], which is 6

    for (int i = 0; i < 5; i++) // For loop to print the values of x using p1
    {
        printf("x[%d] = %d\n", i, *p1++);
        printf("Memory address of p1: %p\n", (void*)p1)
        ;
    }

    return 0;
}

*/

#include <stdio.h>
#define MONTHS 12 // months defined as 12.

int main(void)
{
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // array days is initialized with the number of days in each month.
    int index;

    for (index = 0; index < MONTHS; index++)  // same as days[index]  loop iterates over the array days.
    {
        printf("Month %2d has %d days.\n", index + 1, *(days + index));
    }

    return 0;
}

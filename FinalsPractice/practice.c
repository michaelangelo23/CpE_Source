#include <stdio.h>

// these are for function prototyping, defining your functions before the main function
int add(int a, int b);
void printArray(int arr[], int size);
void modifyString(char *str);
void incrementPointer(int *ptr);
void printPerson(struct Person *p);

struct Person {  // this is a structure function
    int age;
};

int main()
{
    printf("=== Sequence ===\n"); // this is a sequence statement
    int a = 5;
    int b = 10;
    int sum = a + b;
    printf("Sum: %d\n", sum);

// this here are different kinds of selection statements

// bwlow is an if else statement
// PROS : it is easy to understand and implement
// CONS : it is not efficient as it executes only one condition in a single code block
// it is bad to nest if else statements as it can be confusing so use switch statements instead

    printf("\n=== Selection ===\n");  
    if (sum > 10) // if sum is greater than 10
    {
        printf("Sum is greater than 10\n");   
    }
    else
    {
        printf("Sum is 10 or less\n");
    }

// below is an example of a switch statement
// PROS : it is efficient as it can execute multiple conditions
// CONS : it is not easy to write a flowchart if you're not familiar with the code
// it is better to use switch statements if you have multiple conditions to check
// and it is bad to use switch statements if you have only one condition

    int num = 3;
    switch (num)
    {
        case 1:
            printf("Number is 1\n");
            break;
        case 2:
            printf("Number is 2\n");
            break;
        case 3:
            printf("Number is 3\n");
            break;
        default:
            printf("Number is not 1, 2, or 3\n");
    }

// below are different kinds of loop statements

//this here is a for loop
// this is good for when you know how many times you want to loop
// or if you want to loop the code a specific number of times
    printf("\n=== Loop ===\n");
    for (int i = 0; i < 5; i++)
    {
        printf("for loop i: %d\n", i);
    }

// this here is a while loop
// this is used when you want to loop the code until a certain condition is met
// or keep the code running until a certain condition is met
    int j = 0;
    while (j < 5)
    {
        printf("while loop j: %d\n", j);
        j++;
    }

//this here is a do while loop
// this is used when you want to loop the code at least once before checking the condition
// this is only good for times when you want to loop the code at least once
    int k = 0;
    do
    {
        printf("do-while loop k: %d\n", k);
        k++;
    } while (k < 5);

// this is an example of a function
// PROS : it is reusable and can be used multiple times
// CONS : it can be hard to understand if you have a lot of functions so do remember to comment your code

    printf("\n=== Functions ===\n");
    int result = add(5, 10);
    printf("Result: %d\n", result);

// this is an example of an array
// PROS : it is easy to store multiple values in a single variable
// CONS : it is hard to manipulate the values in the array
// remmeber that arrays start at 0 so if you have an array of 5 elements, the last element is 4
    printf("\n=== Arrays ===\n");
    int numbers[5] = {1, 2, 3, 4, 5};
    printArray(numbers, 5);

    // Strings
    printf("\n=== Strings ===\n");
    char str[] = "Hello, World!";
    printf("Original String: %s\n", str);
    modifyString(str);
    printf("Modified String: %s\n", str);

    // Pointers
    printf("\n=== Pointers ===\n");
    int x = 10;
    int *ptr = &x;
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Value pointed to by ptr: %d\n", *ptr);
    incrementPointer(ptr);
    printf("Value of x after increment: %d\n", x);

    // Structures
    printf("\n=== Structures ===\n");
    struct Person person;
    person.age = 25;
    snprintf(person.name, sizeof(person.name), "John Doe");
    printPerson(&person);

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("numbers[%d]: %d\n", i, arr[i]);
    }
}

void modifyString(char *str) {
    str[0] = 'h';
}

void incrementPointer(int *ptr) {
    (*ptr)++;
}

void printPerson(struct Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}
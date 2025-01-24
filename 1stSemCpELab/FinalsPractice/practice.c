#include <stdio.h>

// Structure definition
struct Person {
    char name[50];
    int age;
};


// Function prototypes
int add(int a, int b);
void printArray(int arr[], int size);
void modifyString(char *str);
void incrementPointer(int *ptr);
void printPerson(struct Person *p);

int main() {
    // Sequence
    printf("=== Sequence ===\n");
    int a = 5;
    int b = 10;
    int sum = a + b;
    printf("Sum: %d\n", sum);

    // Selection
    printf("\n=== Selection ===\n");
    if (sum > 10) {
        printf("Sum is greater than 10\n");
    } else {
        printf("Sum is 10 or less\n");
    }

    // Below is an example of a switch statement
    // PROS: It is efficient as it can execute multiple conditions
    // CONS: It is not easy to write a flowchart if you're not familiar with the code
    // It is better to use switch statements if you have multiple conditions to check
    // and it is bad to use switch statements if you have only one condition

    int num = 3;
    switch (num) {
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

    // Loop
    printf("\n=== Loop ===\n");
    for (int i = 0; i < 5; i++) {
        printf("for loop i: %d\n", i);
    }

    int j = 0;
    while (j < 5) {
        printf("while loop j: %d\n", j);
        j++;
    }

    int k = 0;
    do {
        printf("do-while loop k: %d\n", k);
        k++;
    } while (k < 5);

    // Functions
    printf("\n=== Functions ===\n");
    int result = add(5, 10);
    printf("Result: %d\n", result);

    // Arrays
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
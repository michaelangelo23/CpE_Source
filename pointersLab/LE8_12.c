/*
============================================================================
FILE : LE8_12.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :
                            Search Element
Write a function to search an element in array using pointers and return the index
location. The function accepts the starting address of the array, number of entries
and number to search.

      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-05-24 By: Mickel Angelo Castroverde
Description: Finished and verified the code for errors. Improvised and also applied
modularization.
============================================================================
*/

#include <stdio.h>

int searchElement(int *arr, int size, int num, int *index); // function prototypes

int main()
{
    int size, num, searchNum, index;

    printf("Enter number of entries: "); // prompt in number of entries
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int)); // dynamically allocate memory for the array
    if (arr == NULL) // check if memory allocation was successful
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) // declare an array of the specified size
    {
        printf("Enter number: "); // prompts user to enter a number
        scanf("%d", arr + i);
    }

    printf("Search data: "); // prompts the user to enter the number to search
    scanf("%d", &searchNum);

    if (searchElement(arr, size, searchNum, &index)) // call searchElement function
    {
        // If found, print the index
        printf("FOUND in Index %d\n", index);
    }
    else
    {
        // If not found, print not found message
        printf("NOT FOUND\n");
    }

    free(arr); // free the allocated memory
    return 0;
}

int searchElement(int *arr, int size, int num, int *index) // function for searchElement
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == num)
        {
            *index = i;
            return 1;
        }
    }
    return 0;
}
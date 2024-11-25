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

int searchElement(int *arr, int size, int num, int *index);

int main()
{
    int size, num, searchNum, index;

    printf("Enter number of entries: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter number: ");
        scanf("%d", arr + i);
    }

    printf("Search data: ");
    scanf("%d", &searchNum);

    if (searchElement(arr, size, searchNum, &index))
    {
        printf("FOUND in Index %d\n", index);
    }
    else
    {
        printf("NOT FOUND\n");
    }

    return 0;
}

int searchElement(int *arr, int size, int num, int *index)
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
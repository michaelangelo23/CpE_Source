#include <stdio.h>

int findMax(int *arr, int size); 

int main()
{
    int size;

    printf("Enter number of entries: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, size);
    printf("Maximum Number: %d\n", max);

    return 0;
}

int findMax(int *arr, int size)
{
    int max = *arr;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }
    return max;
}
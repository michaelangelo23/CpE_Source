#include <stdio.h>

int main (void)
{
    int a[5] = {2,4,6,8,22}; // plus 5 
    *(a+0) = 6;
     
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", (a + i));
    }

    return 0;
}


#include <stdio.h>

int main()
{
    int row, col, i, j, table;

    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            table = i * j;
            printf("%2d\t", table);
        }
        printf("\n");
    }
    return 0;
}
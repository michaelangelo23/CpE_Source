#include <stdio.h>

int main() {

    int i;
    float f;
    char c;

    printf("Input integer:");
    scanf("%d", &i);

    printf("input float:");
    scanf("%f", &f);

    printf("input character:");
    scanf(" %c", &c);



    printf("Integer:\t%d\nFloat:\t\t%f\nChar:\t\t%c\n", i, f, c);



    return 0;
}
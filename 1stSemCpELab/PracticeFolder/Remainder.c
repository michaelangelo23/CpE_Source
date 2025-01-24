/*
This code's purpose is to divide a number and include the remainder in the output.
-- This project is good for understanding how to use operators.
*/
#include <stdio.h>=

int main() {

    unsigned int inputNum = 0;
    float result;

    scanf("%d", &inputNum);

    result = (float)inputNum / 3;

    printf("%.2f", result);

    return 0;
}
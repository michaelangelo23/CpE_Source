#include <stdio.h>

#define VOWEL "A E I O U" // Defined Constant

int main() {

    const char evenNum[] = "2 4 6 8"; // Memory Constant
    char oddNum[] = "1 3 5 7 9"; // Literal Constant

    printf("VOWELS:\t%s\n", VOWEL);
    printf("EVEN:\t%s\n", evenNum);
    printf("ODD:\t%s\n", oddNum);


    return 0;
}
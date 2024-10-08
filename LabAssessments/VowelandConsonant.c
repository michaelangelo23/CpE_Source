/*
============================================================================
FILE : 6_12.c
AUTHOR : Mickel Angelo Castroverde
DESCRIPTION : Vowel and Consonant; adding bool isLetter and boo isVowel in the code
COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.
REVISION HISTORY
|Date: 10-08-24 |By: Mickel Angelo Castroverde |Description: finished and commented the code
============================================================================
*/
#include <stdio.h>
#include <stdbool.h>

bool isLetter(char ch); // function prototypes for isLetter and isVowel
bool isVowel(char ch);

int main()
{
    char letter;

    // Asks for a letter
    printf("Enter a letter: ");
    scanf("%c", &letter);

    bool isALetter = isLetter(letter);
    bool isAVowel = isVowel(letter);

    if (isALetter)
    {
        if (isAVowel)
        {
            printf("VOWEL!");
        }
        else
        {
            printf("CONSONANT!");
        }
    }
    else
    {
        printf("INVALID INPUT!");
    }
    return 0;
}


bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}


bool isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') || (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

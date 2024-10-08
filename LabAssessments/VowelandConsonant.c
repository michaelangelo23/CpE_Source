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
#include <math.h>
#include <stdbool.h>

bool isLetter(char ch); // function prototype for isLetter and isVowel
bool isVowel(char ch); 


int main() // main function
{
    char letter;    

    printf("Enter a letter: "); // Asks for a letter

    scanf("%c", &letter);

    bool vowel = isVowel(letter);   // checks if the input is a vowel
    bool letter = isLetter(letter); // checks if the input is a letter
    
    if (letter) // if the input is a letter
    {
        if (vowel) // if input is a vowel
        {
            printf("VOWEL!", letter);
        }
        else
        {
            printf("CONSONANT!", letter);
        }
    }
    else // if the input is not a letter
    {
        printf("INVALID INPUT!", letter);
    }
    return 0;
}

bool isVowel(char ch) // function to check if the input is a letter
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') || (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

bool isLetter(char ch) // function to check if the input is a letter
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}




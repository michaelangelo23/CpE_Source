/*
============================================================================
FILE : LE8_11.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :

                            Days of the Week

Write a function that sets up an array called days, which contains pointers to
the names of the days of the week and return the name of the day from the given day.
The function accepts the given day.


      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-22-24 By: Mickel Angelo Castroverde
Description: Finished and verified the code for errors. Improvised and also applied
modularization.
============================================================================
*/

#include <stdio.h>

char* getDayOfWeek(int day); // protoype of the function

int main()
{
    int day;
    printf("Enter day: "); // prompts the user to enter a day
    scanf("%d", &day);
    
    char *dayName = getDayOfWeek(day); // gets the day name

    printf("Day of the week: %s\n", dayName); // prints the day name
    
    return 0;
}

char* getDayOfWeek(int day) // function to get the day of the week
{
    char *days[] = {  // array of day names, array 0 is invalid :)
        "INVALID", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
        };
    
    if (day < 1 || day > 7) // checks if the day is valid or within 1-7
    {
        return days[0]; // returns invalid if not
    }
    
    return *(days + day); // returns the day name
}



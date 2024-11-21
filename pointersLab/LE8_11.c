#include <stdio.h>

char* getDayName(int day);

int main()
{
    int day;
    printf("Enter day: ");
    scanf("%d", &day);
    printf("Day of the week: %s\n", getDayName(day));
    return 0;
}

char* getDayName(int day)
{
    char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    char** ptr = (char**)days;

    if (day >= 1 && day <= 7)
    {
        return *(ptr + (day - 1));
    }
    else
    {
        return "INVALID";
    }
}
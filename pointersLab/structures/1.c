#include <stdio.h>

struct book {
    char title[100];
    char author[100];
    int year;    
};

int main () { 
    
    struct book s1[5];
    int i;
    
    for (i = 0; i < 5; i++)
    {
        printf("put title here: ");
        gets(s1[i].title);
        printf("put author here: ");
        gets(s1[i].author);
        printf("put year here: ");
        scanf("%d", &s1[i].year);
        printf("\n");
    }

    printf("\n\nHere are the books in order ^_^\n");

    for (i = 0; i < 5; i++) {
        printf("Title: %s\n", s1[i].title);
        printf("Author: %s\n", s1[i].author);
        printf("Year: %d\n\n", s1[i].year);
    }

    return 0;
}
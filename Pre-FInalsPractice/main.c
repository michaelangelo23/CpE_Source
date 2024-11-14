/*
============================================================================
FILE : mockPreFinals2.c
AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :
                        MOCK EXAM 2 PRE-FINALS

      COPYRIGHT : © 2024 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-12-24 By: Mickel Angelo Castroverde
Description: 
============================================================================
*/
#include <stdio.h>

// Function prototypes
int askInputStudent();
float calcFinalGrade(float quiz, float labExercise, float me, float fe);
void classifyPassFailed(float finalGrade);
void classifyStudent(float finalGrade);

int main()
{
    int numStudents = askInputStudent();
    for (int i = 0; i < numStudents; i++)
    {
        float quiz, labExercise, me, fe;

        printf("Enter grade for student %d (Quiz): ", i + 1);
        scanf("%f", &quiz);

        printf("Enter grade for student %d (Lab Exercises): ", i + 1);
        scanf("%f", &labExercise);

        printf("Enter grade for student %d (ME): ", i + 1);
        scanf("%f", &me);

        printf("Enter grade for student %d (FE): ", i + 1);
        scanf("%f", &fe);
        
        float finalGrade = calcFinalGrade(quiz, labExercise, me, fe);

        classifyPassFailed(finalGrade);
        classifyStudent(finalGrade);
    }
    return 0;
}

int askInputStudent()
{
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    return numStudents;
}

float calcFinalGrade(float quiz, float labExercise, float me, float fe)
{
    return (0.15 * quiz) + (0.15 * labExercise) + (0.35 * me) + (0.35 * fe);
}

void classifyPassFailed(float finalGrade)
{
    if (finalGrade <= 3.0) {
        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }
}

void classifyStudent(float finalGrade)
{
    if (finalGrade >= 1.0 && finalGrade <= 1.5) {
        printf("EXPERT\n");
    }
    else if (finalGrade >= 1.6 && finalGrade <= 2.0) 
    {
        printf("COMPETENT\n");
    }
    else if (finalGrade >= 2.1 && finalGrade <= 2.5)
    {
        printf("NOVICE\n");
    }
    else
    {
        printf("BEGINNER\n");
    }
}
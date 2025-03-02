/*
============================================================================
FILE : Exercise1.3_castroverdeMickelAngelo.c

AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :
                            Exercise1.3

Create a program with 2 objects (structs), one an element of the other. Ask
the user how many of the first object to create, and how many of the second
object to create for each instance of the first object. After that, display
all objects.

Use typedef to define the structs, and use malloc to dynamically create both
arrays of objects.

Example: First object: Library; Second object: Book - here, Book is an element
of Library.

Sample output:

How many libraries to create? 1

Enter Name of Library: Main Library
Enter Name of Manager: John Santos

How many books to create for Main Library? 2

Enter Title of Book 1: Harry Potter 1
Enter Author of Book 1: JK Rowling
Enter Title of Book 2: Harry Potter 2
Enter Author of Book 2: JK Rowling

Displaying Libraries and their Books...

Main Library (managed by John Santos):
Harry Potter 1, JK Rowling
Harry Potter 2, JK Rowling

      COPYRIGHT : © 2025 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 11-05-24 By: Mickel Angelo Castroverde
Description:
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    int idNumber;
} Student;

typedef struct
{
    char name[100];
    char instructor[100];
    int studentCount;
    Student *students;
} Course;

void getCourseName(Course *course);
void getInstructorName(Course *course);
void getStudentDetails(Course *course);
void displayCourses(Course *courses, int courseCount);

int main()
{
    int courseCount;
    printf("How many courses to create? ");
    scanf("%d", &courseCount);
    getchar();

    Course *courses = (Course *)malloc(courseCount * sizeof(Course));

    for (int i = 0; i < courseCount; i++)
    {
        getCourseName(&courses[i]);
        getInstructorName(&courses[i]);
        getStudentDetails(&courses[i]);
    }

    displayCourses(courses, courseCount);

    for (int i = 0; i < courseCount; i++)
    {
        free(courses[i].students);
    }
    free(courses);

    return 0;
}

void getCourseName(Course *course)
{
    printf("Enter Name of Course: ");
    fgets(course->name, 100, stdin);
    for (int j = 0; course->name[j] != '\0'; j++)
    {
        if (course->name[j] == '\n')
        {
            course->name[j] = '\0';
            break;
        }
    }
}

void getInstructorName(Course *course)
{
    printf("Enter Name of Instructor: ");
    fgets(course->instructor, 100, stdin);
    for (int j = 0; course->instructor[j] != '\0'; j++)
    {
        if (course->instructor[j] == '\n')
        {
            course->instructor[j] = '\0';
            break;
        }
    }
}

void getStudentDetails(Course *course) {
    printf("How many students to create for %s? ", course->name);
    scanf("%d", &course->studentCount);
    getchar();

    course->students = (Student *)malloc(course->studentCount * sizeof(Student));

    for (int j = 0; j < course->studentCount; j++)
    {
        printf("Enter Name of Student %d: ", j + 1);
        fgets(course->students[j].name, 100, stdin);
        for (int k = 0; course->students[j].name[k] != '\0'; k++)
        {
            if (course->students[j].name[k] == '\n')
            {
                course->students[j].name[k] = '\0';
                break;
            }
        }

        printf("Enter ID Number of Student %d: ", j + 1);
        scanf("%d", &course->students[j].idNumber);
        getchar();
    }
}

void displayCourses(Course *courses, int courseCount)
{
    printf("\nDisplaying Courses and their Students...\n\n");

    for (int i = 0; i < courseCount; i++)
    {
        printf("%s (managed by %s):\n", courses[i].name, courses[i].instructor);
        for (int j = 0; j < courses[i].studentCount; j++)
        {
            printf("%s, %d\n", courses[i].students[j].name, courses[i].students[j].idNumber);
        }
        printf("\n");
    }
}

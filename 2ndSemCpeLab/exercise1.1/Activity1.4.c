/*
============================================================================
FILE : Exercise1.4_castroverdeMickelAngelo.c

AUTHOR : Mickel Angelo Castroverde

DESCRIPTION :
                            Exercise1.4

Modify your program from Exercise 1.3 to add file handling capabilities.
The program should:

Load Previous Data (If Available)

When the program starts, check if a .txt file exists.
If the file exists, read its contents and load the stored objects into
your program's arrays.

Allow User Input

Continue running as before, allowing the user to add more objects.
Save Data Before Exiting

Before the program terminates, write all objects (both previously loaded and
newly added) to the .txt file.

Ensure that the file maintains a growing record of all objects across multiple
program executions.

Hint: you can use these functions: fopen(), fclose(), strtok(), fprintf(), fgets(), fscanf()

      COPYRIGHT : © 2025 Mickel Angelo Castroverde. All rights reserved.

----------------------------REVISION HISTORY--------------------------------
Date: 02-17-25 By: Mickel Angelo Castroverde
Description:
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "courses.txt"  // defined file name
#define MAX_LENGTH 100

typedef struct {  // structure for student data
    char name[MAX_LENGTH];
    int idNumber;
} Student;

typedef struct {     // structure for course data
    char name[MAX_LENGTH];
    char instructor[MAX_LENGTH];
    int studentCount;
    Student *students;
} Course;

void loadFromFile(Course **courses, int *courseCount); // function prototypes for handling the file "courses.txt"
void saveToFile(Course *courses, int courseCount);
void displayFileContents(void);

void getCourseName(Course *course); // function prototypes for data input and display
void getInstructorName(Course *course);
void getStudentDetails(Course *course);
void displayCourses(Course *courses, int courseCount);

void cleanupMemory(Course *courses, int courseCount); // function prototypes for memory management and string handling
void removeLine(char *str);

int main(void) // main function starts here //
{
    Course *courses = NULL;
    int courseCount = 0, newCourseCount, totalCourses;

    printf("Current file contents:\n=====================\n");  // display the existing data from the file
    displayFileContents();                                      // or display contents of the file
    printf("=====================\n\n");

    loadFromFile(&courses, &courseCount);                       // load contents from file

    printf("\nHow many new courses to create? ");               // get number of course to add
    scanf("%d", &newCourseCount);
    getchar();

    totalCourses = courseCount + newCourseCount;                // calculate total courses and reallocate memory
    courses = (Course *)realloc(courses, totalCourses * sizeof(Course));

    for (int i = courseCount; i < totalCourses; i++)             // input new course data
    {
        getCourseName(&courses[i]);
        getInstructorName(&courses[i]);
        getStudentDetails(&courses[i]);
    }

    displayCourses(courses, totalCourses);              // display all courses and save to file
    saveToFile(courses, totalCourses);
    cleanupMemory(courses, totalCourses);

    return 0;
}

void displayFileContents(void)          // display the current contents of the courses file
{
    FILE *file = fopen(FILENAME, "r");
    if (!file)
    {
        printf("No existing data.\n");
        return;
    }

    char line[MAX_LENGTH * 2];                  // read and display file contents line by line
    while (fgets(line, sizeof(line), file))
        printf("%s", line);

    fclose(file);
}

void loadFromFile(Course **courses, int *courseCount)  // load existing course data from file into memory
{
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        *courseCount = 0;
        return;
    }

    char line[MAX_LENGTH * 2], *token;   // read course count and allocate memory
    fgets(line, sizeof(line), file);
    *courseCount = atoi(line);

    *courses = (Course *)malloc(*courseCount * sizeof(Course));

    for (int i = 0; i < *courseCount; i++)       // read course and student data
    {
        fgets(line, sizeof(line), file);         // parse course information
        removeLine(line);

        token = strtok(line, ",");
        strcpy((*courses)[i].name, token);

        token = strtok(NULL, ",");
        strcpy((*courses)[i].instructor, token);

        token = strtok(NULL, ",");
        (*courses)[i].studentCount = atoi(token);

        (*courses)[i].students = (Student *)malloc((*courses)[i].studentCount * sizeof(Student));  // parse course information

        fgets(line, sizeof(line), file);
        removeLine(line);

        token = strtok(line, ",");
        for (int j = 0; j < (*courses)[i].studentCount; j++)
        {
            strcpy((*courses)[i].students[j].name, token);
            token = strtok(NULL, ",");
            (*courses)[i].students[j].idNumber = atoi(token);
            token = strtok(NULL, ",");
        }
    }

    fclose(file);
}

void saveToFile(Course *courses, int courseCount) // saves data to file
{
    FILE *file = fopen(FILENAME, "w");
    if (!file) return;

    fprintf(file, "%d\n", courseCount); // write number of courses

    for (int i = 0; i < courseCount; i++) // write student data
    {
        fprintf(file, "%s,%s,%d\n", courses[i].name, courses[i].instructor, courses[i].studentCount);

        for (int j = 0; j < courses[i].studentCount; j++)
        {
            fprintf(file, "%s,%d%s",
                courses[i].students[j].name,
                courses[i].students[j].idNumber,
                j < courses[i].studentCount - 1 ? "," : "\n");
        }
    }

    fclose(file);
}

void getCourseName(Course *course) // gets course name
{
    printf("Enter Name of Course: ");
    fgets(course->name, MAX_LENGTH, stdin);
    removeLine(course->name);
}

void getInstructorName(Course *course) // gets instructor name
{
    printf("Enter Name of Instructor: ");
    fgets(course->instructor, MAX_LENGTH, stdin);
    removeLine(course->instructor);
}

void getStudentDetails(Course *course)  // gets student details
{
    printf("How many students to create for %s? ", course->name);
    scanf("%d", &course->studentCount);
    getchar();

    course->students = (Student *)malloc(course->studentCount * sizeof(Student)); // allocate memory for students and get details

    for (int j = 0; j < course->studentCount; j++)
    {
        printf("Enter Name of Student %d: ", j + 1);
        fgets(course->students[j].name, MAX_LENGTH, stdin);
        removeLine(course->students[j].name);

        printf("Enter ID Number of Student %d: ", j + 1);
        scanf("%d", &course->students[j].idNumber);
        getchar();
    }
}

void displayCourses(Course *courses, int courseCount) // displays all courses and students
{
    printf("\nDisplaying Courses and Students...\n\n");

    for (int i = 0; i < courseCount; i++) {
        printf("%s (managed by %s):\n", courses[i].name, courses[i].instructor);
        for (int j = 0; j < courses[i].studentCount; j++)
            printf("%s, %d\n", courses[i].students[j].name, courses[i].students[j].idNumber);
        printf("\n");
    }
}

void cleanupMemory(Course *courses, int courseCount) // frees memory
{
    for (int i = 0; i < courseCount; i++)
        free(courses[i].students);
    free(courses);
}

void removeLine(char *str) // removes newline character from string
{
    str[strcspn(str, "\n")] = 0;
}
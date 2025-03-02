#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define AllocFailed "Memory allocation failed.\n"

typedef struct
{
    char fullName[100];
    int studentID;
} Student;

typedef struct
{
    char courseName[100];
    int enrolledStudentCount;
    Student *enrolledStudents;
} Course;

typedef struct CourseNode
{
    Course courseData;
    struct CourseNode *previous;
    struct CourseNode *next;
} CourseNode;

typedef struct
{
    CourseNode *head;
    CourseNode *tail;
    int length;
} CourseLinkedList;

void inputCourseName(Course *currentCourse);
void inputStudentDetails(Course *currentCourse);
void displayCourse(Course *currentCourse);
void displayAllCourses(Course *courseArray, int totalCourses);
void clearInputBuffer();
void clearScreen();
Course createCourse();
void freeCourseData(Course* course);

CourseLinkedList* createEmptyCourseList();
void addCourseAtFront(CourseLinkedList *courseList, Course newCourse);
void addCourseAtEnd(CourseLinkedList *courseList, Course newCourse);
void displayCoursesForward(CourseLinkedList *courseList);
void displayCoursesBackward(CourseLinkedList *courseList);
void insertCourseAtPosition(CourseLinkedList *courseList, int position, Course newCourse);
void deleteCourseAtPosition(CourseLinkedList *courseList, int position);
void updateCourseAtPosition(CourseLinkedList *courseList, int position, Course updatedCourse);
void destroyCourseList(CourseLinkedList *courseList);
void manageCourseLinkedList(CourseLinkedList *courseList);

int main()
{
    int userChoice;
    CourseLinkedList *courseList = createEmptyCourseList();

    do
    {
        clearScreen();
        printf("Choose operation:\n");
        printf("1. Create and Manage Courses and Students\n");
        printf("2. Manage Course List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        clearInputBuffer();

        switch (userChoice)
        {
            case 1:
            {
                clearScreen();
                int totalCourses;
                printf("How many courses to create? ");
                scanf("%d", &totalCourses);
                clearInputBuffer();

                if (totalCourses <= 0)
                {
                    printf("Invalid number of courses.\n");
                    printf("Press Enter to continue..");
                    getchar();
                    break;
                }

                Course *courseArray = (Course *)malloc(totalCourses * sizeof(Course));

                if (courseArray == NULL)
                {
                    printf(AllocFailed);
                    printf("Press Enter to continue..");
                    getchar();
                    break;
                }

                for (int courseIndex = 0; courseIndex < totalCourses; courseIndex++)
                {
                    clearScreen();
                    inputCourseName(&courseArray[courseIndex]);
                    inputStudentDetails(&courseArray[courseIndex]);
                }

                clearScreen();
                displayAllCourses(courseArray, totalCourses);

                // add courses to list
                for (int courseIndex = 0; courseIndex < totalCourses; courseIndex++)
                {
                    addCourseAtEnd(courseList, courseArray[courseIndex]);
                }

                // free the array not the course data
                free(courseArray);

                printf("\nPress Enter to continue..");
                getchar();
                break;
            }

            case 2:
                clearScreen();
                manageCourseLinkedList(courseList);
                break;

            case 0:
                clearScreen();
                printf("Exiting program.\n");
                destroyCourseList(courseList);
                break;

            default:
                printf("Invalid choice.\n");
                printf("Press Enter to continue..");
                getchar();
        }
    }
    while (userChoice != 0);

    return 0;
}

void clearInputBuffer() // got this before from chatgpt on capturing character constant \n
{
    int character;
    while ((character = getchar()) != '\n');
}

void clearScreen()
{
    system("cls");
}

void trimNewline(char* str)
{
    char* newline = strchr(str, '\n');
    if (newline) {
        *newline = '\0';
    }
}

// course and student functions
void inputCourseName(Course *currentCourse)
{
    printf("Enter Name of Course: ");
    fgets(currentCourse->courseName, 100, stdin);
    trimNewline(currentCourse->courseName);
}

void inputStudentDetails(Course *currentCourse)
{
    printf("How many students to create for %s? ", currentCourse->courseName);
    scanf("%d", &currentCourse->enrolledStudentCount);
    clearInputBuffer();

    if (currentCourse->enrolledStudentCount <= 0)
    {
        printf("Invalid number of students, setting to 0.\n");
        currentCourse->enrolledStudentCount = 0;
        currentCourse->enrolledStudents = NULL;
        return;
    }

    currentCourse->enrolledStudents = (Student *)malloc(currentCourse->enrolledStudentCount * sizeof(Student));

    if (currentCourse->enrolledStudents == NULL)
    {
        printf(AllocFailed);
        printf("Setting count to 0.\n"); // to know where the failed alloc is at
        currentCourse->enrolledStudentCount = 0;
        return;
    }

    for (int studentIndex = 0; studentIndex < currentCourse->enrolledStudentCount; studentIndex++)
    {
        printf("Enter Name of Student %d: ", studentIndex + 1);
        fgets(currentCourse->enrolledStudents[studentIndex].fullName, 100, stdin);
        trimNewline(currentCourse->enrolledStudents[studentIndex].fullName);

        printf("Enter ID Number of Student %d: ", studentIndex + 1);
        scanf("%d", &currentCourse->enrolledStudents[studentIndex].studentID);
        clearInputBuffer();
    }
}

void displayCourse(Course *currentCourse)
{
    printf("Course: %s\n", currentCourse->courseName);
    printf("Enrolled Students:\n");

    if (currentCourse->enrolledStudentCount == 0)
    {
        printf("  No students enrolled.\n");
    }
    else
    {
        for (int studentIndex = 0; studentIndex < currentCourse->enrolledStudentCount; studentIndex++)
        {
            printf("  %d. %s (ID: %d)\n", studentIndex + 1,
                   currentCourse->enrolledStudents[studentIndex].fullName,
                   currentCourse->enrolledStudents[studentIndex].studentID);
        }
    }

    printf("\n");
}

void displayAllCourses(Course *courseArray, int totalCourses)
{
    for (int courseIndex = 0; courseIndex < totalCourses; courseIndex++)
    {
        displayCourse(&courseArray[courseIndex]);
    }
}

Course createCourse()
{
    Course newCourse;

    inputCourseName(&newCourse);
    inputStudentDetails(&newCourse);

    return newCourse;
}

void freeCourseData(Course* course)
{
    if (course != NULL && course->enrolledStudents != NULL)
    {
        free(course->enrolledStudents);
        course->enrolledStudents = NULL;
    }
}

void copyCourseToNode(CourseNode *node, Course *course)
{
    strcpy(node->courseData.courseName, course->courseName);
    node->courseData.enrolledStudentCount = course->enrolledStudentCount;

    if (course->enrolledStudentCount > 0)
    {
        node->courseData.enrolledStudents = (Student*)malloc(course->enrolledStudentCount * sizeof(Student));
        if (node->courseData.enrolledStudents == NULL)
        {
            printf(AllocFailed);
            node->courseData.enrolledStudentCount = 0;
            return;
        }

        // copy of all students
        for (int studentIndex = 0; studentIndex < course->enrolledStudentCount; studentIndex++)
        {
            strcpy(node->courseData.enrolledStudents[studentIndex].fullName, course->enrolledStudents[studentIndex].fullName);
            node->courseData.enrolledStudents[studentIndex].studentID = course->enrolledStudents[studentIndex].studentID;
        }
    }
    else
    {
        node->courseData.enrolledStudents = NULL;
    }
}

// linked list functions
CourseLinkedList* createEmptyCourseList()
{
    CourseLinkedList *newList = (CourseLinkedList*)malloc(sizeof(CourseLinkedList));
    if (newList == NULL)
    {
        printf(AllocFailed);
        exit(1);
    }
    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;
    return newList;
}

void addCourseAtFront(CourseLinkedList *courseList, Course newCourse)
{
    CourseNode *newNode = (CourseNode*)malloc(sizeof(CourseNode));
    if (newNode == NULL)
    {
        printf(AllocFailed);
        return;
    }

    // copy course data to node
    copyCourseToNode(newNode, &newCourse);
    newNode->previous = NULL;

    if (courseList->head == NULL)
    {
        // if list is empty
        newNode->next = NULL;
        courseList->head = newNode;
        courseList->tail = newNode;
    }
    else
    {
        // if list is not empty
        newNode->next = courseList->head;
        courseList->head->previous = newNode;
        courseList->head = newNode;
    }

    courseList->length++;
    printf("Course '%s' added at the front.\n", newCourse.courseName);
}

void addCourseAtEnd(CourseLinkedList *courseList, Course newCourse)
{
    CourseNode *newNode = (CourseNode*)malloc(sizeof(CourseNode));
    if (newNode == NULL)
    {
        printf(AllocFailed);
        return;
    }

    // copy course data to node
    copyCourseToNode(newNode, &newCourse);
    newNode->next = NULL;

    if (courseList->head == NULL)
    {
        // if list is empty
        newNode->previous = NULL;
        courseList->head = newNode;
        courseList->tail = newNode;
    }
    else
    {
        // if list is not empty
        newNode->previous = courseList->tail;
        courseList->tail->next = newNode;
        courseList->tail = newNode;
    }

    courseList->length++;
    printf("Course '%s' added at the end.\n", newCourse.courseName);
}

void displayCoursesForward(CourseLinkedList *courseList)
{
    if (courseList->head == NULL)
    {
        printf("Course list is empty.\n");
        return;
    }

    CourseNode *currentNode = courseList->head;
    int position = 1;

    while (currentNode != NULL)
    {
        printf("Position %d:\n", position);
        displayCourse(&currentNode->courseData);
        currentNode = currentNode->next;
        position++;
    }
}

void displayCoursesBackward(CourseLinkedList *courseList)
{
    if (courseList->head == NULL)
    {
        printf("Course list is empty.\n");
        return;
    }

    CourseNode *currentNode = courseList->tail;
    int position = courseList->length;

    while (currentNode != NULL)
    {
        printf("Position %d:\n", position);
        displayCourse(&currentNode->courseData);
        currentNode = currentNode->previous;
        position--;
    }
}

void insertCourseAtPosition(CourseLinkedList *courseList, int position, Course newCourse)
{
    // check position if valid
    if (position < 1 || position > courseList->length + 1)
    {
        printf("Invalid position, should be between 1 and %d.\n", courseList->length + 1);
        return;
    }

    // inserting at the beginning
    if (position == 1)
    {
        addCourseAtFront(courseList, newCourse);
        return;
    }

    //  inserting at the end
    if (position == courseList->length + 1)
    {
        addCourseAtEnd(courseList, newCourse);
        return;
    }

    // inserting in the middle
    CourseNode *newNode = (CourseNode*)malloc(sizeof(CourseNode));
    if (newNode == NULL)
    {
        printf(AllocFailed);
        return;
    }

    // copy course data to node
    copyCourseToNode(newNode, &newCourse);

    // find node at position - 1
    CourseNode *currentNode = courseList->head;
    for (int nodeIndex = 1; nodeIndex < position - 1; nodeIndex++)
    {
        currentNode = currentNode->next;
    }

    // insert new node
    newNode->next = currentNode->next;
    newNode->previous = currentNode;
    currentNode->next->previous = newNode;
    currentNode->next = newNode;

    courseList->length++;
    printf("Course '%s' inserted at position %d.\n", newCourse.courseName, position);
}

void deleteCourseAtPosition(CourseLinkedList *courseList, int position)
{
    // check if list is empty
    if (courseList->head == NULL)
    {
        printf("Course list is empty.\n");
        return;
    }

    // check if position is valid
    if (position < 1 || position > courseList->length)
    {
        printf("Invalid position, should be between 1 and %d.\n", courseList->length);
        return;
    }

    CourseNode *nodeToDelete;

    // removing the first node
    if (position == 1)
    {
        nodeToDelete = courseList->head;

        if (courseList->length == 1)
        {
            // if onl;y one node in the list
            courseList->head = NULL;
            courseList->tail = NULL;
        }
        else
        {
            // if more than one node
            courseList->head = courseList->head->next;
            courseList->head->previous = NULL;
        }
    }
    // removing the last node
    else if (position == courseList->length)
    {
        nodeToDelete = courseList->tail;
        courseList->tail = courseList->tail->previous;
        courseList->tail->next = NULL;
    }

    // removing the middle
    else
    {
        // find node at the position
        nodeToDelete = courseList->head;
        for (int nodeIndex = 1; nodeIndex < position; nodeIndex++)
        {
            nodeToDelete = nodeToDelete->next;
        }

        // update links
        nodeToDelete->previous->next = nodeToDelete->next;
        nodeToDelete->next->previous = nodeToDelete->previous;
    }

    char deletedCourseName[100];
    strcpy(deletedCourseName, nodeToDelete->courseData.courseName);

    // free the array mem
    if (nodeToDelete->courseData.enrolledStudents != NULL)
    {
        free(nodeToDelete->courseData.enrolledStudents);
    }

    // free node mem
    free(nodeToDelete);

    courseList->length--;
    printf("Course '%s' at position %d is removed.\n", deletedCourseName, position);
}

void updateCourseAtPosition(CourseLinkedList *courseList, int position, Course updatedCourse)
{
    // check list if empty
    if (courseList->head == NULL)
    {
        printf("Course list is empty.\n");
        return;
    }

    // check position if valid
    if (position < 1 || position > courseList->length)
    {
        printf("Invalid position, should be between 1 and %d.\n", courseList->length);
        return;
    }

    // find node at pos
    CourseNode *currentNode = courseList->head;
    for (int nodeIndex = 1; nodeIndex < position; nodeIndex++)
    {
        currentNode = currentNode->next;
    }

    char oldCourseName[100];
    strcpy(oldCourseName, currentNode->courseData.courseName);

    // free existing array of students
    if (currentNode->courseData.enrolledStudents != NULL)
    {
        free(currentNode->courseData.enrolledStudents);
    }

    // update with new course data
    copyCourseToNode(currentNode, &updatedCourse);

    printf("Course at position %d updated from '%s' to '%s'.\n", position, oldCourseName, updatedCourse.courseName);
}

void destroyCourseList(CourseLinkedList *courseList)
{
    if (courseList == NULL)
    {
        return;
    }

    CourseNode *currentNode = courseList->head;
    CourseNode *nextNode;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;

        // free students array inside course data
        if (currentNode->courseData.enrolledStudents != NULL)
        {
            free(currentNode->courseData.enrolledStudents);
        }

        // free node
        free(currentNode);
        currentNode = nextNode;
    }

    free(courseList);
    printf("Course list freed.\n");
}

void manageCourseLinkedList(CourseLinkedList *courseList)
{
    int menuChoice, coursePosition;
    Course tempCourse;

    do
    {
        printf("1. Add Course at Front\n");
        printf("2. Add Course at End\n");
        printf("3. Display Courses (Forward)\n");
        printf("4. Display Courses (Backward)\n");
        printf("5. Insert Course at Position\n");
        printf("6. Remove Course at Position\n");
        printf("7. Update Course at Position\n");
        printf("0. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);
        clearInputBuffer();

        switch (menuChoice)
        {
            case 1: // add at front
                clearScreen();
                tempCourse = createCourse();
                addCourseAtFront(courseList, tempCourse);

                // free temp course's student data
                if (tempCourse.enrolledStudents != NULL)
                {
                    free(tempCourse.enrolledStudents);
                }
                break;

            case 2: // add at end
                clearScreen();
                tempCourse = createCourse();
                addCourseAtEnd(courseList, tempCourse);

                // free temp course's student data
                if (tempCourse.enrolledStudents != NULL)
                {
                    free(tempCourse.enrolledStudents);
                }
                break;

            case 3: // display regularly
                displayCoursesForward(courseList);
                break;

            case 4: // display in reverse
                displayCoursesBackward(courseList);
                break;

            case 5: //insert at pos
                printf("Enter position to insert (1 to %d): ", courseList->length + 1);
                scanf("%d", &coursePosition);
                clearInputBuffer();
                clearScreen();
                tempCourse = createCourse();
                insertCourseAtPosition(courseList, coursePosition, tempCourse);

                // free temp course's student data
                if (tempCourse.enrolledStudents != NULL)
                {
                    free(tempCourse.enrolledStudents);
                }
                break;

            case 6:
                printf("Enter position to remove (1 to %d): ", courseList->length);
                scanf("%d", &coursePosition);
                clearInputBuffer();
                deleteCourseAtPosition(courseList, coursePosition);
                break;

            case 7:
                printf("Enter position to update (1 to %d): ", courseList->length);
                scanf("%d", &coursePosition);
                clearInputBuffer();
                clearScreen();
                tempCourse = createCourse();
                updateCourseAtPosition(courseList, coursePosition, tempCourse);

                if (tempCourse.enrolledStudents != NULL)
                {
                    free(tempCourse.enrolledStudents);
                }
                break;

            case 0: // return to menu
                printf("Returning to Main Menu.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

        if (menuChoice != 0)
        {
            printf("\nPress Enter to continue..");
            getchar();
            clearScreen();
        }
    }
    while (menuChoice != 0);
}

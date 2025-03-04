#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX 100
#define AllocFailed "Memory allocation failed.\n"

typedef struct
{
    char fullName[MAX];
    int studentID;
} Student;

typedef struct
{
    char courseName[MAX];
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


// activity 2.2 added functions
void makeNull(CourseLinkedList *courseList);
CourseNode* first(CourseLinkedList *courseList);
CourseNode* last(CourseLinkedList *courseList);
CourseNode* retrieve(CourseLinkedList *courseList, int position);
CourseNode* search(CourseLinkedList *courseList, const char *searchTerm);
int empty(CourseLinkedList *courseList);
void addedListOperations(CourseLinkedList *courseList);
void trimNewline(char* str);
CourseNode* getNode(CourseLinkedList *courseList, int first);

int main()
{
    int userChoice;
    CourseLinkedList *courseList = createEmptyCourseList();

    do
    {
        printf("Choose operation:\n");
        printf("1. Create and Manage Courses and Students\n");
        printf("2. Manage Course List\n");
        printf("3. Added List Operation\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        clearInputBuffer();

        switch (userChoice)
        {
            case 1:
            {
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
                    inputCourseName(&courseArray[courseIndex]);
                    inputStudentDetails(&courseArray[courseIndex]);
                }

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
                manageCourseLinkedList(courseList);
                break;

            case 3:
                addedListOperations(courseList);
                break;

            case 0:
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

void clearInputBuffer()
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

void inputCourseName(Course *currentCourse)
{
    printf("Enter Name of Course: ");
    fgets(currentCourse->courseName, MAX, stdin);
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
        printf("Setting count to 0.\n");
        currentCourse->enrolledStudentCount = 0;
        return;
    }

    for (int studentIndex = 0; studentIndex < currentCourse->enrolledStudentCount; studentIndex++)
    {
        printf("Enter Name of Student %d: ", studentIndex + 1);
        fgets(currentCourse->enrolledStudents[studentIndex].fullName, MAX, stdin);
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
    node->courseData = *course; // Shallow copy
    node->courseData.enrolledStudents = course->enrolledStudents; // Share the student data
}

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

void addCourse(CourseLinkedList *courseList, Course newCourse, int atFront)
{
    CourseNode *newNode = (CourseNode*)malloc(sizeof(CourseNode));
    if (newNode == NULL)
    {
        printf(AllocFailed);
        return;
    }

    copyCourseToNode(newNode, &newCourse);
    newNode->previous = NULL;
    newNode->next = NULL;

    if (courseList->head == NULL)
    {
        courseList->head = newNode;
        courseList->tail = newNode;
    }
    else if (atFront)
    {
        newNode->next = courseList->head;
        courseList->head->previous = newNode;
        courseList->head = newNode;
    }
    else
    {
        newNode->previous = courseList->tail;
        courseList->tail->next = newNode;
        courseList->tail = newNode;
    }

    courseList->length++;
    printf("Course '%s' added at the %s.\n", newCourse.courseName, atFront ? "front" : "end");
}

void addCourseAtFront(CourseLinkedList *courseList, Course newCourse)
{
    addCourse(courseList, newCourse, 1);
}

void addCourseAtEnd(CourseLinkedList *courseList, Course newCourse)
{
    addCourse(courseList, newCourse, 0);
}

void displayCourses(CourseLinkedList *courseList, int forward)
{
    if (courseList->head == NULL)
    {
        printf("Course list is empty.\n");
        return;
    }

    CourseNode *currentNode = forward ? courseList->head : courseList->tail;
    int position = forward ? 1 : courseList->length;

    while (currentNode != NULL)
    {
        printf("Position %d:\n", position);
        displayCourse(&currentNode->courseData);
        currentNode = forward ? currentNode->next : currentNode->previous;
        position += forward ? 1 : -1;
    }
}

void displayCoursesForward(CourseLinkedList *courseList)
{
    displayCourses(courseList, 1);
}

void displayCoursesBackward(CourseLinkedList *courseList)
{
    displayCourses(courseList, 0);
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
            // if only one node in the list
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

    char deletedCourseName[MAX];
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
            case 1:
                tempCourse = createCourse();
                addCourse(courseList, tempCourse, 1);
                free(tempCourse.enrolledStudents);
                break;

            case 2:
                tempCourse = createCourse();
                addCourse(courseList, tempCourse, 0);
                free(tempCourse.enrolledStudents);
                break;

            case 3:
                displayCourses(courseList, 1);
                break;

            case 4:
                displayCourses(courseList, 0);
                break;

            case 5:
                printf("Enter position to insert (1 to %d): ", courseList->length + 1);
                scanf("%d", &coursePosition);
                clearInputBuffer();
                tempCourse = createCourse();
                insertCourseAtPosition(courseList, coursePosition, tempCourse);
                free(tempCourse.enrolledStudents);
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
                tempCourse = createCourse();
                updateCourseAtPosition(courseList, coursePosition, tempCourse);
                free(tempCourse.enrolledStudents);
                break;

            case 0:
                printf("Returning to Main Menu.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

        if (menuChoice != 0)
        {
            printf("\nPress Enter to continue..");
            getchar();
        }
    }
    while (menuChoice != 0);
}

// added list functions for 2.2
void makeNull(CourseLinkedList *courseList)
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

        // free students array inside the course data
        if (currentNode->courseData.enrolledStudents != NULL)
        {
            free(currentNode->courseData.enrolledStudents);
        }

        // freeing the node
        free(currentNode);
        currentNode = nextNode;
    }

    // assigning the node to NULL
    courseList->head = NULL;
    courseList->tail = NULL;
    courseList->length = 0;

    printf("Course list has been made empty.\n");
}

CourseNode* first(CourseLinkedList *courseList)
{
    if (courseList == NULL || courseList->head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    return courseList->head;
}

CourseNode* last(CourseLinkedList *courseList)
{
    if (courseList == NULL || courseList->tail == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    return courseList->tail;
}

CourseNode* retrieve(CourseLinkedList *courseList, int position)
{
    // check if list is NULL or empty or the pos is valid
    if (courseList == NULL || courseList->head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (position < 1 || position > courseList->length)
    {
        printf("Invalid position. Should be between 1 and %d.\n", courseList->length);
        return NULL;
    }

    // find node at a specific pos
    CourseNode *currentNode = courseList->head;
    for (int nodeIndex = 1; nodeIndex < position; nodeIndex++)
    {
        currentNode = currentNode->next;
    }

    return currentNode;
}

CourseNode* search(CourseLinkedList *courseList, const char *searchTerm)
{
    if (courseList == NULL || courseList->head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    CourseNode *currentNode = courseList->head;
    while (currentNode != NULL)
    {
        // search course name
        if (strcmpi(currentNode->courseData.courseName, searchTerm) == 0)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
    }

    printf("No course found with name '%s'.\n", searchTerm);
    return NULL;
}

int empty(CourseLinkedList *courseList)
{
    return (courseList == NULL || courseList->head == NULL) ? 1 : 0; // ternary operator to make the code short
}

void addedListOperations(CourseLinkedList *courseList)
{
    int menuChoice;
    char searchTerm[MAX];
    int position;
    CourseNode *foundNode;

    do
    {
        printf("Added List Operations:\n");
        printf("1. Make List Null (Empty)\n");
        printf("2. Get First Node\n");
        printf("3. Get Last Node\n");
        printf("4. Retrieve Node at Position\n");
        printf("5. Search Course by Name\n");
        printf("6. Check if List is Empty\n");
        printf("0. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);
        clearInputBuffer();

        switch (menuChoice)
        {
            case 1: // make the list null
                makeNull(courseList);
                break;

            case 2: // first node
                foundNode = first(courseList);
                if (foundNode != NULL)
                {
                    printf("First Course:\n");
                    displayCourse(&foundNode->courseData);
                }
                break;

            case 3: // last node
                foundNode = last(courseList);
                if (foundNode != NULL)
                {
                    printf("Last Course:\n");
                    displayCourse(&foundNode->courseData);
                }
                break;

            case 4: // retrieve node at pos
                printf("Enter position to retrieve (1 to %d): ", courseList->length);
                scanf("%d", &position);
                clearInputBuffer();

                foundNode = retrieve(courseList, position);
                if (foundNode != NULL)
                {
                    printf("Course at position %d:\n", position);
                    displayCourse(&foundNode->courseData);
                }
                break;

            case 5: // search term
                printf("Enter course name to search: ");
                fgets(searchTerm, sizeof(searchTerm), stdin);
                trimNewline(searchTerm);

                foundNode = search(courseList, searchTerm);
                if (foundNode != NULL)
                {
                    printf("Course found:\n");
                    displayCourse(&foundNode->courseData);
                }
                break;

            case 6: // checking if empty
                printf("List is %s.\n", empty(courseList) ? "empty" : "not empty");
                printf("Current list length: %d\n", courseList->length);
                break;

            case 0:
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

CourseNode* getNode(CourseLinkedList *courseList, int first)
{
    if (courseList == NULL || courseList->head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    return first ? courseList->head : courseList->tail;
}

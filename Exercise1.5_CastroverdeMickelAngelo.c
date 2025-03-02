#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN_COMMAND "cls"
#else
    #define CLEAR_SCREEN_COMMAND "clear"
#endif

typedef struct {
    char fullName[100];
    int studentID;
} Student;

typedef struct {
    char courseName[100];
    char instructorName[100];
    int enrolledStudentCount;
    Student *enrolledStudents;
} Course;

typedef struct CourseNode {
    Course courseData;
    struct CourseNode *previous;
    struct CourseNode *next;
} CourseNode;

typedef struct {
    CourseNode *head;
    CourseNode *tail;
    int length;
} CourseLinkedList;

void inputCourseName(Course *currentCourse);
void inputInstructorName(Course *currentCourse);
void inputStudentDetails(Course *currentCourse);
void displayCourse(Course *currentCourse);
void displayAllCourses(Course *courseArray, int totalCourses);
void clearInputBuffer();
void clearScreen();
Course createCourse();
Course* copyCourse(Course* sourceCourse);
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
        printf("=== COURSE MANAGEMENT SYSTEM ===\n\n");
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
                    printf("Invalid number of courses!\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                }

                Course *courseArray = (Course *)malloc(totalCourses * sizeof(Course));
                
                if (courseArray == NULL) 
                {
                    printf("Memory allocation failed!\n");
                    printf("Press Enter to continue...");
                    getchar();
                    break;
                }

                for (int courseIndex = 0; courseIndex < totalCourses; courseIndex++) 
                {
                    clearScreen();
                    printf("=== COURSE %d DETAILS ===\n\n", courseIndex + 1);
                    inputCourseName(&courseArray[courseIndex]);
                    inputInstructorName(&courseArray[courseIndex]);
                    inputStudentDetails(&courseArray[courseIndex]);
                }

                clearScreen();
                displayAllCourses(courseArray, totalCourses);

                // add courses to list
                for (int courseIndex = 0; courseIndex < totalCourses; courseIndex++) {
                    addCourseAtEnd(courseList, courseArray[courseIndex]);
                }

                // free the array not the course data 
                free(courseArray);

                printf("\nPress Enter to continue...");
                getchar();
                break;
            }
            
            case 2:
                clearScreen();
                manageCourseLinkedList(courseList);
                break;
                
            case 0:
                clearScreen();
                printf("Exiting program. Goodbye!\n");
                destroyCourseList(courseList);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
                printf("Press Enter to continue...");
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
    system(CLEAR_SCREEN_COMMAND);
}

// course and student functions
void inputCourseName(Course *currentCourse) 
{
    printf("Enter Name of Course: ");
    fgets(currentCourse->courseName, 100, stdin);
    
    for (int charIndex = 0; currentCourse->courseName[charIndex] != '\0'; charIndex++) {
        if (currentCourse->courseName[charIndex] == '\n') {
            currentCourse->courseName[charIndex] = '\0';
            break;
        }
    }
}

void inputInstructorName(Course *currentCourse)
{
    printf("Enter Name of Instructor: ");
    fgets(currentCourse->instructorName, 100, stdin);
    // Remove newline character
    for (int charIndex = 0; currentCourse->instructorName[charIndex] != '\0'; charIndex++) {
        if (currentCourse->instructorName[charIndex] == '\n') {
            currentCourse->instructorName[charIndex] = '\0';
            break;
        }
    }
}

void inputStudentDetails(Course *currentCourse) {
    printf("How many students to create for %s? ", currentCourse->courseName);
    scanf("%d", &currentCourse->enrolledStudentCount);
    clearInputBuffer();

    if (currentCourse->enrolledStudentCount <= 0) {
        printf("Invalid number of students! Setting to 0.\n");
        currentCourse->enrolledStudentCount = 0;
        currentCourse->enrolledStudents = NULL;
        return;
    }

    currentCourse->enrolledStudents = (Student *)malloc(currentCourse->enrolledStudentCount * sizeof(Student));
    if (currentCourse->enrolledStudents == NULL) {
        printf("Memory allocation failed! Setting student count to 0.\n");
        currentCourse->enrolledStudentCount = 0;
        return;
    }

    for (int studentIndex = 0; studentIndex < currentCourse->enrolledStudentCount; studentIndex++) {
        printf("Enter Name of Student %d: ", studentIndex + 1);
        fgets(currentCourse->enrolledStudents[studentIndex].fullName, 100, stdin);
        // Remove newline character
        for (int charIndex = 0; currentCourse->enrolledStudents[studentIndex].fullName[charIndex] != '\0'; charIndex++) {
            if (currentCourse->enrolledStudents[studentIndex].fullName[charIndex] == '\n') {
                currentCourse->enrolledStudents[studentIndex].fullName[charIndex] = '\0';
                break;
            }
        }

        printf("Enter ID Number of Student %d: ", studentIndex + 1);
        scanf("%d", &currentCourse->enrolledStudents[studentIndex].studentID);
        clearInputBuffer();
    }
}

void displayCourse(Course *currentCourse) {
    printf("Course: %s (Instructor: %s)\n", currentCourse->courseName, currentCourse->instructorName);
    printf("Enrolled Students:\n");

    if (currentCourse->enrolledStudentCount == 0) {
        printf("  No students enrolled.\n");
    } else {
        for (int studentIndex = 0; studentIndex < currentCourse->enrolledStudentCount; studentIndex++) {
            printf("  %d. %s (ID: %d)\n", studentIndex + 1,
                   currentCourse->enrolledStudents[studentIndex].fullName,
                   currentCourse->enrolledStudents[studentIndex].studentID);
        }
    }
    printf("\n");
}

void displayAllCourses(Course *courseArray, int totalCourses) {
    printf("=== COURSE INFORMATION ===\n\n");

    for (int courseIndex = 0; courseIndex < totalCourses; courseIndex++) {
        displayCourse(&courseArray[courseIndex]);
    }
}

Course createCourse() {
    Course newCourse;

    inputCourseName(&newCourse);
    inputInstructorName(&newCourse);
    inputStudentDetails(&newCourse);

    return newCourse;
}

Course* copyCourse(Course* sourceCourse) {
    if (sourceCourse == NULL) {
        return NULL;
    }

    Course* newCourse = (Course*)malloc(sizeof(Course));
    if (newCourse == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Copy course name and instructor
    strcpy(newCourse->courseName, sourceCourse->courseName);
    strcpy(newCourse->instructorName, sourceCourse->instructorName);

    // Copy student count
    newCourse->enrolledStudentCount = sourceCourse->enrolledStudentCount;

    // Allocate memory for students and copy them
    if (newCourse->enrolledStudentCount > 0) {
        newCourse->enrolledStudents = (Student*)malloc(newCourse->enrolledStudentCount * sizeof(Student));
        if (newCourse->enrolledStudents == NULL) {
            printf("Memory allocation failed!\n");
            free(newCourse);
            return NULL;
        }

        // Deep copy of all students
        for (int studentIndex = 0; studentIndex < newCourse->enrolledStudentCount; studentIndex++) {
            strcpy(newCourse->enrolledStudents[studentIndex].fullName, sourceCourse->enrolledStudents[studentIndex].fullName);
            newCourse->enrolledStudents[studentIndex].studentID = sourceCourse->enrolledStudents[studentIndex].studentID;
        }
    } else {
        newCourse->enrolledStudents = NULL;
    }

    return newCourse;
}

void freeCourseData(Course* course) {
    if (course != NULL && course->enrolledStudents != NULL) {
        free(course->enrolledStudents);
        course->enrolledStudents = NULL;
    }
}

// Doubly Linked List functions
CourseLinkedList* createEmptyCourseList() {
    CourseLinkedList *newList = (CourseLinkedList*)malloc(sizeof(CourseLinkedList));
    if (newList == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;
    return newList;
}

void addCourseAtFront(CourseLinkedList *courseList, Course newCourse) {
    CourseNode *newNode = (CourseNode*)malloc(sizeof(CourseNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Copy course data to the node
    strcpy(newNode->courseData.courseName, newCourse.courseName);
    strcpy(newNode->courseData.instructorName, newCourse.instructorName);
    newNode->courseData.enrolledStudentCount = newCourse.enrolledStudentCount;

    if (newCourse.enrolledStudentCount > 0) {
        newNode->courseData.enrolledStudents = (Student*)malloc(newCourse.enrolledStudentCount * sizeof(Student));
        if (newNode->courseData.enrolledStudents == NULL) {
            printf("Memory allocation failed!\n");
            free(newNode);
            return;
        }

        // Deep copy of all students
        for (int studentIndex = 0; studentIndex < newCourse.enrolledStudentCount; studentIndex++) {
            strcpy(newNode->courseData.enrolledStudents[studentIndex].fullName, newCourse.enrolledStudents[studentIndex].fullName);
            newNode->courseData.enrolledStudents[studentIndex].studentID = newCourse.enrolledStudents[studentIndex].studentID;
        }
    } else {
        newNode->courseData.enrolledStudents = NULL;
    }

    newNode->previous = NULL;

    if (courseList->head == NULL) {
        // List is empty
        newNode->next = NULL;
        courseList->head = newNode;
        courseList->tail = newNode;
    } else {
        // List is not empty
        newNode->next = courseList->head;
        courseList->head->previous = newNode;
        courseList->head = newNode;
    }

    courseList->length++;
    printf("Course '%s' added at the front successfully!\n", newCourse.courseName);
}

void addCourseAtEnd(CourseLinkedList *courseList, Course newCourse) {
    CourseNode *newNode = (CourseNode*)malloc(sizeof(CourseNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Copy course data to the node
    strcpy(newNode->courseData.courseName, newCourse.courseName);
    strcpy(newNode->courseData.instructorName, newCourse.instructorName);
    newNode->courseData.enrolledStudentCount = newCourse.enrolledStudentCount;

    if (newCourse.enrolledStudentCount > 0) {
        newNode->courseData.enrolledStudents = (Student*)malloc(newCourse.enrolledStudentCount * sizeof(Student));
        if (newNode->courseData.enrolledStudents == NULL) {
            printf("Memory allocation failed!\n");
            free(newNode);
            return;
        }

        // Deep copy of all students
        for (int studentIndex = 0; studentIndex < newCourse.enrolledStudentCount; studentIndex++) {
            strcpy(newNode->courseData.enrolledStudents[studentIndex].fullName, newCourse.enrolledStudents[studentIndex].fullName);
            newNode->courseData.enrolledStudents[studentIndex].studentID = newCourse.enrolledStudents[studentIndex].studentID;
        }
    } else {
        newNode->courseData.enrolledStudents = NULL;
    }

    newNode->next = NULL;

    if (courseList->head == NULL) {
        // List is empty
        newNode->previous = NULL;
        courseList->head = newNode;
        courseList->tail = newNode;
    } else {
        // List is not empty
        newNode->previous = courseList->tail;
        courseList->tail->next = newNode;
        courseList->tail = newNode;
    }

    courseList->length++;
    printf("Course '%s' added at the end successfully!\n", newCourse.courseName);
}

void displayCoursesForward(CourseLinkedList *courseList) {
    if (courseList->head == NULL) {
        printf("Course list is empty!\n");
        return;
    }

    printf("\n=== COURSES (FORWARD ORDER) ===\n\n");
    CourseNode *currentNode = courseList->head;
    int position = 1;

    while (currentNode != NULL) {
        printf("Position %d:\n", position);
        displayCourse(&currentNode->courseData);
        currentNode = currentNode->next;
        position++;
    }
}

void displayCoursesBackward(CourseLinkedList *courseList) {
    if (courseList->head == NULL) {
        printf("Course list is empty!\n");
        return;
    }

    printf("\n=== COURSES (REVERSE ORDER) ===\n\n");
    CourseNode *currentNode = courseList->tail;
    int position = courseList->length;

    while (currentNode != NULL) {
        printf("Position %d:\n", position);
        displayCourse(&currentNode->courseData);
        currentNode = currentNode->previous;
        position--;
    }
}

void insertCourseAtPosition(CourseLinkedList *courseList, int position, Course newCourse) {
    // Check if position is valid
    if (position < 1 || position > courseList->length + 1) {
        printf("Invalid position! Position should be between 1 and %d.\n", courseList->length + 1);
        return;
    }

    // If inserting at the beginning
    if (position == 1) {
        addCourseAtFront(courseList, newCourse);
        return;
    }

    // If inserting at the end
    if (position == courseList->length + 1) {
        addCourseAtEnd(courseList, newCourse);
        return;
    }

    // Inserting in the middle
    CourseNode *newNode = (CourseNode*)malloc(sizeof(CourseNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Copy course data to the node
    strcpy(newNode->courseData.courseName, newCourse.courseName);
    strcpy(newNode->courseData.instructorName, newCourse.instructorName);
    newNode->courseData.enrolledStudentCount = newCourse.enrolledStudentCount;

    if (newCourse.enrolledStudentCount > 0) {
        newNode->courseData.enrolledStudents = (Student*)malloc(newCourse.enrolledStudentCount * sizeof(Student));
        if (newNode->courseData.enrolledStudents == NULL) {
            printf("Memory allocation failed!\n");
            free(newNode);
            return;
        }

        // Deep copy of all students
        for (int studentIndex = 0; studentIndex < newCourse.enrolledStudentCount; studentIndex++) {
            strcpy(newNode->courseData.enrolledStudents[studentIndex].fullName, newCourse.enrolledStudents[studentIndex].fullName);
            newNode->courseData.enrolledStudents[studentIndex].studentID = newCourse.enrolledStudents[studentIndex].studentID;
        }
    } else {
        newNode->courseData.enrolledStudents = NULL;
    }

    // Find the node at position - 1
    CourseNode *currentNode = courseList->head;
    for (int nodeIndex = 1; nodeIndex < position - 1; nodeIndex++) {
        currentNode = currentNode->next;
    }

    // Insert the new node
    newNode->next = currentNode->next;
    newNode->previous = currentNode;
    currentNode->next->previous = newNode;
    currentNode->next = newNode;

    courseList->length++;
    printf("Course '%s' inserted at position %d successfully!\n", newCourse.courseName, position);
}

void deleteCourseAtPosition(CourseLinkedList *courseList, int position) {
    // Check if list is empty
    if (courseList->head == NULL) {
        printf("Course list is empty!\n");
        return;
    }

    // Check if position is valid
    if (position < 1 || position > courseList->length) {
        printf("Invalid position! Position should be between 1 and %d.\n", courseList->length);
        return;
    }

    CourseNode *nodeToDelete;

    // If removing from the beginning
    if (position == 1) {
        nodeToDelete = courseList->head;

        if (courseList->length == 1) {
            // Only one node in the list
            courseList->head = NULL;
            courseList->tail = NULL;
        } else {
            // More than one node
            courseList->head = courseList->head->next;
            courseList->head->previous = NULL;
        }
    }
    // If removing from the end
    else if (position == courseList->length) {
        nodeToDelete = courseList->tail;
        courseList->tail = courseList->tail->previous;
        courseList->tail->next = NULL;
    }
    // Removing from the middle
    else {
        // Find the node at the position
        nodeToDelete = courseList->head;
        for (int nodeIndex = 1; nodeIndex < position; nodeIndex++) {
            nodeToDelete = nodeToDelete->next;
        }

        // Update the links
        nodeToDelete->previous->next = nodeToDelete->next;
        nodeToDelete->next->previous = nodeToDelete->previous;
    }

    char deletedCourseName[100];
    strcpy(deletedCourseName, nodeToDelete->courseData.courseName);

    // Free the students array inside the course data
    if (nodeToDelete->courseData.enrolledStudents != NULL) {
        free(nodeToDelete->courseData.enrolledStudents);
    }

    // Free the node itself
    free(nodeToDelete);

    courseList->length--;
    printf("Course '%s' at position %d removed successfully!\n", deletedCourseName, position);
}

void updateCourseAtPosition(CourseLinkedList *courseList, int position, Course updatedCourse) {
    // Check if list is empty
    if (courseList->head == NULL) {
        printf("Course list is empty!\n");
        return;
    }

    // Check if position is valid
    if (position < 1 || position > courseList->length) {
        printf("Invalid position! Position should be between 1 and %d.\n", courseList->length);
        return;
    }

    // Find the node at the position
    CourseNode *currentNode = courseList->head;
    for (int nodeIndex = 1; nodeIndex < position; nodeIndex++) {
        currentNode = currentNode->next;
    }

    char oldCourseName[100];
    strcpy(oldCourseName, currentNode->courseData.courseName);

    // Free the existing students array
    if (currentNode->courseData.enrolledStudents != NULL) {
        free(currentNode->courseData.enrolledStudents);
    }

    // Update with new course data
    strcpy(currentNode->courseData.courseName, updatedCourse.courseName);
    strcpy(currentNode->courseData.instructorName, updatedCourse.instructorName);
    currentNode->courseData.enrolledStudentCount = updatedCourse.enrolledStudentCount;

    if (updatedCourse.enrolledStudentCount > 0) {
        currentNode->courseData.enrolledStudents = (Student*)malloc(updatedCourse.enrolledStudentCount * sizeof(Student));
        if (currentNode->courseData.enrolledStudents == NULL) {
            printf("Memory allocation failed!\n");
            currentNode->courseData.enrolledStudentCount = 0;
            return;
        }

        // Deep copy of all students
        for (int studentIndex = 0; studentIndex < updatedCourse.enrolledStudentCount; studentIndex++) {
            strcpy(currentNode->courseData.enrolledStudents[studentIndex].fullName, updatedCourse.enrolledStudents[studentIndex].fullName);
            currentNode->courseData.enrolledStudents[studentIndex].studentID = updatedCourse.enrolledStudents[studentIndex].studentID;
        }
    } else {
        currentNode->courseData.enrolledStudents = NULL;
    }

    printf("Course at position %d updated from '%s' to '%s' successfully!\n", position, oldCourseName, updatedCourse.courseName);
}

void destroyCourseList(CourseLinkedList *courseList) {
    if (courseList == NULL) {
        return;
    }

    CourseNode *currentNode = courseList->head;
    CourseNode *nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;

        // Free the students array inside the course data
        if (currentNode->courseData.enrolledStudents != NULL) {
            free(currentNode->courseData.enrolledStudents);
        }

        // Free the node itself
        free(currentNode);
        currentNode = nextNode;
    }

    free(courseList);
    printf("Course list freed successfully!\n");
}

void manageCourseLinkedList(CourseLinkedList *courseList) {
    int menuChoice, coursePosition;
    Course tempCourse;

    do {
        printf("=== COURSE LIST MANAGEMENT ===\n\n");
        printf("Doubly Linked List Operations:\n");
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

        switch (menuChoice) {
            case 1: // Add at Front
                clearScreen();
                printf("=== ADD COURSE AT FRONT ===\n\n");
                tempCourse = createCourse();
                addCourseAtFront(courseList, tempCourse);
                // Free the temporary course's student data
                if (tempCourse.enrolledStudents != NULL) {
                    free(tempCourse.enrolledStudents);
                }
                break;

            case 2: // Add at End
                clearScreen();
                printf("=== ADD COURSE AT END ===\n\n");
                tempCourse = createCourse();
                addCourseAtEnd(courseList, tempCourse);
                // Free the temporary course's student data
                if (tempCourse.enrolledStudents != NULL) {
                    free(tempCourse.enrolledStudents);
                }
                break;

            case 3: // Display Forward
                displayCoursesForward(courseList);
                break;

            case 4: // Display Backward
                displayCoursesBackward(courseList);
                break;

            case 5: // Insert at Position
                printf("Enter position to insert (1 to %d): ", courseList->length + 1);
                scanf("%d", &coursePosition);
                clearInputBuffer();
                clearScreen();
                printf("=== INSERT COURSE AT POSITION %d ===\n\n", coursePosition);
                tempCourse = createCourse();
                insertCourseAtPosition(courseList, coursePosition, tempCourse);
                // Free the temporary course's student data
                if (tempCourse.enrolledStudents != NULL) {
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
                printf("=== UPDATE COURSE AT POSITION %d ===\n\n", coursePosition);
                tempCourse = createCourse();
                updateCourseAtPosition(courseList, coursePosition, tempCourse);

                if (tempCourse.enrolledStudents != NULL) {
                    free(tempCourse.enrolledStudents);
                }
                break;

            case 0: // Return to Main Menu
                printf("Returning to Main Menu.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

        if (menuChoice != 0) {
            printf("\nPress Enter to continue...");
            getchar();
            clearScreen();
        }
    } while (menuChoice != 0);
}
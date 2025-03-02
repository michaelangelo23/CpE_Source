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

typedef struct Node {
    char data[100];
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} DoublyLinkedList;

void getCourseName(Course *course);
void getInstructorName(Course *course);
void getStudentDetails(Course *course);
void displayCourses(Course *courses, int courseCount);

void prepend(DoublyLinkedList *list, const char *data);
void append(DoublyLinkedList *list, const char *data);
void display(DoublyLinkedList *list);
void insert(DoublyLinkedList *list, int position, const char *data);
void removeNode(DoublyLinkedList *list, int position);
void edit(DoublyLinkedList *list, int position, const char *newData);
void displayReverse(DoublyLinkedList *list);

int main() // main function
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

    // Doubly linked list demonstration
    DoublyLinkedList list = {NULL, NULL};

    prepend(&list, "Node 1");
    append(&list, "Node 2");
    append(&list, "Node 3");
    display(&list);

    insert(&list, 1, "Inserted Node");
    display(&list);

    edit(&list, 2, "Edited Node");
    display(&list);

    removeNode(&list, 1);
    display(&list);

    displayReverse(&list);

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

void getStudentDetails(Course *course)
{
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

void prepend(DoublyLinkedList *list, const char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head != NULL) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode;
    }
    list->head = newNode;
}

void append(DoublyLinkedList *list, const char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;
}

void display(DoublyLinkedList *list) {
    Node *current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert(DoublyLinkedList *list, int position, const char *data) {
    if (position == 0) {
        prepend(list, data);
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        append(list, data);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void removeNode(DoublyLinkedList *list, int position) {
    if (list->head == NULL) return;

    Node *current = list->head;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) return;

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    free(current);
}

void edit(DoublyLinkedList *list, int position, const char *newData) {
    Node *current = list->head;
    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current != NULL) {
        strcpy(current->data, newData);
    }
}

void displayReverse(DoublyLinkedList *list) {
    Node *current = list->tail;
    printf("List in reverse: ");
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->prev;
    }
    printf("\n");
}
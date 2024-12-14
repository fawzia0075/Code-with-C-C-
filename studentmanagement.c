#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
struct Student {
    int rollNo;
    char name[50];
    float marks;
};
struct Student students[MAX_STUDENTS];
int numStudents = 0;
void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }
    printf("Enter student details:\n");
    printf("Roll No: ");
    scanf("%d", &students[numStudents].rollNo);
    printf("Name: ");
    scanf("%s", students[numStudents].name);
    printf("Marks: ");
    scanf("%f", &students[numStudents].marks);
    numStudents++;
    printf("Student added successfully.\n");
}
void deleteStudent() {
    int rollNo;
    printf("Enter roll number of the student to delete: ");
    scanf("%d", &rollNo);
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNo == rollNo) {
            found = 1;
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            printf("Student deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}
void showStudentList() {
    if (numStudents == 0) {
        printf("No students added yet.\n");
        return;
    }
    printf("Student List:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}
int main() {
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Show Student List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                showStudentList();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}


#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int rollNumber;
    char name[NAME_LENGTH];
    float marks;
} Student;

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter roll number: ");
    if (scanf("%d", &students[*count].rollNumber) != 1) {
        printf("Invalid roll number.\n");
        return;
    }

    printf("Enter student name (one word): ");
    if (scanf("%49s", students[*count].name) != 1) {
        printf("Invalid name.\n");
        return;
    }

    printf("Enter marks (0 to 100): ");
    if (scanf("%f", &students[*count].marks) != 1 ||
        students[*count].marks < 0 || students[*count].marks > 100) {
        printf("Invalid marks. Enter a value from 0 to 100.\n");
        return;
    }

    (*count)++;
    printf("Student added successfully.\n");
}

void displayStudents(const Student students[], int count) {
    int i;

    if (count == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\n--- STUDENT RECORDS ---\n");
    printf("%-12s %-20s %-10s %-10s\n", "Roll No.", "Name", "Marks", "Grade");

    for (i = 0; i < count; i++) {
        char grade;
        if (students[i].marks >= 90) grade = 'A';
        else if (students[i].marks >= 75) grade = 'B';
        else if (students[i].marks >= 60) grade = 'C';
        else if (students[i].marks >= 40) grade = 'D';
        else grade = 'F';

        printf("%-12d %-20s %-10.2f %-10c\n",
               students[i].rollNumber, students[i].name,
               students[i].marks, grade);
    }
}

void searchStudent(const Student students[], int count) {
    int roll, i;

    printf("Enter roll number to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            printf("Found: Roll No: %d, Name: %s, Marks: %.2f\n",
                   students[i].rollNumber, students[i].name,
                   students[i].marks);
            return;
        }
    }

    printf("Student not found.\n");
}

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search by roll number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a menu number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Please choose a number from 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}

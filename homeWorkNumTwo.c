#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int studentNo;
    char name[50];
    char department[50];
};

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Add Student\n");
        printf("2. Search by Student Number\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numStudents < MAX_STUDENTS) {
                    printf("Enter student number: ");
                    scanf("%d", &students[numStudents].studentNo);
                    printf("Enter student name: ");
                    scanf(" %[^\n]", students[numStudents].name);
                    printf("Enter student department: ");
                    scanf(" %[^\n]", students[numStudents].department);

                    FILE *file = fopen("students.dat", "ab");
                    if (file != NULL) {
                        fwrite(&students[numStudents], sizeof(struct Student), 1, file);
                        fclose(file);
                        numStudents++;
                    } else {
                        printf("Error opening file.\n");
                    }
                } else {
                    printf("Maximum number of students reached.\n");
                }
                break;
            case 2:
                if (numStudents == 0) {
                    printf("No students in the database.\n");
                } else {
                    int searchNo;
                    printf("Enter student number to search for: ");
                    scanf("%d", &searchNo);

                    FILE *file = fopen("students.dat", "rb");
                    if (file != NULL) {
                        int found = 0;
                        struct Student student;
                        while (fread(&student, sizeof(struct Student), 1, file) == 1) {
                            if (student.studentNo == searchNo) {
                                found = 1;
                                printf("Student found:\n");
                                printf("Student Number: %d\n", student.studentNo);
                                printf("Name: %s\n", student.name);
                                printf("Department: %s\n", student.department);
                                break;
                            }
                        }
                        if (!found) {
                            printf("Student not found.\n");
                        }
                        fclose(file);
                    } else {
                        printf("Error opening file.\n");
                    }
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}


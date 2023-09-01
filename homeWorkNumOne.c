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
        printf("2. Search by Name\n");
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

                    FILE *file = fopen("students.dat", "w");
                    if (file != NULL) {
                        fprintf(file, "%d|%s|%s\n",
                                students[numStudents].studentNo,
                                students[numStudents].name,
                                students[numStudents].department);
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
                    char searchName[50];
                    printf("Enter name to search for: ");
                    scanf(" %[^\n]", searchName);

                    FILE *file = fopen("students.dat", "r");
                    if (file != NULL) {
                        int found = 0;
                        char line[200];
                        while (fgets(line, sizeof(line), file)) {
                            char *token = strtok(line, "|");
                            if (strcmp(token, searchName) == 0) {
                                found = 1;
                                printf("Student found:\n");
                                printf("Student Number: %s\n", token);
                                printf("Name: %s\n", strtok(NULL, "|"));
                                printf("Department: %s\n", strtok(NULL, "\n"));
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

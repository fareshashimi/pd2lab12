#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct Student {
    int studentNo;
    char name[50];
    char department[50];
};

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    // Read data from the random access file and add it to the list
    FILE *file = fopen("students.dat", "rb");
    if (file != NULL) {
        struct Student student;
        while (fread(&student, sizeof(struct Student), 1, file) == 1) {
            if (numStudents < MAX_STUDENTS) {
                students[numStudents] = student;
                numStudents++;
            } else {
                printf("Maximum number of students reached.\n");
                break;
            }
        }
        fclose(file);
    } else {
        printf("Error opening file.\n");
        return 1; // Exit with an error code
    }

    // Print all the records
    printf("List of Student Records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student Number: %d\n", students[i].studentNo);
        printf("Name: %s\n", students[i].name);
        printf("Department: %s\n", students[i].department);
        printf("------------------------\n");
    }

    return 0;
}


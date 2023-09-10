#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int student_no;
    char name[20];
    char department[20];
}student;

void addStdRecord(FILE *mp){
    student std;
    
    printf("Number: ");
    scanf("%d", &std.student_no);
    printf("Name: ");
    scanf("%s", std.name);
    printf("Department: ");
    scanf("%s", std.department);
    
    fseek(mp, 0, SEEK_SET);
    fwrite(&std, sizeof(student), 1, mp);
    printf("\n\n The record is added successfully.\n\n");
}

void searchFileByName(FILE *mp){
    int stdNum;
    printf("Insert a student number to search:\n");
    scanf("%d", &stdNum);
    printf("\n");
    
    student std;
    fseek(mp, 0, SEEK_SET);
    
    if(fread(&std, sizeof(student), 1, mp)==1){
        printf("Number: %d\n", std.student_no);
        printf("Name: %s\n", std.name);
        printf("Department: %s\n\n\n", std.department);
    }
    else{
        printf(" The record is not found.\n\n");
    }
    
}

int main(){
    int c;
    FILE *mp = fopen("student.txt", "rb+");
    
    if(mp==NULL){
        mp = fopen("student.txt", "wb+");
        if(mp==NULL){
            return 0;
        }
    }
    
    while(1){
        printf("Menu:\n");
        printf("1.Adding a record.\n2.Search a record by his or her name.\n3.Exit.\n\n");
        printf("Select your choice: ");
        scanf("%d", &c);
        printf("\n\n");
        
        switch(c){
            case 1:
                addStdRecord(mp);
            break;
            
            case 2:
                searchFileByName(mp);
            break;
            
            case 3:
                fclose(mp);
                exit(0);
            break;
            
            default:
                printf(" Wrong. Try again...\n\n");
            break;
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int number;
    char name[20];
    char department[20];
}student;

void addStdRecord(FILE *mp){
    student std;
    
    printf("Number: ");
    scanf("%d", &std.number);
    printf("Name: ");
    scanf("%s", std.name);
    printf("Department: ");
    scanf("%s", std.department);
    
    fwrite(&std, sizeof(student), 1, mp);
    printf("\n\n The record is added successfully.\n\n");
}

void searchRecordByNmae(FILE *mp){
    char searchName[20];
    printf("Insert a name to search: ");
    scanf("%s", searchName);
    printf("\n\n");
    
    student std;
    int found=0;
    
    fseek(mp, 0, SEEK_SET);
    while(fread(&std, sizeof(student), 1, mp)==1){
        if(strcmp(searchName, std.name)==0){
            printf("Number: %d\n", std.number);
            printf("Name: %s\n", std.name);
            printf("Department: %s\n\n", std.department);
            found=1;
        }
    }
    
    if(!found){
        printf("\n\n The record is not found in the system.\n\n");
    }
}

int main(){
    int c;
    FILE *mp = fopen("student.dat", "ab+");
    
    if(mp==NULL){
        return 0;
    }
    else{
        while(1){
            printf("Menu:\n");
            printf("1.Adding a record to the system.\n2.Searching a record by his or her name.\n3.Exit\n\n");
            printf("Select your choice: ");
            scanf("%d", &c);
            printf("\n\n");
            
            switch(c){
                case 1:
                    addStdRecord(mp);
                break;
                
                case 2:
                    searchRecordByNmae(mp);
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
    }
    
    return 0;
}

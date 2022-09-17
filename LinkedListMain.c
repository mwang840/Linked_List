#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.c"



int main(){
    int input = 0;
    char *oneName, *serName;
    serName = (char*)(malloc(28 *sizeof(char)));
    oneName = (char*)(malloc(28 *sizeof(char)));
    char *year = (char*)(malloc(28 *sizeof(char)));
    student_t *student = (student_t *)(malloc(sizeof(student_t)));
    long id = 0;
    int expeceted = 0;
    printf("Enter a first name\n");
    scanf("%s", oneName);
    printf("Enter a last name\n");
    scanf("%s", serName);
    printf("Enter your current year\n");
    scanf("%s", year);
    printf("Enter a student id\n");
    scanf("%ld", &id);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Enter graduation date\n");
    scanf("%d", &expeceted);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("1. Add a student to the list\n");
    printf("2. Deletes a student to the list\n");
    printf("3. Prints the list from the begining to the end:\n");
    printf("4. Prints the list from the end to the begining:\n");
    printf("5. Exit the program\n");
    scanf("%d", input);
    student->firstName = oneName;
    student->lastName = serName;
    student->year = year;
    //student->id = id;
    student->expected = expeceted;
    
    switch(input){
        case 1:
        addAtEnd(student, oneName, serName, year);
        break;
        case 2:
            if(head == NULL){
                printf("Empty list");
            }
            else{
                delete(student, serName);
            }
        break;
        case 3:
            printListForward(student);
            break;
        case 4:
            printListBackwards(student);
            break;
        case 5:
            clear();
            break;
        default:
        printf("You entered the %d out of the range 1-5, please try again\n", input);    
        break;        
    }
    return 0;
}
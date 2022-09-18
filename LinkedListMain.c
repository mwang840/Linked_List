#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.c"

void runProgram();

int main(){
    runProgram();
    return 0;
}

void runProgram(){
    int input = 0;
    //U need to allocate new memory for each try
    while(1) {
        char *oneName = (malloc(28 *sizeof(char)));
        char *serName = (malloc(28 *sizeof(char)));
        char *year = (malloc(28 *sizeof(char)));
        student_t *student = (student_t *)(malloc(sizeof(student_t)));
        printf("1. Add a student to the list\n");
        printf("2. Deletes a student to the list\n");
        printf("3. Prints the list from the begining to the end:\n");
        printf("4. Prints the list from the end to the begining:\n");
        printf("5. Exit the program\n");
        scanf("%d", &input);
    switch(input){
        case 1:
            getData(student, oneName, serName, year);
            break;
        case 2:
            if(head == NULL){
                printf("Empty list\n");
            }
            else{
                char *a;
                printf("Type the last name you want gone\n");
                scanf("%s", a);
                delete(a);
            }
            break;
        case 3:
            printListForward();
            break;
        case 4:
            printListBackwards();
            break;
        case 5:
            clear();
            free(oneName);
            free(serName);
            free(student);
            return;
        default:
            printf("You entered the %d out of the range 1-5, please try again\n", input);    
            break;        
        }
    }
}
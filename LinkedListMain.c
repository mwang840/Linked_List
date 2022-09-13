#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int main(){
    char *studentName = (char*)malloc(28 * sizeof(char));
    student_t *student = (student_t*)malloc(sizeof(student_t));
    long id = 0;
    int selection = 0;
    printf("What is the students name\n");
    scanf("%s", studentName);
    printf("Enter a number from 1-5 for %s\n", studentName);
    printf("1. Add a student to the list\n");
    printf("2. Add a student to the list\n");
    printf("3. Add a student to the list\n");
    printf("4. Add a student to the list\n");
    printf("5. Add a student to the list\n");
    scanf(selection);
    switch(selection){
        case 1:
        
        break;
    }

    return 0;
}
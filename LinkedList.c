#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//Finds the total amount of students starting from the begining of the doubly-linked list
int totalStudents(student_t *head){
    int total = 0;
    while(head != NULL){
        total++;
        head = head->next;
    }
    return total;
}

//Prints the students with their graduation, class and expected graduation with the id from the front of the list
void printListForward(student_t *head){
    student_t *current = head;
    printf("Printing out the list of students in order\n");
    while(current != NULL){
        printf("The students name is %s %s, with an id of %ld, in the class of %s and will be expected to graduate in spring of %d", current->firstName, current->lastName, current->id, current->expected);
        current = current->next;
    }
}

//Same thing but reverse order
void printListBackwards(student_t *tail){
    student_t *current = tail;
    printf("Printing out the list of students in reverse order\n");
    while(current != NULL){
        printf("The students name is %s %s, with an id of %ld, in the class of %s and will be expected to graduate in spring of %d", current->firstName, current->lastName, current->id, current->expected);
        printf("Student's id: ");
        printf("\n");
        printf("\n");
        current = current->prev;
    }
}

student_t *pop(){
    student_t *end = (student_t*)malloc(sizeof(student_t));
    student_t *temp = end;
    free(temp);
    return NULL;
}


void push(student_t *head, long id){
    student_t *newStudent = (student_t*)malloc(sizeof(student_t));
    newStudent->id = id;
    newStudent->prev = NULL;
    newStudent->next = head;

    if(head != NULL){
        head->prev = newStudent;
    }
}

char *getStudent(char *first, char *last, long id, char *year, int expected){
    return 'a';
}

int removeLast(student_t *tail){
    return 0;
}

int removeById(long id){
    return 0;
}

void addAtEnd(student_t *end){

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//Set the global variables head and tail to null initially
student_t *head = NULL;
student_t *tail = NULL;
student_t *currentStudent = NULL;

void getData(student_t *student, char *oneName, char *serName, char *year){
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

    printf("Enter graduation date\n");
    scanf("%d", &expeceted);

    student->firstName = oneName;
    student->lastName = serName;
    student->year = year;
    student->id = id;
    student->expected = expeceted;
    addAtEnd(student, oneName, serName, year);
}

//Prints the students with their graduation, class and expected graduation with the id from the front of the list
void printListForward(){
    if(currentStudent == NULL) {
        printf("Empty List\n");
    }
    currentStudent = head;
    printf("Printing out the list of students in order\n");
    if(head == NULL){
        printf("Error cannot print due to an empty list\n");
        return;
    }
   while(currentStudent->next != NULL){
        printf("Name: %s %s, Year: %s, Id: %ld, Expected Graduation: %d\n\n\n\n", currentStudent->firstName, currentStudent->lastName, currentStudent->year, currentStudent->id, currentStudent->expected);
        currentStudent = currentStudent->next;
    }
    printf("Name: %s %s, Year: %s, Id: %ld, Expected Graduation: %d\n\n\n\n", currentStudent->firstName, currentStudent->lastName, currentStudent->year, currentStudent->id, currentStudent->expected);

}

//Same thing but reverse order
void printListBackwards(){
    if(currentStudent == NULL){
        printf("Empty List\n");
    }
     currentStudent = tail;
    printf("Printing out the list of students in reverse order\n");
    if(tail == NULL){
        printf("Error cannot print due to an empty list\n");
        return;
    }
   while(currentStudent->prev != NULL){
        printf("Name: %s %s, Year: %s, Id: %ld, Expected Graduation: %d\n\n\n\n", currentStudent->firstName, currentStudent->lastName, currentStudent->year, currentStudent->id, currentStudent->expected);
        currentStudent = currentStudent->prev;
    }
    printf("Name: %s %s, Year: %s, Id: %ld, Expected Graduation: %d\n\n\n\n", currentStudent->firstName, currentStudent->lastName, currentStudent->year, currentStudent->id, currentStudent->expected);

}

//pops the first node off the dll, returns the student id of the popped node
long pop(student_t *node){
    long returnNode = -1;
    student_t *nextStudent = node;
    student_t *otherStudent = NULL;
    if(node == NULL){
        return -1;
    }
    otherStudent = node->next;
    returnNode = node->id;
    free(node);
    return returnNode;

}

void delete(char *last){
    if(currentStudent == NULL) {
        printf("No list to delete");
        return;
    }
    currentStudent = head;
        printf("Executing the while loop\n");
        while(currentStudent->next != NULL) {
        if(*(currentStudent->lastName) == *last) {
            break;
        }
        currentStudent = currentStudent->next;
    }
    if(*(currentStudent->lastName) != *last) {
        return;
    }
    if (head == tail) {
        currentStudent = NULL;
        return;
    }
    if(currentStudent == head) {
        printf("Deleting head student\n");
        currentStudent = currentStudent->next;
        currentStudent->prev = NULL;
        head = currentStudent;
        return;
    }
    if (currentStudent == tail) {
        printf("Deleting last student\n");
        currentStudent = currentStudent->prev;
        currentStudent->next = NULL;
        tail = currentStudent;
        return;
    }
    student_t *temp = currentStudent->next;
    currentStudent = currentStudent->prev;
    currentStudent->next = temp;
    temp = currentStudent;
    currentStudent = currentStudent->next;
    currentStudent->prev = temp;
}



//Adds the node at the end of the list
void addAtEnd(student_t *student, char *first, char *last, char *year){
    student->prev = NULL;
    student->next = NULL;
    if(currentStudent == NULL){
        currentStudent = student;
        head = student;
        tail = student;
    }
    else{
        while(currentStudent->next != NULL) {
            currentStudent = currentStudent -> next;
        }
        

        currentStudent->next = student;
        student->prev = currentStudent;
        tail = student;
        printf("Tail Pointer %p\n", tail);
        printf("Tail Pointer prev %p\n", tail->prev);
        printf("Input pointers %p\n", student->next);
        printf("Input pointer prev %p\n", student->prev);
    }    
}

//Clears the entire list
void clear(){
    printf("Clearing the list\n");
    student_t *current = (student_t *)malloc(sizeof(student_t));
    current = head;
    student_t *temp;
    while(current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
    printf("Done!\n");
}
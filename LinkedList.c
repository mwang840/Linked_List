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
    if(head == NULL){
        return;
    }
    student_t *current = head;
    printf("Printing out the list of students in order\n");
    while(current != NULL){
        printf("The students name is %s %s, with an id of %ld, in the class of %s and will be expected to graduate in spring of %d", current->firstName, current->lastName, current->id, current->expected);
        current = current->next;
    }
}

//Same thing but reverse order
void printListBackwards(student_t *tail){
    if(tail == NULL){
        return;
    }
    student_t *current = tail;
    printf("Printing out the list of students in reverse order\n");
    while(current != NULL){
        printf("The students name is %s %s\n", current->firstName, current->lastName);
        printf("Student's id: %ld\n", current->id);
        printf("%s is in the class of %d\n", current->firstName, current->expected);
        printf("%s will be expected to graduate in %d\n", current->firstName, current->expected);
        current = current->prev;
    }
}

//pops the first node off the dll
student_t *pop(student_t *node){
    student_t *first = NULL;
    if(node == NULL){
        return NULL;
    }
    student_t *nextStudent = NULL;
    nextStudent = node->next;
    first->firstName = node->firstName;
    first->lastName = node->lastName;
    first->id = node->id;
    first->expected = node->expected;
    nextStudent = first;
    free(node);
    nextStudent->prev = NULL;
    return NULL;
}

//pushes the node to the front of the list
void push(student_t *head, long id){
    if(head == NULL){
        return;
    }
    student_t *newStudent = (student_t*)malloc(sizeof(student_t));
    newStudent->id = id;
    newStudent->prev = NULL;
    newStudent->next = head;
}

//gets the student node and returns the students  first name
/*char *getStudent(student_t *student){
    char *surName = (char*)malloc(128 * sizeof(char));
    char *frontName = (char*)malloc( 128 * sizeof(char));
    if(student == NULL){
        return NULL;
    }
    if(student->firstName == ' ' || student->lastName == ' '){
        return ' ';
    }
    else{
        surName = student->lastName;
        frontName = student->firstName;
        return surName + frontName;
    }
}*/

int removeLast(student_t *tail){
    int lastStudentPos = 0;
    return 0;
}

int removeById(student_t *student, long id){
    if(student == NULL){
        return 0;
    }
    else if(id == 0){
        return pop(student);
    }
    int index = 0;
    student_t *temp = NULL;
    student_t *current = student;
    return 0;
}

void addAtEnd(student_t *head, char *first, char *last, long id, char *year, int expected){
    if(head == NULL){
        return;
    }
    student_t *newStudent = malloc(sizeof(student_t));
    student_t *lastStudent = head;
    while(lastStudent->next != NULL){
        lastStudent = lastStudent->next;
    }
    lastStudent->next = newStudent;
    newStudent->prev = lastStudent;
    newStudent->next = NULL;
}
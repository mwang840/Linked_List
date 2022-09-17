#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
student_t *head;
student_t *tail;

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

//Deletes the student by last name  take in last name and 
void delete(student_t *node, char *last){
    if(node == NULL || last == NULL){
        return;
    }
    student_t *student = (student_t *)malloc(sizeof(student_t));
    student = node;
    student_t *temp;
    if(strcmp(student->lastName, last) ==  0 && (student->prev == NULL && student->next == NULL)){
        printf("The student that will be deleted is %s", last);
        free(student);
    }
    while(student != NULL){
        if(strcmp(student->lastName, last) ==  0){
            if(student == head){
                temp = student;
                free(student);
                temp->prev = NULL;
            }
            else if(student != head || student != tail){
                temp = student;
                temp->prev = student->prev;
                temp->next = student->next;
                free(student);
            }
            else if(student == tail){
                temp = student;
                temp->prev = student->prev;
                free(student);
                temp->next = NULL;
            }
        }
        student = student->next;
    }
    /*char buffer[BUFFERSIZE];
    char *last = (char *)malloc(28 * sizeof(char));
    char *yearOfGraduation = (char *)malloc(4 * sizeof(char));
    if(node == NULL){
        return;
    }
    student_t *current = node;
    printf("Enter the first and last name of the student and the year:\n");
    if(fgets(last, buffer, yearOfGraduation)){
        printf("The student %s %s who graduates in %s will be deleted", last, yearOfGraduation);
    }
    if(current->next == NULL && current->prev == NULL){
        free(current);
        free(last);
        free()
    }
    while(current != NULL){
        
    }*/
}



//Adds the node at the end of the list
void addAtEnd(student_t *head, char *first, char *last, long id, char *year, int expected){
    if(head == NULL){
        return;
    }
    student_t *newStudent = (student_t*)malloc(sizeof(student_t));
    char *one = (char*)malloc(20 * sizeof(char));
    char *surname = (char*)malloc(20 * sizeof(char));
    student_t *lastStudent = head;
    while(lastStudent->next != NULL){
        lastStudent = lastStudent->next;
    }
    lastStudent->firstName = one;
    lastStudent->lastName = surname;
    lastStudent->next = newStudent;
    newStudent->prev = lastStudent;
    newStudent->firstName = first;
    newStudent->lastName = last;
    newStudent->id = id;
    newStudent->year = year;
    newStudent->expected = expected;
    newStudent->next = NULL;
    printf("Student added at end is %s, %s, %s", first, last, year);
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
}
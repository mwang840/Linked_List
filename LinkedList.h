#include <stdio.h>

char *getStudent(char *first, char *last, long id, char *year, int expected);


typedef struct student{
    char *firstName;
    char *lastName;
    long id;
    int expected;
    struct student *prev;
    struct student *next;

} student_t;
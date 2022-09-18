typedef struct student{
    char *firstName;
    char *lastName;
    long id;
    int expected;
    char *year;
    struct student *prev;
    struct student *next;

} student_t;
void printListForward();
void printListBackwards();
long pop(student_t *node);
void push(student_t *head, long id);
int totalStudents(student_t *head);
void delete(char *last);
void addAtEnd(student_t *student, char *first, char *last, char *year);
void clear();
void getData(student_t *student, char *oneName, char *serName, char *year);

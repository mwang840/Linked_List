typedef struct student{
    char *firstName;
    char *lastName;
    long id;
    int expected;
    char *year;
    struct student *prev;
    struct student *next;

} student_t;

student_t *head;
student_t *tail;

char getStudent(student_t *student);
void printListForward(student_t *head);
void printListBackwards(student_t *tail);
long pop(student_t *node);
void push(student_t *head, long id);
int totalStudents(student_t *head);
void delete(student_t *head, char *last);
void addAtEnd(student_t *head, char *first, char *last, char *year);
void clear();

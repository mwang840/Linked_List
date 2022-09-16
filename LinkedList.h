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
student_t *pop(student_t *node);
void push(student_t *head, long id);
int totalStudents(student_t *head);
int removeLast(student_t *head);
int removeById(student_t *student, long id);
void addAtEnd(student_t *head, char *first, char *last, long id, char *year, int expected);

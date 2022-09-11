typedef struct student{
    char *firstName;
    char *lastName;
    long id;
    int expected;
    char *year;
    struct student *prev;
    struct student *next;
    struct student *head;
    struct student *tail;

} student_t;

char *getStudent(char *first, char *last, long id, char *year, int expected);
void printListForward(student_t *head);
void printListBackwards(student_t *tail);
student_t *pop();
void push(student_t *head, long id);
int totalStudents(student_t *head);
int removeLast(student_t *head);
int removeById(long id);
void addAtEnd(student_t end);

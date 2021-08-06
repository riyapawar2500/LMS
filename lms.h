#ifndef LMS_H_INCLUDED
#define LMS_H_INCLUDED

struct User{
char userid[20];
char pwd[20];
};

struct Category
{
    int id;
    char cat_name[20];
};

struct book
{
    int bookid;
    char bookName[20];
    char authorName[50];
    int categoryId;
    int quantity;
};

struct Student{
int roll;
char name[30];
};

struct IssueBook{
int roll;
int bookId;
};
typedef struct IssueBook IssueBook;
typedef struct Student Student;
typedef struct book book;
typedef struct Category Category;
typedef struct User User;

int enterchoice();
void addUser();
void addCategory();
void input();
int isUserPresent(char *,char *);
int showCategory();
book* getBookDetails();
void addbooks(book,int);
void show_books();





#endif // LMS_H_INCLUDED

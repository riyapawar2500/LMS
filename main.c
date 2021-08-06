#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"lms.h"

int main()
{
    gotoxy(40,10);
    textcolor(YELLOW);
    printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM");
    gotoxy(32,13);
    textcolor(LIGHTGREEN);
    printf("* Having Fun Is Not Hard. When You Have a Library card *");
    getch();
    textcolor(YELLOW);
    addUser();
    input();
    addCategory();
    clrscr();
    int choice;
    while(1){
    clrscr();
    choice=enterchoice();
    clrscr();
    if(choice==7)
        exit(0);
    showCategory();
    }
}

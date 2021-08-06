#include<stdio.h>
#include<string.h>
#include"lms.h"
#include<stdlib.h>
#include"conio2.h"

//function for adding user id or password.
void addUser(){
   FILE *fp=fopen("User.bin","rb");
    if(fp==NULL){
        fp=fopen("User.bin","wb");
        User u={"admin","abc"};
        fwrite(&u,sizeof(User),1,fp);
        fclose(fp);
    }
    else{
            fclose(fp);
    }
}

//function for accepting user id and password.
void input(){
    clrscr();
    char x;
    int n,i;
    gotoxy(42,1);
    textcolor(YELLOW);
    printf("LIBRARY MANAGEMENT SYSTEM");

    gotoxy(1,3);
    for(int i=0,x=35;i<120;i++)
    printf("%c",x);

    gotoxy(50,7);
    printf("* LOGIN PANEL *");

    textcolor(LIGHTGREEN);
    gotoxy(1,9);
     for(i=0,x=35;i<120;i++)
    printf("%c",x);

    gotoxy(44,12);
    textcolor(LIGHTCYAN);
    printf("Enter user id:");

    gotoxy(44,13);
    textcolor(LIGHTCYAN);
    printf("Enter Password:");

    textcolor(LIGHTGREEN);
    gotoxy(1,15);
    for(int i=0,x=35;i<120;i++)
    printf("%c",x);

    do{
    textcolor(WHITE);
    User u;
    gotoxy(58,12);
    fgets(u.userid,20,stdin);
    char *pos;
    pos=strchr(u.userid,'\n');
    *pos='\0';
    gotoxy(59,13);

    for(i=0;x!=13;){
            x=getch();
    if(x==8&&i!=0){
            printf("\b");
            printf(" \b");
            u.pwd[--i]='\0';
            continue;
    }
    u.pwd[i]=x;
    if(u.pwd[i]==13)
        break;
    printf("*");
    ++i;
    }

    u.pwd[i]=0;
    n=isUserPresent(u.userid,u.pwd);
    x=0;
    }while(n!=1);

}


//function for checking user id and password

int isUserPresent(char *u,char *p){
    if(*(u)==0 || *(p)==0){
        gotoxy(48,20);
        textcolor(LIGHTRED);
        printf("BOTH FIELDS ARE MANDATORY");
        getch();
        gotoxy(47,20);
        printf("\t\t\t\t\t\t\t\t\t\t");
        getch();
        gotoxy(58,12);
        printf("\t\t\t\t\t\t\t");
        gotoxy(59,13);
        printf("\t\t\t\t\t\t\t");
        textcolor(WHITE);
        return 0;
    }
    FILE *fp=fopen("user.bin","rb");
    User user;
    fread(&user,sizeof(User),1,fp);
    if((strcmp(u,user.userid)) || (strcmp(p,user.pwd))){
        gotoxy(47,20);
        textcolor(LIGHTRED);
        printf("INVALID USERNAME OR PASSWORD");
        getch();
        gotoxy(47,20);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(58,12);
    printf("\t\t\t\t\t\t\t");
    gotoxy(59,13);
    printf("\t\t\t\t\t\t\t");
    textcolor(WHITE);
    fclose(fp);
    return 0;
    }
    fclose(fp);
    return 1;
}
//function of addCategory
  void addCategory(){
  FILE *fp=fopen("Category.bin","rb");
  if(fp==NULL){
    fp=fopen("Category.bin","wb");
    Category cat[6]={
                {1,"CSE"},
                {2,"EC"},
                {3,"EX"},
                {4,"IT"},
                {5,"ME"},
                {6,"CIVIL"}
                };
  fwrite(cat,6*sizeof(Category),1,fp);
  fclose(fp);
  }
  else{
        fclose(fp);
  }
  }
  //function for accepting choice from user and creating new display window
  int enterchoice()
  {
      int choice,i;
      textcolor(YELLOW);
      gotoxy(48,1);
      printf("LIBRARY MANAGEMENT SYSTEM\n");
      for(i=1;i<120;i++)
        printf("%c",274);
      gotoxy(52,5);
      textcolor(LIGHTGREEN);
      printf("* ADMIN PANEL *");
      gotoxy(1,6);
      for(i=1;i<=240;i++)
       printf("%c",176);
       gotoxy(52,9);
       textcolor(YELLOW);
       printf("1-ADD BOOKS");
       gotoxy(52,10);
       printf("2-View All Books");
       gotoxy(52,11);
       printf("3-Search Book");
       gotoxy(52,12);
       printf("4-Issue Book");
       gotoxy(52,13);
       printf("5-Update Book");
       gotoxy(52,14);
       printf("6-Delete Book");
       gotoxy(52,15);
       printf("7-Quit");
       textcolor(LIGHTGREEN);
       gotoxy(1,17);
       for(i=1;i<=240;i++)
        printf("%c",176);
       gotoxy(52,20);
       textcolor(LIGHTCYAN);
       printf("Enter Choice");
       textcolor(WHITE);
       int ch;
       scanf("%d",&ch);
       return ch;
  }

  //Function for displaying categories
  int showCategory(){
  clrscr();
  gotoxy(45,1);
  textcolor(YELLOW);
  printf("LIBRARY MANAGEMENT SYSTEM");
  gotoxy(1,3);
  for(int i=0;i<120;i++)
    printf("%c",247);
    textcolor(GREEN);
    gotoxy(50,5);
    printf("* CATEGORY *");
    textcolor(GREEN);
    gotoxy(1,7);
    for(int i=0;i<240;i++)
        printf("%c",176);

    Category ctt[6];
    FILE *fp=fopen("Category.bin","rb");
    fread(&ctt,sizeof(ctt),6,fp);
    textcolor(YELLOW);
    gotoxy(50,10);
    printf("1-%s",ctt[0].cat_name);
    gotoxy(50,11);
    printf("2-%s",ctt[1].cat_name);
    gotoxy(50,12);
    printf("3-%s",ctt[2].cat_name);
    gotoxy(50,13);
    printf("4-%s",ctt[3].cat_name);
    gotoxy(50,14);
    printf("5-%s",ctt[4].cat_name);
    gotoxy(50,15);
    printf("6-%s",ctt[5].cat_name);


    textcolor(GREEN);
    gotoxy(1,17);
    for(int i=0;i<240;i++)
        printf("%c",176);


    textcolor(LIGHTCYAN);
    gotoxy(50,20);
    int c;
    printf("SELECT CATEGORY");
    textcolor(WHITE);
    scanf("&dd",&c);



    getch();
    return 0;
  }


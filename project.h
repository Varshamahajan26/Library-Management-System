
#include<stdio.h>                  
#include <stdlib.h>
#include<string.h>
#include<time.h>  

struct lastdate {
    int mm, dd, yy;
};
struct books {
    int bkid;
    char studname[20];
    char bkname[20];
    char Authname[20];
    int qty;
    float Price;
    int cnt;
    
    char *cat;
    struct lastdate issued;
    struct lastdate duedate;
};
struct books a;

struct student {
	int mis;
	int ctno;
	char stname[50], eid[50], branch[20];
};
struct student stud;
struct teacher {
	int id;
	int ctno;
	char tname[50], eid[50], dept[20];
};
struct teacher tr;
int init();
int  accept();
void addteacher();
void addstudent();
void deletebooks();
void viewteacher();
void viewstudent();
void menu();
void searchbooks();


void login();
void addbooks();
void issuebooks();
int  checkid(int);
int  checktid(int);
int  checkmis(int);
void issuerecord();
void editbooks();
void viewbooks();

char branch[][15] = {"Computer", "IT", "Electrical", "Civil"};
FILE *fp, *ft, *st;
int s;
int flag;


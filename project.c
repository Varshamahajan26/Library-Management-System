


/*****************************************************************************
 * "Library Management System" 
 *
 * This code performs various operations mainly used in college library.
 *
 * Copyright (C) 2017 Varsha Sahebrao Mahajan
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>
 *****************************************************************************/


#include<stdio.h>

#include<time.h>                   

#include <stdlib.h>

#include<string.h>

#include"project.h" 



int main() {
	init(); /*Initiate the code*/
	return 0;
}

int init() {
	system("clear");
	int log;
	printf("*********************  L I B R A R Y    M A N A G E M E N T  ********************\n");
	printf("1. MEMBERS\n\n");
	printf("2. ADMIN\n");
	scanf("%d", &log);
	switch(log) {
		case 1: 
			login();
			break;
		case 2:
			menu();
			break;
	}
	return 0;
}

void login() {	   /*Provides login option for student and teacher both*/
	int op;
	system("clear");
	int t, y;
	char ch,ch1;
	printf("1.TEACHER\n2.STUDENT\n3.EXIT");	
	scanf("%d",&op);
	switch(op) {
		case 1:
		
		printf(" \n");
		printf("a. ADD TEACHER\n");
		printf("b. VIEW TEACHER\n");
		printf("c. BACK\n");
		printf("d. CLOSE\n\n");
		scanf("%s", &ch);	
		switch(ch) {
		case 'a': 
			addteacher();
			break;
		case 'b':
			viewteacher();
			break;
		case 'c':
			init();
			break;

		case 'd': 
			system("clear");
			exit(0);
	   	
		default: 
			printf("\aWRONG OPTION SELECTED");
			init();

	}
		case 2:
		system("clear");

		printf(" \n");
		printf("a. ADD STUDENT\n");
		printf("b. VIEW STUDENT\n");
		printf("c. BACK\n");
		printf("d. CLOSE\n\n");
		scanf("%s", &ch1);	
		switch(ch1) {
		case 'a': 
			addstudent();
			break;
		case 'b':
			viewstudent();
			break;
		case 'c':
			init();
			break;

		case 'd': 
			system("clear");
			exit(0);
	   	
		default: 
			printf("\aWRONG INPUT");
			init();

		}
	}
}


/*This function adds student member*/
void addstudent() {		
	int t, y;
	st = fopen("Student.txt","ab+");      /*open student file*/
	printf("	Add student member :\n");
	printf("MIS :\t");

	scanf("%d", &t);
	if(checkmis(t) == 0) {
		printf("MIS ALREADY REGISTERED\t");
		login();
		
	}
	stud.mis = t;
	printf("\nNAME OF STUDENT :\t");
	scanf("%s", stud.stname);
	printf("\nMOBILE NO: :\t");
	scanf("%d", &stud.ctno);
	printf("\nEMAIL ID :\t");
	scanf("%s", stud.eid);
	printf("\nBRANCH :\t");
	scanf("%s", stud.branch);
	fseek(st, 0, SEEK_END);
	fwrite(&stud, sizeof(stud), 1, st);
	
	printf("RECORD SUCCESSFULLY STORED\n");
	fclose(st);
		login();
	
	
}

/* This fuction shows the registered student members */
void viewstudent() {		
	int j, y;
	system("clear");
	
	st = fopen("Student.txt", "rb+");
	
	while(fread(&stud, sizeof(stud), 1, st) == 1) {  /*read student info from file*/
		printf("\nMIS :%d		", stud.mis);
		printf("\nNAME :%s	", stud.stname);
		printf("\nEMAIL ID :%s	", stud.eid);
		printf("\nMOBILE NO :%d		", stud.ctno);
		printf("\nBRANCH :%s	", stud.branch);
		printf("\n\n");
		
	}
	printf("Press 1 to go main menu :");
	scanf("%d", &y);
	if(y == 1) 
		init();	
}

/* This function adds taecher member and details of student */
void addteacher() {		
	int t, y;
	st = fopen("teacher.txt","ab+");
	printf("	ADD TEACHER :\n");
	printf("Id :\t");
	scanf("%d", &t);
	if(checktid(t) == 0) {
		printf("ID ALREADY REGISTERED\t");
		login();
		
	}
	tr.id = t;
	printf("\nNAME :\t");
	scanf("%s", tr.tname);
	printf("\nMOBILE NO: :\t");
	scanf("%d", &tr.ctno);
	printf("\nEMAIL ID :\t");
	scanf("%s", tr.eid);
	printf("\nDEPARTMENT :\t");
	scanf("%s", tr.dept);
	fseek(st, 0, SEEK_END);
	fwrite(&tr, sizeof(tr), 1, st);
	fclose(st);
	printf("RECORD SUCCESSFULLY STORED\n");
	
		login();
	
	
}

/* This fuction shows the registered taecher members */
void viewteacher() {		
	int j, y;
	system("clear");
	
	st = fopen("teacher.txt", "rb+");
	
	while(fread(&tr, sizeof(tr), 1, st) == 1) {
		printf("\nID :%d		", tr.id);
		printf("\nNAME :%s	", tr.tname);
		printf("\nEMAIL ID :%s	", tr.eid);
		printf("\nMOBILE NO: :%d		", tr.ctno);
		printf("\nDEPARTMENT :%s	", tr.dept);
		printf("\n\n");
		
	}
	printf("Press 1 to go main menu :");
	scanf("%d", &y);
	if(y == 1) 
		init();	
}

/* Call every function handle from Administrator */
void menu() {		
      	int i,r;
	system("clear");
	printf(" \n");
	printf("**********************  A D M I N  *********************\n");
	
	printf("1. ADD BOOKS\n");
	printf("2. DELETE BOOKS\n");
	printf("3. VIEW BOOKS\n");
	printf("4. ISSUE BOOKS\n");
	printf("5. BACk\n");
	printf("6. CLOSE\n");
	//printf("7. \n");
	printf("WHAT OPRATION DO WANT 2 PERFORM? ENTER CHOICE\n");
	scanf("%d", &r);
	switch(r) {
		case 1:
			addbooks();
			break;
		case 2:
			deletebooks();
			break;
		
	    	case 3:
			viewbooks();
			break;
	   	case 4:
			
			issuebooks();
			break;
		case 5:
			init();
			break;  

	    	case 6: {
			system("clear");
			exit(0);
	   	}
		default: 
			printf("\aPLEASE ENTER CORRECT OPTION\n");
			menu();
	   
    }
}

/* Add new book to library. Details of books and on which shelf it is*/	
void addbooks() {		
	int y;
	system("clear");
	int i;
	printf("SELECT CATEGOIES\n");
	printf("1.COMPUTER\n");
	printf("2.IT\n");
	printf("3.E&TC\n");
	printf("4.CIVIL\n");
	printf("5.Back to main menu\n");
	printf("ENTER CATEGORY");
	scanf("%d",&s);
	if(s == 5) {
		menu() ;
	}
	
	system("clear");
	fp = fopen("Library.dat", "ab+");
	if(accept() == 1) {
		a.cat = branch[s-1];
		fseek(fp, 0, SEEK_END);
		fwrite(&a, sizeof(a), 1, fp);
		fclose(fp);
		printf("RECORD SUCCESSFULLY STORED\n");
		
	    		addbooks();
		
	}
}

/* accept data to add book */
int accept() {		
	int t;
	
	printf("CATEGORY:");
	printf("%s",branch[s-1]);
	printf("\nBOOK ID:\t");
	scanf("%d",&t);
	if(checkid(t) == 0) {
		printf("THE BOOKID ALREADY EXISTS\t");
		menu();
	}
	a.bkid = t;
	printf("\nBOOK NAME:");
	scanf("%s", a.bkname);
	printf("\nAUTHOR:");
	scanf("%s", a.Authname);
	printf("\nQUANTITY:");
	scanf("%d", &a.qty);
	printf("\nPRICE:");
	scanf("%f", &a.Price);
	
	return 1;
}



/* check whether student is already registered or not */
int checkmis(int t) {		
	rewind(st);
	while(fread(&stud, sizeof(stud), 1, st) == 1)
	if(stud.mis == t) {
		return 0;
	}
      return 1; 
}

/* check whether teacher is already registered or not */
int checktid(int t) {		
	rewind(st);
	while(fread(&tr, sizeof(tr), 1, st) == 1)
	if(tr.id == t) {
		return 0;
	}
      return 1; 
}
/* check whether book id is already present or not */
int checkid(int t) {		
	rewind(fp);
	while(fread(&a, sizeof(a), 1, fp) == 1)
	if(a.bkid == t) {
		return 0;
	}
      return 1; 
}

/* Delete books from library */
void deletebooks() {		
	system("clear");
	int d, y;
        while(1) {
		system("clear");
		printf("ENTER BOOK ID");
		scanf("%d", &d);
		fp = fopen("Library.dat", "rb+");
		rewind(fp);
		while(fread(&a, sizeof(a), 1, fp) == 1) {
			if(a.bkid == d) {
				printf("No record found");
			menu();
			
			}
		
		else{
			printf("YOUR RECORD WIIL BE PERMANNANTLY DELETED,CONTINUE?(Y/N) PRESS 1 FOR  YES AND 2 FOR NO");
			scanf("%d", &y);
			if(y == 1) {
				ft = fopen("test.dat", "w+");		
				rewind(fp);
				while(fread(&a, sizeof(a), 1, fp) == 1) {
					if(a.bkid != d) {
						fseek(ft, 0, SEEK_CUR);
						fwrite(&a, sizeof(a), 1, ft); 
		    			}                              
				}
					printf("RECORD SUCCESSFULLY DELETED\n");
				fclose(ft);
				fclose(fp);
				remove("Library.dat");
				rename("test.dat", "Library.dat"); 
				
					
					
		        			menu();	
					
				
			}
			
		}}
	}
}

/* View all the books available in library */
void viewbooks(void) {		
	int i = 0, j, v;
	system("clear");
	printf("************************  BOOK LIST  *************************\n");
	j = 4;
	fp = fopen("Library.dat", "rb+");
	while(fread(&a, sizeof(a), 1, fp) == 1) {
		printf("BRANCH :	%s\n", a.cat);
		printf("BOOK ID :		%d\n", a.bkid);
		printf("BOOK NAME :	%s\n", a.bkname);
		printf("AUTHOR :	%s\n", a.Authname);
		printf("QUANTY :	%d\n", a.qty);
		printf("PRICE :		%.2f\n", a.Price);
		
		printf("\n\n");
		j++;
		i = i + a.qty;
	}
	printf("TOTAL BOOKS = %d\n",i);

	printf("PRESS 1 2 GO 2 MAIN MENU :");
	scanf("%d", &v);
	if(v == 1) 
		menu();
	
}



/* Issue perticular book to member*/
void issuebooks() {				
	time_t td = time(0);   
	struct tm * now = localtime( & td );
	a.issued.dd = now->tm_mday;
	a.issued.mm = now->tm_mon;
	a.issued.yy = now->tm_year;
	printf("\n\n******** %d  %d  %d\n\n",a.issued.dd, a.issued.mm, a.issued.yy);
	int t, ch, y;
	system("clear");
	printf("BOOK ISSUE SECTION\n");
	
	FILE *fs;
	
					
				START:system("clear");
				int c = 0;
				while(1) {
					system("clear");
					
					printf("ENTER BOOK ID:\n");
					scanf("%d", &t);
					fp = fopen("Library.dat","rb+");
					fs = fopen("Issue.txt","ab+");
					if(checkid(t) == 0) {
			     			printf("THE BOOK IS AVAILABLE U CAN ISSUE IT\n");
			    			printf("ENTER MEMBER NAME:\n");
			    			scanf("%s", a.studname);
						a.issued.dd = now->tm_mday;
						a.issued.mm = now->tm_mon;
						a.issued.yy = now->tm_year;
			    	 		printf("Issued date = %d - %d - %d\n", a.issued.dd, a.issued.mm, a.issued.yy);
			    			printf("The BOOK of ID %d is issued ", a.bkid);
			    	 		
					if(c == 0) {
						printf("No record found\n");
					}
					fclose(fp);
					printf("\nIssue any more(Y/N) press 1 for YES and 2 for NO:");
					scanf("%d", &y);
					if(y == 1)
						goto START;
					else 
						menu();	
				
				}
				
}
}

/*void searchbooks() {	
system("clear");
	int d,y;
	fp = fopen("Library.dat", "rb+"); 
	
			
			printf("ENTER THE BOOK ID:");
			scanf("%d", &d);
			while(fread(&a, sizeof(a), 1, fp) == 1) {
				if(a.bkid == d) {
					printf("THE BOOK IS AVAILABLE\n");
		    			printf("ID:%d\n", a.bkid);
		   			printf("NAME:%s\n", a.bkname);
		    			printf("AUTHOR:%s\n", a.Authname);
		  			printf("QUANTITY:%d\n", a.qty);
		    			printf("PRICE.%.2f\n", a.Price);
					
		   			flag = 10;
				}
	
	   		}
	    		if(flag != 10) {
	    			printf("No Record Found\n");
			}
	    		printf("Try another search?(Y/N) press 1 for YES and 2 for NO");
			scanf("%d", &y);
	    		if(y == 1)
	    			searchbooks();
	    		else
	   			 menu();
	    		
		}		

}*/


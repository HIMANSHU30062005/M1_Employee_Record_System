#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <string.h>  
COORD coord = {0,0}; 

void gotoxy(int a,int b)
{
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void login()
{
	int a=0,i=0;
    char uname[20],c=' '; 
    char pword[20],code[20];
    char user[20]="user";
    char pass[20]="pass";
    do
{
	
    printf("\n  ::  LOGIN FORM  ::  ");
    printf(" \n     ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n     ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("***");
	    i++;
	}
	pword[i]='\0';
	i=0;
	 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO EMPLOYEE_RECORD_SYSTEM ******** LOGIN IS SUCCESSFUL**********");
	    printf("\n LOADING PLEASE WAIT........ \n");
    for(i=0; i<5; i++)
    {
        printf(".");
        Sleep(700);
    }
	printf("\n\n\n\t\t\t\tPress any key to continue..........");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY ## LOGIN IS UNSUCESSFUL ##");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}


int main()
{
	int i=0;
	login();
    FILE *fp, *ft; 
    char another, choice;

    
    typedef struct emp
    {
        char name[50]; 
        int age; 
        char address[20];
        float salary;
    };

    struct emp e; 

    char empname[50];

    long int recsize; 
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }

    recsize = sizeof(e);
    while(1)
    {
    	
        system("cls"); 
        
        printf(" \n  ::::::::::::::::::::::::::  |EMPLOYEES RECORD MANAGEMENT|  :::::::::::::::::::::::::: \n");
        gotoxy(30,05); 
		printf("1> Add Employee's Records"); 
        gotoxy(30,07);
        printf("2> List Employee's Records"); 
        gotoxy(30,9);
        printf("3> Modify Employee's Records"); 
        gotoxy(30,11);
        printf("4> Delete Employee's Records");
        gotoxy(30,13);
        printf("5> Exit System");
        gotoxy(30,15);
        printf("Your Choice: "); 
        fflush(stdin); 
        choice  = getche();
        switch(choice)
        
        
        {
        case '1':  
            system("cls");
            fseek(fp,0,SEEK_END); 

            another = 'y';
            while(another == 'y')  
            {
                printf("\nEnter name: ");
                scanf("%s",e.name);
                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("\nEnter Address:");
                scanf("%s",e.address);
                printf("\nEnter salary: ");
                scanf("%f", &e.salary);

                fwrite(&e,recsize,1,fp); 
                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        case '2':
            system("cls");
            printf("EMPLOYEE's RECORD LIST (name, age, address, salary)");
            rewind(fp); 
            while(fread(&e,recsize,1,fp)==1)  
            {
            	
                printf("\n\n%s \t\t%d \t%s \t%.2f",e.name,e.age,e.address,e.salary); 
            }
            getch();
            break;

        case '3':  
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the employee name to modify: ");
                scanf("%s", empname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)  
                {
                    if(strcmp(e.name,empname) == 0) 
                    {
                        printf("\nEnter new name,age,address and bs: ");
                        scanf("%s%d%s%f",e.name,&e.age,&e.address,&e.salary);
                        fseek(fp,-recsize,SEEK_CUR); 
                        fwrite(&e,recsize,1,fp); 
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of employee to delete: ");
                scanf("%s",empname);
                ft = fopen("Temp.dat","wb");  
                rewind(fp);
                while(fread(&e,recsize,1,fp) == 1)  
                {
                    if(strcmp(e.name,empname) != 0)  
                    {
                        fwrite(&e,recsize,1,ft); 
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT"); 
                rename("Temp.dat","EMP.DAT"); 
                fp = fopen("EMP.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(fp);  
            exit(0); 
        }
    }
    return 0;
}l
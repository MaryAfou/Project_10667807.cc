
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//STUDENT MANAGEMENT SYSTEM

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Headers inclusion

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <windows.h>

using namespace std;

//Structure defining


struct Stafftype
{
 char fst_name[50];//first name of staff
 char lst_name[50];//last name of staff
 char id[50];//ID of the staff
 char course[100];//course taught by staff
 int cel_no;//Phone number of staff

};

struct Coursetype
{
 char Name[50];//first name of course
 char Code[50];//Code of course
 int credits ;//credit hours of course
 float score;//Total score in course
 char  grade;//Grade of course

};
Coursetype course;

Stafftype staff;
    struct student
    {
        char first_name[50], last_name[50];
        char course[100];
        int section;
    };

    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;
     char courseName[50], staffName[50];
     

///////////////////////////////////////////////////
//Main function

int main()
{
 FILE *fp, *ft, *cp, *sp, *ct, *st ;
char another;
int i=0,j;//for processing usage 
char choice;//for getting choice
string find;//for sorting
string srch;
 long int recsize;
fp=fopen("users.txt","rb+");
sp=fopen("sat.txt","rb+");
cp=fopen("sub.txt","rb+");
    if (fp == NULL)
    {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }
   

    recsize = sizeof(e);
   long int  resize=sizeof(course);
long int rsize=sizeof(staff);
while(1)//outer loop
{ 
 system("cls");//Clear screen

//Level 1-Display process 
 cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
 cout<<"\n\n\t\t\tSTUDENT MANAGEMENT SYSTEM\n\n";
 cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
 cout<<"\n\n\t\t\tMAIN SCREEN\n\n";
 cout<<"Enter your choice: "<<endl;
 cout<<"1. Students"<<endl;
 cout<<"2. Course"<<endl;
 cout<<"3. Staff"<<endl;
 cout<<"4. Exit program"<<endl;
 cin>>choice;
fflush(stdin);
system("cls");//Clear screen


switch(choice)//first switch

case '1': //Student
 { 
while(1)
    {
        system("cls");

        cout << "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Add    Records";
        cout << "\n \t\t\t 2. List   Records";
        cout << "\n \t\t\t 3. Modify Records";
        cout << "\n \t\t\t 4. Delete Records";
        cout << "\n \t\t\t 5. Exit   Program";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice :=> ";
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the Firt Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course    : ";
                cin >> e.course;
                cout << "Enter the Section   : ";
                cin >> e.section;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
            
        case '2':
            system("cls");
            rewind(fp);
            cout << "=== View the Records in the Database ===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout <<"\n" << e.first_name << setw(10)  << e.last_name;
                cout << "\n";
                cout <<"\n" <<e.course <<  setw(8)  << e.section;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student : ";
                cin >> xlast_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "Enter new the Firt Name : ";
                        cin >> e.first_name;
                        cout << "Enter new the Last Name : ";
                        cin >> e.last_name;
                        cout << "Enter new the Course    : ";
                        cin >> e.course;
                        cout << "Enter new the Section   : ";
                        cin >> e.section;
                        fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout<<"record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student to delete : ";
                cin >> xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;

        case '5':
            {
             break;//inner switch breaking
            }
        } 
		break;
}
continue;

case '2'://course
{ 
while(1)//inner loop-2
{ 
system("cls");//Clear screen
//Level-2 Display process
cout<<"\t\t\t\tCOURSE\n\n\n";
cout<<"Enter your choice: "<<endl;
cout << "\n \t\t\t 1. Add    Course";
cout << "\n \t\t\t 2. List   Course";
cout << "\n \t\t\t 3. Modify Course";
cout << "\n \t\t\t 4. Delete Course";
cout << "\n \t\t\t 5. Back";
cout << "\n\n";
fflush(stdin);
cin>>choice;

switch (choice)
 {
        case '1' ://add course
            fseek(cp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter course Name : ";
                cin >> course.Name;
                cout << "Enter course Code :";
                cin >> course.Code;
                cout << "Enter credit hours: ";
                cin >> course.credits;
                cout << "Enter the score  : ";
                cin >> course.score;
                cout << "Enter the grade  : ";
                cin >> course.grade;
                fwrite(&course,resize,1,cp);
                cout << "\n Add Another course (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(cp);
            cout << "=== View the courses in the Database ===";
            cout << "\n";
            while (fread(&course,resize,1,cp) == 1)
            {
                cout << "\n";
                cout <<"\n" << course.Name << setw(8)  << course.Code<<setw(8)<<course.score;
                cout << "\n";
                 cout << "\n"<<course.credits<<setw(8)<<course.grade;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter name of course : ";
                cin >>courseName;

                rewind(cp);
                while (fread(&course,resize,1,cp) == 1)
                {
                    if (strcmp(course.Name,courseName) == 0)
                    {
                        cout << "Enter new Course Name : ";
                        cin >> course.Name;
                        cout << "Enter new Course Code: ";
                        cin >> course.Code;
                        cout << "Enter new credit hours    : ";
                        cin >> course.credits;
                        cout << "Enter new score : ";
                        cin >> course.score;
                        cout << "Enter new grade : ";
                        cin >> course.grade;
                        fseek(cp, - resize, SEEK_CUR);
                        fwrite(&course,resize,1,cp);
                        break;
                    }
                    else
                        cout<<"Course not found";
                }
                cout << "\n Modify Another Course (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


            case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter course to delete : ";
                cin >> courseName;

                ct = fopen("temp.dat", "wb");

                rewind(cp);
                while (fread (&course, recsize,1,cp) == 1)

                    if (strcmp(course.Name,courseName) != 0)
                    {
                        fwrite(&course,recsize,1,ct);
                    }
                fclose(cp);
                fclose(ct);
                remove("sub.txt");
                rename("temp.dat","sub.txt");

                cp=fopen("sub.txt","rb+");

                cout << "\n Delete Another course (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;

        case '5':
            {
             break;//inner switch breaking
            }
        } 
		break;
}
continue;

case '3'://staff
{ 
while(1)//inner loop-2
{ 
system("cls");//Clear screen
//Level-2 Display process
cout<<"\t\t\t\tSTAFF \n\n\n";
cout<<"Enter your choice: "<<endl;
cout << "\n \t\t\t 1. Add    Staff";
cout << "\n \t\t\t 2. List   Staff";
cout << "\n \t\t\t 3. Modify Staff";
cout << "\n \t\t\t 4. Delete Staff";
cout << "\n \t\t\t 5. Back";
cout << "\n\n";
fflush(stdin);
cin>>choice;

switch (choice)
 {
        case '1' ://add staff
            fseek(sp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter first Name of Staff : ";
                cin >> staff.fst_name;
                cout << "Enter last Name of Staff ";
                cin >> staff.lst_name;
                cout << "Enter ID of Staff ";
                cin >>staff.id;
                cout << "Enter course taught : ";
                cin >> staff.course;
                cout << "Enter Phone number of staff  : ";
                cin >> staff.cel_no;
                fwrite(&staff,rsize,1,sp);
                cout << "\n Add Another Staff (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(sp);
            cout << "=== View the Staff in the Database ===";
            cout << "\n";
            while (fread(&staff,rsize,1,sp) == 1)
            {
                cout << "\n";
                cout <<"\n" << staff.fst_name << setw(10)  << staff.lst_name<<setw(10)<<staff.id<<setw(10)<<staff.course<<setw(10)<<staff.cel_no;
                cout << "\n";
                
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter last name of staff : ";
                cin >>staffName;

                rewind(sp);
                while (fread(&staff,rsize,1,sp) == 1)
                {
                    if (strcmp(staff.fst_name,staffName) == 0)
                    {
                        cout << "Enter new staff first Name : ";
                        cin >> staff.fst_name;
                        cout << "Enter new staff last Name: ";
                        cin >> staff.lst_name;
                        cout << "Enter new staff ID : ";
                        cin >> staff.id;
                        cout << "Enter new staff course: ";
                        cin >> staff.course;
                        cout << "Enter new staff phone number : ";
                        cin >> staff.cel_no;
                        fseek(cp, - rsize, SEEK_CUR);
                        fwrite(&staff,rsize,1,cp);
                        break;
                    }
                    else
                        cout<<"staff not found";
                }
                cout << "\n Modify Another staff (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


            case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter staff last name to delete : ";
                cin >>staffName;

                st = fopen("temp.dat", "wb");

                rewind(sp);
                while (fread (&staff, rsize,1,sp) == 1)

                    if (strcmp(staff.lst_name,courseName) != 0)
                    {
                        fwrite(&staff,rsize,1,st);
                    }
                fclose(sp);
                fclose(st);
                remove("sat.txt");
                rename("temp.dat","sat.txt");

                sp=fopen("sat.txt","rb+");

                cout << "\n Delete Another staff (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;

        case '5':
            {
             break;//inner switch breaking
            }
        } 
		break;
}
continue;

  case '5':
            fclose(fp);
            cout << "\n\n";    
            cout << "\n\n";
            exit(0);
        }
   }
 
}//for loop

}
system("pause");
    return 0;
}


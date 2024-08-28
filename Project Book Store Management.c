/*name : Abdur Rahman Faruk khan
   ID : 2021794642
   sec :17
   project : Book store Management
*/


#include<stdio.h>
#include<string.h>  //using string functions
#include<windows.h> // for cursor positioning
#include<time.h>
struct Book_info{    // structure for book details

 char name[30];
 char id[10];
 int publish;
 int edition;
 char writter[25];
 float price;
};
typedef struct Book_info list;
void read(list A[],int n);      //  reads data from user and stores it in the
void showList(void);           // shows all pre stored data
void editlist(list A[],int n);// edits data and stores it
void searchid(list A[],int n);  // searches specific data inside all stored data
void saveTofile(list A[],int n); // saves all the data to a text file named by the user
void Deletebook(void);   // deletes a specific data from stored data

int main()
{
  int x; // to get user input for selecting choice
  time_t Ti=time(NULL);  // to display time on console
  struct tm timE=*localtime(&Ti);
  gotoxy(63,4);
  printf("--------------------------------------------");
  gotoxy(64,5);
  printf("<<< WELCOME TO READER'S POINT BOOK SHOP >>>");
  gotoxy(63,6);
  printf("--------------------------------------------");
  gotoxy(66,9);
  printf("**********************************");
  gotoxy(68,11);
  printf("Address:Dhaka 1205");
  gotoxy(68,12);
  printf("Email:readerspoint@gmail.com");
  gotoxy(68,13);
  printf("Contact :021236546");
  gotoxy(68,15);
  printf("Powered By Faruk Tech Tips");
  gotoxy(66,17);
  printf("**********************************");
  gotoxy(66,18);
  printf("Date : %d/%d/%d ",timE.tm_mday,timE.tm_mon+1,timE.tm_year+1900);
  gotoxy(66,19);
  printf("Time : %d:%d",timE.tm_hour,timE.tm_min);
  gotoxy(72,20);
  printf("press any key....");
  getch();
  system("cls");  // clears console
  a:printf("");  // a leble to return back to main menu
  gotoxy(63,5);
  printf("***Book Store Management***");
  gotoxy(63,7);
  printf("Select one of the following");
  gotoxy(63,10);
  printf(" 1.Enter Book/Books Details");
  gotoxy(63,11);
  printf(" 2.Show All Books");
  gotoxy(63,12);
  printf(" 3.Edit Book Details");
  gotoxy(63,13);
  printf(" 4.Search Book by ID");
  gotoxy(63,14);
  printf(" 5.Save To A Text File");
  gotoxy(63,15);
  printf(" 6.Delete A Book\n");
  gotoxy(63,16);
  printf(" 7.Exit");
  gotoxy(63,17);
  printf(" Enter your choice :");
  scanf("%d",&x);
  gotoxy(63,18);
  printf("Press any key.....");
  getch();
  system("cls"); // clears console

  if(x==1)
  {
    int n;
    gotoxy(3,2);
    printf("Enter Number of Books :");
    scanf("%d",&n);
    list book[n];
    read(book,n);
    goto a;      //returns to main menu after function ends
  }
  else if (x==2)
  {
    showList();
    goto a;      //returns to main menu after function ends
  }
  else if(x==3)
  {
    int z=200;
    list b[z];
    editlist(b,z);
    goto a;     //returns to main menu after function ends

  }
  else if(x==4)
  {
    int h=200;
    list ser[h];
    searchid(ser,h);
    goto a;    //returns to main menu after function ends
  }
  else if(x==5)
  {
    int s=200;
    list q[s];
    saveTofile(q,s);
    goto a;   //returns to main menu after function ends
  }
  else if(x==6)
  {
    Deletebook();
    goto a;   //returns to main menu after function ends
  }
  else if(x==7)
  {
    int e;   // takes data to ensure if user wants to exit
    gotoxy(60,5);
    printf("Do You Want To Exit?");
    gotoxy(61,7);
    printf("1.YES");
    gotoxy(75,7);
    printf("2.NO");
    gotoxy(63,9);
    printf("Enter choice :");
    scanf("%d",&e);
      if(e==1)
      {
        system("cls");
        goto f; // goes to end of main function to terminate programme
      }
      else if(e==2)
      {
        system("cls");
        goto a; //returns to main menu after function ends
      }
      else
      {
        system("cls");  // clears console
        gotoxy(60,5);
        printf("Invalid Input");
        gotoxy(60,7);
        printf("press any key....");
        getch();
        system("cls"); // clears console
        goto a;  //returns to main menu after function ends
      }
  }
  else
  {
    gotoxy(60,5);
    printf("Invalid Input!");
    gotoxy(60,7);
    printf("press any key....");
    getch();
    system("cls"); // clears console
    goto a;   //returns to main menu after function ends
  }

  f:gotoxy(60,5);
  printf("Good Bye");
  getch();

}
void gotoxy(int x,int y)  //to move cursor position
{
  COORD a;
  a.X=x;
  a.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void read(list A[],int n) //to read data from user
{
  int i;
  FILE *list;  // to save data to a text file which be read back to the structure array
  FILE *list2; // saves data that will be always displayed to the user
  printf("Do not use any space.Use only ( - ) or( _ )\n\n");
  for(i=0;i<n;i++)  // loop to take input from user
  {

    printf("Enter book name :");
    fflush(stdin);
    gets(A[i].name);
    printf("Enter ID : ");
    fflush(stdin);
    gets(A[i].id);
    printf("Enter Publishing Year : ");
    scanf("%d",&A[i].publish);
    printf("Enter Edition No :");
    scanf("%d",&A[i].edition);
    printf("Enter Writer name : ");
    fflush(stdin);
    gets(A[i].writter);
    printf("Enter Price : ");
    scanf("%f",&A[i].price);
    printf("\n");
  }
  list=fopen("listbooks.txt","a"); // saving to text file to read back to the  array
  for(i=0;i<n;i++) //loop to print into file
  {
    fprintf(list,"%s %s %d %d %s %0.2f\n",A[i].name,A[i].id,A[i].publish,A[i].edition,A[i].writter,A[i].price);
  }
  fclose(list);

  list2=fopen("listshow.txt","a"); // saving to text file that will be displayed to user
  for(i=0;i<n;i++) //loop to print into file
  {
    fprintf(list,"Book Name :%s\nID :%s\nPublishing year :%d\nEdition :%d\nWriter Name:%s\nPrice :%0.2f\n\n",A[i].name,A[i].id,A[i].publish,A[i].edition,A[i].writter,A[i].price);
  }
  fclose(list2);
  printf("Press any key....");
  getch();
  system("cls");  // clears console
   for(i=0;i<=10000;i++)
      {
          gotoxy(67,5);
          printf("Processing_%d",i/100);
      }
  system("cls"); // clears console
  gotoxy(67,5);
  printf("Data Entry Successful");
  gotoxy(67,6);
  printf("press any key....");
  getch();
  system("cls"); // clears console
}

void showList(void) // function to display data
{
  char ch;
  FILE *slist; // to open and read text file to display data
  slist=fopen("listshow.txt","r");
  if(slist==NULL)
  {
    gotoxy(65,5);
    printf("No Data Entered !\n");
    gotoxy(65,6);
    printf("press any key....");
    getch();
    system("cls"); // clears console
  }
  else
  {
    gotoxy(50,2);
    printf("List of books");
    gotoxy(48,3);
    printf("****************\n");
    while(!feof(slist)) // to read until file ends
    {
      ch=fgetc(slist);
      printf("%c",ch);
    }
    fclose(slist);
    printf(" \npress any key....");
    getch();
    system("cls"); // clears console
  }
}

void editlist(list A[],int n)
{
   int i=0,l=0,x,m;
   char ID[10]; // to read specific id from user
   FILE *list3; // to read from file and take input into array and enter new data into file
   FILE *list4; // to place new data into file that will be displayed
   list3=fopen("listbooks.txt","r");
   if(list3==NULL)
  {
    gotoxy(65,5);
    printf("No Data Entered !\n");
    gotoxy(65,6);
    printf("press any key....");
    getch();
    system("cls");// clears console
  }
   else
   {


     for(i=0;!feof(list3);i++,l++) //loop to read data into array
     {
      fscanf(list3,"%s %s %d %d %s %f",&A[i].name,&A[i].id,&A[i].publish,&A[i].edition,&A[i].writter,&A[i].price);

     }
     fclose(list3);
     b:printf("");  // b label to return to this point
     for(i=0;i<(l-1);i++) //loop to display data on console
     {
       printf("Name :%s\n",A[i].name);
       printf("ID :%s\n",A[i].id);
       printf("\n");
     }
      printf("Enter Book ID :");
      fflush(stdin);
      gets(ID);
      printf("press any key....");
      getch();
      system("cls"); // clears console

      int flag=0; // to control loop

     for(i=0;i<l;i++)
      {
        if(strcmp(ID,A[i].id)==0) // comparing user input id and prestored book id
         {
           m=i;
           flag=0;
           break;
         }
         else
         {
           flag=1;
         }
      }

      if(flag==1)
      {
           gotoxy(35,5);
           printf("Book not found");
           gotoxy(35,6);
           printf("press any key....");
           getch();
           system("cls"); // clears console
           goto b;
      }
      gotoxy(30,3);
      printf("Current Book Name :%s",A[m].name);
      gotoxy(30,4);
      printf("Current Book ID :%s",A[m].id);
      gotoxy(30,5);
      printf("Current Publishing Year :%d",A[m].publish);
      gotoxy(30,6);
      printf("Current Edition No :%d",A[m].edition);
      gotoxy(30,7);
      printf("Current Writer :%s",A[m].writter);
      gotoxy(30,8);
      printf("Current Price :%0.2f",A[m].price);
      gotoxy(55,1);
      printf("DO NOT USE ANY SPACE.USE (- or _)");
      gotoxy(78,3);
      printf("Enter New Book Name :");
      fflush(stdin);
      gets(A[m].name);
      gotoxy(78,4);
      printf("Enter New ID : ");
      fflush(stdin);
      gets(A[m].id);
      gotoxy(78,5);
      printf("Enter New Publishing Year : ");
      scanf("%d",&A[m].publish);
      gotoxy(78,6);
      printf("Enter New Edition No :");
      scanf("%d",&A[m].edition);
      gotoxy(78,7);
      printf("Enter New Writer name : ");
      fflush(stdin);
      gets(A[m].writter);
      gotoxy(78,8);
      printf("Enter New Price : ");
      scanf("%f",&A[m].price);
      gotoxy(60,13);
      printf("press any key....");
      getch();

      list3=fopen("listbooks.txt","w"); // loop to print data into file
      for(i=0;i<(l-1);i++)
      {
       fprintf(list3,"%s %s %d %d %s %0.2f\n",A[i].name,A[i].id,A[i].publish,A[i].edition,A[i].writter,A[i].price);
      }
      fclose(list3);

      list4=fopen("listshow.txt","w"); // loop to print data into file that will be displayed
      for(i=0;i<(l-1);i++)
      {
        fprintf(list4,"Book Name :%s\nID :%s\nPublishing year :%d\nEdition :%d\nWriter Name:%s\nPrice :%0.2f\n\n",A[i].name,A[i].id,A[i].publish,A[i].edition,A[i].writter,A[i].price);
      }
      fclose(list4);
      system("cls");
     for(i=0;i<=10000;i++)
      {
        gotoxy(67,5);
        printf("Processing_%d",i/100);
      }
     system("cls"); // clears console
      gotoxy(60,5);
      printf("Change Successful");
      getch();
      system("cls");
   }

}

void searchid(list A[],int n) // function to search specific data from all data
{

  int i=0,k=0,x,m;
   char ID[10]; // to read specific id from user
   FILE *listc;
   listc=fopen("listbooks.txt","r"); // to read data from file into array
   if(listc==NULL)
  {
    gotoxy(60,5);
    printf("No Data Entered !\n");
    gotoxy(60,6);
    printf("press any key....");
    getch();
    system("cls");// clears console
  }
   else
   {


     for(i=0;!feof(listc);i++,k++) //loop to read data into array
     {
      fscanf(listc,"%s %s %d %d %s %f",&A[i].name,&A[i].id,&A[i].publish,&A[i].edition,&A[i].writter,&A[i].price);


     }
     fclose(listc);
     c:printf(""); // c label to return to this point
     for(i=0;i<(k-1);i++)
     {
       printf("Name :%s\n",A[i].name);
       printf("ID :%s\n",A[i].id);
       printf("\n");
     }

      printf("Enter Book ID :");
      fflush(stdin);
      gets(ID);
      printf("press any key....");
      getch();
      system("cls"); // clears console
      int flag=0;

     for(i=0;i<k;i++)
      {
        if(strcmp(ID,A[i].id)==0)
         {
           m=i;
           flag=0;
           break;
         }
         else
         {
            flag=1;
         }
      }
      if(flag==1)
      {
        gotoxy(60,5);
        printf("Book not found");
        gotoxy(61,6);
        printf("press any key....");
        getch();
        system("cls");
        goto c;
      }
      gotoxy(55,5);
      printf("Book Name :%s\n",A[m].name);
      gotoxy(55,6);
      printf("Book ID :%s\n",A[m].id);
      gotoxy(55,7);
      printf("Publishing Year :%d\n",A[m].publish);
      gotoxy(55,8);
      printf("Edition No :%d\n",A[m].edition);
      gotoxy(55,9);
      printf("Writer :%s\n",A[m].writter);
      gotoxy(55,10);
      printf("Price :%0.2f\n",A[m].price);
      gotoxy(60,12);
      printf("press any key...");
      getch();
      system("cls"); // clears console

   }
}

void saveTofile(list A[],int n) // function to save data into text file name given by user
{
  char fname[40]; // reads file name from user
  char fname2[]=".txt"; //joins formate at the end of the file name given by user.
                       // just in case if the user forgets to give extension
  int i,j=0;
  FILE *liste; //opens file to read data and take input into array
  FILE *listU; // to print all data into the user named file
  liste=fopen("listbooks.txt","r");
  if(liste==NULL)
  {
    gotoxy(65,5);
    printf("No data Entered to Transfer !");
    gotoxy(65,6);
    printf("press any key....");
    getch();
    system("cls");// clears console
    goto g;
  }
   for(i=0;!feof(liste);i++,j++) //loop to read until file ends
     {
      fscanf(liste,"%s %s %d %d %s %f",&A[i].name,&A[i].id,&A[i].publish,&A[i].edition,&A[i].writter,&A[i].price);
     }
     fclose(liste);
  gotoxy(60,5);
  printf("Enter File Name : ");
  fflush(stdin);
  gets(fname);
  strcat(fname,fname2); // joins extension to user given file name
  gotoxy(60,7);
  printf("press any key....");
  getch();
  system("cls"); // clears console
  listU=fopen(fname,"w");
    for(i=0;i<(j-1);i++) //loop to print all data into user given file name
      {
        fprintf(listU,"Book Name :%s\nID :%s\nPublishing year :%d\nEdition :%d\nWriter Name:%s\nPrice :%0.2f\n\n",A[i].name,A[i].id,A[i].publish,A[i].edition,A[i].writter,A[i].price);
      }
     fclose(listU);
     system("cls"); // clears console
     for(i=0;i<=10000;i++)
      {
        gotoxy(67,5);
        printf("Processing_%d",i/100);
      }
     system("cls"); // clears console
     gotoxy(60,5);
     printf(" File Created and Data Saved");
    g:printf("");
     gotoxy(60,7);
     printf("press any key...."); //label to return to this point
     getch();
     system("cls"); // clears console
}

void Deletebook(void) //function to delete specific data from all stored data
{
  list A[200];
  int i,k=0,x,m;
   char ID[10];
   FILE *listc; //to read all data from file into array and print new data into file
   FILE *listd; // to print new data into file
   listc=fopen("listbooks.txt","r");
   if(listc==NULL)
  {
    gotoxy(60,5);
    printf("No Data Entered !\n");
    gotoxy(60,7);
    printf("press any key....");
    getch();
    system("cls"); // clears console
  }
   else
   {


     for(i=0;!feof(listc);i++,k++) // loop to read until file ends
     {

      fscanf(listc,"%s %s %d %d %s %f",&A[i].name,&A[i].id,&A[i].publish,&A[i].edition,&A[i].writter,&A[i].price);

     }
     fclose(listc);
     d:printf(""); // d label to return to this point if invailde data is entered
     for(i=0;i<(k-1);i++) // to display name and id
     {
       printf("Name :%s\n",A[i].name);
       printf("ID :%s\n",A[i].id);
       printf("\n");
     }
      printf("Enter Book ID :");
      fflush(stdin);
      gets(ID);
      printf("press any key....");
      getch();
      system("cls"); // clears console
        int flag=0;
     for(i=0;i<k;i++)
      {
        if(strcmp(ID,A[i].id)==0) //comparing book id and user given id
         {
           m=i;
           flag=0;
           break;
         }
         else
         {
           flag=1;
         }
      }
      if(flag==1)
      {
        gotoxy(60,5);
        printf("Book not found");
        gotoxy(60,7);
        printf("press any key....");
        getch();
        system("cls");// clears console
        goto d;
      }

      gotoxy(60,5);
      printf("  Book Name :%s\n",A[m].name);
      gotoxy(60,6);
      printf("  Book ID :%s\n",A[m].id);
      gotoxy(60,7);
      printf("  Publishing Year :%d\n",A[m].publish);
      gotoxy(60,8);
      printf("  Edition No :%d\n",A[m].edition);
      gotoxy(60,9);
      printf("  Writer :%s\n",A[m].writter);
      gotoxy(60,10);
      printf("  Price :%0.2f\n",A[m].price);
      gotoxy(60,12);
      printf("press any key to delete details");
      getch();



       listc=fopen("listbooks.txt","w");
     for(i=0;i<(k-1);i++) //loop to enter new data into file
     {
        if(strcmp(ID,A[i].id)!=0)
        {
          fprintf(listc,"%s %s %d %d %s %0.2f\n",A[i].name,A[i].id,A[i].publish,A[i].edition,A[i].writter,A[i].price);
        }
     }
     fclose(listc);

     listd=fopen("listshow.txt","w");
     for(i=0;i<k-1;i++) //loop to enter new data into file that will be displayed
     {
        if(strcmp(ID,A[i].id)!=0)
        {
          fprintf(listd,"Book Name :%s\nID :%s\nPublishing year :%d\nEdition :%d\nWriter Name:%s\nPrice :%0.2f\n\n",A[i].name,A[i].id,A[i].publish,A[i].edition,A[i].writter,A[i].price);
        }
     }
     fclose(listd);
     system("cls");// clears console
      for(i=0;i<=10000;i++)
      {
        gotoxy(67,5);
        printf("Processing_%d",i/100);
      }
     system("cls");// clears console
     gotoxy(60,5);
     printf(" Book Details deleted ");
     gotoxy(63,7);
     printf("press any key....");
     getch();
     system("cls");// clears console


   }
}



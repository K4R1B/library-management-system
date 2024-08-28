#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

COORD coordinate={0,0};
void gotoxy(int x, int y)
{
    coordinate.X=x;
    coordinate.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
}
struct admin{
    char username[50],fname[30],lname[30],pass[10],conpass[10];

}ad;
struct employee{
    char fstn[30],lastn[30],pssem[10],conpssem[10],address[100];
    int id,login,logout,loginhr,loginmin,loginsec,logoutmin,logoutsec,logouthr;
    double salary,age;

}emp;
void adminMenu(void);
void addemployee(void);
void viewemployee(void);
void modifyemployee(void);
void deleteemployee(void);
void EmpStat(void);
void dailyRec(void);
void commonpanel(void);
void mainMenu(void);
void Mangemenu(void);
char anotherOne;
int i;
long long int resize=sizeof(emp);
void main(void)
{
    Mangemenu();
}
void Mangemenu(void)
{

int catChoose;
    system("cls");
    gotoxy(20,10); printf("Welcome to employee management system");
    gotoxy(20,12); printf("Choose your category: ");
    gotoxy(10,14); printf("Administrative control [1]");
    gotoxy(10,16); printf("Common panel [2]");
    gotoxy(20,18); printf("Which category you want to choose (1/2) : ");
    scanf("%d", &catChoose);


    switch(catChoose){


        case 1:{
                mainMenu();

                break;
            }
            case 2: {
                system("cls");
            commonpanel();
            break;
            }

    }
    getch();
}
void mainMenu(void)
{
    char signupOp[1],ch[1],signINpass[10],signINuser[20];
     int catChoose,adchoose,i;
    long long int size=sizeof(ad);
    FILE *fp;
    fp=fopen("admin_data.txt","a");
     stream:
                system("cls");
            gotoxy(20,5); printf("If you are a new administrative member please SIGN UP first.\n\t\t    If you already have an administrative account then SIGN IN.\n");
            gotoxy(30,7); printf("[1] SIGN UP");
            gotoxy(30,8); printf("[2] SIGN IN");
            gotoxy(30,10); printf("Enter your choice: ");
            scanf("%d",&adchoose);
            for(i=0;i<=10000;i++)
            {
                printf("\r\t\tProcessing_%d",i/100);
            }

            switch(adchoose){
                case 1: {
                    system("cls");
                    gotoxy(20,5); printf("Welcome!! Please SIGN UP to create your Administrative account.");
                    gotoxy(30,7); printf("Do you want to create new account? (Y/N): ");
                    scanf("%s",signupOp);
                    fseek(fp,0,SEEK_END);
                   while((strcmp(signupOp,"y")==0)||(strcmp(signupOp,"Y")==0))
                        {

                            gotoxy(20,10); printf("First name: "); scanf("%s",ad.fname);
                            gotoxy(60,10); printf("Last name: "); scanf("%s",ad.lname);
                            gotoxy(20,12); printf("Welcome %s %s! Please set up an user name and password to complete your account.",ad.fname,ad.lname);
                            gotoxy(30,14);fflush(stdin); printf("Username: "); gets(ad.username);
                            gotoxy(30,16); printf("Password: ");
                            for(i=0;i<6;i++)
                            {
                                ad.pass[i]=getch();
                                printf("* ");
                            }
                            ad.pass[6]='\0';
                            password:
                            gotoxy(60,16); printf("confirm Password: ");
                            for(i=0;i<6;i++)
                            {
                                ad.conpass[i]=getch();
                                printf("* ");
                            }
                            ad.conpass[6]='\0';
                            if(strcmp(ad.conpass,ad.pass)==0){
                            gotoxy(30,19);printf("Password matched!                     ");
                            gotoxy(30,21);printf("Account created successfully!");

                            fwrite(&ad,size,1,fp);
                            fclose(fp);
                            gotoxy(30,23);
                            printf("Press any key to continue ");
                            getch();
                            system("cls");
                            adminMenu();
                            }
                            else {
                                gotoxy(30,19);printf("Password didn't matched! try again");
                                goto password;
                            }
                        }
                         if((strcmp(signupOp,"n")==0)||(strcmp(signupOp,"N")==0))
                        {

                             goto stream;
                        }

                        break;
                    }
                    case 2:{

                        system("cls");
                        fp=fopen("admin_data.txt","a+");
                        gotoxy(20,5);printf("Welcome to administrative control panel! Sign in to control your company details.");
                        gotoxy(30,7); printf("Username: "); fflush(stdin);gets(signINuser);
                        gotoxy(30,9); printf("Password: "); fflush(stdin);
                        for(i=0;i<6;i++)
                        {
                            signINpass[i]=getch();
                            printf("* ");
                        }
                        signINpass[6]='\0';
                        while(getch()!=13);
                       rewind(fp);
                    while(fread(&ad,size,1,fp)==1)  /// fetch all record from file
                    {
                        {
                        if(strcmp(ad.username,signINuser)==0){
                            if(strcmp(ad.pass,signINpass)==0)
                            gotoxy(20,11); printf("Welcome %s %s you have successfully sign in!\n",ad.fname,ad.lname);
                            gotoxy(30,15); printf("Press any key to continue: ");
                            getch();
                            adminMenu();

                        }
                       }
                       break;
                    }
                    break;
                    }
                }
}
void adminMenu(void)
{
        system("cls");
        char adminChoice[2];
        int viewemp,addemp,modemp,delemp,rethome;
        system("cls");
        gotoxy(30,5); printf("Welcome to administrative panel. ");
        gotoxy(35,9);printf("Admin options-->");
        gotoxy(30,11);printf(" Add a new employee                        [1]");
        gotoxy(30,13);printf(" View employees' list                      [2]");
        gotoxy(30,15);printf(" Search and modify an employee details     [3]");
        gotoxy(30,17);printf(" Remove an employee                        [4]");
        gotoxy(30,19);printf(" RETURN TO HOMEPAGE                        [5]");
        gotoxy(25,23);printf("Enter your choice: ");
        gets(adminChoice);
        addemp=strcmp(adminChoice,"1");
        viewemp=strcmp(adminChoice,"2");
        modemp=strcmp(adminChoice,"3");
        delemp=strcmp(adminChoice,"4");
        rethome=strcmp(adminChoice,"5");

        if(rethome==0){
            for(i=0;i<=10000;i++)
            {
                printf("\r\t\tProcessing_%d",i/100);
            }
            system("cls");
            Mangemenu();

            getch();
        }
        if(addemp==0){

            addemployee();
        }
        if(viewemp==0){
            system("cls");
            gotoxy(50,5); printf("LIST OF EMPLOYEES");
            viewemployee();
        }
        if(modemp==0){

            modifyemployee();
        }
        if(delemp==0){
            system("cls");
            deleteemployee();
        }
}
void addemployee(void)
{
    int i;
    FILE *fe;
        fe=fopen("Employee_data.txt","rb+");
        if(fe==NULL)
        {
                fe=fopen("Employee_data.txt","wb+");
        }
    fseek(fe,0,SEEK_END);
    anotherOne='y';
    while (anotherOne== 'y'){
        system("cls");
        gotoxy(30,5); printf("ADD A NEW EMPLOYEE");
        gotoxy(20,7);printf("Employee ID: "); scanf("%d",&emp.id); fflush(stdin);
        gotoxy(20,9); printf("First Name: "); gets(emp.fstn); fflush(stdin);
        gotoxy(60,9); printf("Last Name: "); gets(emp.lastn); fflush(stdin);
        gotoxy(20,11); printf("Address(District): "); gets(emp.address); fflush(stdin);
        gotoxy(20,13); printf("Age: "); scanf("%lf",&emp.age);
        gotoxy(60,13); printf("Salary: "); scanf("%lf",&emp.salary);
        gotoxy(20,15); printf("Welcome %s %s! Please create a password, which will you need to use daily record panel.",emp.fstn,emp.lastn);
        gotoxy(30,17); printf("Password: ");
        for(i=0;i<6;i++)
        {
            emp.pssem[i]=getch();
            printf("* ");
            }
            emp.pssem[6]='\0';
            emppassword:
            gotoxy(60,17); printf("confirm Password: ");
            for(i=0;i<6;i++)
            {
            emp.conpssem[i]=getch();
            printf("* ");
            }
            emp.conpssem[6]='\0';
            if(strcmp(emp.conpssem,emp.pssem)==0){
            gotoxy(30,19);printf("Password matched! Employee details saved!");
            }
            else {
            gotoxy(30,19);printf("Password didn't matched! try again");
            goto emppassword;
                }
            fwrite(&emp,resize,1,fe);
            gotoxy(30,21);printf("Do you want you add another employee?(y/n): ");
            fflush(stdin);
            anotherOne=getch();
    }
    fclose(fe);
    adminMenu();
}
void viewemployee(void)
{
    int i;
    FILE *fe;
        fe=fopen("Employee_data.txt","rb+");
        if(fe==NULL)
        {
                fe=fopen("Employee_data.txt","wb+");
        }
        gotoxy(5,8); printf("\t\tEmployee ID\t\tEmployee Name\tEmployee Age\t\tAddress\t\tSalary");
        rewind(fe); ///this moves file cursor to start of the file
            while(fread(&emp,resize,1,fe)==1)  /// read the file and fetch the record one record per fetch
            {

                printf("\n\t\t| %10d \t|    %s %s     \t|    %.1lf\t|  %15s  \t|  %6.2f  |",emp.id,emp.fstn,emp.lastn,emp.age,emp.address,emp.salary); /// print the name, age and basic salary
            }
            printf("\n\n\t\t\tPress any key to return_");
            getch();
            printf("\n\n");
            for(i=0;i<=10000;i++)
            {
                printf("\r\t\tSaving_Data_%d",i/100);
            }
        fclose(fe);
        adminMenu();
}
void modifyemployee(void)
{
    int i,srchID;
    char modOption[1];
    FILE *fe;
        fe=fopen("Employee_data.txt","rb+");
        if(fe==NULL)
        {
                fe=fopen("Employee_data.txt","wb+");
        }
            anotherOne = 'y';
            while(anotherOne == 'y')
            {
            system("cls");
            gotoxy(40,5); printf("SEARCH AND MODIFY EMPLOYEE DETAILS");
            gotoxy(20,8);printf("Enter employee ID to search: ");
            scanf("%d",&srchID);
                rewind(fe); ///this moves file cursor to start of the file
                while(fread(&emp,resize,1,fe)==1)  /// fetch all record from file
                {
                    if(emp.id==srchID)  ///if entered name matches with that in file
                    {
                        gotoxy(25,10);printf("FOUND!! Here is his details:                                  ");
                        printf("\n\n\t\t\tFirst name:  %s  \t\tLast name:  %s  \n\t\t\tAge:   %.1lf   \t\tAddress:  %s   \n\t\t\tSalary:  %.2lf   \n",emp.fstn,emp.lastn,emp.age,emp.address,emp.salary);
                        gotoxy(25,15); printf("Do you want to modify his details(Y/N): ");
                        fflush(stdin);
                        gets(modOption);
                        if((strcmp(modOption,"Y")==0)||(strcmp(modOption,"y")==0))
                        {
                        system("cls");
                        gotoxy(40,5);printf("MODIFY DATA");
                        gotoxy(25,8); printf("%s's stored details given below: ",emp.fstn);
                        printf("\n\n\t\tID:  %6d  \n\t\tFirst name:  %s  \t\tLast name:  %s  \n\t\tAge:   %.1lf   \t\t\tAddress:  %s   \n\t\tSalary:  %.2lf   \n",emp.id,emp.fstn,emp.lastn,emp.age,emp.address,emp.salary);
                        gotoxy(20,15); printf("Enter modified data: ");
                        gotoxy(20,17); printf("Employee ID: "); scanf("%d",&emp.id); fflush(stdin);
                        gotoxy(20,18); printf("First Name: "); gets(emp.fstn); fflush(stdin);
                        gotoxy(60,18); printf("Last Name: "); gets(emp.lastn); fflush(stdin);
                        gotoxy(20,19); printf("Address(District): "); gets(emp.address); fflush(stdin);
                        gotoxy(60,19); printf("Age: "); scanf("%lf",&emp.age);
                        gotoxy(20,20); printf("Salary: "); scanf("%lf",&emp.salary);

                        fseek(fe,-resize,SEEK_CUR); /// move the cursor 1 step back from current position
                        fwrite(&emp,resize,1,fe);/// override the record
                        fclose(fe);
                        break;
                    }
                    break;
                }
              else  {
                    gotoxy(25,10);printf("Employee ID not available!");

                }
                }
               gotoxy(25,23); printf("Do you want search Again to modify another record?(y/n): ");
                fflush(stdin);
                anotherOne = getche();
            }
            printf("\n\n");
            for(i=0;i<=10000;i++)
            {
                printf("\r\t\tSaving_Data_%d",i/100);
            }
        adminMenu();

}

void deleteemployee(void)
{
     int i,srchID;
     char delOption[1],findemp='f';
     FILE *fe,*temp;
        fe=fopen("Employee_data.txt","rb+");
        if(fe==NULL)
        {
                fe=fopen("Employee_data.txt","wb+");
        }
            anotherOne = 'y';
            while(anotherOne == 'y')
            {
                system("cls");
                gotoxy(40,5); printf("REMOVE AN EMPLOYEE");
                gotoxy(20,8);printf("Enter employee ID to remove: ");
                scanf("%d",&srchID);
                rewind(fe); /// move record to starting of file
                while(fread(&emp,resize,1,fe)==1)  /// fetch all record from file
                {
                    if(emp.id==srchID)  ///if entered name matches with that in file
                    {
                        gotoxy(25,10);printf("Here is his/her details:                                  ");
                        printf(" \n\n\t\t\tFirst name:  %s  \t\tLast name:  %s  \n \t\t\tAge:   %.1lf   \t\t\tAddress:  %s   \n \t\t\tSalary:  %.2lf   \n",emp.fstn,emp.lastn,emp.age,emp.address,emp.salary);
                    }

                }
                temp = fopen("Temp.txt","wb+");  /// create a intermediate file for temporary storage
                rewind(fe); /// move record to starting of file
                while(fread(&emp,resize,1,fe) == 1)  /// read all records from file
                {
                    if(emp.id!=srchID)  /// if the entered record match
                    {

                        fwrite(&emp,resize,1,temp); /// move all records except the one that is to be deleted to temp file
                    }
                }
                gotoxy(25,17); printf("This employee has successfully removed from the database.");
                fclose(fe);
                fclose(temp);
                remove("Employee_data.txt"); /// remove the orginal file
                rename("Temp.txt","Employee_data.txt"); /// rename the temp file to original file name
                temp = fopen("Employee_data.txt", "rb+");
                gotoxy(25,20); printf("Do you want to delete another record? (y/n)");
                fflush(stdin);
                anotherOne = getche();
            }
             printf("\n\n");
            for(i=0;i<=10000;i++)
            {
                printf("\r\t\tSaving_Data_%d",i/100);
            }
        adminMenu();

}
char findEmp;
void commonpanel(void)
{
    system("cls");
    int comChoice,i;
    gotoxy(40,5);printf("WELCOME TO COMMON PANEL");
    gotoxy(20,8); printf("By this common panel an employee will be able to log in and log out");
    gotoxy(35,10); printf("Daily Entry record     [1]");
    gotoxy(35,12); printf("Employees' status      [2]");
    gotoxy(35,14); printf("BACK TO THE HOME MENU  [3]");
    gotoxy(25,18); printf("Enter your choice(1/2/3): ");
    scanf("%d",&comChoice);
    switch(comChoice)
    {
        case 1: dailyRec();
                break;
        case 2: EmpStat();
                break;
        case 3: {
                for(i=0;i<=10000;i++)
            {
                printf("\r\t\tReturning_%d",i/100);
            }
            Mangemenu();
            break;
        }
    }
}
void dailyRec(void)
{
    int i,id,logChoice;
    char firstname[50], lastname[50], password[10],cnfrmpassword[10];
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    FILE *fe;
        fe=fopen("Employee_data.txt","rb+");
        if(fe==NULL)
        {
                fe=fopen("Employee_data.txt","wb+");
        }
        system("cls");
        gotoxy(35,5); printf("WELCOME TO DAILY TIME RECORD MANAGEMENT SYSTEM");
        gotoxy(40,8);printf("[1]  Employee Log in");
        gotoxy(40,10);printf("[2]  Employee Log out");
        gotoxy(35,12);printf("Enter your choice: ");
        scanf("%d",&logChoice);
        switch(logChoice)
        {
            case 1: {
                system("cls");
                gotoxy(35,5); printf("WELCOME TO LOG IN SECTION");
                gotoxy(20,8);printf("ID: ");
                scanf("%d",&id);
                gotoxy(60,8); printf("Password: ");
            for(i=0;i<6;i++)
            {
            password[i]=getch();
            printf("* ");
            }
            password[6]='\0';
            cnfrmpass:
            gotoxy(60,10); printf("confirm Password: ");
            for(i=0;i<6;i++)
            {
            cnfrmpassword[i]=getch();
            printf("* ");
            }
            cnfrmpassword[6]='\0';
            while(getch()!=13);
            if(strcmp(password,cnfrmpassword)==0) {
            gotoxy(30,12);printf("Password matched!");
            }
            else {
            gotoxy(30,12);printf("Password mismatched! Try again");
            goto cnfrmpass;
            }
            findEmp='f';
            rewind(fe);
            while(fread(&emp,resize,1,fe)==1)
            {
            if(emp.id==id&&(strcmp(emp.pssem,password)==0))
            {
                gotoxy(30,12); printf("You have successfully logged in!");
                gotoxy(35,15);printf("Name: %s %s",emp.fstn,emp.lastn);
                gotoxy(35,16);printf("Log in time: %02d:%02d:%02d",tm.tm_hour, tm.tm_min, tm.tm_sec);
                gotoxy(35,17);printf("Log in date: %02d/%02d/%04d",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
                emp.login=1;
                emp.loginhr=tm.tm_hour;
                emp.loginmin=tm.tm_min;
                emp.loginsec=tm.tm_sec;
                fseek(fe,-resize,SEEK_CUR);
                fwrite(&emp,resize,1,fe);
                fclose(fe);
            }
            else{
                    gotoxy(30,12);
                printf("Employee ID invalid!                               ");
            }
            }
             gotoxy(30,20);printf("Press any key to go back to common panel.");
                getch();
                system("cls");
                commonpanel();
            }
            break;
            case 2: {
                system("cls");
                gotoxy(35,5); printf("WELCOME TO LOG OUT SECTION");
                gotoxy(20,8);printf("ID: ");
                scanf("%d",&id);
                gotoxy(60,8); printf("Password: ");
            for(i=0;i<6;i++)
            {
            password[i]=getch();
            printf("* ");
            }
            password[6]='\0';
            cnfrmpassout:
            gotoxy(60,10); printf("confirm Password: ");
            for(i=0;i<6;i++)
            {
            cnfrmpassword[i]=getch();
            printf("* ");
            }
            cnfrmpassword[6]='\0';
            while(getch()!=13);
            if(strcmp(password,cnfrmpassword)==0) {
            gotoxy(30,12);printf("Password matched!");
            }
            else {
            gotoxy(30,12);printf("Password mismatched! Try again");
            goto cnfrmpassout;
            }
            rewind(fe);
            while(fread(&emp,resize,1,fe)==1)
            {
            if(emp.id==id&&(strcmp(emp.pssem,password)==0))
            {
                gotoxy(30,12); printf("You have successfully logged out!");
                gotoxy(35,15);printf("Name: %s %s",emp.fstn,emp.lastn);
                gotoxy(35,16);printf("Log out time: %02d:%02d:%02d",tm.tm_hour, tm.tm_min, tm.tm_sec);
                gotoxy(35,17);printf("Log out date: %02d/%02d/%04d",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
                emp.logout=1;
                emp.logouthr=tm.tm_hour;
                emp.logoutmin=tm.tm_min;
                emp.logoutsec=tm.tm_sec;
                fseek(fe,-resize,SEEK_CUR);
                fwrite(&emp,resize,1,fe);
                fclose(fe);
            }
            else{
                    gotoxy(30,12);
                printf("Employee ID invalid!                               ");
            }
            }
                gotoxy(30,20);printf("Press any key to go back to common panel.");
                getch();
                system("cls");
                commonpanel();
            }
             break;
        }


}
void EmpStat(void)
{
    system("Cls");
    gotoxy(60,5); printf("WELCOME TO EMPLOYEE STATUS PANEL");
    int i;
    FILE *fe;
        fe=fopen("Employee_data.txt","rb+");
        if(fe==NULL)
        {
                fe=fopen("Employee_data.txt","wb+");
        }
        gotoxy(34,10);printf("Employee ID\tEmployee Name\t\tLogin status\tLogin time\tLogout status\tLogout time");
        rewind(fe); ///this moves file cursor to start of the file
            while(fread(&emp,resize,1,fe)==1)  /// read the file and fetch the record one record per fetch
            {

                printf("\n\t\t\t\t| %10d \t|    %s %s     \t",emp.id,emp.fstn,emp.lastn);/// print the name, age and basic salary
                if(emp.login==1) {
                        printf("|   Logged in   "); printf("| %02d : %02d : %02d  ",emp.loginhr,emp.loginmin,emp.loginsec);
                }
                else {  printf("|       NOT     ");  printf("| not available ");}
                if(emp.logout==1) {
                        printf("|   Logged out  ");  printf("| %02d : %02d : %02d  |",emp.logouthr,emp.logoutmin,emp.logoutsec);
                }
                else {  printf("|       NOT     ");  printf("| not available |");
            }}
            printf("\n\n\t\t\tPress any key to return_");
            getch();
            printf("\n\n");
            for(i=0;i<=10000;i++)
            {
                printf("\r\t\tLoading_%d",i/100);
            }
        fclose(fe);
        commonpanel();

}

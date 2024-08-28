#include<stdio.h>
#include<windows.h>
void gotoxy(int x,int y);
int main()
{
  gotoxy(55,7);
  printf("Hello world\n");
  printf("press any key");
  getch();

  system("cls");
  gotoxy(55,7);
  printf("\tfuck you");
}
void gotoxy(int x,int y)
{
  COORD a;
  a.X=x;
  a.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}


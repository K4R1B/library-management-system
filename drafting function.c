#include<stdio.h>
#include<string.h>
struct Book_info{

 char name[20];
 int id;
 float price;
};
typedef struct Book_info list;
void read(list A[],int n);
void showList(list A[],int n);
void alterprice(list A[],int n);
int main()
{
  int n,x;
  printf("Enter quantity of books :");
  scanf("%d",&n);
  list B[n];
  read(B,n);
  printf("Enter your choice : ");
  printf("     Press 1 for book details      Press 2 for change price and show details\n");
  scanf("%d",&x);
  while(1)
  {
    if(x==1)
    {
      showList(B,n);
      break;
    }
    else if (x==2)
    {
      alterprice(B,n);
      break;
    }
    else
      continue;
  }

  return 0;
}
void read(list A[],int n)
{
  int i;
  FILE *list;
  for(i=0;i<n;i++)
  {
    printf("Enter book name(%d) :",i+1);
    fflush(stdin);
    gets(A[i].name);
    printf("Enter ID(%d) :",i+1);
    scanf("%d",&A[i].id);
    printf("Enter price(%d) :",i+1);
    scanf("%f",&A[i].price);
    printf("\n");
  }
  list=fopen("listbooks.txt","w");
  for(i=0;i<n;i++)
  {
    fprintf(list,"name :%s\nid : %d\nprice : %f\n\n",A[i].name,A[i].id,A[i].price);
  }
  fclose(list);
}

void showList(list A[],int n)
{
  int i;
  printf("\n");
  for(i=0;i<n;i++)
  {
    printf("Book name : %s\n",A[i].name);
    printf("Price : %f",A[i].price);
    printf("\n\n");
  }
}

void alterprice(list A[],int n)
{
  int i;
  float temp;
  list N[n];
  float x;
  printf("\n");
  for(i=0;i<n;i++)
  {
    if(A[i].id%2==0)
    {
      N[i].price=(A[i].price*2);
    }
    else
    {
      temp=(A[i].price*60)/100;
      N[i].price=A[i].price+temp;
    }
  }
  for(i=0;i<n;i++)
  {
    printf("\nName : %s\n",A[i].name);
    printf("ID : %d\n",A[i].id);
    printf("old price :%f\n",A[i].price);
    printf("New price :%f",N[i].price);
    printf("\n\n");
  }
}


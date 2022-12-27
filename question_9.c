//9. Write a program to store information of n students and display them using structure
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct student
{
    int class;
    char name[50];
    int roll;
};
void input(int size,struct student student[])
{
   int i;
   for(i=0;i<size;i++)
   {
      printf("Enter data of Student %d\n",i+1);
      printf("class: ");
      scanf("%d",&student[i].class);
      printf("name: ");
      fflush(stdin);
      fgets(student[i].name,50,stdin);
      printf("Roll no.: ");
      scanf("%d",&student[i].roll);
   }
}
void display(struct student *ptr,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("\nData of Student %d\n",i+1);
        printf("Class : %d\n",(ptr+i)->class);
        printf("Name : %s",(*(ptr+i)).name);
        printf("Roll : %d\n",ptr[i].roll);
    }
}
int main()
{
   int size ;
   printf("Enter number of students:\n");
   scanf("%d",&size);
   struct student student[size];
   input(size,student);
   display(student,size);
}
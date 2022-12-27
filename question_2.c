//2. Write a function to take input employee data from the user. [ Refer structure from question 1 ]
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Employee
    {
       int id;
       char name[50];
       float salary;
    };
struct Employee input(void)
{
   struct Employee emp;
   printf("Enter Employee data id, name &salary:\n");
   scanf("%d",&emp.id);
   fflush(stdin);
   fgets(emp.name,50,stdin);
   scanf("%f",&emp.salary);
   return emp;
}
int main()
{  
    struct Employee emp;
    emp = input();
    /*printf("Employee data:\n");
    printf("Id = %d\nName = %sSalary = %.2f",emp.id,emp.name,emp.salary);*/
    getch();
    return 0;
}
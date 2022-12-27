//4. Write a function to find the highest salary employee from a given array of 10\
employees. [ Refer structure from question 1]
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Employee
{
    int id;
    char name[50];
    float salary;
};
struct Employee input()
{
    struct Employee emp;
    printf("Enter Employee id:\n");
    scanf("%d",&emp.id);
    fflush(stdin);
    printf("Enter Employee name:\n");
    fgets(emp.name,50,stdin);
    printf("Enter Employee sal:\n");
    scanf("%f",&emp.salary);
    return emp;
}
void display(struct Employee emp)
{
    printf("\nHighest Salary Employee:\n");
    printf("Id = %d\n",emp.id);
    printf("Name = %s",emp.name);
    printf("Salary = %.2f",emp.salary);
}
int MaxSalEmp(struct Employee emp[],int size)
{
    int i,j=0;
    float Max_sal = emp[0].salary;
    for(i=1;i<size;i++)
    {
        if(Max_sal<emp[i].salary)
        {
            j=i;
            Max_sal = emp[i].salary;
        }
    }
    return j;
}
int main()
{
    int size,i;
    printf("Enter number of employee:\n");
    scanf("%d",&size);
    struct Employee emp[size];
    for(i=0;i<size;i++)
    {
      printf("Enter Employee data %d\n",i+1);
      emp[i]=input();
    } 
   // int highest_sal_Emp=MaxSalEmp(emp,size); //we can also write in simple
    display(emp[MaxSalEmp(emp,size)]);
    getch();
    return 0;
}
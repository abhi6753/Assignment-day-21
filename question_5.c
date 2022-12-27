//5. Write a function to sort employees according to their salaries [ refer structure from question 1]
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Employee
{
    int id;
    char name[50];
    float sal;
};
void input(struct Employee *ptr,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("Enter Data of Employee %d\n",i+1);
        printf("Id: ");
        scanf("%d",&(ptr+i)->id);
        fflush(stdin);
        printf("Name: ");
        fgets((ptr+i)->name,50,stdin);
        printf("Salary: ");
        scanf("%f",&(ptr+i)->sal);
        printf("\n");
    }
}
void SortBySalary(struct Employee *ptr,int size)
{
    int i,j;
    struct Employee temp;
    for(i=0;i<size-1;i++)
    {
       for(j=i+1;j<size;j++)
       {
          if(((ptr+i)->sal)>((ptr+j)->sal))
          {
              temp = *(ptr+i);
              *(ptr+i) = *(ptr+j);
              *(ptr+j) = temp;
          }
       }
    }
}
void display(struct Employee *ptr,int size)
{
    int i;
    printf("Sorted by Salary:\n");
    for(i=0;i<size;i++)
    {
       printf("Employee data %d:\n",i+1);
       printf("Id = %d\n",(*(ptr+i)).id);
       printf("Name = %s",(*(ptr+i)).name);
       printf("Salary = %.2f",(*(ptr+i)).sal);
       printf("\n\n");
    }
}
int main()
{
    int size;
    printf("Enter number of Employee:\n");
    scanf("%d",&size);
    struct Employee emp[size];
    input(emp,size);
    SortBySalary(emp,size);
    display(emp,size);
    getch();
    return 0;
}
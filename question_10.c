/* 10. Write a program to enter the marks of 5 students in Chemistry, Mathematics and
Physics (each out of 100) using a structure named Marks having elements roll no.,
name, chem_marks, maths_marks and phy_marks and then display the percentage
of each student. */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct marks
{
    int roll;
    char name[50];
    float chem_marks,math_marks,phy_marks;
};
void input(struct marks marks[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("\nEnter data of student %d\n",i+1);
        printf("Enter Roll no. : ");
        scanf("%d",&marks[i].roll);
        fflush(stdin);
        printf("Enter name : ");
        fgets(marks[i].name,50,stdin);
        printf("\nAll Subject Marks is out 100\n\n");
       try: printf("Enter Chemestry marks : ");
        scanf("%f",&marks[i].chem_marks);
        if(marks[i].chem_marks>100)
        {
            marks[i].chem_marks = 0;
            printf("Please Enter Correct Marks:\n");
            goto try;
        }
      try1:  printf("Enter Math marks : ");
        scanf("%f",&marks[i].math_marks);
        if(marks[i].math_marks>100)
        {
            marks[i].math_marks = 0;
            printf("Please Enter Correct Marks:\n");
            goto try1;
        }
       try2: printf("Enter physics marks : ");
        scanf("%f",&marks[i].phy_marks);
        if(marks[i].phy_marks>100)
        {
            marks[i].phy_marks = 0;
            printf("Please Enter Correct Marks:\n");
            goto try2;
        }
    }
}
float percentage(struct marks *ptr,int i)
{
    float percentage = (ptr+i)->chem_marks + (*(ptr+i)).math_marks + ptr[i].phy_marks;
    percentage = (percentage*100)/300;
    return percentage;

}
void display(struct marks marks[],int size)
{
   int i;
   for(i=0;i<size;i++)
   {
       printf("\nReport Card of student %d\n",i+1);
       printf("Roll no. : %d\n",marks[i].roll);
       printf("Name = %s",marks[i].name);
       printf("*****Marks*****\n");
       printf("Chemestry = %.2f\n",marks[i].chem_marks);
       printf("Maths = %.2f\n",marks[i].math_marks);
       printf("Physics = %.2f\n",marks[i].phy_marks);
       printf("Percentage = %.2f%%\n",percentage(marks,i));
   }
}
int main()
{
  int size =1;
  struct marks student_marks[size]; 
  input(student_marks,size);
  display(student_marks,size);
  getch();
  return 0;
}
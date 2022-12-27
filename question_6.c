//6. Write a function to sort employees according to their names [refer structure from question 1]
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
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
        printf("\nEnter Data of Employee %d\n",i+1);
        printf("Enter id: ");
        scanf("%d",&(ptr+i)->id);
        fflush(stdin);
        printf("Enter name: ");
        fgets((ptr+i)->name,50,stdin);
        ptr[i].name[strlen(ptr[i].name)-1]='\0';
        strlwr((ptr+i)->name);
        printf("Enter salary: ");
        scanf("%f",&(ptr+i)->sal);
    }
}
void SortByName(struct Employee *ptr,int size)
{
      int i,j,k,len1,len2;
      len1 = strlen((ptr+i)->name);
      len2 = strlen((ptr+j)->name);
      struct Employee temp;
      for(i=0;i<size-1;i++)
      {
        for(j=i+1;j<size;j++)
        {
            for(k=0;(ptr+i)->name[k];k++)
            {
                if((ptr+i)->name[k]>(ptr+j)->name[k])
                {
                    temp = ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = temp;
                }
                else if((ptr+i)->name[k]==(ptr+j)->name[k])
                {
                   len1--;
                   len2--;   
                   continue;
                }
                else if((ptr+i)->name=='\0'||(ptr+j)->name=='\0')
                {
                    if(len1>len2)
                    {
                        temp = ptr[i];
                        ptr[i]= ptr[j];
                        ptr[j] =temp;
                    }
                }
                else
                 break;
            }
        }
      }
}
void display(struct Employee *ptr,int size)
{
    int i;
    printf("Sorted by Name:\n");
    for(i=0;i<size;i++)
    {
        (ptr+i)->name[0]=(ptr+i)->name[0]-32;
        printf("\nData of Employee %d\n",i+1);
        printf("id: %d\n",(ptr+i)->id);
        printf("name: %s\n",(ptr+i)->name);
        printf("salary: %.2f\n",(ptr+i)->sal);
    }
}
int main()
{
  int size;
  printf("Enter number of Employees:\n");
  scanf("%d",&size);
  struct Employee emp[size];
  input(emp,size);
  SortByName(emp,size);
  display(emp,size);
}
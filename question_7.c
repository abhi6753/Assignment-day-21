//7. Write a program to calculate the difference between two time periods.
#include<stdio.h>
#include<conio.h>
struct TIME{
  unsigned int hours,minutes,seconds;
};
void differenceBetweenTimePeriod(struct TIME start_time,struct TIME end_time,struct TIME *diff_time)
{
  while(end_time.seconds>start_time.seconds)
       {
          --start_time.minutes;
          start_time.seconds +=60;
       }
  while(end_time.minutes>start_time.minutes)
       {
          --start_time.hours;
          start_time.minutes +=60;
       } 
  diff_time->seconds =start_time.seconds-end_time.seconds;
  diff_time->minutes = start_time.minutes-end_time.minutes;
  diff_time->hours = start_time.hours-end_time.hours;
}
int main()
{
  struct TIME start_time,end_time,diff_time;
  printf("Enter the start time:\n");
  printf("Enter hours, minutes and seconds:\n");
  scanf("%u%u%u",&start_time.hours,&start_time.minutes,&start_time.seconds);
  printf("Enter the stop time:\n");
  printf("Enter hours, minutes and seconds:\n");
  scanf("%u%u%u",&end_time.hours,&end_time.minutes,&end_time.seconds);
  // Difference between start and stop time
  differenceBetweenTimePeriod(start_time,end_time,&diff_time);
  printf("\nTime Difference: %d:%d:%d - ", start_time.hours,start_time.minutes,start_time.seconds);
  printf("%d:%d:%d ", end_time.hours,end_time.minutes,end_time.seconds);
  printf("= %d:%d:%d\n", diff_time.hours,diff_time.minutes,diff_time.seconds);
  return 0;
}
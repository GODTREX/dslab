#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
 char *name;
 int date;
 char *activity;
};
struct Day* create(char *name, int date, char *activity) {
 struct Day *day = (struct Day*)malloc(sizeof(struct Day));
 day->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
 strcpy(day->name, name);
 day->date = date;
 day->activity = (char *)malloc((strlen(activity) + 1) * sizeof(char));
 strcpy(day->activity, activity);
 return day;
}
struct Day* read() {
 char name[20];
 int date;
 char activity[100];
 printf("Enter day name: ");
 scanf("%s", name);
 printf("Enter date: ");
 scanf("%d", &date);
 printf("Enter activity: ");
 scanf(" %[^\n]s", activity);
 return create(name, date, activity);
}
void display(struct Day *day) 
{
 printf("Day: %s, Date: %d, Activity: %s\n", day->name, day->date, day->activity);
}
int main() {
 struct Day *week[7];
 
 int i;
 for (i = 0; i < 7; i++) 
 {
 printf("\nEnter details for day %d:\n", i+1);
 week[i] = read();
 }
 printf("\nWeek's Activity Details Report:\n");
 for ( i = 0; i < 7; i++) 
 {
 display(week[i]);
 }
 for ( i = 0; i < 7; i++) 
 {
 free(week[i]->name);
 free(week[i]->activity);
 free(week[i]);
 }
 return 0;
}

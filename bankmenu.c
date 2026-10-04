/*
Q.1  Write a C program to simulate Banker's algorithm for the purpose of deadlock avoidance.
Implement following functionality (menu driven).
a. Accept Available
b. Display Allocation, Max
c. Display the contents of need matrix
d. Display Available
Process Allocation Max Available
 A B C A B C A B C
P0 2 3 2 9 7 5 3 3 2
P1 4 0 0 5 2 2
P2 5 0 4 1 0 4
P3 4 3 3 4 4 4
P4 2 2 4 6 5 5
*/
#include <stdio.h>
int n,m,alloc[10][10],max[10][10],need[10][10],avail[10];
void accept_alloc_max()
{
int i,j;
printf("Enter number of processes and resource types: ");
scanf("%d %d",&n,&m);
printf("Enter Allocation matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
scanf("%d",&alloc[i][j]);
printf("Enter Max matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
scanf("%d",&max[i][j]);
}
void accept_avail()
{
int j;
printf("Enter Available resources: ");
for(j=0;j<m;j++)
scanf("%d",&avail[j]);
}
void calc_need()
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
need[i][j]=max[i][j]-alloc[i][j];
}
void show_matrix(char *title,int a[10][10])
{
int i,j;
printf("%s:\n",title);
for(i=0;i<n;i++)
{
printf("P%d: ",i);
for(j=0;j<m;j++)
printf("%d ",a[i][j]);
printf("\n");
}
}
void show_avail()
{
int j;
printf("Available: ");
for(j=0;j<m;j++)
printf("%d ",avail[j]);
printf("\n");
}
int main()
{
int ch;
do
{
printf("\n1.Accept Allocation and Max\n2.Accept Available\n3.Display Allocation and Max\n4.Display Need matrix\n5.Display Available\n0.Exit\nEnter choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: accept_alloc_max(); break;
case 2: accept_avail(); break;
case 3: show_matrix("Allocation",alloc); show_matrix("Max",max); break;
case 4: calc_need(); show_matrix("Need",need); break;
case 5: show_avail(); break;
}
}
while(ch!=0);
return 0;
}

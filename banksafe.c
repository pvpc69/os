/*
Q.1  Write a C program to simulate Banker's algorithm for the purpose of deadlock avoidance. Consider the following snapshot of system, A, B, C and D is the resource type.
Process Allocation Max Available
 A B C D A B C D A B C D
P0 0 0 1 2 0 0 1 2 1 5 2 0
P1 1 0 0 0 1 7 5 0
P2 1 3 5 4 2 3 5 6
P3 0 6 3 2 0 6 5 2
P4 0 0 1 4 0 6 5 6
a) Calculate and display the content of need matrix?
b) Is the system in safe state? If so display the safe sequence.
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
int safe()
{
int work[10],fin[10]={0},seq[10],cnt=0,i,j,found,ok;
calc_need();
for(j=0;j<m;j++)
work[j]=avail[j];
while(cnt<n)
{
found=0;
for(i=0;i<n;i++)
{
if(fin[i]) continue;
ok=1;
for(j=0;j<m;j++)
if(need[i][j]>work[j])
{
ok=0;
break;
}
if(ok)
{
for(j=0;j<m;j++)
work[j]+=alloc[i][j];
fin[i]=1;
seq[cnt++]=i;
found=1;
}
}
if(!found)
{
printf("System is NOT in safe state\n");
return 0;
}
}
printf("System is in SAFE state\nSafe sequence: ");
for(i=0;i<n;i++)
printf("P%d ",seq[i]);
printf("\n");
return 1;
}
int main()
{
accept_alloc_max();
accept_avail();
calc_need();
show_matrix("Need",need);
safe();
return 0;
}

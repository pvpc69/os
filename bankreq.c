/*
Q.2  Consider a system with 'n' processes and 'm' resource types. Accept number of instances for every resource type. For each process accept the allocation and maximum requirement matrices. Write a program to display the contents of need matrix and to check if the given request of a process can be granted immediately or not. (Use resource request algorithm)
*/
#include <stdio.h>
int n,m,alloc[10][10],max[10][10],need[10][10],avail[10];
void accept_total()
{
int i,j,total[10];
printf("Enter number of processes and resource types: ");
scanf("%d %d",&n,&m);
printf("Enter total instances of each resource type: ");
for(j=0;j<m;j++)
scanf("%d",&total[j]);
printf("Enter Allocation matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
scanf("%d",&alloc[i][j]);
printf("Enter Max matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
scanf("%d",&max[i][j]);
for(j=0;j<m;j++)
{
avail[j]=total[j];
for(i=0;i<n;i++)
avail[j]-=alloc[i][j];
}
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
void request()
{
int p,j,req[10];
calc_need();
printf("Enter process number: ");
scanf("%d",&p);
printf("Enter request: ");
for(j=0;j<m;j++)
scanf("%d",&req[j]);
for(j=0;j<m;j++)
{
if(req[j]>need[p][j])
{
printf("Error: request exceeds maximum claim\n");
return;
}
if(req[j]>avail[j])
{
printf("Process must wait: resources not available\n");
return;
}
}
for(j=0;j<m;j++)
{
avail[j]-=req[j];
alloc[p][j]+=req[j];
}
if(safe())
printf("Request can be granted immediately\n");
else
{
for(j=0;j<m;j++)
{
avail[j]+=req[j];
alloc[p][j]-=req[j];
}
printf("Request cannot be granted immediately\n");
}
}
int main()
{
accept_total();
calc_need();
show_matrix("Need",need);
show_avail();
request();
return 0;
}

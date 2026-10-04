/*
Q.2  Write a simulation program for disk scheduling using LOOK algorithm.
Accept total number of disk blocks, disk request string, and current head position from the user.
Display the list of requests in the order in which it is served.
Also display the total number of head moments.
55, 58, 39, 18, 90, 160, 150, 38
Start Head Position: 100
Direction: Left
*/
#include <stdio.h>
#include <stdlib.h>
int pos,total;
void go(int x)
{
printf("%d ",x);
total+=abs(x-pos);
pos=x;
}
int main()
{
int n,i,size,head,req[50],j,t,k,dir;
printf("Enter total number of disk blocks: ");
scanf("%d",&size);
printf("Enter number of requests: ");
scanf("%d",&n);
printf("Enter request string: ");
for(i=0;i<n;i++)
scanf("%d",&req[i]);
printf("Enter current head position: ");
scanf("%d",&head);
printf("Enter direction (1=Right, 0=Left): ");
scanf("%d",&dir);
pos=head;
for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
if(req[j]>req[j+1])
{
t=req[j];
req[j]=req[j+1];
req[j+1]=t;
}
for(i=0;i<n && req[i]<head;i++);
printf("Order served: ");
if(dir==1)
{
for(k=i;k<n;k++)
go(req[k]);
for(k=i-1;k>=0;k--)
go(req[k]);
}
else
{
for(k=i-1;k>=0;k--)
go(req[k]);
for(k=i;k<n;k++)
go(req[k]);
}
printf("\nTotal head movements = %d\n",total);
return 0;
}

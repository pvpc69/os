/*
Q.2  Write a simulation program for disk scheduling using C-SCAN algorithm.
Accept total number of disk blocks, disk request string, and current head position from the user.
Display the list of requests in the order in which it is served.
Also display the total number of head movements. (Assume disk size=200)
15, 45, 75, 105, 135, 165, 195, 80
Start Head Position: 100
Direction: Right
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
int n,i,size,head,req[50],j,t,k;
printf("Enter total number of disk blocks: ");
scanf("%d",&size);
printf("Enter number of requests: ");
scanf("%d",&n);
printf("Enter request string: ");
for(i=0;i<n;i++)
scanf("%d",&req[i]);
printf("Enter current head position: ");
scanf("%d",&head);
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
for(k=i;k<n;k++)
go(req[k]);
go(size-1);
go(0);
for(k=0;k<i;k++)
go(req[k]);
printf("\nTotal head movements = %d\n",total);
return 0;
}

/*
Q.2  Write a simulation program for disk scheduling using SSTF algorithm.
Accept total number of disk blocks, disk request string, and current head position from the user.
Display the list of requests in the order in which it is served.
Also display the total number of head moments.
98, 183, 37, 122, 14, 124, 65
Start Head Position: 53
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
int n,i,size,head,req[50],k,best,done[50]={0};
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
printf("Order served: ");
for(k=0;k<n;k++)
{
best=-1;
for(i=0;i<n;i++)
if(!done[i] && (best==-1 || abs(req[i]-pos)<abs(req[best]-pos)))
best=i;
done[best]=1;
go(req[best]);
}
printf("\nTotal head movements = %d\n",total);
return 0;
}

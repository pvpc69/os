/*
Q.2  Write a simulation program for disk scheduling using FCFS algorithm.
Accept total number of disk blocks, disk request string, and current head position from the user.
Display the list of requests in the order in which it is served.
Also display the total number of head moments.
55, 58, 39, 18, 90, 160, 150, 38, 184
Start Head Position: 50
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
int n,i,size,head,req[50];
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
for(i=0;i<n;i++)
go(req[i]);
printf("\nTotal head movements = %d\n",total);
return 0;
}

/*
Q.1  Write the simulation program for demand paging and show the page scheduling and total number of page faults according the optimal page replacement algorithm. Assume the memory of n frames.
Reference String: 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
*/
#include <stdio.h>
int n,ref[50];
int nextuse(int page,int from)
{
int k;
for(k=from;k<n;k++)
if(ref[k]==page)
return k;
return 1000;
}
int main()
{
int f,i,t,v,hit,faults=0,fr[10];
printf("Enter number of frames: ");
scanf("%d",&f);
printf("Enter length of reference string: ");
scanf("%d",&n);
printf("Enter reference string: ");
for(i=0;i<n;i++)
scanf("%d",&ref[i]);
for(i=0;i<f;i++)
fr[i]=-1;
for(t=0;t<n;t++)
{
hit=-1;
for(i=0;i<f;i++)
if(fr[i]==ref[t])
hit=i;
printf("%d : ",ref[t]);
if(hit==-1)
{
faults++;
v=-1;
for(i=0;i<f;i++)
if(fr[i]==-1)
{
v=i;
break;
}
if(v==-1)
{
v=0;
for(i=1;i<f;i++)
if(nextuse(fr[i],t+1)>nextuse(fr[v],t+1)) v=i;
}
fr[v]=ref[t];
}
for(i=0;i<f;i++)
if(fr[i]==-1) printf("- ");
else printf("%d ",fr[i]);
if(hit>=0) printf("  Hit\n");
else printf("  Fault\n");
}
printf("Total page faults = %d\n",faults);
return 0;
}

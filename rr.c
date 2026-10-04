/*
Q.1  Write the program to simulate Round Robin (RR) scheduling. The arrival time and first CPU burst for different n number of processes should be input to the algorithm. Also give the time quantum as input. The next CPU burst should be generated randomly. The output should give Gantt chart, turnaround time and waiting time for each process. Also find the average waiting time and turnaround time.
*/
#include <stdio.h>
int main()
{
int n,i,q,t=0,done=0,p,run,s=0,head=0,tail=0,at[20],bt[20],rem[20],ct[20],inq[20]={0},queue[500],gantt[500];
float tw=0,tt=0;
printf("Enter number of processes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter arrival time and burst time of P%d: ",i+1);
scanf("%d %d",&at[i],&bt[i]);
rem[i]=bt[i];
}
printf("Enter time quantum: ");
scanf("%d",&q);
while(done<n)
{
for(i=0;i<n;i++)
if(at[i]<=t && rem[i]>0 && !inq[i])
{
queue[tail++]=i;
inq[i]=1;
}
if(head==tail)
{
gantt[t++]=-1;
continue;
}
p=queue[head++];
run=rem[p]<q?rem[p]:q;
while(run--)
{
gantt[t++]=p;
rem[p]--;
}
for(i=0;i<n;i++)
if(at[i]<=t && rem[i]>0 && !inq[i])
{
queue[tail++]=i;
inq[i]=1;
}
if(rem[p]>0)
queue[tail++]=p;
else
{
ct[p]=t;
done++;
}
}
printf("\nGantt chart:\n");
for(i=1;i<=t;i++)
if(i==t || gantt[i]!=gantt[s])
{
if(gantt[s]==-1) printf("| Idle (%d-%d) ",s,i);
else printf("| P%d (%d-%d) ",gantt[s]+1,s,i);
s=i;
}
printf("|\n\nProcess AT BT CT TAT WT\n");
for(i=0;i<n;i++)
{
printf("P%d %d %d %d %d %d\n",i+1,at[i],bt[i],ct[i],ct[i]-at[i],ct[i]-at[i]-bt[i]);
tt+=ct[i]-at[i];
tw+=ct[i]-at[i]-bt[i];
}
printf("Average turnaround time = %.2f\nAverage waiting time = %.2f\n",tt/n,tw/n);
return 0;
}

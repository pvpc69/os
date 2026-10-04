/*
Q.2  Write the program to simulate Non-preemptive Shortest Job First (SJF) scheduling. The arrival time and first CPU burst for different n number of processes should be input to the algorithm. The next CPU burst should be generated randomly. The output should give Gantt chart, turnaround time and waiting time for each process. Also find the average waiting time and turnaround time.
*/
#include <stdio.h>
int main()
{
int n,i,t=0,done=0,cur=-1,s=0,at[20],bt[20],rem[20],ct[20],gantt[500];
float tw=0,tt=0;
printf("Enter number of processes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter arrival time and burst time of P%d: ",i+1);
scanf("%d %d",&at[i],&bt[i]);
rem[i]=bt[i];
}
while(done<n)
{
if(cur==-1)
{
for(i=0;i<n;i++)
if(at[i]<=t && rem[i]>0 && (cur==-1 || bt[i]<bt[cur]))
cur=i;
}
gantt[t++]=cur;
if(cur!=-1 && --rem[cur]==0)
{
ct[cur]=t;
done++;
cur=-1;
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

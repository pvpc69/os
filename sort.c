/*
Q.2  Implement the C program to accept n integers to be sorted. Main function creates child process using fork system call. Parent process sorts the integers using bubble sort and waits for child process using wait system call. Child process sorts the integers using insertion sort.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int a[20],n,i,j,t,key;
printf("Enter number of integers: ");
scanf("%d",&n);
printf("Enter integers: ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
fflush(stdout);
if(fork()==0)
{
for(i=1;i<n;i++)
{
key=a[i];
for(j=i-1;j>=0 && a[j]>key;j--)
a[j+1]=a[j];
a[j+1]=key;
}
printf("Child (insertion sort): ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
}
else
{
for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
printf("Parent (bubble sort): ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
wait(NULL);
}
return 0;
}

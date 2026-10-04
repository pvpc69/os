/*
Q.1  Implement the C program that accepts an integer array. Main function forks child process. Parent process sorts an integer array and passes the sorted array to child process through the command line arguments of execve() system call. The child process uses execve() system call to load new program that uses this sorted array for performing the binary search the particular item in the array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc,char *argv[])
{
int a[20],n,i,j,t,key,lo,hi,mid;
char buf[22][12],*args[24];
if(argc>1)
{
key=atoi(argv[1]);
n=argc-2;
for(i=0;i<n;i++)
a[i]=atoi(argv[i+2]);
printf("New program received sorted array: ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
lo=0;
hi=n-1;
while(lo<=hi)
{
mid=(lo+hi)/2;
if(a[mid]==key)
{
printf("%d found at position %d\n",key,mid+1);
return 0;
}
if(a[mid]<key)
lo=mid+1;
else
hi=mid-1;
}
printf("%d not found\n",key);
return 0;
}
printf("Enter number of integers: ");
scanf("%d",&n);
printf("Enter integers: ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter item to search: ");
scanf("%d",&key);
for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
args[0]=argv[0];
sprintf(buf[0],"%d",key);
args[1]=buf[0];
for(i=0;i<n;i++)
{
sprintf(buf[i+1],"%d",a[i]);
args[i+2]=buf[i+1];
}
args[n+2]=NULL;
fflush(stdout);
if(fork()==0)
{
execve("/proc/self/exe",args,NULL);
perror("execve");
exit(1);
}
wait(NULL);
return 0;
}

/*
Q.1  Write a C program to illustrate the concept of orphan process. Parent process creates a child and terminates before child has finished its task. So child process becomes orphan process. (Use fork(), sleep(), getpid(), getppid())
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
int pid=fork();
if(pid>0)
{
printf("Parent: PID = %d, child PID = %d\n",getpid(),pid);
printf("Parent terminating\n");
sleep(1);
}
else
{
printf("Child : PID = %d, parent PID = %d\n",getpid(),getppid());
sleep(3);
printf("Child : PID = %d, new parent PID = %d\n",getpid(),getppid());
}
return 0;
}

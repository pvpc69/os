/*
Q.2  Write a program that demonstrates the use of nice() system call. After a child process is started using fork(), assign higher priority to the child using nice() system call.
*/
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int pid=fork();
if(pid==0)
{
printf("Child : nice value before = %d\n",nice(0));
errno=0;
if(nice(-5)==-1 && errno!=0)
perror("nice (run with sudo)");
printf("Child : nice value after = %d\n",nice(0));
}
else
{
printf("Parent: nice value = %d\n",nice(0));
wait(NULL);
}
return 0;
}

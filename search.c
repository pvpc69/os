/*
Q.2  Write a C program that behaves like a shell which displays the command prompt '$'. It accepts the command, tokenize the command line and execute it by creating the child process. Also implement the additional command 'search' as
a. $ search f filename pattern : It will search the first occurrence of pattern in the given file
b. $ search a filename pattern : It will search all the occurrence of pattern in the given file
c. $ search c filename pattern : It will count the number of occurrence of pattern in the given file
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
void search(char *opt,char *fname,char *pat)
{
FILE *fp=fopen(fname,"r");
char line[256],*p;
int ln=0,total=0;
if(!fp)
{
printf("Cannot open %s\n",fname);
return;
}
while(fgets(line,256,fp))
{
ln++;
p=line;
while((p=strstr(p,pat))!=NULL)
{
total++;
if(opt[0]=='f')
{
printf("First occurrence: line %d: %s",ln,line);
fclose(fp);
return;
}
if(opt[0]=='a')
printf("Line %d, column %d\n",ln,(int)(p-line)+1);
p+=strlen(pat);
}
}
fclose(fp);
if(opt[0]=='c')
printf("Occurrences = %d\n",total);
else if(total==0)
printf("Pattern not found\n");
}
int main()
{
char cmd[200],*arg[32];
int i;
while(1)
{
printf("$ ");
fflush(stdout);
if(!fgets(cmd,200,stdin))
break;
for(i=0;i<30 && (arg[i]=strtok(i?NULL:cmd," \t\n"));i++);
arg[i]=NULL;
if(i==0)
continue;
if(strcmp(arg[0],"exit")==0)
break;
if(strcmp(arg[0],"search")==0 && i==4)
search(arg[1],arg[2],arg[3]);
else if(fork()==0)
{
execvp(arg[0],arg);
perror("command");
exit(1);
}
else
wait(NULL);
}
return 0;
}

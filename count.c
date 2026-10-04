/*
Q.2  Write a C program that behaves like a shell which displays the command prompt '$'. It accepts the command, tokenize the command line and execute it by creating the child process. Also implement the additional command 'count' as
a. $ count c filename : It will display the number of characters in given file
b. $ count w filename : It will display the number of words in given file
c. $ count l filename : It will display the number of lines in given file
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
void count(char *opt,char *fname)
{
FILE *fp=fopen(fname,"r");
int ch,c=0,w=0,l=0,inword=0;
if(!fp)
{
printf("Cannot open %s\n",fname);
return;
}
while((ch=fgetc(fp))!=EOF)
{
c++;
if(ch=='\n')
l++;
if(ch==' ' || ch=='\n' || ch=='\t')
inword=0;
else if(!inword)
{
inword=1;
w++;
}
}
fclose(fp);
if(opt[0]=='c') printf("Characters = %d\n",c);
else if(opt[0]=='w') printf("Words = %d\n",w);
else if(opt[0]=='l') printf("Lines = %d\n",l);
else printf("Use c, w or l\n");
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
if(strcmp(arg[0],"count")==0 && i==3)
count(arg[1],arg[2]);
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

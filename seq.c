/*
Q.1  Write a program to simulate Sequential file allocation method. Assume disk with n number of blocks. Give value of n as input. Randomly mark some block as allocated and accordingly maintain the list of free blocks. Write menu driven program with menu options as mentioned below and implement each option.
a. Show Bit Vector
b. Create New File
c. Show Directory
d. Exit
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int n,cnt=0,bit[100];
struct File { char name[20]; int start,len; } f[20];
void show_bits()
{
int i;
printf("Bit vector: ");
for(i=0;i<n;i++)
printf("%d",bit[i]);
printf("\n");
}
void create()
{
struct File x;
int i,k;
if(cnt==20)
{
printf("Directory full\n");
return;
}
printf("Enter file name and size (blocks): ");
scanf("%s %d",x.name,&x.len);
if(x.len<1)
{
printf("Invalid size\n");
return;
}
for(i=0;i+x.len<=n;i++)
{
for(k=i;k<i+x.len && !bit[k];k++);
if(k==i+x.len)
break;
}
if(i+x.len>n)
{
printf("Not enough contiguous free blocks\n");
return;
}
x.start=i;
for(k=i;k<i+x.len;k++)
bit[k]=1;
f[cnt++]=x;
printf("File created\n");
}
void show_dir()
{
int i;
if(cnt==0)
printf("Directory is empty\n");
for(i=0;i<cnt;i++)
printf("%s : start = %d, length = %d\n",f[i].name,f[i].start,f[i].len);
}
int main()
{
int i,ch;
srand(time(0));
printf("Enter number of disk blocks: ");
scanf("%d",&n);
for(i=0;i<n;i++)
bit[i]=(rand()%100<25);
do
{
printf("\n1.Show Bit Vector\n2.Create New File\n3.Show Directory\n4.Exit\nEnter choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: show_bits(); break;
case 2: create(); break;
case 3: show_dir(); break;
}
}
while(ch!=4);
return 0;
}

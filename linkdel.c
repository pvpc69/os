/*
Q.1  Write a program to simulate Linked file allocation method. Assume disk with n number of blocks. Give value of n as input. Randomly mark some block as allocated and accordingly maintain the list of free blocks. Write menu driven program with menu options as mentioned below and implement each option.
a. Show Bit Vector
b. Create New File
c. Show Directory
d. Delete File
e. Exit
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int n,cnt=0,bit[100];
struct File { char name[20]; int len,blk[50]; } f[20];
void show_bits()
{
int i;
printf("Bit vector: ");
for(i=0;i<n;i++)
printf("%d",bit[i]);
printf("\n");
}
int pick()
{
int i;
for(i=0;i<n;i++)
if(!bit[i])
{
bit[i]=1;
return i;
}
return -1;
}
int free_count()
{
int i,c=0;
for(i=0;i<n;i++)
if(!bit[i])
c++;
return c;
}
void create()
{
struct File x;
int k;
if(cnt==20)
{
printf("Directory full\n");
return;
}
printf("Enter file name and size (blocks): ");
scanf("%s %d",x.name,&x.len);
if(x.len<1 || x.len>49 || free_count()<x.len)
{
printf("Cannot create file\n");
return;
}
for(k=0;k<x.len;k++)
x.blk[k]=pick();
f[cnt++]=x;
printf("File created\n");
}
void show_dir()
{
int i,k;
if(cnt==0)
printf("Directory is empty\n");
for(i=0;i<cnt;i++)
{
printf("%s : start = %d : ",f[i].name,f[i].blk[0]);
for(k=0;k<f[i].len;k++)
printf("%d -> ",f[i].blk[k]);
printf("NULL\n");
}
}
void delete_file()
{
char nm[20];
int i,k;
printf("Enter file name to delete: ");
scanf("%s",nm);
for(i=0;i<cnt;i++)
if(strcmp(f[i].name,nm)==0)
{
for(k=0;k<f[i].len;k++)
bit[f[i].blk[k]]=0;
f[i]=f[--cnt];
printf("File deleted\n");
return;
}
printf("File not found\n");
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
printf("\n1.Show Bit Vector\n2.Create New File\n3.Show Directory\n4.Delete File\n5.Exit\nEnter choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: show_bits(); break;
case 2: create(); break;
case 3: show_dir(); break;
case 4: delete_file(); break;
}
}
while(ch!=5);
return 0;
}

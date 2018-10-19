#include<stdio.h>
#include<conio.h>
int check(char table[5][5],char k)
{
int i,j;
for(i=0;i<5;++i)
for(j=0;j<5;++j)
{
if(table[i][j]==k)
return 0;
}
return 1;
}
void main()
{
int i,j,len;
char table[5][5];
for(i=0;i<5;++i)
for(j=0;j<5;++j)
table[i][j]='0';
printf("\n\nApplying Polyalphabetic Substitution cipher (Playfair Cipher)\n\n");
printf("How many alphabets are there in the key : ");
scanf("%d",&len);
char key[len];
printf("\nPlease enter the key text : ");
for(i=-1;i<len;++i)
{
scanf("%c",&key[i]);
if(key[i]=='j')
key[i]='i';
}
int flag;
int count=0;
for(i=0;i<5;++i)
{
for(j=0;j<5;++j)
{
flag=0;
while(flag!=1)
{
if(count>len)
goto l1;
flag=check(table,key[count]);
++count;
}
table[i][j]=key[(count-1)];
}
}
l1:printf("\n");
int val=97;
for(i=0;i<5;++i)
{
for(j=0;j<5;++j)
{
if(table[i][j]>=97 && table[i][j]<=123)
{}
else
{
flag=0;
while(flag!=1)
{
if('j'==(char)val)
++val;
flag=check(table,(char)val);
++val;
}
table[i][j]=(char)(val-1);
}
}
}
printf("\nTable of key is : \n");
for(i=0;i<5;++i)
{
for(j=0;j<5;++j)
{
printf("%c ",table[i][j]);
}
printf("\n");
}
int l=0;
printf("\nWhat is the length of plain text(without spaces) you want to encrypt :");
scanf("%d",&l);
printf("\nPlease enter the Plain text : ");
char p[l];
for(i=-1;i<l;++i)
{
scanf("%c",&p[i]);
}
for(i=-1;i<l;++i)
{
if(p[i]=='j')
p[i]='i';
}
printf("\nReplacing text j with i\n");
for(i=-1;i<l;++i)
{
printf("%c",p[i]);
}
count=0;
for(i=-1;i<l;++i)
{
if(p[i]==p[i+1])
count=count+1;
}
int length=0;
if((l+count)%2!=0)
length=(l+count+1);
else
length=(l+count);
printf("\n\nCheckinf if it is required to enter %d bogus char('x' or 'z') in the plain taext
or not to perform playfair cipher . \n\n",count);
char p1[length];
char temp1;
int count1=0;
for(i=-1;i<l;++i)
{
p1[count1]=p[i];
if(p[i]==p[i+1])
{
count1=count1+1;
if(p[i]=='x')
p1[count1]='z';
else
p1[count1]='x';
}
count1=count1+1;
}
char bogus;
if((l+count)%2!=0)
{
if(p[i]=='x')
p1[count1]='z';
else
p1[length]='x';
}
printf("\nText obtained after adding %d bogus characters is is :\n",count );
for(i=0;i<=length;++i)
printf("%c ",p1[i]);
char ct[length];
int r1,r2,c1,c2;
int k;
for(k=1;k<=length;++k)
{
for(i=0;i<5;++i)
{
for(j=0;j<5;++j)
{
if(table[i][j]==p1[k])
{
r1=i;
c1=j;
}
else
if(table[i][j]==p1[k+1])
{
r2=i;
c2=j;
}
}
}
if(r1==r2)
{
ct[k]=table[r1][(c1+1)%5];
ct[k+1]=table[r1][(c2+1)%5];
}
else
if(c1==c2)
{
ct[k]=table[(r1+1)%5][c1];
ct[k+1]=table[(r2+1)%5][c1];
}
else
{
ct[k]=table[r1][c2];
ct[k+1]=table[r2][c1];
}
k=k+1;
}
printf("\n\n\nCipher text obtained on applying Playfair cipher for given plain text is :
\n\n");
for(i=1;i<=length;++i)
printf("%c ",ct[i]);
printf("\n\n\n\n\nRahul Mishra ( 17SCSE101240 )");
getch();
}

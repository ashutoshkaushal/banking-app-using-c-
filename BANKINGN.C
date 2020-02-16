#include<stdio.h>

struct bank
{ int accno,balance,phone;
char name[20],address[50],id[20];
};


void new_account();
void list_account();
void delete_account();
void deposit();
void withdrawl();

FILE *fp;
int main()
{
int i,n;
int clrscr;
n = login;
if(n==0)
{
clrscr();
printf("  Invalid user Bye --");
exit(0);
}

fp=fopen("c:/bank/data/bank.txt","rb+");
if(fp==NULL)
{
fp=fopen("c:/bank/data/bank.txt","wb+");
}
while(1)
{
getch();
clrscr();
printf("\n1.new account");
printf("\n2.list account");
printf("\n3.delete account");
printf("\n4.deposit");
printf("\n5.withdraw");
printf("\n6.exit");
printf("\nEnter your choice");
scanf("%d",&i);
if(i==1)
new_account();
else if(i==2)
list_account();
else if(i==3)
delete_account();
else if(i==4)
deposit();
else if(i==5)
withdrawl();
else if(i==6)
return 0;
}

}
void new_account()
{
 struct bank e1;
 fseek(fp,0,SEEK_END);
printf("Enter account no");
scanf("%d",&e1.accno);
fflush(stdin);
printf("Enter name");
gets(e1.name);
fflush(stdin);
printf("Enter phone");
scanf("%d",&e1.phone);
fflush(stdin);
printf("Enter address");
gets(e1.address);
printf("Enter id");
scanf("%s",e1.id);
fflush(stdin);
printf("Enter balance");
scanf("%d",&e1.balance);
fwrite(&e1,sizeof(e1),1,fp);
}

void list_account()
{
 struct bank e1;
rewind(fp);
clrscr();
printf("\n\n");
printf(" State Bank of India Branch Chandigarh\n");
printf("---------------------------------------------------------------------");
printf("\nAccno\t\tName\t\tPhone\t\tAddress\t\tEmail\tBalance");
//textcolor(13);
while(fread(&e1,sizeof(e1),1,fp))
{ printf("\n%d\t\t%s\t\t%d\t\t%s\t\t%s\t%d",
	     e1.accno,e1.name,e1.phone,e1.address,e1.id,e1.balance);
}
getch();
}


void delete_account()
{
struct bank e1;
int accno;
FILE *fp1;
rewind(fp);
fp1=fopen("c:/bank/data/temp","wb");
printf("enter the account no to be deleted");
scanf("%d",&accno);
while(fread(&e1,sizeof(e1),1,fp))
{ if(accno!=e1.accno)
  { fwrite(&e1,sizeof(e1),1,fp1);
  }
 }
fclose(fp);
fclose(fp1);
remove("c:/bank/data/bank.txt");
rename("c:/bank/data/temp","c:/bank/data/bank.txt");
fp=fopen("c:/bank/data/bank.txt","rb+");
}


void deposit()
{
struct bank e1;
int r=sizeof(e1);
int accno,amt;
printf("enter accno");
scanf("%d",&accno);
rewind(fp);

while(fread(&e1,sizeof(e1),1,fp))
{ if(accno==e1.accno)
  {
  fseek(fp,-r,SEEK_CUR);
  printf("enter the amount to deposit");
scanf("%d",&amt);

  e1.balance=e1.balance+amt;

  fwrite(&e1,sizeof(e1),1,fp);
 break;
  }
 }
 printf( " Deposited ");
}



void withdrawl()
{

struct bank e1;
int r=sizeof(e1);
int accno,amt;
printf("enter accno");
scanf("%d",&accno);
rewind(fp);

while(fread(&e1,sizeof(e1),1,fp))
{ if(accno==e1.accno)
  {
  fseek(fp,-r,SEEK_CUR);
  printf("enter the amount to withdraw");
scanf("%d",&amt);

  e1.balance=e1.balance-amt;

  fwrite(&e1,sizeof(e1),1,fp);
 break;
  }
 }
 printf( " amount withdrawn ");
 }

int login()
{


int i=0;
char name[20];
char pass[10];
char ch=0;
char actual[20]={"admin"};

printf("\n\n\n\n\n  ---     LOGIN     ---      ");
printf("\n ---------------------------------");

printf("\n            Username ");
scanf("%s",name);
printf("\n            Password ");
fflush(stdin);
while(ch!=13)
{
 ch=getch();
//fflush(stdin);
if(ch!=13)
{
pass[i++]=ch;
printf("%c",15);
}

}
pass[i]=0;
if(strcmp(pass,actual)==0)
return 1;
else
printf("sry,try again");
getch();
return 0;
}

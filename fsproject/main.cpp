#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
int n=0,ind=0;
using namespace std;
class record
{
public: char name[20],ssn[20],address[20],department[20];
void insert(fstream &f1,fstream &f2)
{
cout<<"Enter Name: ";
cin>>name;
cout<<"Enter ssn: ";
cin>>ssn;
cout<<"Enter department: ";
cin>>department;
cout<<"Enter address: ";
cin>>address;
write(f1,f2);
}
void write(fstream &f1,fstream &f2)
{
f1<<++ind<<"\t"<<ssn<<"\n";
f2<<name<<"\t"<<ssn<<"\t"<<department<<"\t"<<address<<"\n";
}
void display(fstream &f2)
{
f2>>name>>ssn>>department>>address;
cout<<name<<"\t"<<ssn<<"\t"<<department<<"\t"<<address<<"\n";
}
int search(fstream &f1,char key[20])
{
int i,x;
for(i=1;i<=n;i++)
{
f1>>x>>ssn;
if(strcmp(ssn,key)==0)
return i;
}
cout<<"Record not found\n";
return 0;
}

int remove(fstream &f1,char key[20])
{
int i;
i=search(f1,key);
return i;
}
};
int main()
{
fstream f1,f2;
record s[20],p;
int ch,k=0,i;
f1.open("m1.txt",ios::trunc);
f2.open("mn1.txt",ios::trunc);
f1.close();
f2.close();
for(;;)
{
cout<<"\n***************************************\n";
cout<<"\nWELCOME TO EMPLOYEE RECORD MANAGEMENT SYSTEM\n";
cout<<"\n***************************************\n";
cout<<"1.Insert 2.Display 3.Search 4.Delete 5.Exit\n";
cout<<"\n---------------------------------------\n";
cout<<"Enter choice: ";
cin>>ch;
switch(ch)
{
case 1: f1.open("m1.txt",ios::app);
        f2.open("mn1.txt",ios::app);
        cout<<"Enter no. of Employees: ";
        cin>>k;
        n=n+k;
        for(int i=1;i<=k;i++)
           s[i].insert(f1,f2);
        f1.close();
        f2.close();
        break;
case 2: f2.open("mn1.txt",ios::in);
        for(i=0;i<2;i++)
           s[i].display(f2);
        f2.close();
        break;
case 3: char ssn[20];
        cout<<"Enter ssn to search: ";
        cin>>ssn;
        f1.open("m1.txt",ios::in);
        f2.open("mn1.txt",ios::in);
        int j;
        j=p.search(f1,ssn);
        if(j!=0)
        {
        cout<<"Record found & Details are\n";
        cout<<"Name="<<s[j].name<<"\n"<<"SSN="<<s[j].ssn<<"\n"<<"Department="<<s[j].department<<"\n"<<"Address="<<s[j].address<<"\n";
        }
        f1.close();
        f2.close();
        break;
case 4: f1.open("m1.txt",ios::in);
        f2.open("mn1.txt",ios::in);
        cout<<"Enter SSN to delete: ";
        cin>>ssn;
        j=p.remove(f1,ssn);
        if(j!=0)
        {
         for(i=j;i<n;i++)
           s[i]=s[i+1];
           cout<<"Deletion successfull\n";
        }
        n--;
        ind--;
        f1.close();
        f2.close();
        f1.open("m1.txt",ios::trunc|ios::app);
        f2.open("mn1.txt",ios::trunc|ios::app);
        ind=0;
        for(i=1;i<=n;i++)
        s[i].write(f1,f2);
        f1.close();
        f2.close();
        break;
default:exit(0);
}
}
return 0;
}


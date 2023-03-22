#include <iostream>
#include <cstring>
#include <fstream>
struct Node{
	char fname[51];
	char lname[101];
	char number[21];
	Node *next;
};
void download(Node **);
void search(Node **);
bool checkl(Node **,char [],int);
bool sizel(Node **,char [],int);
bool checkf(Node **,char [],int);
bool sizef(Node **,char [],int);
void st(Node **,Node **);
void newc(Node **);
void editc(Node **,Node **);
void print (Node **);
void deletec(Node **,Node **);
using namespace std;
int main()
{
	char n;
	Node **first=new Node *[26],**second=new Node *[26],**third=new Node *[26];
	for(int i=0;i<26;i++)
	{
		first[i]=new Node,second[i]=third[i]=first[i];
	}
	download(first);
	for(;;)
	{
		do
		{
			cout<<"1.search"<<endl<<"2.new contact"
			<<endl<<"3.update contact"<<endl<<"4.delete contact"
			<<endl<<"5.show all"<<endl<<"6.exit"<<endl<<"input your number:"<<endl;
			cin>>n;
			system("cls");
		}while(n<'1' || n>'6');
		switch (n)
		{
			case '1':search(second);break;
			case '2':newc(first);break;
			case '3':editc(second,third);break;
			case '4':deletec(second,third);break;
			case '5':print(second);break;
			case '6':
				cout<<"end !!!"<<endl;
				system("cls");
				ofstream f;
				f.open("your directory of a text file");
				for(int i=0;i<26;i++)
				while(second[i]->next)
				{
					f<<second[i]->fname<<'\t'<<second[i]->lname<<'\t'<<second[i]->number<<endl;
					second[i]=second[i]->next;
				}
				f.close();
				for(int i=0;i<26;i++)
					delete first[i];
				delete first;
				system("pause");
				return 0;
		}
		st(second,third);
		cout<<"done !!!"<<endl;
		system("pause");
		system("cls");
	}
}
void download(Node **first)
{
	ifstream f;
	char fn[51],ln[101],x[21];
	int a;
	f.open("your directory of a text file");
	for(;f>>fn>>ln>>x;)
	{
		a=(int)ln[0]-97;
		strcpy(first[a]->fname,fn);
		strcpy(first[a]->lname,ln);
		strcpy(first[a]->number,x);
		first[a]->next=new Node,first[a]=first[a]->next;
	}
	for(int i=0;i<26;i++)
		first[i]->next=NULL;
	f.close();
}
void print(Node **second)
{
	int k=0;
	for(int i=0;i<26;i++)
	{
		if(second[i]->next)
		{
			cout<<second[i]->lname[0]<<':'<<endl;
			k++;
		}
		while(second[i]->next)
		{
			cout<<'\t'<<second[i]->fname<<'\t'<<second[i]->lname<<'\t'<<second[i]->number<<endl;
			second[i]=second[i]->next;
		}
	}
	if(!k)
	{
		cout<<"the list is empty"<<endl;
		return;
	}
}
void search(Node **second)
{
	char n;
	int k=0;
	char ln[101],fn[51]; 
	do
	{
		cout<<"1.search by last name"<<endl<<"2.search by first and last name"<<endl<<"enter number:";
		cin>>n;
		system("cls");
	}while(n!='1' && n!='2');
	if(n=='1')
	{
		cout<<"enter your last name:";
		cin>>ln;
		int a=(int) ln[0]-97;
		while(second[a]->next)
		{
			if(checkl(second,ln,a) && sizel(second,ln,a))
			{
				cout<<second[a]->fname<<'\t'<<second[a]->lname<<'\t'<<second[a]->number<<endl,k++;
			}
			second[a]=second[a]->next;
		}
		if(!k)
		{
			cout<<"invalid contact"<<endl;
			return;
		}
	}
	else
	{
		cout<<"enter your first name:";
		cin>>fn;
		cout<<"enter your last name:";
		cin>>ln;
		int a=(int) ln[0]-97;
		while(second[a]->next)
		{
			if(checkl(second,ln,a) && sizel(second,ln,a) && checkf(second,fn,a) && sizef(second,fn,a))
			{
				cout<<second[a]->fname<<'\t'<<second[a]->lname<<'\t'<<second[a]->number<<endl,k++;
			}
			second[a]=second[a]->next;
		}
		if(!k)
		{
			cout<<"invalid contact"<<endl;
			return;
		}
	}
}
bool checkl(Node **second,char a[],int n)
{
	for(int i=0;a[i]!='\0' && second[n]->lname[i]!='\0';i++)
		if(a[i]!=second[n]->lname[i])
			return false;
	return true;
}
bool sizel(Node **second,char a[],int n)
{
	int i,j;
	for(i=0;a[i]!='\0';i++);
	for(j=0;second[n]->lname[j]!='\0';j++);
	if(i==j)return true;
	return false;
}
bool checkf(Node **second,char a[],int n)
{
	for(int i=0;a[i]!='\0' && second[n]->fname[i]!='\0';i++)
		if(a[i]!=second[n]->fname[i])
			return false;
	return true;
}
bool sizef(Node **second,char a[],int n)
{
	int i,j;
	for(i=0;a[i]!='\0';i++);
	for(j=0;second[n]->fname[j]!='\0';j++);
	if(i==j)return true;
	return false;
}
void st(Node **second,Node **third)
{
	for(int i=0;i<26;i++)
		second[i]=third[i];
}
void newc(Node **first)
{
	char fn[51],ln[101],x[21];
	int i=0,a;
	do
	{
		cout<<"enter your phone number:";
		cin>>x;
		for(i=0;x[i]!='\0';i++);
	}while(i!=11);
	cout<<"enter your first name:";
	cin>>fn;
	cout<<"enter your last name:";
	cin>>ln;
	a=(int)ln[0]-97;
	strcpy(first[a]->fname,fn);
	strcpy(first[a]->lname,ln);
	strcpy(first[a]->number,x);
	first[a]->next=new Node;
	first[a]=first[a]->next;
	first[a]->next=NULL;
	ofstream f;
	f.open("your directory of a text file",ios::app);
	f<<fn<<'\t'<<ln<<'\t'<<x<<endl;
	f.close();
}
void editc(Node **second,Node **third)
{
	char ln[101],fn[101];
	int k=0;
	cout<<"enter your first name:";
	cin>>fn;
	cout<<"enter your last name:";
	cin>>ln;
	int i=1,x,a=(int)ln[0]-97,b;	
	while(second[a]->next)
	{
		if(checkl(second,ln,a) && sizel(second,ln,a) && checkf(second,fn,a) && sizef(second,fn,a))
		{
			cout<<i<<'.'<<second[a]->fname<<'\t'<<second[a]->lname<<'\t'<<second[a]->number<<endl,i++,k++;
		}
		second[a]=second[a]->next;
	}
	if(!k)
	{
		cout<<"invalid contact"<<endl;
		return ;
	}
	do
	{
		cout<<"enter your contact:";
		cin>>x;
	}while(x>i || x<1);
	system("cls");
	do
	{
		cout<<"1.edit first name"<<endl<<"2.edit last name"<<endl<<"3.edit phone number"<<endl<<"enter your number:";
		cin>>i;
	}while(i>3 || i<1);
	st(second,third);
	if(i==1)
	{
		for(i=0;;)
		{
			if(checkl(second,ln,a) && sizel(second,ln,a) && checkf(second,fn,a) && sizef(second,fn,a))
				i++;
			if(i==x)break;
			second[a]=second[a]->next;
		}
		cout<<"enter your first name:";
		cin>>fn;
		strcpy(second[a]->fname,fn);
	}
	else if(i==2)
	{
		for(i=0;;)
		{
			if(checkl(second,ln,a) && sizel(second,ln,a) && checkf(second,fn,a) && sizef(second,fn,a))
				i++;
			if(i==x)break;
			second[a]=second[a]->next;
		}
		char x[101];
		strcpy(fn,second[a]->fname);
		strcpy(x,second[a]->number);
		cout<<"enter your last name:";
		cin>>ln;
		if(ln[0]==second[a]->lname[0])
			strcpy(second[a]->lname,ln);
		else
		{
			for(;second[a]->next->next;)
			{
				strcpy(second[a]->fname,second[a]->next->fname);
				strcpy(second[a]->lname,second[a]->next->lname);
				strcpy(second[a]->number,second[a]->next->number);
				second[a]=second[a]->next;
			}
			second[a]->next=NULL;
			b=(int)ln[0]-97;
			strcpy(second[b]->fname,fn);
			strcpy(second[b]->lname,ln);
			strcpy(second[b]->number,x);
			second[b]->next=new Node;
			second[b]=second[a]->next;
		}
	}
	else
	{
		for(i=0;;)
		{
			if(checkl(second,ln,a) && sizel(second,ln,a) && checkf(second,fn,a) && sizef(second,fn,a))
				i++;
			if(i==x)break;
			second[a]=second[a]->next;
		}
		do
		{
			cout<<"enter your phone number:";
			cin>>fn;
			for(i=0;fn[i]!='\0';i++);
		}while(i!=11);
		strcpy(second[a]->number,fn);
	}
	st(second,third);
}
void deletec(Node **second,Node **third)
{
	char ln[101],fn[101];
	int k=0;
	cout<<"enter your first name:";
	cin>>fn;
	cout<<"enter your last name:";
	cin>>ln;
	int j,i=1,x,a=(int)ln[0]-97;	
	while(second[a]->next)
	{
		if(checkl(second,ln,a) && sizel(second,ln,a) && checkf(second,fn,a) && sizef(second,fn,a))
		{
			cout<<i<<'.'<<second[a]->fname<<'\t'<<second[a]->lname<<'\t'<<second[a]->number<<endl,i++,k++;
		}
		second[a]=second[a]->next;
	}
	if(!k)
	{
		cout<<"invalid contact"<<endl;
		return ;
	}
	do
	{
		cout<<"enter your contact:";
		cin>>x;
	}while(x>i || x<1);
	system("cls");
	st(second,third);
	for(i=0;second[a]->next;i++)
		second[a]=second[a]->next;
	st(second,third);
	for(j=0;;)
	{
		if(checkl(second,ln,a) && sizel(second,ln,a) && checkf(second,fn,a) && sizef(second,fn,a))
				j++;
		if(j==x)break;
		second[a]=second[a]->next;
	}
	for(;second[a]->next->next;)
	{
		strcpy(second[a]->fname,second[a]->next->fname);
		strcpy(second[a]->lname,second[a]->next->lname);
		strcpy(second[a]->number,second[a]->next->number);
		second[a]=second[a]->next;
	}
	second[a]->next=NULL;
	st(second,third);
}

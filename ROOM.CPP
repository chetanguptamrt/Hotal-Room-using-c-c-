#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define m 5
#define n 5
void design();
void check_in();
void check_out();
void detail(int *back);
struct hotel
{
	char name[20];
	int age,person,avl;
};
struct hotel room[5][5];
void main()
{
	int ch,back=0;
	start:
	clrscr();
	design();
	cout<<"press 1 for check in\npress 2 for check out";
	cout<<"\npress 3 for show all room detail\npress 4 for exit\n";
	back_ch:
	cout<<"enter your choice - ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			check_in();
			break;
		case 2:
			check_out();
			break;
		case 3:
			detail(&back);
			if(back==1)
			{
				back=0;
				goto start;
			}
			break;
		case 4:
			goto end;
		default:
			cout<<"wrong choice! re-";
			goto back_ch;
	}
	goto start;
	end:
	clrscr();
	cout<<"thanks for using";
	getch();
}
void design()
{
	int i,j;
	cout<<"Formate of room:-\n";
	cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
	for(i=0;i<m;i++)
	{
		cout<<"|  ";
		for(j=0;j<n;j++)
		{
			if(room[i][j].avl==1)
			{
				cout<<i+1<<"0"<<j+1;
			}
			else
			{
				cout<<"emt";
			}
			cout<<"  |  ";
		}
		cout<<"\n";
	}
	cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
}
void check_in()
{
	int number,r,f;
	cout<<"\n\nplease write correct information!\n";
	top:
	cout<<"enter room number - ";
	cin>>number;
	r=number%10;
	f=number/100;
	if(room[f-1][r-1].avl==1)
	{
		cout<<"\nroom already exist re-";
		goto top;
	}
	else
	{
		room[f-1][r-1].avl=1;
	}
	cout<<"Name - ";
	cin>>room[f-1][r-1].name;
	cout<<"Age - ";
	cin>>room[f-1][r-1].age;
	cout<<"No of person - ";
	cin>>room[f-1][r-1].person;
}
void check_out()
{
	int number,r,f;
	cout<<"\n\nplease enter correct room number - ";
	cin>>number;
	r=number%10;
	f=number/100;
	room[f-1][r-1].avl=0;
}
void detail(int *back)
{
	int i,j,ch,p=0;
	clrscr();
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(room[i][j].avl==1)
				p=1;
	if(p==1)
	{
		cout<<"room detail:\nnumber\tname\tperson\tage";
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{

				if(room[i][j].avl==1)
				{
					cout<<endl;
					cout<<i+1<<"0"<<j+1;
					cout<<"\t"<<room[i][j].name;
					cout<<"\t"<<room[i][j].person;
					cout<<"\t"<<room[i][j].age;
				}
			}

		}
	}
	else
		cout<<"there are no information of room\n";
	cout<<"\npress 1 for back\npress 2 for exit\n";
	upr:
	cout<<"enter your choice - ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			++*back;
			break;
		case 2:
			exit(0);
		default:
			cout<<"\nwrong choice re-";
			goto upr;
	}
}
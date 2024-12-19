//Assignment-6 STL Sorting & Searching 

#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
class Student
{
	public:	//Make it public 
	int studRoll;
	char studName[20];
	char studDob[20];
	char studMob[11];
};
Student stud;
vector<Student> clg;
vector<Student>::iterator it;

bool compare(Student &s1,Student &s2)
{
	bool b;
	if(strcmp(s1.studName,s2.studName)<0) //Ascii Value Check krta 
	{
		b=true; //b=true not flag=1
		return b;
	}
	else
	{
		b=false; //b=false not use flag here 
		return b;
	}
}

void create()
{
	int n,i;	//for loop is used in create 
	cout<<"How many students do you want : ";
	cin>>n;
	cout<<"\nEnter details for students : ";
	for(i=0;i<n;i++)
	{
		cout<<"\n-----STUDENT "<<i+1<<" -----";
		cout<<"\nEnter Roll no :-> ";
		cin>>stud.studRoll;	//stud. is used we store data in object of class
		cout<<"Enter Name :-> ";
		cin>>stud.studName;
		cout<<"Enter Date of birth :-> ";
		cin>>stud.studDob;
		cout<<"Enter Contact No :-> ";
		cin>>stud.studMob;
		clg.push_back(stud); //push_back is used  
		cout<<"\nDetails Stored...";
	}
}

void display()
{
	cout<<"\n************************************************************";
	cout<<"\nNo \t Name \t DOB \t Contact No";
	cout<<"\n************************************************************"<<endl;
	for(it=clg.begin();it<clg.end();it++) //loop in both display and search  //here clg.begin / end remind it
	{
		cout<<(*it).studRoll;	//(*it). aahe studaahe  
		cout<<"\t"<<(*it).studName;
		cout<<"\t"<<(*it).studDob;
		cout<<"\t"<<(*it).studMob;
		cout<<endl;
	}
}

void search() //use flag in search
{
	int rollKey,flag;
	cout<<"\nEnter student roll no which u want to search : ";
	cin>>rollKey;
	for(it=clg.begin();it<clg.end();it++)
	{
		if((*it).studRoll==rollKey)
		{
			flag=1;
			break;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		cout<<"\nStudent is exist in college ";
	}
	else
	{
		cout<<"\nStudent is not exist in college ";
	}
}

void sortrecord()
{
	sort(clg.begin(),clg.end(),compare);
	cout<<"Record are get sorted....";
	display();
}

int main()
{
	int ch;
	do{
	cout<<"\n-----MENU-----";
	cout<<"\n1:-Insert Record\n2:-Display Record\n3:-Search Record\n4:-Sort Record\n5:-Exit";
	cout<<"\nEnter your choice...";
	cin>>ch;
	switch(ch){
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			search();
			break;
		case 4:
			sortrecord();
			break;
		case 5:
			cout<<"\Program terminated....";
			break;
		default:
			cout<<"Invalid choice..";
			break;
	}
}while(ch!=5);
	return 0;
}


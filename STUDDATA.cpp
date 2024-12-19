#include<iostream>
#include<string>
using namespace std;

class Student 
{
	public:
		string studName,studCls,studDob,studBg,studMob;
		int studDiv;
		int *studRoll;
		
	public:
		friend class faculty;
		
		Student()
		{
			studRoll=new int;
			*studRoll=studDiv=-1;	
			studName=studBg=studDob=studBg=studMob;
		}
		
		Student(int *studRoll, string studName,string studCls,string studDob,string studBg,string studMob,int studDiv )
		{
			this->studRoll=studRoll;
			this->studName=studName;
			this->studCls=studCls;
			this->studDob=studDob;
			this->studBg=studBg;
			this->studMob=studMob;
			this->studDiv=studDiv;
			cout<<".....Objects Intilized..... ";
		}
		
		~Student ()
		{
			delete studRoll;
		}

void create()
{
	cout<<"Enter Name: ";
	cin.ignore();
	getline(cin,studName);
		
	cout<<"Enter Roll Number: ";
	cin>>*studRoll;
	cout<<"Enter Cls: ";
	cin>>studCls;
	cout<<"Enter Division(1/2/3/4/5): ";
	cin>>studDiv;
	cout<<"Enter Date of Birth: ";
	cin>>studDob;
	cout<<"Enter Blood-Group: ";
	cin>>studBg;
	cout<<"Enter Contact Number: ";
	cin>>studMob;
	
}

void Display()
{
	cout<<*studRoll<<endl;
	cout<<studName<<endl;
	cout<<studCls<<endl;
	cout<<studDiv<<endl;
	cout<<studDob<<endl;
	cout<<studBg<<endl;
	cout<<studMob<<endl;
}
};

class Faculty //faculty is class not fun.
{
	private:
	int id ;
	public:
	Faculty()
	{
		id=000;	
	}
	Faculty(const Faculty &f1)
	{
		id=f1.id;
	}
	void fdisplay(Student &obj,int f_d)
	{
			try
			{
			if(obj.studDiv=f_d)
			obj.Display();
			else
			throw(obj.studDiv);
	        }
			catch(int x)
			{
				cout<<"\nInvalid Division ";
			}
		}
	};

int main()
{
	Student st[5];
	Faculty f;
	int ch, count=0;
	int *a1=0;
	Student obj1(a1,"Chandrakant","SE","25/07/2003","AB+","9146844236",3);
	do
	{
	cout<<"\n1. Add Infromation";
	cout<<"\n2. Display Informtaion";
	cout<<"\n3. Faculty ";
	cout<<"\n4. Exit";
	cout<<"\nEnter Your Choice";
	cin>>ch;
	
	switch(ch)
	{
		case 1:st[count].create();
		count++;
		break;
		
		case 2:
		for (int j=0;j<count;j++)
		{
			cout<<"\nStudent Info"<<endl;
			st[j].Display();
		}
		break;
		
		case 3:
		int f_div;
		cout<<"\nEnter Division of Faculty :";
		cin>>f_div;
		for(int j=0;j<count;j++)
		{
			cout<<"\nStudent RAS";
			f.fdisplay(st[j],f_div);
		}
		break;
		
		case 4:
			exit(0);
		
	}
	}while(ch!=4);
	return 0;
}















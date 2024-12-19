//OOPCGL-ASSIGNMENT NO 2

#include<iostream>
using namespace std;
class Marks;

class Student 
{
	int studRoll;
	string studNme,studCls,studDiv,studDob,studBlood,studAdd,studGender;
	double studCon,studDrive,avg;
	friend Marks;
	
	public:
		//Default constructor
		Student(){}
	//Parametric Constructor
	Student(int studRoll,string studNme,string studCls,string studDiv,string studDob,string studGender,double studCon,string studBlood,string studAdd,double studDrive,double avg){
		this->studRoll=studRoll;
		this->studNme=studNme;
		this->studCls=studCls;
		this->studDiv=studDiv;
		this->studDob=studDob;
		this->studGender=studGender;
		this->studCon=studCon;
		this->studBlood=studBlood;
		this->studAdd=studAdd;
		this->studDrive=studDrive;
		this->avg=avg;	
	}
	
		void putData(int n,Student s[]);
		static double calculate(int);	
};

class Marks 
{
	float oop,fds,deld,cg,dm;
	friend Student;
	public:
		
	Marks()
	{
		oop=0;
		fds=0;
		deld=0;
		cg=0;
		dm=0;
	}
		
		double getMarks(int);
		
};
inline double Marks::getMarks(int n)
{
	cout<<"Enter marks for oop,fds,deld,cg,dm:-> \n";
	cin>>oop>>fds>>deld>>cg>>dm;
	double avg=0,total=0;
	total=oop+fds+deld+cg+dm;
	avg=total/n;
	return avg;
}
void Student::putData(int n,Student s[])
{
	int i;
	cout<<"\n------DETAILS------";
	for(i=0;i<n;i++)
	{
//	cout<<"\nStudent "<<i+1<<endl;
	cout<<"\nRoll no : "<<s[i].studRoll;
	cout<<"\nName : "<<s[i].studNme;
	cout<<"\nClass : "<<s[i].studCls;
	cout<<"\nDivision : "<<s[i].studDiv;
	cout<<"\nContact : "<<s[i].studCon;
	cout<<"\nBlood Group : "<<s[i].studBlood;
	cout<<"\nAddress : "<<s[i].studAdd;
	cout<<"\nGender : "<<s[i].studGender;
	cout<<"\nDate of Birth : "<<s[i].studDob;
	cout<<"\nDriving : "<<s[i].studDrive;
	cout<<"Average : "<<s[i].avg;
	}
}
int main()
{
	int stud,i,ch;
	int studRoll;
	string studNme,studCls,studDiv,studDob,studBlood,studAdd,studGender;
	double studCon,studDrive,avg;
	Student obj;
	cout<<"Enter total number of student : "<<endl;
	cin>>stud;
	Student studArr[stud];
	do{
	
	cout<<"\n-----MENU-----"<<endl;
	cout<<"\t1:-Enter Details"<<endl;
	cout<<"\t2:-Display Details"<<endl;
	cout<<"\t3:-Exit"<<endl;
	cout<<"Enter your choice ....";
	cin>>ch;
	switch(ch)
	{
	case 1:
		for(i=0;i<stud;i++)
		{
			cout<<"\nEnter the details for student "<<i+1<<" :-> "<<endl;
			cout<<"Roll no: ";
			cin>>studRoll;
			cout<<"Name: ";
			cin>>studNme;
			cout<<"Class: ";
			cin>>studCls;
			cout<<"Division: ";
			cin>>studDiv;
			cout<<"Date of birth: ";
			cin>>studDob;
			cout<<"Gender: ";
			cin>>studGender;
			cout<<"Contact No: ";
			cin>>studCon;
			cout<<"Blood Group: ";
			cin>>studBlood;
			cout<<"Address: ";
			cin>>studAdd;
			cout<<"Driving liecence: ";
			cin>>studDrive;
			Marks mObj;
			avg=mObj.getMarks(stud);
			Student studObj1(studRoll,studNme,studCls,studDiv,studDob,studGender,studCon,studBlood,studAdd,studDrive,avg);
			studArr[i]=studObj1;
			cout<<"Details stored for student "<<i+1;
		}
		break;
	case 2:
		obj.putData(stud,studArr);
		break;
	}
}while(ch!=3);
	cout<<"Thank you...!!";
	return 0;
}


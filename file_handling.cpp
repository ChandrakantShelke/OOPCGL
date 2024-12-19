// Assignment-4 - Concept of file handling

#include<iostream>
#include<fstream>

using namespace std;

class Student
{
	int studRoll;
	string studName,studCls;
	double studMob;
	
	public:
		void acceptDetails();
		void displayDetails();
};

void Student::acceptDetails()
{
	cout<<"\n-----STUDENT DETAILS-----"<<endl;
	cout<<"Enter enrollment number :-> ";
	cin>>studRoll;
	cin.ignore();
	cout<<"Enter Name :-> ";
	getline(cin,studName);
	cout<<"Enter Class :-> ";
	getline(cin,studCls);
	cout<<"Enter Contact number :-> ";
	cin>>studMob;
}

void Student::displayDetails()
{
	cout<<"\n-----DETAILS-----";
	cout<<"\nEnrollment No : "<<studRoll;
	cout<<"\nName : "<<studName;
	cout<<"\nClass : "<<studCls;
	cout<<"\nContact No : "<<studMob;
}

int main()
{
	Student studObj[5];
	int i,n;
	ofstream fout;
	ifstream fin;
	cout<<"Enter total number of student : ";
	cin>>n;
	
	// Write in the file
	fout.open("student.txt", ios::binary|ios::out|ios::app); // app-append which start from next line
	if(fout.is_open())
	{
		for(i=0;i<n;i++)
		{
			studObj[i].acceptDetails(); 
			fout.write((char*) &studObj[i], sizeof studObj[i]);
		}
		cout<<"All details are get stored in file...";
	}
	else
	{
		cout<<"Error occured while opening file";
	}
	fout.close();
	
	//Read from the File 
	fin.open("student.txt",ios::binary|ios::in);
	if(fin.is_open())
	{
		for(i=0;i<n;i++)
		{
			while(fin.tellg()!=EOF)	////tellg-file pointer EOF- End of file 
			{ 
			fin.read((char*)&studObj[i],sizeof studObj[i]);
			studObj[i].displayDetails();
			}
		}
	}
	else
	{
		cout<<"Error occured while opening file";
	}
	fin.close();
	return 0;
}

//ios::binary makes sure the data is read or written without translating new line characters
//DISPLAY ALL DETAILS 
//READ & PRINT 


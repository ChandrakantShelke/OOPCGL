//Assignment-1 ----- Complex Number

#include<iostream>
using namespace std;
class Complex
{
	float real,imag;
	
public:
	Complex()
	{ //make the constructor of class
		real=0;
		imag=0; //initialize as 0 
	}
	
	Complex operator+(Complex); // complex is return-type for function and pass object as a parameter  
	Complex operator*(Complex); 
	
	friend istream &operator>>(istream &input,Complex &c) // use fried for access the object for both
	{ 
		cout<<"\nReal Part:";
		cin>>c.real;
		cout<<"Imaginary part:";
		cin>>c.imag;
	}
	//use friend isstream/ostream not complex 
	friend ostream &operator<<(ostream &output,Complex &c) //use &here not ::
	{
		cout<<"\n"<<c.real<<"+"<<c.imag<<"i";
	}
	
};

Complex Complex::operator+(Complex c) //use :: here not in friend 
{
	Complex temp;
	temp.real=real+c.real; //friend takes object automatically and we take c as a object
	temp.imag=imag+c.imag;
	return temp;
}
Complex Complex::operator*(Complex c)
{
	Complex temp;
	temp.real=(real*c.real)-(imag*c.imag); //do substraction here bcoz of i2 
	temp.imag=(imag*c.real)+(real*c.imag);
	return temp;
}

int main()
{
	Complex c1,c2,c3,c4;	//make them object of class not declare 
	int ch;
	cout<<"\nEnter first number : ";
	cin>>c1;
	cout<<"\nEnter second number : ";
	cin>>c2;
	cout<<"-----MENU-----"<<endl;
	cout<<"\n1-Addition"<<endl;
	cout<<"\n2-Multiplication"<<endl;
	cout<<"\nEnter choice...";
	cin>>ch;
	if(ch==1)
	{
		c3=c1+c2;
		cout<<"\nResult :- ";
		cout<<c3;
	}
	else if(ch==2)
	{
		c4=c1*c2;
		cout<<"\nResult :- ";
		cout<<c4;
	}
	
}

//Assignment-3

#include<iostream>
#include<string.h> //Don't forget to use this 
using namespace std;

class publication
{ 
  protected: //make this as protected 
     string title;
     float price;
     
  public:
    void add()
    {
        cout<<"Enter the title of book: ";
        cin.ignore();
        getline(cin ,title);
        cout<<"Enter the price of book: ";
        cin>>price;
    }
    
    void display() //void is must here 
    {
    cout<<"\n\nTitle of the book is :"<<title;
    cout<<"\nPrice of the book is :"<<price; 
    }    
};
    
class book:public publication
{
    private:
     int count;
     
    public:	//public is muste here 
    void add1()
     {
       try
       {
        add(); //call add in try block not outside it...
        cout<<"Enter number of the pages: ";
        cin>>count;

        if(count<=0)
          throw count;
       }
       catch(...)
       {
        cout<<"Invalid page count";
        count=0;
       }   
     }
      
	void display1()
    {
    	display();
    	cout<<"\nNumber of pages of the book is :"<<count;
    }
};


class tape:public publication
{
    private:
     float ptime;
     
    public:
     void add2()
    {
	  try
	  {
	  	add();
        cout<<"Enter time of the tape: ";
        cin>>ptime;

        if(ptime<=0)
         throw ptime;
      }
      catch(...)
      {
        cout<<"Invalid time ";
        ptime=0;
      }
  	}
	
    void display2()
    {
      display();
      cout<<"\nTime of the tape is : "<<ptime;
	}
};


int main()
{
  book b[50];
  tape t[50];
  int c,bc=0,tc=0;
  
do
{
cout<<"\n************************** BOOOK PUBLICATION **********************************";
cout<<"\n 1: To add information of book";
cout<<"\n 2: To display information of book";
cout<<"\n 3: To add information of tape";
cout<<"\n 4: To display information of tape";
cout<<"\n 5: To exit the program ";
cout<<"\n\n\nEnter your choice : ";
cin>>c;
switch(c)
{
    case 1:
      b[bc].add1();
			bc++ ;	//use bc++ not b+
			break;
      
    case 2:
      cout<<"\n--Book Information--";
			for(int i=0;i<bc;i++)
			{
				b[i].display1(); //display b[i].display1();
			}
			break;

    case 3:
     	t[tc].add2();
     		tc++;
     		break;

    case 4:
     	cout<<"\n--Tape Information--";
     		for(int i=0;i<tc;i++)
     		{
      			t[i].display2(); //remind this 
     		}
     		break;

    case 5:
     	exit(0);
     
    default:
     	cout<<"Invalid choice";
     	
}
}while(c!=5);
 return 0;
}

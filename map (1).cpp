//Assignment-7 - Map Associative Container
//string.insert in switch case-1 
//for loop state.begin wala in case 2 

#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<string,int> state; //record will save in state
	map<string,int>::iterator it; //for loop through state
	string st;
	int ch,pol;
	
	do
	{
	cout<<"\n-----MENU-----";
	cout<<"\n1:-Insert Record\n2:-Display Record\n3:-Exit";
	cout<<"\nEnter your choice...";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
			cout<<"\nEnter State : ";
			cin>>st;
			cout<<"Enter Polupation : ";
			cin>>pol;
			state.insert(pair<string,int>(st,pol));
			break;
	
		case 2:
			cout<<"\n State | Population"<<endl;
			for(it=state.begin();it!=state.end();it++)
			{	
				cout<<(*it).first<<" : "<<(*it).second<<endl;
			}
			break;
	
		case 3:
			cout<<"\Program terminated....";
			break;
			
		default:
			cout<<"Invalid choice..";
			break;
	}
}while(ch!=3);
	return 0;
}
//In C++, there are generally 3 kinds of STL containers:
//Sequential Containers.
//Associative Containers.
//Unordered Associative Containers.

//C++ provides 4 types of Associative Containers namely Set, Map, multiset and multimap.
//The map and the multimap are both containers that manage key/value pairs as single components. 
//The essential difference between the two is that in a map the keys must be unique, while a multimap permits duplicate keys.

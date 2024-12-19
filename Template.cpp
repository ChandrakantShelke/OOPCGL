// Assignment-5 - Template for selection sort 

#include<iostream>
# define size 20

using namespace std;
int n;

template<class T> //declare class in <>

void selection_sort(T arr[size]) //parameter of T arr[size]
{
	T temp; //dont forget to declare temmp
	int i,j,min;
	for(i=0;i<=n-2;i++)
	{
	 // our loop goes till second last element of array 
		min=i; 	// Our first element is store in min //write it in under for loop of i 
		for(j=i+1;j<=n-1;j++) //j will be 2nd element of array goes end of the array
		{ //remember j=i+1
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}	
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
	cout<<"\n----SORTED ARRAY----"<<endl;
	for(i=0;i<n;i++)
	{							//dont forgte to print sortes array 
		cout<<arr[i]<<"\t";
	}
}

int main()
{
	int int_arr[size];
	float float_arr[size];
	int ch;
	cout<<"-----MENU-----"<<endl;
	cout<<"1. Sort integer values"<<endl;
	cout<<"2. Sort float values"<<endl;
	cout<<"Enter your choice : ";
	cin>>ch;
	
	if(ch==1)
	{
		cout<<"Enter the size of array: "<<endl;
		cin>>n;
		cout<<"Enter integer elements :-> ";
		
	for(int i=0;i<n;i++)
	{
		cin>>int_arr[i];	//
	} 
		selection_sort(int_arr);	//	
	}
	
	else if(ch==2)
	{
		cout<<"Enter the size of array: "<<endl;
		cin>>n;
		cout<<"Enter float elements :-> ";
		
	for(int i=0;i<n;i++)
	{
		cin>>float_arr[i]; //
	}
		selection_sort(float_arr);//
	}
	
	else
	{
		cout<<"Wrong choice...program terminated...:(";
	}
	
	return 0;
}

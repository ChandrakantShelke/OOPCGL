#include<iostream>
#include<stdlib.h>
using namespace std;
char mat[3][3]={'1','2','3','4','5','6','7','8','9'};
char player='X';
int n;
void draw(){
	system("clear");
	cout<<"\tTIC TAC TOE\n"<<endl;
	cout<<" ______________"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		cout<<" | "<<mat[i][j];
		}
		cout<<" | ";
		cout<<endl;
		cout<<" ______________";
		cout<<endl;
	}
}
void input(){
	int a;
	cout<<"\n\n\tIt's "<<player<<" turn. "<<"Press number of the field :-> ";
	cin>>a;
	
	if(a==1){
		if(mat[0][0]=='1')
			mat[0][0]=player;
		else{
			cout<<"Field is already taken try again"<<endl;
			input();
		}
	}
	else if(a==2){
		if(mat[0][1]=='2')
			mat[0][1]=player;
		else{
			cout<<"Field is already taken try again"<<endl;
			input();
		}
	}
	else if(a==3){
		if(mat[0][2]=='3')
			mat[0][2]=player;
		else{
			cout<<"Field is already taken try again"<<endl;
			input();
		}
	}
	else if(a==4){
		if(mat[1][0]=='4')
			mat[1][0]=player;
		else{
			cout<<"Field is already taken try again"<<endl;
			input();
		}
	}
	else if(a==5){
		if(mat[1][1]=='5')
			mat[1][1]=player;
		else{
			cout<<"Field is already taken try again"<<endl;
			input();
		}
	}
	else if(a==6){
		if(mat[1][2]=='6')
			mat[1][2]=player;
		else{
			cout<<"Field is already taken try again"<<endl;
			input();
		}
	}
	else if(a==7){
		if(mat[2][0]=='7')
			mat[2][0]=player;
		else{
			cout<<"Field is already taken try again"<<endl;
			input();
		}
	}
	else if(a==8){
		if(mat[2][1]=='8')
			mat[2][1]=player;
		else{
			cout<<"Field is already taken try again"<<endl;
			input();
		}
	}
	else if(a==9){
		if(mat[2][2]=='9')
			mat[2][2]=player;
		else{
			cout<<"Field is already taken try again"<<endl;
			input();
		}
	}
}
void TogglePlayer(){
	if(player=='X')
		player='O';
	else
		player='X';
}
char win(){
	//Player X
	//Row:-
	if(mat[0][0]=='X' && mat[0][1]=='X' && mat[0][2]=='X')
		return 'X';
	if(mat[1][0]=='X' && mat[1][1]=='X' && mat[1][2]=='X')
		return 'X';
	if(mat[2][0]=='X' && mat[2][1]=='X' && mat[2][2]=='X')
		return 'X';
	
	//Column:-	
	if(mat[0][0]=='X' && mat[1][0]=='X' && mat[2][0]=='X')
		return 'X';
	if(mat[0][1]=='X' && mat[1][1]=='X' && mat[2][1]=='X')
		return 'X';
	if(mat[0][2]=='X' && mat[1][2]=='X' && mat[2][2]=='X')
		return 'X';
	
	//Diagonal:-	
	if(mat[0][0]=='X' && mat[1][1]=='X' && mat[2][2]=='X')
		return 'X';
	if(mat[2][0]=='X' && mat[1][1]=='X' && mat[0][2]=='X')
		return 'X';
		
	//Player O
	//Row:-
	if(mat[0][0]=='O' && mat[0][1]=='O' && mat[0][2]=='O')
		return 'O';
	if(mat[1][0]=='O' && mat[1][1]=='O' && mat[1][2]=='O')
		return 'O';
	if(mat[2][0]=='O' && mat[2][1]=='O' && mat[2][2]=='O')
		return 'O';
	
	//Column:-	
	if(mat[0][0]=='O' && mat[1][0]=='O' && mat[2][0]=='O')
		return 'O';
	if(mat[0][1]=='O' && mat[1][1]=='O' && mat[2][1]=='O')
		return 'O';
	if(mat[0][2]=='O' && mat[1][2]=='O' && mat[2][2]=='O')
		return 'O';
	
	//Diagonal:-	
	if(mat[0][0]=='O' && mat[1][1]=='O' && mat[2][2]=='O')
		return 'O';
	if(mat[2][0]=='O' && mat[1][1]=='O' && mat[0][2]=='O')
		return 'O';
	
	return 'f';
}
int main(){
	n=0;
	draw();
	while(1){
		n++;
		input();
		draw();
		if(win()=='X'){
			cout<<"\n\nX wins...!! :)"<<endl;
			break;
		}
		else if(win()=='O'){
			cout<<"\n\nO wins...!! :)"<<endl;
			break;
		}
		else if(win()=='f' && n==9){
			cout<<"\n\nIt's a draw"<<endl;
			break;
		}
		TogglePlayer();
		}
	//getch();
	return 0;

}

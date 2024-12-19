//Assignment - 12

#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int main(){
	int tx,ty,c,t,i,j,k,sx,sy,x1,x2,y1,y2;
	int ch;
	int refx,refy;
	float tx1;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	x1=y2=100;
	x2=y1=150;
	rectangle(x1,y1,x2,y2);
	while(ch!=4){
		cout<<"-----MENU----";
		cout<<"\n\t1: Transalation";
		cout<<"\n\t2: Rotation";
		cout<<"\n\t3: Scaling";
		cout<<"\n\t4: Exit";
		cout<<"\nEnter your choice...";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter tx and ty : ";
				cin>>tx>>ty;
				rectangle(x1+tx,y1+ty,x2+tx,y2+ty);
				break;
			case 2:
				int xx1,yy1,xx2,yy2,xx3,yy3,xx4,yy4;
				int ax1,ay1,ax2,ay2,ax3,ay3,ax4,ay4;
				cout<<"Enter angle : ";
				cin>>tx1;
				tx1=tx1*(3.14/180);
				refx=refy=100;
				
				xx1=yy1=yy2=xx4=100;
				xx2=xx3=yy3=yy4=150;
				
				ax1=refy+(xx1-refx)*cos(tx1)-(yy1-refy)*sin(tx1);
				ay1=refy+(xx1-refx)*sin(tx1)+(yy1-refy)*cos(tx1);
				
				ax2=refy+(xx2-refx)*cos(tx1)-(yy2-refy)*sin(tx1);
				ay2=refy+(xx2-refx)*sin(tx1)+(yy2-refy)*cos(tx1);
				
				ax3=refy+(xx3-refx)*cos(tx1)-(yy3-refy)*sin(tx1);
				ay3=refy+(xx3-refx)*sin(tx1)+(yy3-refy)*cos(tx1);
				
				ax4=refy+(xx4-refx)*cos(tx1)-(yy4-refy)*sin(tx1);
				ay4=refy+(xx4-refx)*sin(tx1)+(yy4-refy)*cos(tx1);
				
				line(ax1,ay1,ax2,ay2);
				line(ax2,ay2,ax3,ay3);
				line(ax3,ay3,ax4,ay4);
				line(ax4,ay4,ax1,ay1);
				break;
				
			case 3:
				cout<<"Enter sx and sy : ";
				cin>>sx>>sy;
				rectangle(x1*sx,y1*sy,x2*sx,y2*sy);
				break;
				
			case 4:
				cout<<"Program terminated..";
				break;
			
				
				
		}
	}
	getch();
	closegraph;
	
	return 0;	
}

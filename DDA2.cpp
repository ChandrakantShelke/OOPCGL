#include<graphics.h>
#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>

void dda(int x1,int y1,int x2,int y2)
{
	int length;
	int dx=(x2-x1);
	int dy=(y2-y1);
	
	if(dx>dy)
		float length = dx;
	else
		float length =dy;
		
	float xInc=dx/(float)length;
	float yInc=dy/(float)length;
	float x=x1;
	float y=y1;
	int i=1;
	
while(i<=length)
{
putpixel(x,y,15);
x=x+xInc;
y=y+yInc;
i++;
}

}

void display(int xc,int yc,int a,int b)
{
	putpixel(xc+a, yc+b, 15);
    putpixel(xc+a, yc-b, 15);
    putpixel(xc-a, yc+b, 15);
    putpixel(xc-a, yc-b, 15);
    putpixel(xc+b, yc+a, 15);
    putpixel(xc+b, yc-a, 15);
    putpixel(xc-b, yc+a, 15);
    putpixel(xc-b, yc-a, 15);
}

void circleb(int x1,int y1,int r) //int xc/yc and r remind 
{
	int a=0,b=r;
	int p=3-2*r; //decision parameter 
	display(x1,y1,a,b);
	while(b>=a)
	{
		a++;
		if(p>0)
		{
			b--;
			p=p+4*(a-b)+10;
		}
		else
		{ 
		p=p+4*a+6;
		}
		display(x1,y1,a,b);
	}
}

int main()
{
	int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    
    circleb(150,180,57);
    circleb(150,180,57/2);
    
    dda(102,209,150,123);
    dda(102,209,198,209); 
    dda(150,123,198,209) ;
    
    getch();
    closegraph();
    return 0;
}


#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

/*
 150	150		1
 250	150		1
 250	250		1
 150	250		1
*/	
void Input(float arr[][3],int n) //take here float 
{
    //cout<<"\nEnter the co-ordinates in clockwise order \n"; //polygon co-ordinate not only clockwise wale co-ordinates 
    for(int i=0 ; i<n ;i++)
	{
        cout<<"Enter the co-ordinates of " << i+1<<" vertex (x,y) : "; //no need to cin after that
        for( int j=0;j<=1;j++)
		{
            cin>>arr[i][j];
        }
        arr[i][2]=1;
    }
}

int multi(float a1[][3] , float a2[3][3], float arr[][3],int n) //a1-original a2-trans. a3f-final
{
    for(int i=0 ;i <n ;i++)
	{
        for(int j=0 ;j<3 ;j++)
		{
            for(int k=0 ;k<3;k++)
			{
                arr[i][j]=arr[i][j]+(a1[i][k] * a2[k][j]); //here not arr in brackets here a1 & a2 used in the brackets 
            }
        }
    }
}


int main()
{
	int m;
    cout<<"Enter the number of vertices of Polygon : ";
    cin>>m;

    float a[m][3]; //m -no of vertices 3-co-ordinate  //remind this to take both two lines 
    Input(a,m); //original polygon
    
    float  tx,ty , sx , sy ; //declare for taking the input from user fo TSR
    float ang; //remind to declare it ;

    float f[m][3]={0};	//Not forget to set it as 0
    // float b[3][3]={1,0,0,0,1,0,0,0,1};
    float r[3][3];
    float t[3][3];
    float s[3][3];
    
    cout<<"\n\t1.Translation\n\t2.Scaling\n\t3.Rotation\n";
    int c;
    cout<<"Enter your choice : ";
    cin>>c;
    
       
    switch(c)
	{
        case 1:
            cout<<"Enter translation factor\n";
            
        /*
        	1	0	0
        	0	1	0
        	tx	ty	1
        */
            cout<<"tx : ";
            cin>>tx;
            cout<<"ty : ";
            cin>>ty;
            t[0][0]=1;
            t[0][1]=0;
            t[0][2]=0;
            t[1][0]=0;
            t[1][1]=1;
            t[1][2]=0;
            t[2][0]=tx;
            t[2][1]=ty;
            t[2][2]=1;
            
            multi(a,t,f,m); //a-predefined polygon ..t-transformation ..F- final Square ..m-co-ordinates  
            break;
            
        case 2:
            cout<<"Enter the Scaling factor\n";
            
        /*
        	Sx	0	0
			0	Sy	0
			0	0	1    
        */
            cout<<"sx : ";
            cin>>sx;
            cout<<"sy : ";
            cin>>sy;
            s[0][0]=sx;
            s[0][1]=0;
            s[0][2]=0;
            s[1][0]=0;
            s[1][1] =sy;
            s[1][2]=0;
            s[2][0]=0;
            s[2][1]=0;
            s[2][2]=1;
            
            multi(a,s,f,m);
            break;
            
        case 3:
            cout<<"Enter the Angle of rotation : ";
            cin>>ang;
            ang=ang*(3.14/180.0); //convert this into radiant // declare it after taking the input 
        /*
			cos	 -sin	0
			sin	  cos	0
			0	   0    1        
        */
            r[0][0]=cos(ang);
            r[0][1]=-sin(ang);
            r[0][2]=0;
            r[1][0]=sin(ang);
            r[1][1]=cos(ang);
            r[1][2]=0;
            r[2][0]=0;
            r[2][1]=0;
            r[2][2]=1;
            
            multi(a,r,f,m);
            break;
            
        default:
            break;
    }

    int gd=DETECT , gm ;
    initgraph(&gd , &gm ,NULL);
    
    int j=0; //dont forget to make j =0
    
    for(int i=0 ;i<m ;i++)
	{
            line(a[i][j] , a[i][j+1], a[((i+1)%m)][j] , a[((i+1)%m)][j+1] ); //= is not use direct line() //arr is not used for ist loop a is used for next one f is used 
    }
    delay(4000);
    cleardevice();
    
    for(int i=0 ;i<m ;i++)
	{
            line(f[i][j] , f[i][j+1], f[((i+1)%m)][j] , f[((i+1)%m)][j+1] );
    }
    delay(4000);
    
    getch();
    closegraph();
    return 0;
}

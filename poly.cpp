#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

void polygon(int a[][2] ,int n){
    for(int i=0 ; i<n ;i++){
            cout<<"Enter the coordinates of "<<i+1 <<"Vertex (x,y) : ";
            cin>>a[i][0]>>a[i][1];
        }
        a[n][0]=a[0][0];
        a[n][1]=a[0][1];
}
int main(){
    cout<<"Enter the number of vertices of polygon : ";
    int n , k;
    cin>>n;
    int a[n+1][2];
    polygon(a,n);
    
    float slp[n];
    for(int i=0 ;i<n ;i++){
        float dx,dy;
        dx=a[i+1][0]-a[i][0];
        dy=a[i+1][0]-a[i][0];

        if(dx==0) slp[i]=0;
        else if (dy==0) slp[1]=1;
        else slp[i]=dy/dx;
    }

    int xi[20];
    int gd=DETECT , gm;
    initgraph(&gd ,&gm ,NULL);
    for(int y=0 ; y<=480 ;y++){
        k=0;
        //Intersection poinys ()
        for(int i=0 ;i<n ;i++){
            if((a[i][1]<=y && a[i+1][1]>y) || (a[i][1]>y && a[i+1][1]<=y)){
                xi[k]=(int)a[i][0] + slp[1]*(y-a[i][1]);
                k++;
            }
        }
        // sort()
        for (int j=0 ;j<n-1 ;j++){
            for(int i=0 ;i<k-1 ;i++){
                if(xi[i]>xi[i+1]){
                    int temp=xi[i];
                    xi[i]=xi[i+1];
                    xi[i+1]=temp;
                }
            }
        }
        //filling()
        setcolor(15);
        for(int i=0 ;i<k ;i+2){
            line(xi[i],y, xi[i+1]+1 ,y);
            //delay(10);
        }
    }

    closegraph();
    return 0;
}

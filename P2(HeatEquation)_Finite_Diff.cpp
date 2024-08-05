#include<iostream>
#include<cmath>
using namespace std;


#define pi 3.14159
// u(0,t)=u(1,t)=0
// u(x,0)=sin(pi*x)

// h=0.2 and k=0.02

// for t=0 to 0.06

float f(float x){

	return sin(pi*x);
}

int main(){
	
	int i,j,m,n;
	float h,k;
	float c,r,u[20][20];
	
	cout<<"Enter the value of  c: ";
	cin>>c;
	
	cout<<"\nEnter the values of h and k :";
	cin>>h>>k;
	
	m=int(0.06/k);
	n=int(1/h);
	r=(c*c*k)/(h*h);
	
	for (j=0;j<=m;j++){
		u[0][j]=u[n][j]=0;
	}
	
	for(i=1;i<n;i++){
		u[i][0]=f(i*h);
	}
	
	for(j=0;j<m;j++){
		for (i =1;i<n;i++){
			u[i][j+1]=r*(u[i-1][j]+u[i+1][j]) + (1-2*r)*u[i][j];
		}
	}
	
	cout<<"Solution of the heat equation is given by:\n";
	
	for(j=0;j<=m;j++){
		for(i=0;i<=n;i++)
		{
			printf("%.2f\t",u[i][j]);
		}
		cout<<endl;
	}
	
	return 0;
	
	
	
	
	
	
}

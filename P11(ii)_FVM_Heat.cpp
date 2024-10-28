#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int n,i;
	float h,k,A,B,Ua,Ub,L;
	float  a[10],b[10],c[10],d[10],a1[10],be[10],x[10];
	cout<<"Enter the initial and final temp:\n";
	cin>>Ua>>Ub;
	cout<<"Enter the length of the rod:\n";
	cin>>L;
	cout<<"Enter the thermal condictivity of the rod:\n";
	cin>>k;
	cout<<"Enter the cross section area: \n";
	cin>>A;
	cout<<"Enter the no. of nodal points:\n";
	cin>>n;

	h=L/n;
	B=(k*A)/h;
	for(i=2;i<=n;i++){
		a[i]=-B;
	}
	for(i=1;i<n;i++){
		c[i]=-B;
	}
	
	for(i=1;i<=n;i++){
		if(i==1||i==n){
			b[i]=3*B;
		}
		else
		{
			b[i]=2*B;
		}
	}
	for(i=2;i<n;i++){
		d[i]=0;
	}
	d[1]=2*B*Ua;
	d[n]=2*B*Ub;
	
	a1[1]=b[1];
	be[1]=d[1]/b[1];
	
	for (i=2;i<=n;i++){
		a1[i]=b[i]-(a[i]*c[i-1]/a1[i-1]);
		be[i]=(d[i]-a[i]*be[i-1])/a1[i];
	}
	x[n]=be[n];
	for(i=n-1;i>=1;i--){
		x[i]=be[i]-(c[i]*x[i+1])/a1[i];
	}
	cout<<"The solution of the system is: \n";
	
	for(i=1;i<=n;i++){
		cout<<fixed<<setprecision(2)<<x[i]<<", ";
		}
		
	
	return 0;
}

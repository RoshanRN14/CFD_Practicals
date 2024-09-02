#include<iostream>
#include<iomanip>
using namespace std;
float x[10];
float *tridiagonal(float r, float d[],int n)
{
    int i;
    float a=-r,b=(1+2*r),c=-r;
    float alpha[10],beta[10];
    alpha[1]=b;
    beta[1]=d[1]/b;
    for(i=2;i<n;i++)
    {
        alpha[i]=b-(a*c/alpha[i-1]);
        beta[i]=(d[i]-a*beta[i-1])/alpha[i];
    }
    x[n-1]=beta[n-1];
    for(i=n-2;i>=1;i--)
        x[i]=beta[i]-(c*x[i+1])/alpha[i];
    return x;
}
int main()
{
    int i,j,n,m;
    float u[100][100],h,k,c,r;
    r=0.5;
    m=5;
    n=5;
    for(j=0;j<=m;j++)
    {
        u[0][j]=0;
        u[n][j]=0;
    }
    for(i=1;i<n;i++)
        u[i][0]=10*i*(5-i);
    float d[n];
    for(j=0;j<m;j++)
    {
        for(i=1;i<n;i++)
            d[i]=r*u[i-1][j]+2*(1-r)*u[i][j+1]+r*u[i+1][j];
        float *y=tridiagonal(r,d,n);
        for(i=1;i<n;i++)
            u[i][j+1]=y[i];
    }
    cout<<"The value of all u(i,j): \n";
    cout<<fixed<<setprecision(2);
    for(j=m;j>=0;j--)
    {
        for(i=0;i<=n;i++)
           cout<<"\t"<<u[i][j];
       cout<<endl;
    }
}

#include<stdio.h>
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
    printf("Enter the value of c:");
    scanf("%f",&c);
    printf("Enter the value of r:");
    scanf("%f",&r);
    printf("Enter the value of m:");
    scanf("%d",&m);
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(j=0;j<=m;j++)
    {
        u[0][j]=0;
        u[n][j]=0;
    }
    for(i=1;i<n;i++)
        u[i][0]=(i*(8-i))/2.0;
    float d[n];
    for(j=0;j<m;j++)
    {
        for(i=1;i<n;i++)
            d[i]=r*u[i-1][j]+2*(1-r)*u[i][j+1]+r*u[i+1][j];
        float *y=tridiagonal(r,d,n);
        for(i=1;i<n;i++)
            u[i][j+1]=y[i];
    }
    printf("The value of all u(i,j):\n");
    for(j=m;j>=0;j--)
    {
        for(i=0;i<=n;i++)
            printf("%2.4f\t",u[i][j]);
        printf("\n");
    }
}
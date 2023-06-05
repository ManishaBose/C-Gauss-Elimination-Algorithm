#include<stdio.h>
#include<stdlib.h>
int main()
{
    int  n,i,j,k;
    float mult,pivot;
    printf("Enter the number of equations: ");
    scanf("%d",&n);
    float a[n][n+1],x[n];
    printf("Enter the equation coefficients:\n");
    for(i=0;i<n;i++)
        for(j=0;j<=n;j++)
            scanf("%f",&a[i][j]);
    printf("The matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%.2f\t",a[i][j]);
        printf("\n");
    }
    printf("The augmented matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%.2f\t",a[i][j]);
        printf("\n");
    }
    for(k=0;k<n-1;k++)
    {
        if(a[k][k] == 0.0)
		{
			printf("Mathematical Error!");
			exit(0);
		}
        pivot=a[k][k];
        for(i=k+1;i<n;i++)
        {
            mult=a[i][k]/pivot;
            for(j=0;j<=n;j++)
                a[i][j]=a[i][j]-(mult*a[k][j]);
        }
    }
    printf("The upper triangular matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%.2f\t",a[i][j]);
        printf("\n");
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
            a[i][n]=a[i][n]-a[i][j]*x[j];
        x[i]=a[i][n]/a[i][i];
    }
    printf("The values are:\n");
    for(i=0;i<n;i++)
    printf("x[%d]= %.2f\n",i+1,x[i]);
}

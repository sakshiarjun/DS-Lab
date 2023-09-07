#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10][10],b[10][10],c[10][10],n,m,i,j,temp;
    printf("Enter no. of rows ");
    scanf("%d",&n);
    printf("Enter no. of columns ");
    scanf("%d",&m);
    printf("Enter elements of Matrix A ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter elements of Matrix B ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&b[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]>b[i][j])
          {
             c[i][j]=a[i][j];
             //printf("%d   ",c[n][m]);

          }
        else
            c[i][j]=b[i][j];

        }

    }
    printf("MATRIX C \n");
     for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
            printf("%d ",c[i][j]);
         printf("\n");
     }

}

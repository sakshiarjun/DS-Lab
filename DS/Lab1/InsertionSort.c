#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,x,n,a[10];
    printf("Enter no. of elements of the array ");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1; i<n; i++)
    {
        x=a[i];
        j=i-1;
        while(j>=0)
        {
            if(x<a[j])
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
            j=j-1;
        }
        a[j+1]=x;
    }
    printf("Sorted Array: ");
    for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    return 0;
}

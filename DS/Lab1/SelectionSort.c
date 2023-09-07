#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,a[10],n,temp,min;
    printf("Enter no. of elements of the array ");
    scanf("%d",&n);
    printf("Enter elements of the array ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
    }

    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10],i,j,low,high,mid,num,n,temp,flag=0;
    printf("Enter no. of elements of the array ");
    scanf("%d",&n);
    printf("Enter elements of the array ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter element to be searched ");
    scanf("%d",&num);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    low=0; high=n;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==num)
        {
            flag=1;
            break;
        }
        else if(num<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    if(flag==1)
        printf("%d found at position %d", num,mid);
    else
        printf("Element not found");
    return 0;
}

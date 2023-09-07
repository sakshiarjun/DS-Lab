#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10],n,i,num,pos,flag=0;
    printf("Enter no. of elements in array ");
    scanf("%d",&n);
    printf("Enter elements of the array ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter element to be searched ");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        if(num==a[i])
        {
          pos=i;
          flag=1;
          break;
        }
    }
    if(flag==1)
        printf("Element found at position: %d",pos);
    else
        printf("Element not found");
    return 0;
}

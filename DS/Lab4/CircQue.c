#include<stdio.h>
#define MAX_SIZE 50
#include<stdbool.h>
#include<stdlib.h>
typedef struct
{
    int key;
    int r;
    int f;
}element;
element CQ[MAX_SIZE];
r=0; f=0;
bool isFull()
{
    return ((r+1)%MAX_SIZE==f);
}
bool isEmpty()
{
    return (r==f);
}
void insert(element e)
{
    if(!isFull())
    {
        r=(r+1)%MAX_SIZE;
        CQ[r]=e;
    }
}
element delete()
{
    element ret;
    ret.key=-1;
    if(!isEmpty())
    {
        f=(f+1)%MAX_SIZE;
        ret=CQ[f];
    }
    return(ret);
}
void display()
{
    for(int i=(f+1)%MAX_SIZE; i!=r; i=(i+1)%MAX_SIZE)
    {
        printf("%d ",CQ[i].key);
    }
    printf("%d\n",CQ[r].key);
}
int main()
{
    int c;
    element e;
    do
    {
        printf("Enter 0 to insert, 1 to delete, 2 to display, 3 to stop");
        scanf("%d",&c);
        switch(c)
            {
                case 0:
                    printf("Enter value: ");
                    scanf("%d",&e.key);
                    insert(e);
                    break;
                case 1:
                    printf("Deleted: %d\n", delete(e));
                    break;
                case 2:
                    display();
                case 3:
                    //exit(0);
                    break;
                default:
                    printf("Enter Valid input");
                    break;
            }
    }while(c!=3);

}

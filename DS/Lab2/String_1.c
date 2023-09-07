#include<stdio.h>
int main()
{
    char str[100],str2[100],str1[100],temp1[100],substr[50],subdel[50];
    printf("Enter a string: ");
    scanf("%[^\n]",str);
    fflush(stdin);
    int i,strlen=0,str2len=0,loc,substrlen=0,isfound=0,subdellen=0;
    for(i=0;str[i]!='\0';i++)
    {
        strlen++;
        str1[i]=str[i];
        temp1[i]=str[i];
    }
    printf("String length= %d\n",strlen);
    printf("Enter another string: ");
    scanf("%[^\n]",str2);
    fflush(stdin);
    for(i=0;str2[i]!='\0';i++)
        str2len++;
    for(i=0;i<=str2len;i++)
        str[strlen+i]=str2[i];
    printf("Concatenated String= %s\n",str);
    //printf("BOOM %s\n",temp);
    for(i=0;i<(strlen+str2len);i++)
    {
        if(str1[i]>str2[i])
            {
                printf("First String is greater");
                break;
            }
        else
            {
                printf("Second String is greater");
                break;
            }
    }
    printf("\nEnter substring: ");
    scanf("%[^\n]",substr);
    fflush(stdin);
    for(i=0;substr[i]!='\0';i++)
        substrlen++;
    printf("Enter location where substring should be added ");
    scanf("%d",&loc);
    for(i=strlen; i>=loc; i--)
        str1[i+substrlen]=str1[i];
    for(i=0; i<substrlen; i++)
        str1[loc+i]=substr[i];
    printf("String w Substring= %s",str1);
    printf("Enter SubString to be deleted: ");
    scanf("%[^\n]",subdel);
    for(i=0;subdel[i]!='\0';i++)
        subdellen++;
    for(i=0;i<strlen;i++)
    {
        isfound=1;
        for(j=0;j<subdellen;j++)
        {
            if(temp[i+j]!=)
        }
    }
    return 0;
}

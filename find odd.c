#include<stdio.h>
void main()
{
    int a[5],i,s=0;
    printf("enter the values:- ");  
//scanf("%d",&a[i]);
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++)
    {
        if(a[i]%2!=0)
        {
            s=s+a[i];
        }
    }
    printf("%d",s);
}
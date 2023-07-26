#include<stdio.h>
void main()
{
    int a[10],i;
    printf("enter the values:- ");
    for ( i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
        printf("%d\t",a[i]);
    }
    
    printf("\n");
}
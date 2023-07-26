#include<stdio.h>
void main()
{
    int a[10][10],b[10][10],c[10][10],i,j,k,s=0,r1,r2,c1,c2;
    printf("enter the no of rows:- ");
    scanf("%d",&r1);
    printf("enter the column:- ");
    scanf("%d",&c1);
    printf("enter the elements of 1st matrix:- ");
    for(i=0;i<r1;i++)
    {
        for ( j = 0; j<c1; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    printf("enter the no of rows:- ");
    scanf("%d",&r2);
    printf("enter the column:- ");
    scanf("%d",&c2);
    printf("enter the elements of 2nd matrix:- ");
    for(i=0;i<r2;i++)
    {
        for ( j = 0; j<c2; j++)
        {
            scanf("%d",&b[i][j]);
        }
        
    }



    if (c1==r2)
    {
        
        for ( i = 0; i < r1; i++)
        {
            for ( j = 0; j< c2; j++)
            {
                for ( k = 0; k < r2; k++)
                {
                    s += a[i][k] * b[k][j];
                }
                c[i][j]=s;

                s=0;
            }
            // printf("%4d",s);
            // printf("\n");
        }
        // printf("\n");


    for ( i = 0; i < r1; i++)
    {
        for ( j = 0; j < c2; j++)
        {
            printf("%d\t ",c[i][j]);
        }
        printf("\n");
        
        
    }


    }
    else
    {
        printf("please enter another elements");
    }
    // for ( i = 0; i < r1; i++)
    // {
    //     for ( j = 0; j < c2; j++)
    //     {
    //         printf("%d",c[i][j]);
    //     }
        
    // }
    
}
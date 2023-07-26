#include<stdio.h>
void main()
{
    int  BT[5],i,n,time=0,AT[5],TAT[5],ET[5],WT[5];
    printf("enter the process number:- ");
    scanf("%d",&n);
    // input BT and At
    for ( i =0; i < n; i++)
    {
        printf("\np%d BT AT: ",(i+1));
        scanf("%d",&BT[i]);
        scanf("%d",&AT[i]);
    }
    
    // calculate ET
    for ( i = 0; i < n; i++)
    {
        time=BT[i]+time;
        ET[i]=time;

    }
    // process method
    for ( i = 0; i < n; i++)
    {
        TAT[i]=ET[i]-AT[i];
        printf("%d\n",TAT[i]);
    }

    for ( i = 0; i < n  ; i++)
    {
        WT[i]=TAT[i]-BT[i];
        printf("%d\n",WT[i]);
    }
    
}
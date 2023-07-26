#include<stdio.h>
void main()
{
    int a[5],i,s=0,j,p=0;
    printf("enter the values:- ");  
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
 
    }

    for(i=0; i<5; i++)
    {
        // printf("1st for loop %d %d\n", a[i],i);
        if((a[i]%2) != 0)
        {
            // printf("\t 1st if %d %d\n", a[i],i);
            for(j=2;j<=(a[i]/2);j++)
            {
                // printf("\t\t 2nd for loop %d %d\n", a[i],j);
                if((a[i]%j) != 0)
                {
                    // printf("\t\t\t 2nd if %d %d\n", a[i],j);
                    p=1;

                }
                else{
                    p=0;
                    break;
                }
            }

            if(p==1)
            {
                // printf("3rd if %d %d\n\n", a[i],i);
                printf("%d\n",a[i]);
                s=s+a[i];
            }

            
        }
        
    }
    printf(" \t sum of the odd prime number is %d\n",s);

}
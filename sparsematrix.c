#include <stdio.h>
void main()
{
    int i, j, a[2][3], c = 0, b = 0;
    printf("enter the matrix:-");

    for (i = 0; i < 2; i++)
    {
        // printf(" l1 run %d\n",i);
        for (j = 0; j < 3; j++)
        {
            // printf("l2 run %d",j);

            scanf("%d", &a[i][j]);
        }
    }

// printf("dfshdgf");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
            {
                c++;
            }
            else
            {
                b++;
            }
        }
    }
    if (c>b)
    {
        printf("it is a sparse matrix");
    }
    else
    {
        printf("it is not sparse matrix");
    }
}
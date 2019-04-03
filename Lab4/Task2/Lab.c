#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int n = 20, r = 100;
    int i,j, a[n];

    srand((unsigned)time(NULL));

    for (i = 0; i < n; i++)
    {
        a[i] = (int)(rand()%r);
        printf("%d ",a[i]);
    }

    int tmp;
    for (i = 0; i <(n-1);i++)
    {
        for (j = 0; j<(n-1)-i;j++)
        {
            if (a[j]%2 != 0)
            {
                tmp =a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }


    printf("\nResult:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    getch();
    return 0;
}


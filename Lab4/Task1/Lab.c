#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int n = 20, r = 100;
    int i, a[n];

    srand((unsigned)time(NULL));

    for(i = 0; i < n; i++)
    {
        a[i] = (int)(rand()%r);
        printf("%d ",a[i]);
    }

    int min = a[0],max =a[0];

    for(i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    int iminpr,imaxpr;
    int k = 0;

    for(i = 0;i < n; i++)
    {
        if (a[i]%2 == 0)
        {
            k++;
            if (k == 1)
                iminpr = i;
            else imaxpr = i;
        }
    }

    if (k < 2)
        printf("\nImpossible because of parity numbers less then two");
    else
    {
        a[iminpr] = min;
        a[imaxpr] = max;
        printf("\nResult:\n");
        for(i = 0; i < n; i++)
            printf("%d ",a[i]);
    }

    getch();
    return 0;
}


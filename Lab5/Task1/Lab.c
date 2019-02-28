#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int main()
{

    int n, r = 100;

    printf("Enter array length: ");
    scanf("%d",&n);

    int* a;
    int i,j;

    a=(int*)malloc(n*sizeof(int));
    srand((unsigned)time(NULL));

    printf("\nArray:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = (int)(rand()%r);
        printf("%d ",a[i]);
    }

	int max=a[0],min=a[0];
	int imin,imax,tmp,imaxnew;

	for(i =0;i<n;i++)
	{
		if(a[i]<min)
		{
			min = a[i];
			imin = i;
		}
		if(a[i]>max)
		{
			max = a[i];
			imax = i;
		}
	}

	for (i=0;i<imin;i++)
	{
		tmp = a[0];
		for (j=0;j<n-1;j++)
		{
			a[j]=a[j+1];
		}
		a[n-1]=tmp;
	}

	imaxnew = imax - imin;

	if (imaxnew<0) imaxnew = n-abs(imaxnew);
	printf("\nLeft cyclic shift with min element on first place:\n");

	for(i =0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	//printf("\n%d",imaxnew);

	for (i=0;i<n-1-imaxnew;i++)
	{
		tmp = a[n-1];
		for (j=n-1;j>1;j--)
		{
			a[j]=a[j-1];
		}
		a[1]=tmp;
	}

	printf("\nRight cyclic shift of n-1 element with max on last place:\n");
	for(i =0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
    free(a);
	getch();
	return 0;
}


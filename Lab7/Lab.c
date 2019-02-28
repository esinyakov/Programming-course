#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int** a;
	int min,max,n,i,j,r=100;
	
	printf("Enter n: ");
    scanf("%d",&n);
    srand((unsigned)time(NULL));
    
	a = (int**)malloc(n*sizeof(int*));
	for (int i = 0; i<n;i++)
	{
		*(a+i)=(int*)malloc(n*sizeof(int*));
	}
	

    printf("\nArray:\n");
	for (i = 0; i < n; i++)
    {
		for (j = 0; j < n; j++)
		{
			*(*(a+i)+j) = (int)(rand()%r);
		}
        
    }
	
	for (i = 0; i < n; i++)
    {
		for (j = 0; j < n; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
    }
	
	min = a[0][0];
	max = a[0][0];
	for (i = 0,j=0; i < n; i++,j++)
    {
            if (a[i][j]<min) min = a[i][j];
		    if (a[i][j]>max) max = a[i][j];
    }
    
    printf("min %d,max %d",min,max);
    
    for (i = 0; i < n; i++)
    {
		for (j = 0; j < n; j++)
		{
		    if((j>i) && (a[i][j]%2==0)) a[i][j]=min;
		    else if ((j<i) && (a[i][j]%2!=0)) a[i][j]=max;
		}
    }
    
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
		for (j = 0; j < n; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
    }
    
    for(i =0;i<n;i++)
    {
        free(a[i]);
    }
    free(a);
    
	getch();
	return 0;
}
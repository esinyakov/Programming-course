#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

	int const n =4 , m =5;
	int a[n][m],b[n];	
	int i,j,min,tmp,k,r = 100;

	srand((unsigned)time(NULL));

	printf("\nArray:\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a[i][j] = (int)(rand()%r);
		}

	}

	for (i = 0; i < n; i++)
	{
		min = a[i][0];
		for (j = 0; j < m; j++)
		{
			printf("%d ",a[i][j]);
			if(a[i][j]<min) min = a[i][j];
		}
		printf(" min:%d\n",min);
		b[i] = min;       
	}


	for(i = 0 ; i < n - 1; i++) 
	{ 
		for(j = 0; j < n - 1 - i ; j++) 
	   	{  
	   		if(b[j] > b[j+1]) 
			{           
				tmp = b[j+1];
				b[j+1] = b[j];
				b[j]=tmp;

				for(k=0; k < m; k++)
				{	
					tmp = a[j+1][k];
					a[j+1][k]=a[j][k];
					a[j][k]=tmp;
				}
	   		}
		}
	}

	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ",b[i]);
	}

	printf("\n\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");     
	}

	getch();
	return 0;
}

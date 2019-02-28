#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

    const int n =4;
	int a[n][n];
    int i,j,tmp,r = 100;
	int* pa;
    srand((unsigned)time(NULL));

	pa = a;
	
    printf("\nArray:\n");
	
    for (i = 0; i < n; i++)
    {
		for (j = 0; j < n; j++)
		{
			a[i][j] = (int)(rand()%r);
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
    

	for(i = 0 ; i < n*n - 1; i++) 
	{ 
       for(j = 0; j < n*n - 1 - i ; j++) 
	   {  
           if(*(pa+j) > *(pa+j+1)) 
		   {           
				tmp = *(pa+j+1);
				*(pa+j+1) = *(pa+j);
				*(pa+j)=tmp;
           }
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
    
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			tmp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=tmp;
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
	
	getch();
	return 0;
}
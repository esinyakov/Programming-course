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
    int i,j,k;

    a=(int*)malloc(n*sizeof(int));
    srand((unsigned)time(NULL));

    printf("\nArray:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = (int)(rand()%r);
        printf("%d ",a[i]);
    }

	printf("\n\n");

	for (i=0;i<n;i++)
	{
		k=0;
		for(j=i;j<n;j++)
		{
			if(a[i]==a[j])k++;
		}
		printf("%d - %d times\n",a[i],k);

	}
	free(a);

	getch();
	return 0;
}


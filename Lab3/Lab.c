#include <stdio.h>

int main()
{
	int x, y, i;
	printf("Enter x,y: ");
	scanf("%d%d", &x, &y);

	for (i += x; i <= y;)
	{
		int a = i;
		int temp = a;
		int b = 0;

		while (temp != 0)
		{
			b = b * 10 + temp % 10;
			temp /= 10;
		}

		if (a == b)
		{
			printf("\nPolindrom: %d", a);
		}

		i += 1;
	}

    getch();
    return 0;
}


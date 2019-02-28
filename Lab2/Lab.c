#include <stdio.h>
#include <math.h>

int main()
{
	double r, a, b, c;
	printf("Enter circle radius r: ");
	scanf("%lf", &r);
	printf("Enter parallelepiped edges a,b,c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	if (sqrt(a * a + b * b) < r) printf("\nThe shape can be inserted in circle along the edges a and b");
	if (sqrt(b * b + c * c) < r) printf("\nThe shape can be inserted in circle along the edges b and c");
	if (sqrt(a * a + c * c) < r) printf("\nThe shape can be inserted in circle along the edges a and c");
	else printf("The shape can not be inserted in circle");
	getch();
	return 0;
}


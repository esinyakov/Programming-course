//Create two arrays A and B. Fill it with random numbers.
//Array C should be filled with numbers wich are matching in arrays A and B, without doubling.
//Use pointers.
//Создать массив A и B, заполнить массивы случайными числами. В массив C должны попасть числа которые
//совпадают в массивах A и B, без повторений. Используйте указатели.
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#pragma warning (disable: 4996)
using namespace std;

int main()
{
	const int n1 = 5, n2 = 7, r = 100;
	int a[n1], b[n2];
	int i = 0;
	int j = 0;
	int ipc = 0;
	srand((unsigned)time(NULL));
	int *pc = NULL;

	cout << "Array A: ";
	for (i = 0; i < n1; i++)
	{
		a[i] = (int)(rand() % r);
		cout << a[i] << " ";
	}
	printf("\n");

	cout << "Array B: ";
	for (j = 0; j < n2; j++)
	{
		b[j] = (int)(rand() % r);
		cout << b[j] << " ";
	}

	pc = (int*)calloc(n2, sizeof(int));

	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			if (a[i] == b[j])
			{
				*(pc + ipc) = a[i];
				ipc++;
				break;
			}
		}
	}

	printf("\n");

	cout << "Array C: ";
	for (i = 0; i < ipc; i++)
	{
		cout << *(pc + i) << " ";
	}

	free((void*)pc);

	_getch();
}

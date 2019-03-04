#include "dic.h"

void dicMain()
{
    char **ptrDictionary = NULL;
    int dictionaryFilled = 0;//filled dictionary positions
    int dictionaryLength = 0;
    int wordMaxLength = 0;
    int sortedDictionary = 0;

    const char *commandsenum=
    "\n-----------------------------"
    "\n0 - exit"
    "\n1 - create"
    "\n2 - delete"
    "\n3 - dictionary print"
    "\n4 - word print"
    "\n5 - find"
    "\n6 - information"
    "\n-----------------------------"
    "\nenter command: ";

    char command;

    while (check(commandsenum, &command))
	{
		switch (command)
		{
		case '1':
			if (ptrDictionary == NULL) ptrDictionary = createDictionary(&dictionaryLength, &wordMaxLength);
			if (addWord(ptrDictionary, &dictionaryFilled, &dictionaryLength))
				sortedDictionary = sortDictionary(ptrDictionary, dictionaryFilled);
			break;
		case '2':
			if (ptrDictionary == NULL) { printf("dictionary empty"); break; }
			deleteWord(ptrDictionary, &dictionaryFilled);
			break;
		case '3':
			if (ptrDictionary == NULL) { printf("dictionary empty"); break; }
			printDictionary(ptrDictionary, dictionaryFilled);
			break;
		case '4':
			if (ptrDictionary == NULL) { printf("dictionary empty"); break; }
			printWord(ptrDictionary);
			break;
		case '5':
			if (ptrDictionary == NULL) { printf("dictionary empty"); break; }
			findWord(ptrDictionary, dictionaryFilled,wordMaxLength);
			break;
		case '6':
			if (ptrDictionary == NULL) { printf("dictionary empty"); break; }
			printInfo(&dictionaryLength, &dictionaryFilled, &wordMaxLength);
			break;
		default:
			printf("repeat enter");
			break;

		}
	}
}

int check(const char *pcl, char *pc)

{
	printf("%s", pcl);
	const char key0 = '0', key9 = '9';
	char command;
	int ibool = 1;

	while (ibool)
	{
		command = getchar();
		if ((command >= key0) && (command <= key9))
			ibool--;
	}

	*pc = command;
	return(command != key0);
}

char** createDictionary(int *dictionaryLength, int *wordMaxLength)
{

	char **dictArr = NULL;

	printf("\nCreating dictionary: \n");
	printf("enter word amount: \n");
	scanf("%d", dictionaryLength);
	printf("enter word max length: \n");
	scanf("%d", wordMaxLength);

	dictArr = (char **)calloc(*dictionaryLength, sizeof(char*));
	if (!dictArr) return dictArr;//no memory
	for (int i = 0; i < *dictionaryLength; i++)
		dictArr[i] = (char*)calloc(*wordMaxLength, sizeof(char));
	return dictArr;//pdictionary
}

int addWord(char **ptrDictionary, int *dictionaryFilled, int *dictionaryLength)
{

	int wordsNumber = 0;
	printf("how many words do you want to fill now?: \n");
	scanf("%d", &wordsNumber);
	if (wordsNumber > *dictionaryLength - *dictionaryFilled)
	{
		printf("dictionary overfilled\n");
		return 0;
	}

	for (int i = 0; i < wordsNumber; i++)
	{
		printf("enter word: \n");
		scanf("%s", *(ptrDictionary + (i + *dictionaryFilled)));//write in the free position
	}

	(*dictionaryFilled) += wordsNumber;
	return 1;

}
int sortDictionary(char **ptrDictionary, int length)
{


	char *tmp = NULL;
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (strcmp(ptrDictionary[j], ptrDictionary[j + 1]) > 0)
			{
				tmp = ptrDictionary[j];
				ptrDictionary[j] = ptrDictionary[j + 1];
				ptrDictionary[j + 1] = tmp;
			}
		}
	}
	return 1;
}

void deleteWord(char **ptrDictionary, int *dictionaryFilled)
{
	int wordsNumber = 0;
	int index = 0;

	printf("enter number of words to be deleted: \n ");
	scanf("%d", &wordsNumber);

	for (int j = 0; j < wordsNumber; j++)
	{
		printf("enter number of deleted word: \n ");
		scanf("%d", &index);

		for (int i = index - 1; i < *dictionaryFilled; i++)
			ptrDictionary[i] = ptrDictionary[i + 1];
		(*dictionaryFilled)--;
	}
}

void printDictionary(char **s, int length)
{
	printf("-dictionary-\n");
	for (int i = 0; i < length; i++)
		printf("%d. %s\n", i + 1, *(s + i));
}

void printWord(char **ptrDictionary)
{
	int wordsNumber = 0;
	int index = 0;
	printf("enter number of printed words: \n ");
	scanf("%d", &wordsNumber);
	for (int j = 0; j < wordsNumber; j++)
	{
		printf("enter word number: \n ");
		scanf("%d", &index);
		printf("%d. %s\n", index, ptrDictionary[index - 1]);
	}
}

void findWord(char **ptrDictionary, int dictionaryFilled, int wordMaxLength)
{
        char *wordToFind = NULL;
	int wordsNumber = 0;

	wordToFind = (char*)calloc(wordMaxLength, sizeof(char));
	printf("enter number of words to find: \n ");
	scanf("%d", &wordsNumber);
	for (int j = 0; j < wordsNumber; j++)
	{
		printf("\nenter word\n ");
		scanf("%s", wordToFind);
		int flag = 0;
		int l = 0, r = dictionaryFilled - 1;
		int m = 0, c = 0;

		while (l <= r)
		{
			m = (l + r) / 2;
			c = strcmp(wordToFind, ptrDictionary[m]);
			if (!c)	{ flag = 1; break; }
			if (c < 0) r = --m;
			else l = ++m;
		}

		if (flag) printf("word found: # %d. %s\n", m + 1, ptrDictionary[m]);
		else printf("word not found\n");

	}
}

void printInfo(const int *dictionaryLength, const int *dictionaryFilled, const int *wordMaxLength)
{
	printf("information about dictionary:\n");
	printf("1. words number %d\n", *dictionaryLength);
	printf("2. filled positions %d\n", *dictionaryFilled);
	printf("3. max word length %d\n", *wordMaxLength);
}



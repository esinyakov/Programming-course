#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void dicMain();
int check(const char *pcl, char *pc);
char** createDictionary(int *dictionaryLength, int *wordMaxLength);
void deleteDictionary(char** dictArr, int *maxLengthOfWord);
void printDictionary(char **s, int length);
int sortDictionary(char **ptrDictionary, int length);
int addWord(char **ptrDictionary, int *dictionaryFilled, int *dictionaryLength);
void deleteWord(char **ptrDictionary, int *dictionaryFilled);
void printWord(char **ptrDictionary);
void findWord(char **ptrDictionary, int dictionaryFilled, int wordMaxLength);
void printInfo(const int *dictionaryLength, const int *dictionaryFilled, const int *wordMaxLength);

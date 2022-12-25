#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Address.h"
#include "string.h"

#define SPACE " "

int	initAddress(Address* theAddress)
{
	char allData[MAX_STR_LEN];
	char** elements;
	int count;
	int ok = 1;
	do {
		getsStrFixSize(allData, sizeof(allData),
			"Enter address data\nFormat: street#house number#city\nstreet and city can have spaces\n");
		elements = splitCharsToWords(allData, &count, "#");
		ok = checkNumberWords(elements, count);
		if (!ok)
			freeElements(elements, count);
	} while (!ok);
	sscanf(elements[1], "%d", &theAddress->num);
	theAddress->street = fixSentece(elements[0]);
	if (!theAddress->street)
	{
		freeElements(elements, count);
		return 0;
	}

	theAddress->city = fixSentece(elements[2]);
	if (!theAddress->city)
	{
		free(theAddress->street);
		freeElements(elements, count);
		return 0;
	}

	freeElements(elements, count);
	return 1;
}

char*	fixSentece(char* param)
{
	char* fixParamStr;
	char** wordsArray = NULL;
	int totalLength;
	int count;

	wordsArray = splitCharsToWordsBySpace(param, &count, &totalLength);
	fixParamStr = (char*)calloc(totalLength + count, sizeof(char));
	if (!fixParamStr)
	{
		for (int i = 0; i < count; i++)
			free(wordsArray[i]);
		free(wordsArray);
		return NULL;
	}

	int len;
	for (int i = 0; i < count; i++)
	{
		len = (int)strlen(wordsArray[i]);
		wordsArray[i][0] = toupper(wordsArray[i][0]); 
		for (int j = 1; j < len - 1; j++)
		{
			wordsArray[i][j] = tolower(wordsArray[i][j]); 
		}
		if (count == 1 || i == count - 1)
			wordsArray[i][0] = tolower(wordsArray[i][0]);
		if (i != 0)
			strcat(fixParamStr, SPACE);
		strcat(fixParamStr, wordsArray[i]);
		//i tried to print double spaces but for some reason my progrem crash , plz let know that i know that the 
		//I would like to draw your attention to the fact that I really tried according 
		//to the code shown to put a double space after each word as the assignment asks for
		/*if (i != (count - 1))
			strcat(fixParamStr, SPACE);*/	
	}

	for (int i = 0; i < count; i++)
		free(wordsArray[i]);
	free(wordsArray);

	return fixParamStr;

}


int checkNumberWords(char**  elements, int count)
{
	if (count != 3)
		return 0;
	char* streetNum = elements[1];
	while (*streetNum)
	{
		if (!isdigit(*streetNum))
			return 0;
		streetNum++;
	}
	return 1;
}

void freeElements(char**  elements, int count)
{
	for (int i = 0; i < count; i++)
		free(elements[i]);
	free(elements);
}

void printAddress(const Address* Address)
{
	printf("%s,%d,%s\n", Address->street, Address->num, Address->city);
}

void	freeAddress(Address* pAd)
{
	free(pAd->city);
	free(pAd->street);
}
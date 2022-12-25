#pragma once

typedef struct
{
	int		num;
	char*	street;
	char*	city;
}Address;

int	initAddress(Address* theAddress); 
void printAddress(const Address* Address);
void	freeAddress(Address* pAd);

int		checkNumberWords(char**  elements, int count);
char*	fixSentece(char* param);
void	freeElements(char**  elements, int count);


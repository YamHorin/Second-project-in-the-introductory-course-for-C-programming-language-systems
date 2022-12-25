#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Customer.h"

int MakeNewCustomer(Customer * theCustomer)
{
	char temp[255];
	printf("Enter name:");
	scanf("%s", &temp);
	char* theStr;
	theStr = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	if (!theStr)
		return 0;
	strcpy(theStr, temp);
	theCustomer->name = theStr;
	theCustomer->cart = NULL;
	return 1;
}


void freeCustomer(Customer * theCustomer)
{
	free(theCustomer->name);
	if (theCustomer->cart != NULL)
		freeShoppingcart(theCustomer->cart);
}

void printCustomerForSuper(const Customer * theCustomer)
{
	printf("%s \n" ,theCustomer->name);
}

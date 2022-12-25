#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Product.h"
const char* typeTilte[NofTypes] = { "FruitVegtable", "Fridge", "Frozen", "Shelf" };
int initProduct(Product * theProduct)
{
	printf("enter product name up to %d chars:", MAX_LEN_NAME_PRODUCT);
	char name[MAX_LEN_NAME_PRODUCT + 1];
	Mygets(name, MAX_LEN_NAME_PRODUCT);
	strcpy(theProduct->name, name);
	printf("Enter the barcode BY THE RULES:\n A barcode consists only of capital letters\n and digits, the first and last character must be a capital letter (not a number) in addition must\n Be at least 3 digits and no more than 5 digits.\n");
	char inputBarCode[MAX_LEN_BARCODE_PRODUCT+1];
	int checkBarCodeBoolean = 0;
	do
	{
		scanf("%s", &inputBarCode);
		if (checkBarCode(inputBarCode))
			checkBarCodeBoolean = 1;

	} while (!checkBarCodeBoolean);
	strcpy(theProduct->barcode, inputBarCode);
	float price;
	int booleanIsProceOk = 0;
	do
	{
		printf("enter price:\n");
		scanf("%f", &price);
		if (price > 0)
			booleanIsProceOk = 1;

	} while (booleanIsProceOk==0);
	theProduct->price = price;
	theProduct->type = getTypeFromUser();
	int booleanIsSupplyOk=0;
	do
	{
		printf("Enter supply for the product:");
		scanf("%d", &theProduct->supply);
		if (theProduct->supply > 0)
			booleanIsSupplyOk = 1;

	} while (!booleanIsSupplyOk);

	return 1;
}

void printProduct(const Product * theProduct)
{
	printf("the product:\n  name: %s \n  barcode: %s\n  type %s \n price %f \n supply %d\n ", theProduct->name, theProduct->barcode, typeTilte[theProduct->type], theProduct->price, theProduct->supply);
}

int checkBarCode(const char barcode[])
{
	if (strlen(barcode) != 7)
		return 0;
	int counterNumber = 0  , i = 0;
	while (barcode[i] != '\0')
	{
		char letter = barcode[i];
		if (i == 0 || i==7)
		{
			if (!isupper(letter))
				return 0;
		}
		if (isdigit(letter))
			counterNumber++;
		if (islower(letter))
			return 0;
		i++;
	}
	if (counterNumber > 5 || counterNumber < 3)
		return 0;

	return 1;
}
Type	getTypeFromUser()
{
	int i, t;
	printf("Enter product type\n");
	do {
		for (i = 0; i < NofTypes; i++)
			printf("Enter %d for %s\n", i, typeTilte[i]);
		scanf("%d", &t);
	} while (t < 0 || t >= NofTypes);
	return (Type)t;
}




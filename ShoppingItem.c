#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ShoppingItem.h"

int initNewShoppingItem(Product * theProduct, ShoppingItem* theShoppingItem, int numOfProducts)
{
	
	strcpy(theShoppingItem->barcode, theProduct->barcode);
	theShoppingItem->price = theProduct->price;
	theShoppingItem->numberConterOfThisProduct = numOfProducts;
	return 1;
}

void shoppingItemPrint(ShoppingItem * theShoppingItem)
{
	printf("product: %s \n amount: %d \n cost:%f \n", theShoppingItem->barcode, theShoppingItem->numberConterOfThisProduct, theShoppingItem->price);
}

void freeShoppingItem(ShoppingItem * theShoppingItem)
{
	free(theShoppingItem->barcode);
	
}

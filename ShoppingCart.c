#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ShoppingCart.h"


void NewShoppingCart(ShoppingCart * shoppingCart)
{
	shoppingCart->NumberOfProducts = 0;
	shoppingCart->shoppinItemsArr = NULL;
}

int AddShoppingItemToTheCart(Product * theItem, ShoppingCart * shoppingCart, int numOfProducts)
{
	ShoppingItem* ItemOfShopping =(ShoppingItem*)calloc(1, sizeof(ShoppingItem));
	if (!initNewShoppingItem(theItem,ItemOfShopping, numOfProducts))
		return 0;
	//check if we have it in the cart

	if (shoppingCart->NumberOfProducts != 0)
	{
		for (int i = 0; i < shoppingCart->NumberOfProducts; i++)
		{
			int compare = compareTwoString(ItemOfShopping->barcode, shoppingCart->shoppinItemsArr[i]->barcode);
			if (compare==0)
			{
				shoppingCart->shoppinItemsArr[i]->numberConterOfThisProduct += numOfProducts;
				free(ItemOfShopping);
				return 1;
			}
		}
	}
	
	shoppingCart->shoppinItemsArr = (ShoppingItem**)realloc(shoppingCart->shoppinItemsArr, (shoppingCart->NumberOfProducts + 1) * sizeof(ShoppingItem*));
	shoppingCart->shoppinItemsArr[shoppingCart->NumberOfProducts] = ItemOfShopping;
	shoppingCart->NumberOfProducts++;
	return 1;
}

float sumOfTheCart( const ShoppingCart* shoppingCart)
{
	float sum = 0;
	
	for (int i = 0; i < shoppingCart->NumberOfProducts; i++)
	{
		sum +=(float)(shoppingCart->shoppinItemsArr[i]->price * shoppingCart->shoppinItemsArr[i]->numberConterOfThisProduct);
	}
	return sum;
}

void MakeShoppingCartEmptyBecauseOfPayment(ShoppingCart * shoppingCart)
{
	
	for (int  i = 0; i < shoppingCart->NumberOfProducts; i++)
	{
		freeShoppingItem(shoppingCart->shoppinItemsArr[i]);
	}
	free(shoppingCart->shoppinItemsArr);
	shoppingCart->NumberOfProducts = 0;
}

void freeShoppingcart(ShoppingCart * shoppingCart)
{
	if (shoppingCart->NumberOfProducts != 0)
	{
		for (int i = 0; i < shoppingCart->NumberOfProducts; i++)
		{
			freeShoppingItem(shoppingCart->shoppinItemsArr[i]);
		}
		free(shoppingCart->shoppinItemsArr);
		free(shoppingCart);
	}

	
}

void printCart(const ShoppingCart * shoppingCart)
{
	for (int i = 0; i < shoppingCart->NumberOfProducts; i++)
	{
		shoppingItemPrint(shoppingCart->shoppinItemsArr[i]);
	}
	printf("the sum is : %f \n", sumOfTheCart(shoppingCart));
}




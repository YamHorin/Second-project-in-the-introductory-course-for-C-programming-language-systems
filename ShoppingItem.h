#pragma once
#ifndef __SHOPPINGITEM_H
#define __SHOPPINGITEM_H
#define MAX_LEN_BARCODE_PRODUCT 7
#include "Product.h"

typedef struct 
{
	char barcode[MAX_LEN_BARCODE_PRODUCT + 1];
	float price;
	int numberConterOfThisProduct;

}ShoppingItem;
int initNewShoppingItem(Product * theProduct, ShoppingItem* theShoppingItem, int numOfProducts);
void shoppingItemPrint(ShoppingItem* theShoppingItem);
void freeShoppingItem(ShoppingItem* theShoppingItem);







#endif // __SHOPPINGITEM_H
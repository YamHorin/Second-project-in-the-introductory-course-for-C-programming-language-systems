#pragma once
#ifndef __SHOPPINGCART_H
#define __SHOPPINGCART_H
#include "ShoppingItem.h"
#include "Product.h"
#include "string.h"
typedef struct 
{
	ShoppingItem** shoppinItemsArr;
	int NumberOfProducts;
}ShoppingCart;

void NewShoppingCart(ShoppingCart* shoppingCart);
int AddShoppingItemToTheCart(Product * theItem, ShoppingCart * shoppingCart, int numOfProducts);
float sumOfTheCart(const ShoppingCart* shoppingCart);
void MakeShoppingCartEmptyBecauseOfPayment(ShoppingCart* shoppingCart);
void freeShoppingcart(ShoppingCart* shoppingCart);
void printCart(const ShoppingCart* shoppingCart);





#endif // __SHOPPINGCART_H
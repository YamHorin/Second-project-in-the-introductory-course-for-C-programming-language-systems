#pragma once
#ifndef __SHOPPINGMARKET_H
#define __SHOPPINGMARKET_H
#include "Address.h"
#include "SuperMarket.h"
#include "ShoppingCart.h"
#include "Product.h"
#include "Customer.h"
#include "ShoppingItem.h"
#include "String.h"
typedef struct 
{
	Address addressSuper;
	char* nameSuper;
	Customer* customerArr;
	int HowManyCustomerInTheSuper;
	Product** productArr;
	int numberOfProducts;
	

}SuperMarker;

int makeNewEmptyStore(SuperMarker * theSuper);
void printStore(const SuperMarker* theSuper);
int addNewProduct(SuperMarker* theSuper);
int addNewCustomer(SuperMarker* theSuper);
int ShoppingInTheSuper(SuperMarker* theSuper);
void printAllProductsByType(const SuperMarker* theSuper);
void freeSuperMarket(SuperMarker * theSuper);
Customer* isTheCustomerInTheSuperMarket(const char * name, const SuperMarker * theSuper);
void printAllProducts(const SuperMarker* theSuper);
Product* isTheProductInTheSuperMarket(const char * barcode,const SuperMarker * theSuper);
int PayForTheCart(SuperMarker* theSuper);
int addProductWeHave(SuperMarker* theSuper);
int addProductChoise(SuperMarker* theSuper);
int checkProductNewAdd(SuperMarker* theSuper, Product* product);
void printCartOfCustomer(const SuperMarker* theSuper);






#endif // __SHOPPINGMARKET_H
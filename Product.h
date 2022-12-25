#pragma once
#ifndef __PRODUCT_H
#define __PRODUCT_H
#define MAX_LEN_NAME_PRODUCT 20
#define MAX_LEN_BARCODE_PRODUCT 7
#include "String.h"
typedef enum { FruitVegtable, Fridge, Frozen, Shelf , NofTypes} Type;
const char* typeTilte[NofTypes];
typedef struct 
{
	float price;
	Type type;
	char name[MAX_LEN_NAME_PRODUCT+1] ;
	char barcode[MAX_LEN_BARCODE_PRODUCT+1];
	int supply;
	

}Product;

int initProduct(Product* theProduct);
void printProduct(const Product* theProduct);
int checkBarCode(const char barcode[]);
Type getTypeFromUser();







#endif // __PRODUCT_H
#pragma once
#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#include "ShoppingCart.h"
#include "String.h"
typedef struct 
{
	char* name;
	ShoppingCart* cart;
}Customer;

int MakeNewCustomer(Customer* theCustomer);
void freeCustomer(Customer* theCustomer);
void printCustomerForSuper(const Customer* theCustomer);









#endif // __CUSTOMER_H
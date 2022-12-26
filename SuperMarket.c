#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SuperMarket.h"

int makeNewEmptyStore(SuperMarker * theSuper)
{
	theSuper->nameSuper = getString("enter the name of supermarket:\n");
	if (!initAddress(&theSuper->addressSuper))
		return 0;
	theSuper->numberOfProducts = 0;
	theSuper->HowManyCustomerInTheSuper=0;
	theSuper->customerArr = NULL;
	theSuper->productArr = NULL;
	return 1;
}

void printStore(const SuperMarker* theSuper)
{
	printf("\nthe Supermarker: %s \n", theSuper->nameSuper);
	printAddress(&theSuper->addressSuper);
	printf("\nthere are %d products in the super market\n", theSuper->numberOfProducts);
	for (int i = 0; i < theSuper->numberOfProducts; i++)
	{
		printProduct(theSuper->productArr[i]);
		printf("-----------------------------------------\n");
	}
	printf("\nthere are %d customers in the super market\n", theSuper->HowManyCustomerInTheSuper);
	printf("\n*********************************************\n");
	for (int i = 0; i < theSuper->HowManyCustomerInTheSuper; i++)
	{
		printf("\n");
		printCustomerForSuper(&(theSuper->customerArr[i]));
		printf("\n");
	}
	

}

int addNewProduct(SuperMarker * theSuper)
{
	Product* pProd = (Product*)calloc(1, sizeof(Product));
	if (!pProd)
		return 0;
	initProduct(pProd);
	if (!checkProductNewAdd(theSuper, pProd))
	{
		theSuper->productArr = (Product**)realloc(theSuper->productArr, (theSuper->numberOfProducts + 1) * sizeof(Product*));
		if (!theSuper->productArr)
			return 0;
		theSuper->productArr[theSuper->numberOfProducts] = pProd;
		theSuper->numberOfProducts++;
	}
	
	return 1;
}

int addNewCustomer(SuperMarker * theSuper){
	Customer customerToAdd;
	if (!MakeNewCustomer(&customerToAdd))
		return 0;
	if (isTheCustomerInTheSuperMarket(customerToAdd.name, theSuper) != NULL)
		return 0;
	theSuper->customerArr = (Customer*)realloc(theSuper->customerArr , (theSuper->HowManyCustomerInTheSuper+1) * sizeof(Customer));
	if (!theSuper->customerArr)
		return 0;
	theSuper->customerArr[theSuper->HowManyCustomerInTheSuper] = customerToAdd;
	theSuper->HowManyCustomerInTheSuper++;
	return 1;

	
}

int ShoppingInTheSuper(SuperMarker * theSuper)
{
	
	ShoppingCart* cart2 = (ShoppingCart*)calloc(1, sizeof(ShoppingCart));
	NewShoppingCart(cart2);
	int booleanChaeckIfTheInputIsOK = 0; //1
	Customer* customerCurrent;
	if (theSuper->HowManyCustomerInTheSuper == 0 || theSuper->numberOfProducts==0){
		printf("\nmake customer first to complete the process\n or make products first in the super\n");
		return 0;
	}
	printf("\nplease enter name of customer for buy:");
	do{
		char* name = getString("");
		customerCurrent = isTheCustomerInTheSuperMarket(name, theSuper);
		if (customerCurrent != NULL )
			booleanChaeckIfTheInputIsOK = 1;

	} while (!booleanChaeckIfTheInputIsOK);
	if (customerCurrent->cart != NULL)
	{
		printf("\nCan't start new cart for customer that has a cart already\nmake a pay and come back\n");
		return 0;
	}
	printAllProducts(theSuper);//2
	int booleanSwitchCase = 1;
	int choise;
	do{
		printf("\nplease enter your choise in the shopping process:\n 1-add a new product to the cart  \n  0-to exit\n");
		scanf("%d", &choise);
		switch (choise){
		case 1:
			printf("\nEnter the barcode of the product you want: \n");
			char inputBarCode[MAX_LEN_BARCODE_PRODUCT + 1];
			Product* currentProduct;
			int booleanIsBarcodeOk = 0;
			int numOfProducts=0;
			do
			{
				scanf("%s", &inputBarCode);
				currentProduct = isTheProductInTheSuperMarket(inputBarCode, theSuper);
				if (currentProduct == NULL)
					printf("\nthe product is not in the super , plz select another one\n");
				else{
					printf("\nhow many of %s you like to buy?\n", currentProduct->name);
					scanf("%d", &numOfProducts);
					if (currentProduct->supply == 0 || (currentProduct->supply - numOfProducts) < 0 || numOfProducts<=0)
						printf("\nEROOR please select another product , the suply is empty or less then what you want\nor maybe you put wrong input...");
					else {
						booleanIsBarcodeOk = 1;
						currentProduct->supply -= numOfProducts;
					}
				}
			} while (!booleanIsBarcodeOk);
			
			AddShoppingItemToTheCart(currentProduct, cart2, numOfProducts);
			printCart(cart2);
			printAllProducts(theSuper);
			break;
		case 0:
			booleanSwitchCase = 0;
			break;
		default:
			break;
		}
	} while (booleanSwitchCase);
	customerCurrent->cart = cart2;
	return 1;
}

void printAllProductsByType(const SuperMarker* theSuper)
{
	if (theSuper->numberOfProducts == 0)
	{
		printf("\nwe don't have products to prints sorry\n");
		return;
	}
	Type productType = getTypeFromUser();
	for (int i = 0; i < theSuper->numberOfProducts; i++)
	{
		if (theSuper->productArr[i]->type == productType)
			printProduct(theSuper->productArr[i]);
	}
}



void freeSuperMarket(SuperMarker * theSuper)
{
	free(theSuper->nameSuper);
	freeAddress(&theSuper->addressSuper);
	for (int  i = 0; i < theSuper->HowManyCustomerInTheSuper; i++)
	{
		freeCustomer(&theSuper->customerArr[i]);
	}
	free(theSuper->customerArr);
	for (int i = 0; i < theSuper->numberOfProducts; i++)
	{
		if (theSuper->productArr[i] != NULL)
			free(theSuper->productArr[i]);
	}
	free(theSuper->productArr);
}

Customer* isTheCustomerInTheSuperMarket(const char * name, const SuperMarker * theSuper)
{
		for (int i = 0; i < theSuper->HowManyCustomerInTheSuper; i++)
		{
			if (compareTwoString(theSuper->customerArr[i].name, name) == 0) {
				return &(theSuper->customerArr[i]);
			}

		}

	return NULL;
}

void printAllProducts(const SuperMarker* theSuper)
{
	printf("\nall the products in the super :\n");
	for (int i = 0; i < theSuper->numberOfProducts; i++)
	{
		printProduct((theSuper->productArr[i]));
	}
}

Product* isTheProductInTheSuperMarket(const char * barcode, const SuperMarker * theSuper)
{
	if (!checkBarCode(barcode))
		return NULL;
	for (int  i = 0; i < theSuper->numberOfProducts; i++)
	{
		if (compareTwoString(barcode, theSuper->productArr[i]->barcode)==0)
		{
			return theSuper->productArr[i];
		}
			
	}
	return NULL;
}

int PayForTheCart(SuperMarker * theSuper)
{
	int booleanChaeckIfTheInputIsOK = 0; //1
	Customer* customerCurrent;
	if (theSuper->HowManyCustomerInTheSuper == 0) {
		printf("\nmake customer first to complete the process\n");
		return 0;
	}
	printf("\nplease enter name of customer for buy:\n make sure the customer has not empty cart\n");
	do {
		char* name = getString("");
		customerCurrent = isTheCustomerInTheSuperMarket(name, theSuper);
		if (customerCurrent != NULL)
			booleanChaeckIfTheInputIsOK = 1;

	} while (!booleanChaeckIfTheInputIsOK);
	if (customerCurrent->cart->NumberOfProducts == 0 || customerCurrent->cart == NULL)
	{
		printf("the customer already paid for the cart\n");
		return 0;
	}
	printCart(customerCurrent->cart);
	printf("\nthe customer %s pay! the cart is now empty\n--------------------------\n", customerCurrent->name);
	MakeShoppingCartEmptyBecauseOfPayment(customerCurrent->cart);
	customerCurrent->cart = NULL
	return 1;
}

int addProductWeHave(SuperMarker * theSuper)
{
	if (theSuper->numberOfProducts == 0)
	{
		printf("\nwe don't have products to prints sorry\n");
		return 0;
	}
	printf("Enter name of product:");
	char nameProduct[MAX_LEN_NAME_PRODUCT + 1];
	Mygets(nameProduct, MAX_LEN_NAME_PRODUCT);
	int isInTheStore = 0;
	int supply;
	for (int i = 0; i < theSuper->numberOfProducts; i++)
	{
		if (compareTwoString(nameProduct , theSuper->productArr[i]->name)==0)
		{
			int booleanIsSupplyOk = 0;
			do
			{
				printf("Enter supply:\n");
				scanf("%d", &supply);
				if (supply > 0)
					booleanIsSupplyOk = 1;

			} while (!booleanIsSupplyOk);
			theSuper->productArr[i]->supply += supply;
			return 1;
		}
			
	}
	if (!isInTheStore)
		printf("\nthe item is not in the store\n");
	return 0;
}

int addProductChoise(SuperMarker * theSuper)
{
	int choise;
	printf("\nEnter choise\n 1-add new product \n 2-add product we have\n any Number-exit\n");
	scanf("%d", &choise);
	switch (choise)
	{
	case 1:
		return addNewProduct(theSuper);
		break;
	case 2: 
		return addProductWeHave(theSuper);
		break;
	default:
		return 1;
		break;
	}
	return 0;
}

int checkProductNewAdd(SuperMarker* theSuper, Product* product)
{
	for (int  i = 0; i < theSuper->numberOfProducts; i++)
	{
		if (compareTwoString(theSuper->productArr[i]->name, product->name) == 0)
		{
			printf("\nthe product is in the store , supply incrise by the amount you put\n");
			theSuper->productArr[i]->supply += product->supply;
			return 1;
		}
	}
	for (int i = 0; i < theSuper->numberOfProducts; i++)
	{
		if (compareTwoString(theSuper->productArr[i]->barcode, product->barcode) == 0)
		{
			printf("\nthe product is in the store , enter diffrent barcode \nIdentified by the barcode\n");
			return 1;
		}
	}
	return 0;
}

void printCartOfCustomer(const SuperMarker* theSuper)
{
	int booleanChaeckIfTheInputIsOK = 0; //1
	Customer* customerCurrent;
	printf("please enter name of customer for buy:\n make sure the customer has not empty cart\n");
	do {
		char* name = getString("");
		customerCurrent = isTheCustomerInTheSuperMarket(name, theSuper);
		if (customerCurrent != NULL)
			booleanChaeckIfTheInputIsOK = 1;

	} while (!booleanChaeckIfTheInputIsOK);
	if (customerCurrent->cart != NULL)//2
	{
		printf("customer %s has a cart:\n", customerCurrent->name);
		for (int i = 0; i < customerCurrent->cart->NumberOfProducts; i++)
		{
			shoppingItemPrint(customerCurrent->cart->shoppinItemsArr[i]);
		}
		float sum = sumOfTheCart(customerCurrent->cart);
		printf("the sum is : %f \n", sum);
	}
	else
		printf("Customer has no cart!\n");
}


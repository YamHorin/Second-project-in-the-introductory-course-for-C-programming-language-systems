#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
void main()
{
	/*checkShopping();*/
	SuperMarker super;
	makeNewEmptyStore(&super);
	/*super.nameSuper = "the super";
	Address ad;
	ad.city = "Ramat gan";
	ad.num = 45;
	ad.street = "Aba Hillel";
	super.addressSuper = ad;
	super.productArr = NULL;
	Product banana = { 15,FruitVegtable,"banana", "B12345B" ,15 };
	Product orange = { 10,FruitVegtable,"Orange", "O12345O" ,10 };
	Product candy = { 3.5,Shelf,"Candy", "I11111I" ,15 };
	Product Icecream = { 5,Frozen,"Icecream", "I12341I" ,15 };
	super.numberOfProducts = 4;
	super.productArr = (Product**)realloc(super.productArr, 4 * sizeof(Product*));
	Product* pProd1 = &banana;
	Product* pProd2 = &orange;
	Product* pProd3 = &Icecream;
	Product* pProd4 = &candy;

	super.productArr[0] = pProd1;
	super.productArr[1] = pProd2;
	super.productArr[2] = pProd3;
	super.productArr[3] = pProd4;*/
	printStore(&super);
	int choise;
	int isTheProgramGoing = 1;
	while (isTheProgramGoing==1)
	{
		printf("Enter your Choise:\n 1-print super market data \n 2-add new product \n 3- add customer \n 4- start shopping process \n 5- print cart of customer \n 6 -payment of customer \n 7- print all products by type \n 8- exit the program");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			printStore(&super);
			printf("\n");
			break;
		case 2:
			if (!addProductChoise(&super))
				printf("Error adding product\n\n");
			break;

		case 3:
			if(!addNewCustomer(&super))
				printf("Error adding customer\nthe customer is in the super\n\n");
			break;
		case 4:
			if (!ShoppingInTheSuper(&super))
				printf("Error shopping in the cart \n\n");
			break;
		case 5:
			printCartOfCustomer(&super);
			break;
		case 6:
			if (!PayForTheCart(&super))
				printf("Error adding product\n\n");
			break;
		case 7:
			printAllProductsByType(&super);
			break;
		case 8:
			isTheProgramGoing = 0;
			break;
		default:
			printf("choise is not found....\n");
			break;
		}

	}
		
	freeSuperMarket(&super);
	
}
//
//
//void checkShopping()
//{
//	ShoppingCart cart;
//	NewShoppingCart(&cart);
//	Customer c1 = { "Yam" ,&cart };
//	SuperMarker super;
//	super.nameSuper = "the superMarket";
//	Address ad;
//	ad.city = "Ramat gan";
//	ad.num = 45;
//	ad.street = "Aba Hillel";
//	super.addressSuper = ad;
//	super.productArr = NULL;
//	Product banana = { 15,FruitVegtable,"banana", "B12345B" ,15 };
//	Product orange = { 10,FruitVegtable,"Orange", "O12345O" ,10 };
//	Product candy = { 3.5,Shelf,"Candy", "I11111I" ,15 };
//	Product Icecream = { 5,Frozen,"Icecream", "I12341I" ,15 };
//	super.numberOfProducts = 4;
//	super.productArr = (Product**)realloc(super.productArr, 4 * sizeof(Product*));
//	Product* pProd1 = &banana;
//	Product* pProd2 = &orange;
//	Product* pProd3 = &Icecream;
//	Product* pProd4 = &candy;
//	super.productArr[0] = pProd1;
//	super.productArr[1] = pProd2;
//	super.productArr[2] = pProd3;
//	super.productArr[3] = pProd4;
//	super.HowManyCustomerInTheSuper = 1;
//	super.customerArr = NULL;
//	super.HowManyCustomerInTheSuper = 0;
//	printStore(&super);
//	addNewCustomer(&super);
//	printf("begine shopping\n\n");
//	ShoppingInTheSuper(&super);
//
//}

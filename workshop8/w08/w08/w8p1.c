/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
Full Name  : CHAN KA YING
Student ID#: 123231227
Email      : kchan151@matrix.senecacollege.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* ptr)
// 
{
	int input = 0;
	int done = 0;

	do
	{
		scanf("%d", &input);

		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else if (ptr != NULL)
		{
			*ptr = input;
			done = 1;
		}
		else
		{
			done = 1;
		}

	} while (done == 0);

	return input;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* ptr)
{
	double input = 0.0;
	int done = 0;

	do
	{
		scanf("%lf", &input);

		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else if (ptr != NULL)
		{
			*ptr = input;
			done = 1;
		}
		else
		{
			done = 1;
		}

	} while (done == 0);

	return input;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage()
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for 3 dry food bags of product data for analysis.\n");
	printf("NOTE: A 'serving' is %dg\n\n", GRAMS);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo()
{
	int checkSKU;
	int checkCALORIES;
	double checkPRICE;
	double checkWEIGHT;

	struct CatFoodInfo sProd;

	printf("SKU           : ");
	sProd.sku = getIntPositive(&checkSKU);

	printf("PRICE         : ");
	sProd.price = getDoublePositive(&checkPRICE);

	printf("WEIGHT (LBS)  : ");
	sProd.weight = getDoublePositive(&checkWEIGHT);

	printf("CALORIES/SERV.: ");
	sProd.calories = getIntPositive(&checkCALORIES);

	printf("\n");

	return sProd;
}

// 5. Display the formatted table header
void displayCatFoodHeader()
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(struct CatFoodInfo dProd)
{
	printf("%07d %10.2lf %10.1lf %8d\n", dProd.sku, dProd.price, dProd.weight, dProd.calories);
}

// 7. Logic entry point
int start()
{
	int i;

	struct CatFoodInfo Prod[productSIZE];
	openingMessage();

	for (i = 0; i < productSIZE; i++)
	{
		printf("Cat Food Product #%d\n", i + 1);
		printf("--------------------\n");
		Prod[i] = getCatFoodInfo();
	}

	displayCatFoodHeader();
	for (i = 0; i < productSIZE; i++)
	{
		displayCatFoodData(Prod[i]);
	}

	return 0;
}

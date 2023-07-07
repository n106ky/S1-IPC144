/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
Full Name  : CHAN KA YING
Student ID#: 123231227
Email      : kchan151@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* ptr)
{
	int input = 0;

	do
	{
		scanf("%d", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (input <= 0);

	if (ptr != NULL)
	{
		*ptr = input;
	}

	return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* ptr)
{
	double input = 0.0;

	do
	{
		scanf("%lf", &input);

		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}

	} while (input <= 0);

	if (ptr != NULL)
	{
		*ptr = input;
	}

	return input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage()
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", productSIZE);
	printf("NOTE: A 'serving' is %dg\n\n", GRAMS);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productID)
{
	struct CatFoodInfo sProd;

	printf("Cat Food Product #%d\n", productID + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	sProd.sku = getIntPositive(NULL);

	printf("PRICE         : ");
	sProd.price = getDoublePositive(NULL);

	printf("WEIGHT (LBS)  : ");
	sProd.weight = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	sProd.calories = getIntPositive(NULL);

	printf("\n");

	return sProd;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, double* weight, int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* ptrLbs, double* ptrKG)
{
	double KG = 0.0;

	if (ptrKG != NULL)
	{
		*ptrKG = *ptrLbs / LBS_KG;
	}

	KG = *ptrLbs / LBS_KG;

	return KG;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* ptrLbs, int* ptrG)
{
	double KG = 0.0;
	int G = 0;

	convertLbsKg(ptrLbs, &KG);
	if (ptrG != NULL)
	{
		*ptrG = KG * 1000;
	}

	G = KG * 1000;

	return G;
}

// 10. convert lbs: kg and g
void convertLbs(const double* ptrLbs, double* ptrKG, int* ptrG)
{
	double KG = 0.0;
	int G = 0;
	*ptrKG = convertLbsKg(ptrLbs, &KG);
	*ptrG = convertLbsG(ptrLbs, &G);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int size_Grams, const int totalGram_prod, double* ptrNumServ)
{
	double numServ = 0.0;
	double dbSizeG, dbTGprof;

	dbSizeG = size_Grams * 100.0;
	dbTGprof = totalGram_prod * 100.0;

	if (ptrNumServ != NULL)
	{
		*ptrNumServ = dbTGprof / dbSizeG;
	}
	numServ = dbTGprof / dbSizeG;

	return numServ;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* ptrProdPrice, const double* ptrTotalNumServ, double* ptrCostperServ)
{
	double costperServ = 0.0;

	if (ptrCostperServ != NULL)
	{
		*ptrCostperServ = *ptrProdPrice / *ptrTotalNumServ;
	}
	costperServ = *ptrProdPrice / *ptrTotalNumServ;

	return costperServ;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* ptrProdPrice, const double* ptrTotalNumCal, double* ptrCostperCal)
{
	double costperCal = 0.0;

	if (ptrCostperCal != NULL)
	{
		*ptrCostperCal = *ptrProdPrice / *ptrTotalNumCal;
	}
	costperCal = *ptrProdPrice / *ptrTotalNumCal;

	return costperCal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo* cfi)
{
	struct ReportData rd;

	rd.sku = cfi->sku;
	rd.price = cfi->price;
	rd.calories = cfi->calories;
	rd.LBS = cfi->weight;

	convertLbs(&rd.LBS, &rd.KG, &rd.G);
	calculateServings(GRAMS, rd.G, &rd.totalServ);
	calculateCostPerServing(&rd.price, &rd.totalServ, &rd.costperServ);

	double totalCal = 0.0;
	totalCal = rd.calories * rd.totalServ;
	calculateCostPerCal(&rd.price, &totalCal, &rd.costperCal);

	return rd;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(struct ReportData dpRD, double* cheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", dpRD.sku, dpRD.price, dpRD.LBS, dpRD.KG, dpRD.G, dpRD.calories, dpRD.totalServ, dpRD.costperServ, dpRD.costperCal);
	if (*cheapest == dpRD.costperServ)
	{
		printf(" ***");
	}
	printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(int sku, double price)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", sku, price);
	printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------
// 7. Logic entry point
void start()
{
	int i;
	struct CatFoodInfo Prod[productSIZE];
	openingMessage(productSIZE);
	for (i = 0; i < productSIZE; i++)
	{
		Prod[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < productSIZE; i++)
	{
		displayCatFoodData(Prod[i].sku, &Prod[i].price, &Prod[i].weight, Prod[i].calories);
	}

	struct ReportData Data[productSIZE];

	for (i = 0; i < productSIZE; i++)
	{
		Data[i] = calculateReportData(&Prod[i]);
	}

	double cheapest = Data->costperServ;
	int cheapestSKU = Data->sku;
	double cheapestPrice = Data->price;

	for (i = 0; i < productSIZE; i++)
	{
		if (Data[i].costperServ < cheapest)
		{
			cheapest = Data[i].costperServ;
			cheapestSKU = Data[i].sku;
			cheapestPrice = Data[i].price;
		}
	}

	displayReportHeader();
	for (i = 0; i < productSIZE; i++)
	{
		displayReportData(Data[i], &cheapest);
	}

	displayFinalAnalysis(cheapestSKU, cheapestPrice);

}

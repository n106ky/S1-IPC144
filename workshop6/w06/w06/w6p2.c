/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P2)
Full Name  : Chan Ka Ying
Student ID#: 123231227
Email      : kchan151@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_item 1
#define MAX_item 10

int main(void)
{
	// variables for income
	const int MIN_Income = 500, MAX_Income = 400000;
	double monIncome = 0;
	int iMonIncome = 0;

	// variables for wish list items
	int wishItems = 0;

	// flag
	int done = 0, done2 = 0, notePrinted = 0;

	// arrays for items details
	int itemNum[MAX_item] = { 0 };
	int itemPriority[MAX_item] = { 0 };
	char itemFinOpt[MAX_item] = { 0 };
	double itemCost[MAX_item] = { 0 };
	const double MIN_itemCost = 100;

	// varibles of total cost for all items (no filter)
	double TotalCost = 0;
	int iTotalCost = 0;

	// varibles of costs (with filters)
	double pri1Cost = 0, pri2Cost = 0, pri3Cost = 0;
	int iPri1Cost = 0, iPri2Cost = 0, iPri3Cost = 0;

	// variables for forecast selection
	int foreSelect = 0, priFilter = 0;

	// index for input arrays
	int i = 0;


	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");


	// LOOP for monthly NET income
	do
	{
		done = 0;
		printf("Enter your monthly NET income: $");
		scanf("%lf", &monIncome);

		if (monIncome >= MIN_Income && monIncome <= MAX_Income)
		{
			done = 1;
			printf("\n");
		}
		else if (monIncome < MIN_Income)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		else if (monIncome > MAX_Income)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
	} while (done == 0);


	// LOOP for wish list items
	do
	{
		done = 0;
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &wishItems);

		if (wishItems >= MIN_item && wishItems <= MAX_item)
		{
			done = 1;
			printf("\n");
		}
		else if (wishItems < MIN_item || wishItems > MAX_item)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
		}
	} while (done == 0);


	// items details
	for (i = 0; i < wishItems; i++)
	{
		itemNum[i] = i;
		printf("Item-%d Details:\n", itemNum[i] + 1);
		do
		{
			done = 0;
			printf("   Item cost: $"); 
			scanf("%lf", &itemCost[i]);

			if (itemCost[i] >= MIN_itemCost)
			{
				done = 1;
			}
			else if (itemCost[i] < MIN_itemCost)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (done == 0);

		do
		{
			done = 0;
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &itemPriority[i]);

			if (itemPriority[i] >= 1 && itemPriority[i] <= 3)
			{
				done = 1;
			}
			else if (itemPriority[i] < 1 || itemPriority[i] > 3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (done == 0);

		do
		{
			done = 0;
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &itemFinOpt[i]);

			if (itemFinOpt[i] == 'y' || itemFinOpt[i] == 'n')
			{
				done = 1;
				printf("\n");
			}
			else if (itemFinOpt[i] != 'y' && itemFinOpt[i] != 'n')
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}

		} while (done == 0);
	}


	// Summary of Items
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < wishItems; i++)
	{
		printf("%3d  %5d %8c   %12.2lf\n", itemNum[i] + 1, itemPriority[i], itemFinOpt[i], itemCost[i]);
		TotalCost += itemCost[i];
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", TotalCost);


	// LOOP for forecasting customer wish list

	// Cost calculated after filters applied
	for (i = 0; i < wishItems; i++)
	{
		if (itemPriority[i] == 1)
		{
			pri1Cost += itemCost[i];
		}

		else if (itemPriority[i] == 2)
		{
			pri2Cost += itemCost[i];
		}

		else if (itemPriority[i] == 3)
		{
			pri3Cost += itemCost[i];
		}
	}

	// Select Filters
	do
	{
		done = 0;
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &foreSelect);
		printf("\n");

		if (foreSelect >= 0 && foreSelect <= 2)
		{
			if (foreSelect == 1)
			{
				printf("====================================================\n");
				printf("Filter:   All items\n");
				printf("Amount:   $%.2lf\n", TotalCost);
				iTotalCost = TotalCost * 100;
				iMonIncome = monIncome * 100;
				printf("Forecast: %d years, %d months\n", (iTotalCost / iMonIncome) / 12, (int)(TotalCost / monIncome + 0.99) % 12);
				// another way: printf("Forecast: %d years, %d months\n", (iTotalCost / iMonIncome) / 12, (int)((TotalCost / monIncome) + 0.99 - (iTotalCost / iMonIncome) / 12 * 12);
				for (i = 0; i < wishItems; i++)
				{
					if (itemFinOpt[i] == 'y' && notePrinted == 0)
					{
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n");
						notePrinted = 1;
					}
				}
				printf("====================================================\n\n");
			}
			else if (foreSelect == 2)
			{
				do
				{
					done2 = 0;
					printf("What priority do you want to filter by? [1-3]: ");
					scanf("%d", &priFilter);
					printf("\n");

					if (priFilter == 1)
					{
						printf("====================================================\n");
						printf("Filter:   by priority (1)\n");
						printf("Amount:   $%.2lf\n", pri1Cost);
						iPri1Cost = pri1Cost * 100;
						printf("Forecast: %d years, %d months\n", (iPri1Cost / iMonIncome) / 12, (int)(pri1Cost / monIncome + 0.99) % 12);
						// printf("Forecast: %d years, %d months\n", (iPri1Cost / iMonIncome) / 12, (int)((pri1Cost / monIncome) + 0.99 - (iPri1Cost / iMonIncome) / 12 * 12));
						notePrinted = 0;
						for (i = 0; i < wishItems; i++)
						{
							if (itemPriority[i] == 1 && itemFinOpt[i] == 'y' && notePrinted == 0)
							{
								printf("NOTE: Financing options are available on some items.\n");
								printf("      You can likely reduce the estimated months.\n");
								notePrinted = 1;
							}
						}
						printf("====================================================\n\n");
						done2 = 1;
					}
					else if (priFilter == 2)
					{
						printf("====================================================\n");
						printf("Filter:   by priority (2)\n");
						printf("Amount:   $%.2lf\n", pri2Cost);
						iPri2Cost = pri2Cost * 100;
						printf("Forecast: %d years, %d months\n", (iPri2Cost / iMonIncome) / 12, (int)(pri2Cost / monIncome + 0.99) % 12);
						// printf("Forecast: %d years, %d months\n", (iPri2Cost / iMonIncome) / 12, (int)((pri2Cost / monIncome) + 0.99 - (iPri2Cost / iMonIncome) / 12 * 12));
						notePrinted = 0;
						for (i = 0; i < wishItems; i++)
						{
							if (itemPriority[i] == 2 && itemFinOpt[i] == 'y' && notePrinted == 0)
							{
								printf("NOTE: Financing options are available on some items.\n");
								printf("      You can likely reduce the estimated months.\n");
								notePrinted = 1;
							}
						}
						printf("====================================================\n\n");
						done2 = 1;
					}
					else if (priFilter == 3)
					{
						printf("====================================================\n");
						printf("Filter:   by priority (3)\n");
						printf("Amount:   $%.2lf\n", pri3Cost);
						iPri3Cost = pri3Cost * 100;
						printf("Forecast: %d years, %d months\n", (iPri3Cost / iMonIncome) / 12, (int)(pri3Cost / monIncome + 0.99) % 12);
						// printf("Forecast: %d years, %d months\n", (iPri3Cost / iMonIncome) / 12, (int)((pri3Cost / monIncome) + 0.99 - (iPri3Cost / iMonIncome) / 12 * 12));
						notePrinted = 0;
						for (i = 0; i < wishItems; i++)
						{
							if (itemPriority[i] == 3 && itemFinOpt[i] == 'y' && notePrinted == 0)
							{
								printf("NOTE: Financing options are available on some items.\n");
								printf("      You can likely reduce the estimated months.\n");
								notePrinted = 1;
							}
						}
						printf("====================================================\n\n");
						done2 = 1;
					}
				} while (done2 == 0);
			}
			else
			{
				done = 1;
				printf("Best of luck in all your future endeavours!\n\n");
			}
		}
		else
		{
			printf("ERROR: Invalid menu selection.\n\n");
		}
	} while (done == 0);

	return 0;
}
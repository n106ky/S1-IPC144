/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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

    // variables for wish list items
    int wishItems = 0;

    // flag
    int done = 0;

    // arrays for items details
    int itemNum[MAX_item];
    int itemPriority[MAX_item];
    char itemFinOpt[MAX_item];
    double itemCost[MAX_item], totalCost = 0;
    const double MIN_itemCost = 100;

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

    // LOOP for wish list item
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
            itemCost[i] = 0;
            printf("Item cost: $");
            scanf("%lf", &itemCost[i]);

            if (itemCost[i] >= MIN_itemCost)
            {
                done = 1;
            }
            else if (itemCost[i] < MIN_itemCost)
            {
                printf("ERROR: Cost must be at least $100.00\n");
            }
        } while (done == 0);

        do
        {
            done = 0;
            itemPriority[i] = 0;
            printf("How important is it to you? [1=must have, 2=important, 3=want]:");
            scanf("%d", &itemPriority[i]);

            if (itemPriority[i] >= 1 && itemPriority[i] <= 3)
            {
                done = 1;
            }
            else if (itemPriority[i] < 1 || itemPriority[i] > 3)
            {
                printf("ERROR: Value must be between 1 and 3\n");
            }
        } while (done == 0);

        do
        {
            done = 0;
            itemFinOpt[i] = 0;
            printf("Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemFinOpt[i]);

            if (itemFinOpt[i] == 'y' || itemFinOpt[i] == 'n')
            {
                done = 1;
                printf("\n");
            }
            else if (itemFinOpt[i] != 'y' && itemFinOpt[i] != 'n')
            {
                printf("ERROR: Must be a lowercase 'y' or 'n'\n");
            }

        } while (done == 0);
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < wishItems; i++)
    {
        itemNum[i] = i;
        printf("%3d %5d  %8c   %12.2lf\n", itemNum[i] + 1, itemPriority[i], itemFinOpt[i], itemCost[i]);
        totalCost += itemCost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);

    printf("Best of luck in all your future endeavours!");

    return 0;
}
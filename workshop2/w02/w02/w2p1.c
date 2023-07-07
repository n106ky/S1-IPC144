/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  :CHAN KA YING
Student ID#:123231227
Email      :kchan151@myseneca.ca
Section    :NDD

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    float priceSmall, priceMedium, priceLarge, totalPrice, subTotal, taxes, fTaxes;
    int buySmall, iTaxes;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &priceSmall);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &priceMedium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &priceLarge);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", priceSmall);
    printf("MEDIUM : $%.2f\n", priceMedium);
    printf("LARGE  : $%.2f\n\n", priceLarge);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &buySmall);
    printf("\n");

    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", buySmall);

    subTotal = buySmall * priceSmall;
    printf("Sub-total: $%8.4lf\n", subTotal);

    taxes = buySmall * priceSmall * TAX;
    iTaxes = (taxes + .005) * 100.00;
    fTaxes = iTaxes / 100.00;
    printf("Taxes    : $%8.4lf\n", fTaxes);
    totalPrice = subTotal + fTaxes;
    printf("Total    : $%8.4lf\n", totalPrice);
    return 0;
}
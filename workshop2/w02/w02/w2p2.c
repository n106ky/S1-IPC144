/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', tomSize = 'L', salSize = 'M';
    float priceSmall, priceMedium, priceLarge, patTotalPrice, tomTotalPrice, salTotalPrice, patSubTotal, tomSubTotal, salSubTotal, allSubTotal, allTaxes, allTotal, patTaxes, patfTaxes, tomTaxes, tomfTaxes, salTaxes, salfTaxes, bToonies, bLoonies, bQuarters, bDimes, bNickels, bPennies, avgPriceExTax, avgPriceInTax, b2Toonies, b2Loonies, b2Quarters, b2Dimes, b2Nickels, b2Pennies;
    int buySmall, buyMedium, buyLarge, patiTaxes, tomiTaxes, saliTaxes, qToonies, qLoonies, qQuarters, qDimes, qNickels, qPennies, q2Toonies, q2Loonies, q2Quarters, q2Dimes, q2Nickels, q2Pennies, Toonies = 200, Loonies = 100, Quarters = 25, Dimes = 10, Nickels = 5, Pennies = 1;

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

    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &buyLarge);
    printf("\n");

    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &buyMedium);
    printf("\n");

    patSubTotal = buySmall * priceSmall;
    tomSubTotal = buyLarge * priceLarge;
    salSubTotal = buyMedium * priceMedium;

    patTaxes = buySmall * priceSmall * TAX;
    patiTaxes = (patTaxes + .005) * 100;
    patfTaxes = patiTaxes / 100.00;
    tomTaxes = buyLarge * priceLarge * TAX;
    tomiTaxes = (tomTaxes + .005) * 100;
    tomfTaxes = tomiTaxes / 100.00;
    salTaxes = buyMedium * priceMedium * TAX;
    saliTaxes = (salTaxes + .005) * 100;
    salfTaxes = saliTaxes / 100.00;

    patTotalPrice = patSubTotal + patfTaxes;
    tomTotalPrice = tomSubTotal + tomfTaxes;
    salTotalPrice = salSubTotal + salfTaxes;

    allSubTotal = patSubTotal + salSubTotal + tomSubTotal;
    allTaxes = patfTaxes + salfTaxes + tomfTaxes;
    allTotal = patTotalPrice + salTotalPrice + tomTotalPrice;

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, priceSmall, buySmall, patSubTotal, patfTaxes, patTotalPrice);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, priceMedium, buyMedium, salSubTotal, salfTaxes, salTotalPrice);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, priceLarge, buyLarge, tomSubTotal, tomfTaxes, tomTotalPrice);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", allSubTotal, allTaxes, allTotal);


    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");


    /******Sales EXcluding Tax******/
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %6.4lf\n", allSubTotal);

    qToonies = (int)(allSubTotal * 100) / Toonies;
    bToonies = ((int)(allSubTotal * 100) % Toonies) / 100.0;
    qLoonies = (int)(bToonies * 100) / Loonies;
    bLoonies = ((int)(bToonies * 100) % Loonies) / 100.0;
    qQuarters = (int)(bLoonies * 100) / Quarters;
    bQuarters = ((int)(bLoonies * 100) % Quarters) / 100.0;
    qDimes = (int)(bQuarters * 100) / Dimes;
    bDimes = ((int)(bQuarters * 100) % Dimes) / 100.0;
    qNickels = (int)(bDimes * 100) / Nickels;
    bNickels = ((int)(bDimes * 100) % Nickels) / 100.0;
    qPennies = (int)(bNickels * 100) / Pennies;
    bPennies = ((int)(bNickels * 100) % Pennies) / 100.0;

    printf("Toonies  %d    %.4lf\n", qToonies, bToonies);
    printf("Loonies    %d    %.4lf\n", qLoonies, bLoonies);
    printf("Quarters   %d    %.4lf\n", qQuarters, bQuarters);
    printf("Dimes      %d    %.4lf\n", qDimes, bDimes);
    printf("Nickels    %d    %.4lf\n", qNickels, bNickels);
    printf("Pennies    %d    %.4lf\n\n", qPennies, bPennies);

    avgPriceExTax = allSubTotal / (buySmall + buyMedium + buyLarge);
    printf("Average cost/shirt: $%4.4lf\n\n", avgPriceExTax);

    /******Sales INcluding Tax******/
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %6.4lf\n", allTotal);

    q2Toonies = (int)(allTotal * 100) / Toonies;
    b2Toonies = ((int)(allTotal * 100) % Toonies) / 100.0;
    q2Loonies = (int)(b2Toonies * 100) / Loonies;
    b2Loonies = ((int)(b2Toonies * 100) % Loonies) / 100.0;
    q2Quarters = (int)(b2Loonies * 100) / Quarters;
    b2Quarters = ((int)(b2Loonies * 100) % Quarters) / 100.0;
    q2Dimes = (int)(b2Quarters * 100) / Dimes;
    b2Dimes = ((int)(b2Quarters * 100) % Dimes) / 100.0;
    q2Nickels = (int)(b2Dimes * 100) / Nickels;
    b2Nickels = ((int)(b2Dimes * 100) % Nickels) / 100.0;
    q2Pennies = (int)(b2Nickels * 100) / Pennies;
    b2Pennies = ((int)(b2Nickels * 100) % Pennies) / 100.0;

    printf("Toonies  %d    %.4lf\n", q2Toonies, b2Toonies);
    printf("Loonies    %d    %.4lf\n", q2Loonies, b2Loonies);
    printf("Quarters   %d    %.4lf\n", q2Quarters, b2Quarters);
    printf("Dimes      %d    %.4lf\n", q2Dimes, b2Dimes);
    printf("Nickels    %d    %.4lf\n", q2Nickels, b2Nickels);
    printf("Pennies    %d    %.4lf\n\n", q2Pennies, b2Pennies);

    avgPriceInTax = allTotal / (buySmall + buyMedium + buyLarge);
    printf("Average cost/shirt: $%4.4lf\n", avgPriceInTax);

    return 0;
}
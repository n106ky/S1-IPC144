/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    /*Coffee products' types*/
    char c1Type, c2Type, c3Type;
    
    /*Coffee products with Cream*/
    char c1Cream, c2Cream, c3Cream;
    
    /*Coffee products' weight*/
    int c1Weight, c2Weight, c3Weight;
        
    /*Customer preferences*/
    char custStr, custCream;
    int custServ;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &c1Type);
    printf("Bag weight (g): ");
    scanf(" %d", &c1Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c1Cream);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &c2Type);
    printf("Bag weight (g): ");
    scanf(" %d", &c2Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c2Cream);
    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &c3Type);
    printf("Bag weight (g): ");
    scanf(" %d", &c3Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c3Cream);
    printf("\n");


    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", c1Type == 'L' || c1Type == 'l', c1Type == 'M' || c1Type == 'm', c1Type == 'R' || c1Type == 'r', c1Weight, c1Weight / GRAMS_IN_LBS, c1Cream == 'y' || c1Cream == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", c2Type == 'L' || c2Type == 'l', c2Type == 'M' || c2Type == 'm', c2Type == 'R' || c2Type == 'r', c2Weight, c2Weight / GRAMS_IN_LBS, c2Cream == 'y' || c2Cream == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", c3Type == 'L' || c3Type == 'l', c3Type == 'M' || c3Type == 'm', c3Type == 'R' || c3Type == 'r', c3Weight, c3Weight / GRAMS_IN_LBS, c3Cream == 'y' || c3Cream == 'Y');


    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &custStr);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &custCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &custServ);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((c1Type == 'L' || c1Type == 'l') && (custStr == 'L' || custStr == 'l')) || ((c1Type == 'M' || c1Type == 'm') && (custStr == 'M' || custStr == 'm')) || ((c1Type == 'R' || c1Type == 'r') && (custStr == 'R' || custStr == 'r')), ((c1Weight == 250) && (custServ >= 1 && custServ <= 4)) || ((c1Weight == 500) && (custServ >= 5 && custServ <= 9)) || ((c1Weight == 1000) && (custServ >= 10)), ((c1Cream == 'Y' || c1Cream == 'y') && (custCream == 'Y' || custCream == 'y')) || ((c1Cream == 'N' || c1Cream == 'n') && (custCream == 'N' || custCream == 'n')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((c2Type == 'L' || c2Type == 'l') && (custStr == 'L' || custStr == 'l')) || ((c2Type == 'M' || c2Type == 'm') && (custStr == 'M' || custStr == 'm')) || ((c2Type == 'R' || c2Type == 'r') && (custStr == 'R' || custStr == 'r')), ((c2Weight == 250) && (custServ >= 1 && custServ <= 4)) || ((c2Weight == 500) && (custServ >= 5 && custServ <= 9)) || ((c2Weight == 1000) && (custServ >= 10)), ((c2Cream == 'Y' || c2Cream == 'y') && (custCream == 'Y' || custCream == 'y')) || ((c2Cream == 'N' || c2Cream == 'n') && (custCream == 'N' || custCream == 'n')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((c3Type == 'L' || c3Type == 'l') && (custStr == 'L' || custStr == 'l')) || ((c3Type == 'M' || c3Type == 'm') && (custStr == 'M' || custStr == 'm')) || ((c3Type == 'R' || c3Type == 'r') && (custStr == 'R' || custStr == 'r')), ((c3Weight == 250) && (custServ >= 1 && custServ <= 4)) || ((c3Weight == 500) && (custServ >= 5 && custServ <= 9)) || ((c3Weight == 1000) && (custServ >= 10)), ((c3Cream == 'Y' || c3Cream == 'y') && (custCream == 'Y' || custCream == 'y')) || ((c3Cream == 'N' || c3Cream == 'n') && (custCream == 'N' || custCream == 'n')));


    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &custStr);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &custCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &custServ);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", ((c1Type == 'L' || c1Type == 'l') && (custStr == 'L' || custStr == 'l')) || ((c1Type == 'M' || c1Type == 'm') && (custStr == 'M' || custStr == 'm')) || ((c1Type == 'R' || c1Type == 'r') && (custStr == 'R' || custStr == 'r')), ((c1Weight == 250) && (custServ >= 1 && custServ <= 4)) || ((c1Weight == 500) && (custServ >= 5 && custServ <= 9)) || ((c1Weight == 1000) && (custServ >= 10)), ((c1Cream == 'Y' || c1Cream == 'y') && (custCream == 'Y' || custCream == 'y')) || ((c1Cream == 'N' || c1Cream == 'n') && (custCream == 'N' || custCream == 'n')));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((c2Type == 'L' || c2Type == 'l') && (custStr == 'L' || custStr == 'l')) || ((c2Type == 'M' || c2Type == 'm') && (custStr == 'M' || custStr == 'm')) || ((c2Type == 'R' || c2Type == 'r') && (custStr == 'R' || custStr == 'r')), ((c2Weight == 250) && (custServ >= 1 && custServ <= 4)) || ((c2Weight == 500) && (custServ >= 5 && custServ <= 9)) || ((c2Weight == 1000) && (custServ >= 10)), ((c2Cream == 'Y' || c2Cream == 'y') && (custCream == 'Y' || custCream == 'y')) || ((c2Cream == 'N' || c2Cream == 'n') && (custCream == 'N' || custCream == 'n')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((c3Type == 'L' || c3Type == 'l') && (custStr == 'L' || custStr == 'l')) || ((c3Type == 'M' || c3Type == 'm') && (custStr == 'M' || custStr == 'm')) || ((c3Type == 'R' || c3Type == 'r') && (custStr == 'R' || custStr == 'r')), ((c3Weight == 250) && (custServ >= 1 && custServ <= 4)) || ((c3Weight == 500) && (custServ >= 5 && custServ <= 9)) || ((c3Weight == 1000) && (custServ >= 10)), ((c3Cream == 'Y' || c3Cream == 'y') && (custCream == 'Y' || custCream == 'y')) || ((c3Cream == 'N' || c3Cream == 'n') && (custCream == 'N' || custCream == 'n')));

    printf("Hope you found a product that suits your likes!\n\n");


    return 0;
}


/*
Provided formatting parts for printf statements:
As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",
*/

/*Notes:
Use '&' for another round of storing the customer preferences. Else, there will be errors.
*/
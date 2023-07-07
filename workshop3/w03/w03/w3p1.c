/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
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
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    double priceP1 = 111.49, priceP2 = 222.99, priceP3 = 334.49, allPrice;
    int idP1 = 111, idP2 = 222, idP3 = 111;
    char taxP1 = 'Y', taxP2 = 'N', taxP3 = 'N';

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", idP1);
    printf("  Taxed: %c\n", taxP1);
    printf("  Price: $%.4lf\n\n", priceP1);

    printf("Product-2 (ID:%d)\n", idP2);
    printf("  Taxed: %c\n", taxP2);
    printf("  Price: $%.4lf\n\n", priceP2);

    printf("Product-3 (ID:%d)\n", idP3);
    printf("  Taxed: %c\n", taxP3);
    printf("  Price: $%.4lf\n\n", priceP3);

    allPrice = (priceP1 + priceP2 + priceP3) / 3;
    printf("The average of all prices is: $%.4lf\n\n", allPrice);

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", taxP1 == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", taxP2 && taxP3 == 'N');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, priceP3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", priceP3 > (priceP1 + priceP2));
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? -> % d", priceP1 >= (priceP3 - priceP2));
    printf(" (price difference: $%.2lf)\n\n", priceP3 - priceP2);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", priceP2 >= allPrice / 3);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", idP1 != idP2 && idP1 != idP3); //idP1 != idP2 && idP3 // SAME AS idP1 == !idP2 && !idP3 // NOT idP1 == !(idP2 && idP3);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", idP2 != idP1 && idP2 != idP3);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", idP3 != idP1 && idP3 != idP2);

    return 0;
}
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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

#define MIN_YEAR 2012 
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    // months corresponding number
    const int JAN = 1, DEC = 12;

    // month for user input
    int  inputMonth;

    // YYYY-MMM-DD for display, DD always starts from 01
    int YYYY, DD = 01;

    // flag for loops
    int done;

    // ratings for morning and evening
    double mornRate, evenRate;
    int iMornRate = 0, iEvenRate = 0;               // converting mornRate and evenRate to integer version
    double SumMornRate = 0, SumEvenRate = 0;    // accumulator of total rates
    double AvgMornRate, AvgEvenRate;                // average of the rates

    printf("General Well-being Log\n");
    printf("======================\n");


    /*** log date setting LOOP STARTS ***/
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &YYYY, &inputMonth);
        done = 0;

        if ((YYYY >= MIN_YEAR && YYYY <= MAX_YEAR) && (inputMonth >= JAN && inputMonth <= DEC))
        {
            printf("\n*** Log date set! ***\n\n");
            done = 1;
        }
        else if ((YYYY < MIN_YEAR || YYYY > MAX_YEAR) && (inputMonth < JAN || inputMonth > DEC))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if ((YYYY < MIN_YEAR || YYYY > MAX_YEAR) && (inputMonth >= JAN && inputMonth <= DEC))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if ((YYYY >= MIN_YEAR && YYYY <= MAX_YEAR) && (inputMonth < JAN || inputMonth > DEC))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    } while (done == 0);
    /*** log date setting LOOP END ***/


    /*** log days LOOP STARTS ***/
    for (DD = 1; DD <= LOG_DAYS; DD++)
    {
        switch (inputMonth)
        {
        case 1:
            printf("%d-JAN-%02d\n", YYYY, DD);
            break;
        case 2:
            printf("%d-FEB-%02d\n", YYYY, DD);
            break;
        case 3:
            printf("%d-MAR-%02d\n", YYYY, DD);
            break;
        case 4:
            printf("%d-APR-%02d\n", YYYY, DD);
            break;
        case 5:
            printf("%d-MAY-%02d\n", YYYY, DD);
            break;
        case 6:
            printf("%d-JUN-%02d\n", YYYY, DD);
            break;
        case 7:
            printf("%d-JUL-%02d\n", YYYY, DD);
            break;
        case 8:
            printf("%d-AUG-%02d\n", YYYY, DD);
            break;
        case 9:
            printf("%d-SEP-%02d\n", YYYY, DD);
            break;
        case 10:
            printf("%d-OCT-%02d\n", YYYY, DD);
            break;
        case 11:
            printf("%d-NOV-%02d\n", YYYY, DD);
            break;
        case 12:
            printf("%d-DEC-%02d\n", YYYY, DD);
            break;
        default:
            printf("Invalid");
            break;
        }

        // Validation routine for morning ratings
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &mornRate);
            done = 0;
            if (mornRate >= 0.0 && mornRate <= 5.0)
            {
                done = 1;
                iMornRate += (int)(mornRate * 1000);
            }
            else
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (done == 0);

        // Validation routine for evening ratings
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evenRate);
            done = 0;
            if (evenRate >= 0.0 && evenRate <= 5.0)
            {
                done = 1;
                iEvenRate += (int)(evenRate * 1000);
                printf("\n");
            }
            else
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (done == 0);
    }
    /*** log days LOOP END ***/

    /*** summary for the logs ***/
    printf("Summary\n");
    printf("=======\n");

    SumMornRate = iMornRate / 1000.0;
    SumEvenRate = iEvenRate / 1000.0;
    printf("Morning total rating: %6.3lf\n", SumMornRate);
    printf("Evening total rating: %6.3lf\n", SumEvenRate);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n\n", SumMornRate + SumEvenRate);

    AvgMornRate = SumMornRate / LOG_DAYS;
    AvgEvenRate = SumEvenRate / LOG_DAYS;
    printf("Average morning rating: %4.1lf\n", AvgMornRate);
    printf("Average evening rating: %4.1lf\n", AvgEvenRate);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", (AvgMornRate + AvgEvenRate) / 2);

    return 0;
}
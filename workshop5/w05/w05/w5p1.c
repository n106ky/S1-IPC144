/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

int main(void)
{
    /*Variables representing months and years*/
    const int JAN = 1, DEC = 12;
    int  mm;                //month for input

    /*YYYY-MMM-DD for display*/
    int YYYY, DD = 01;      //'DD' always starts with the 1st day of the month


    /*flag for loops*/
    int done;


    printf("General Well-being Log\n");
    printf("======================\n");

    /***log date setting STARTS***/
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM):");
        scanf("%d %d", &YYYY, &mm);
        done = 0;

        if ((YYYY >= MIN_YEAR && YYYY <= MAX_YEAR) && (mm >= JAN && mm <= DEC))
        {
            printf("\n*** Log date set! ***\n\n");
            done = 1;
        }
        else if ((YYYY < MIN_YEAR || YYYY > MAX_YEAR) && (mm < JAN || mm > DEC))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if ((YYYY < MIN_YEAR || YYYY > MAX_YEAR) && (mm >= JAN && mm <= DEC))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if ((YYYY >= MIN_YEAR && YYYY <= MAX_YEAR) && (mm < JAN || mm > DEC))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    } while (done == 0);
    /***log date setting END***/


    /***Print out log date***/
    switch (mm)
    {
    case 1:
        printf("Log starting date: %d-JAN-%02d\n", YYYY, DD);
        break;
    case 2:
        printf("Log starting date: %d-FEB-%02d\n", YYYY, DD);
        break;
    case 3:
        printf("Log starting date: %d-MAR-%02d\n", YYYY, DD);
        break;
    case 4:
        printf("Log starting date: %d-APR-%02d\n", YYYY, DD);
        break;
    case 5:
        printf("Log starting date: %d-MAY-%02d\n", YYYY, DD);
        break;
    case 6:
        printf("Log starting date: %d-JUN-%02d\n", YYYY, DD);
        break;
    case 7:
        printf("Log starting date: %d-JUL-%02d\n", YYYY, DD);
        break;
    case 8:
        printf("Log starting date: %d-AUG-%02d\n", YYYY, DD);
        break;
    case 9:
        printf("Log starting date: %dSEP-%02d\n", YYYY, DD);
        break;
    case 10:
        printf("Log starting date: %d-OCT-%02d\n", YYYY, DD);
        break;
    case 11:
        printf("Log starting date: %d-NOV-%02d\n", YYYY, DD);
        break;
    case 12:
        printf("Log starting date: %d-DEC-%02d\n", YYYY, DD);
        break;
    default:
        printf("Log starting date: Invalid");
        break;
    }
    return 0;
}

/* WAY 2 STARTS

char M1,M2,M3;          // combine them together to get MMM

if (mm == 1)
{
    M1 = 'J';
    M2 = 'A';
    M3 = 'N';
}
else if (mm == 2)
{
    M1 = 'F';
    M2 = 'E';
    M3 = 'B';
}
else if (mm == 3)
{
    M1 = 'M';
    M2 = 'A';
    M3 = 'R';
}
else if (mm == 4)
{
    M1 = 'A';
    M2 = 'P';
    M3 = 'R';
}
else if (mm == 5)
{
    M1 = 'M';
    M2 = 'A';
    M3 = 'Y';
}
else if (mm == 6)
{
    M1 = 'J';
    M2 = 'U';
    M3 = 'N';
}
else if (mm == 7)
{
    M1 = 'J';
    M2 = 'U';
    M3 = 'L';
}
else if (mm == 8)
{
    M1 = 'A';
    M2 = 'U';
    M3 = 'G';
}
else if (mm == 9)
{
    M1 = 'S';
    M2 = 'E';
    M3 = 'P';
}
else if (mm == 10)
{
    M1 = 'O';
    M2 = 'C';
    M3 = 'T';
}
else if (mm == 11)
{
    M1 = 'N';
    M2 = 'O';
    M3 = 'V';
}
else if (mm == 12)
{
    M1 = 'D';
    M2 = 'E';
    M3 = 'C';
}

printf("Log starting date: %d-%c%c%c-%02d\n", YYYY, M1, M2, M3, DD);

WAY 2 END */
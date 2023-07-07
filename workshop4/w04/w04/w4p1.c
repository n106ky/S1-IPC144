/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    /*What letter to print*/
    char letter;

    /*Loop for how many times*/
    int times;

    /*Flag*/
    int done;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do {
        done = 0; //corresponds to the 'while' part of do-while statement, start looping when done is 0
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &letter, &times);

        if (letter == 'D' && (times >= 3 && times <= 20))
        {
            printf("DO-WHILE: "); //the sentense "DO-WHILE" should not enter loop
            do
            {
                times--; //times it loops
                printf("%c", letter); //"\n" is not needed because they need to be in same line
            } while (times > 0);
            printf("\n\n");
        }

        else if (letter == 'W' && (times >= 3 && times <= 20))
        {
            printf("WHILE   : ");
            while (times > 0)
            {
                times--;
                printf("%c", letter);
            }
            printf("\n\n");
        }

        else if (letter == 'F' && (times >= 3 && times <= 20))
        {
            printf("FOR     : ");
            for ( ; times > 0; --times) // To avoid warning of statement with no effect, leave the initializationStatement part empty
            {
                printf("%c", letter);
            }
            printf("\n\n");
        }

        else if (letter == 'Q')
        {
            if (times == 0)
            {
                done = 1;
                printf("\n");
                printf("+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n\n");
            }
            else if (times != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            }
        }

        else
        {
            if ((letter != 'D' && letter != 'F' && letter != 'W' && letter != 'Q') && (times < 3 || times >20))
            {
                printf("ERROR: Invalid entered value(s)!\n\n");
            }

            else if (letter != 'D' && letter != 'F' && letter != 'W' && letter != 'Q')
            {
                printf("ERROR: Invalid entered value(s)!\n\n");
            }

            else if (times < 3 || times >20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }

    } while (done == 0);

    return 0;
}

/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
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

#include <stdio.h>
#include "core.h"

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// TEST #1: Integer input
int inputInt(void)
{
    char newLine = 'x';
    int value = 'x';

    while (newLine != '\n')
    {
        scanf("%d%c", &value, &newLine);

        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } 

    return value;
}

// TEST #2: Positive integer
int inputIntPositive(void) // just call the function
{
    //char newLine = 'x';
    int value = 0;

    while (value <= 0)
    {
        scanf("%d", &value);

        if (value <= 0)
        {
        printf("ERROR! Value must be > 0: ");
        }
    }

    return value;
}

// TEST #3 - 4: Integer range
int inputIntRange(int lowerBound, int upperBound)
{
    char newLine = 'x';
    int value = 'x';

    while (newLine != '\n' || (value < lowerBound || value > upperBound))
    {
        scanf("%d%c", &value, &newLine);
   
            if (newLine != '\n')
            {
                printf("Error! Input a whole number: ");
                clearInputBuffer();
            }
            else if (value < lowerBound || value > upperBound)
            {
                printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
            }
    }

    return value;
}

// TEST #5: Character
char inputCharOption(const char *receive)
{
    char input = '0';
    int i = 0;
    int done = 0;

    do
    {
        scanf("%c", &input); // ** make one more variable to store the '\n' %c%c
        clearInputBuffer();

        for (i = 0; receive[i] != '\0'; i++)
        {
            if (input == receive[i])
            {
                done = 1;
            }
        }

        if (!done)
        {
            printf("ERROR: Character must be one of [%s]: ", receive);
        }

    } while (!done);

    return input;
}

// TEST #6 - 8: String length
void inputCString(char* receive, int min, int max)
{
    int size = 0;
    int done = 0;
    int i = 0;
    char input[100+1] = { "\0" };

    while (!done)
    {
        scanf("%100[^\n]", input);
        clearInputBuffer();
        //printf("receive: %s\n", input);

        while (input[size] != '\0')
        {
            size++;
        }
        //printf("size: %d\n", size);

        if (size >= min && size <= max)
        {
            done = 1;
            for (i = 0; i < size + 1; i++)
            {
                receive[i] = input[i];
            }
        }
        else if (!done)
        {
            if (min == max && (size  < min || size  > max))
            {
                printf("ERROR: String length must be exactly %d chars: ", min);
            }
            else if (size > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else if (size < min)
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
            size = 0;
        }
    }
}

void displayFormattedPhone(const char* receive)
{
    // validation
    const int phonenum_SIZE = 10;
    const char numberArray[] = { "0123456789" };

    int size = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    
    // flag
    int done = 0;

    if (receive == NULL)
    {
        receive = "x";
    }

    while (receive[size] != '\0')
    {
        size++;
    }
    // printf("size is: %d\n", size);

    if (size != phonenum_SIZE)
    {
        printf("(___)___-____");
    }
    else // size == phonenum_SIZE
    {
        for (i = 0; done == 0 && receive[i] != '\0'; i++)
        {
            count = 0; // initialize count for for(i)-loop
            for (j = 0; numberArray[j] != '\0'; j++)
            {
                if (receive[i] != numberArray[j])
                {
                    count++;
                    if (!(count % 10))
                    {
                        printf("(___)___-____");
                        done = 1; // stop the for(i)-loop validation if the input is already incorrect
                    }
                }
            }
        }
        if (count < 10)
        {
                printf("(%c%c%c)%c%c%c-%c%c%c%c", 
                    receive[0],
                    receive[1],
                    receive[2],
                    receive[3],
                    receive[4],
                    receive[5],
                    receive[6],
                    receive[7],
                    receive[8],
                    receive[9]);
        }
    }
}
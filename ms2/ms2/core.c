/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <string.h>
#include "core.h"

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

// TEST #1: Validation for inputting a integer
int inputInt(void)
{
    char newLine = 'x';
    int input = 'x';

    while (newLine != '\n')
    {
        scanf("%d%c", &input, &newLine);

        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    }

    return input;
}

// TEST #2: Validation for inputting a positive integer
int inputIntPositive(void)
{
    int value = 0;

    do
    {
        value = inputInt();

        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value <= 0);

    return value;
}

// TEST #3 - 4: Validation for inputting a integer that is within boundary
int inputIntRange(int lowerBound, int upperBound)
{
    int value = 'x';

    while (value < lowerBound || value > upperBound)
    {
        value = inputInt();

        if (value < lowerBound || value > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    }

    return value;
}

// TEST #5: Check if the input char can be found in the received string.
char inputCharOption(const char* receive)
{
    char input[1000 + 1] = { 0 };
    int done = 0; 
    char* result = NULL;
    char find;

    do
    {
        scanf("%1000[^\n]", input);
        clearInputBuffer();
        
        find = input[0];

        if (input[1] == '\0')
        {
            result = strchr(receive, find);
        }
        if (result != NULL)
        {
            done = 1;
        }
        else if (!done)
        {
            printf("ERROR: Character must be one of [%s]: ", receive);
        }

    } while (!done);

    return find;
}

// TEST #6 - 8: Validation for inputting a string that is within the constrained size
void inputCString(char* receive, int min, int max)
{
    int size = 0;
    int done = 0;
    char input[1000 + 1] = { "\0" };

    while (!done)
    {
        scanf("%1000[^\n]", input);
        clearInputBuffer();
        //printf("receive: %s\n", input);

        size = strlen(input);

        if (size >= min && size <= max)
        {
            done = 1;
            strcpy(receive, input);
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


// Test #9: Validation for inputting a phone-number (string) that match with the provided phone number
void displayFormattedPhone(const char* receive)
{
    const int phonenum_SIZE = 10;
    int len = 0;
    int i = 0;
    int error = 0;

    while (receive != NULL && receive[len] != '\0')
    {
        len++;
    }
    if (len != phonenum_SIZE || receive == NULL)
    {
        printf("(___)___-____");
    }
    else
    {
        for (i = 0; receive[i] != '\0'; i++)
        {
            if (receive[i] < '0' || receive[i] > '9')
            {
                error++;
            }
        }

        if (error)
        {
            printf("(___)___-____");
        }
        else
        {
            i = 0;
            printf("(");
            while (i < 3)
            {
                printf("%c", receive[i]);
                i++;
            }
            printf(")");
            while (i < 6)
            {
                printf("%c", receive[i]);
                i++;
            }
            printf("-");
            while (i < 10)
            {
                printf("%c", receive[i]);
                i++;
            }
        }
    }
}
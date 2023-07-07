/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P2)
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
    /*How many is needed*/
    int nApples, nOranges, nPears, nTomatoes, nCabbages;

    /*How many is picked*/
    int pApples, pOranges, pPears, pTomatoes, pCabbages;

    /*Flag*/
    int done, shop; //starts looping when variables = 1; stop when variables = 0


    /*ENTRANCE of shopping loop*/
    do
    {
        shop = 1;

        printf("Grocery Shopping\n");
        printf("================\n");

        /*INPUT FOR GROCERY NEEDED*/

        printf("How many APPLES do you need? : ");
        scanf("%d", &nApples);
        while (nApples < 0)
            //use 'while' loop instead of just 'if', as we need to keep asking until the data is correct.
            //Avoid to use 'do-while' loop because it is not necessary to ask again.
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &nApples); // '&' for restoring new data
        }
        printf("\n");

        printf("How many ORANGES do you need? : ");
        scanf("%d", &nOranges);
        while (nOranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");
            scanf("%d", &nOranges);
        }
        printf("\n");

        printf("How many PEARS do you need? : ");
        scanf("%d", &nPears);
        while (nPears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");
            scanf("%d", &nPears);
        }
        printf("\n");

        printf("How many TOMATOES do you need? : ");
        scanf("%d", &nTomatoes);
        while (nTomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &nTomatoes);
        }
        printf("\n");


        printf("How many CABBAGES do you need? : ");
        scanf("%d", &nCabbages);
        while (nCabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &nCabbages);
        }
        printf("\n");

        /****************THIS IS JUST A DIVIDING LINE****************/

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        /*INPUT FOR GROCERY PICKED*/

        /*Picking Apples*/
        if (nApples >= 1)
        {
            do // Loop until the number of grocery needed and picked match
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pApples);
                done = 1;
                if (nApples == pApples)
                {
                    done = 0;
                    printf("Great, that's the apples done!\n\n");
                }
                else if (nApples > pApples && pApples > 0)
                {
                    printf("Looks like we still need some APPLES...\n");
                    nApples = nApples - pApples;
                }
                else if (nApples < pApples && pApples > 0)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", nApples);
                }
                else if (pApples <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (done == 1);
        }

        /*Picking Oranges*/
        if (nOranges >= 1)
        {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pOranges);
                done = 1;
                if (nOranges == pOranges)
                {
                    done = 0;
                    printf("Great, that's the oranges done!\n\n");
                }
                else if (nOranges > pOranges && pOranges > 0)
                {
                    printf("Looks like we still need some ORANGES...\n");
                    nOranges = nOranges - pOranges;
                }
                else if (nOranges < pOranges && pOranges > 0)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", nOranges);
                }
                else if (pOranges <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (done == 1);
        }

        /*Picking Pears*/
        if (nPears >= 1)
        {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pPears);
                done = 1;
                if (nPears == pPears)
                {
                    done = 0;
                    printf("Great, that's the pears done!\n\n");
                }
                else if (nPears > pPears && pPears > 0)
                {
                    printf("Looks like we still need some PEARS...\n");
                    nPears = nPears - pPears;
                }
                else if (nPears < pPears && pPears > 0)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", nPears);
                }
                else if (pPears <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (done == 1);
        }

        /*Picking Tomatoes*/
        if (nTomatoes >= 1)
        {
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pTomatoes);
                done = 1;
                if (nTomatoes == pTomatoes)
                {
                    done = 0;
                    printf("Great, that's the tomatoes done!\n\n");
                }
                else if (nTomatoes > pTomatoes && pTomatoes > 0)
                {
                    printf("Looks like we still need some TOMATOES...\n");
                    nTomatoes = nTomatoes - pTomatoes;
                }
                else if (nTomatoes < pTomatoes && pTomatoes > 0)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", nTomatoes);
                }
                else if (pTomatoes <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (done == 1);
        }

        /*Picking Cabbages*/
        if (nCabbages >= 1)
        {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pCabbages);
                done = 1;
                if (nCabbages == pCabbages)
                {
                    done = 0;
                    printf("Great, that's the cabbages done!\n\n");
                }
                else if (nCabbages > pCabbages && pCabbages > 0)
                {
                    printf("Looks like we still need some CABBAGES...\n");
                    nCabbages = nCabbages - pCabbages;
                }
                else if (nCabbages < pCabbages && pCabbages > 0)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", nCabbages);
                }
                else if (pCabbages <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (done == 1);
        }

        printf("All the items are picked!\n\n");

        /****************THIS IS JUST A DIVIDING LINE****************/

        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shop);
        printf("\n");

    } while (shop == 1);

    /*END of Shopping loop*/

    printf("Your tasks are done for today - enjoy your free time!\n");


    return 0;
}
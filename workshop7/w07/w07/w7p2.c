/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

// variables for Player Info
#define MIN_lives 1
#define MAX_lives 10

// variables for Game Info
#define MIN_gamePath 10
#define MAX_gamePath 70
#define MIN_inputMove 1
#define mutipleofNUM 5


struct PlayerInfo
{
    char playerSymbol;                  // single character to represent the player
    int lives;                          // number of lives
    int gotTreasure;                    // number of treasure found
    int pastPositions[MAX_gamePath];    // history of all past entered positions entered by the player
    int inputMove;                      // accept user for next move
};

struct GameInfo
{
    char pathArrays[MAX_gamePath];   // print out the status of the whole path
    int gamePath;                    // length of the game path (value must be 10 - 70 & mutiple of 5)
    int moves;                       // the limit for number of moves allowed (value must be 3 - 26)
    int bomb[MAX_gamePath];          // set the BOMB’s placements along the path
    int treasure[MAX_gamePath];      // number of treasure found
};


int main(void)
{
    // flags
    int done = 0;   // flag for do-while or while-loop
    int i = 0;      // flag for for-loop
    int pass = 0;   // multiple-of-5 check, if number is a multiple of 5, pass = 1

    // numbers
    int n = 0; // numbers for major and minor ruler

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    /************************************************/
    /**************** PLAYER SETTING ****************/
    /************************************************/

    struct PlayerInfo p1 = { 0,0,0, {0} ,0 };
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    // player name setting
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &p1.playerSymbol);

    // validation for setting number of lives
    do
    {
        done = 0;
        printf("Set the number of lives: ");
        scanf("%d", &p1.lives);
        if (p1.lives >= MIN_lives && p1.lives <= MAX_lives)
        {
            done = 1;
            printf("Player configuration set-up is complete\n");
        }
        else
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (done == 0);
    printf("\n");

    /**********************************************/
    /**************** GAME SETTING ****************/
    /**********************************************/

    struct GameInfo g1 = { {0}, 0,0,{0},{0} };
    printf("GAME Configuration\n");
    printf("------------------\n");

    // validation for setting PATH LENGTH (stop only when number match with the multiple-of-5 rule and between 10-70)
    do
    {
        done = 0;
        pass = 0;
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &g1.gamePath);

        // the multiple-of-5 check; when remainder = 0, means mutiple of 5, and pass will = 1;
        if ((g1.gamePath % mutipleofNUM) == 0)
        {
            pass = 1;
        }

        // stop the loop when number is a multiple of 5 and also between 10-70
        if (g1.gamePath >= MIN_gamePath && g1.gamePath <= MAX_gamePath && pass == 1)
        {
            done = 1;
        }
        else
        {
            printf("     Must be a multiple of %d and between %2d-%2d!!!\n", mutipleofNUM, MIN_gamePath, MAX_gamePath);
        }
    } while (done == 0);

    // validation for setting moves
    do
    {
        done = 0;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &g1.moves);
        if (g1.moves >= p1.lives && g1.moves <= (g1.gamePath * .75))
        {
            done = 1;
        }
        else
        {
            printf("    Value must be between %d and %d\n", p1.lives, (int)(g1.gamePath * .75));
        }
    } while (done == 0);
    printf("\n");

    /************************************************/
    /**************** BOMB PLACEMENT ****************/
    /************************************************/

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g1.gamePath);

    for (i = 0; i < g1.gamePath; i += 5) // each time store 5 values, therefore each change will be i = i + 5
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &g1.bomb[i], &g1.bomb[i + 1], &g1.bomb[i + 2], &g1.bomb[i + 3], &g1.bomb[i + 4]);
    }
    printf("BOMB placement set\n");
    printf("\n");

    /***************************************************/
    /**************** TRESURE PLACEMENT ****************/
    /***************************************************/

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g1.gamePath);

    for (i = 0; i < g1.gamePath; i += 5) // each time store 5 values, therefore each change will be i = i + 5
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &g1.treasure[i], &g1.treasure[i + 1], &g1.treasure[i + 2], &g1.treasure[i + 3], &g1.treasure[i + 4]);
    }
    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n\n");

    /*****************************************/
    /**************** SUMMARY ****************/
    /*****************************************/

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", p1.playerSymbol);
    printf("   Lives      : %d\n", p1.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", g1.gamePath);
    printf("   Bombs      : ");
    for (i = 0; i < g1.gamePath; i++) // to print all bombs path
    {
        printf("%d", g1.bomb[i]);
    }
    printf("\n");
    printf("   Treasure   : "); // to print all treasure path
    for (i = 0; i < g1.gamePath; i++)
    {
        printf("%d", g1.treasure[i]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    printf("\n");

    /* =============================================== */
    /* ================ HUNTING START ================ */
    /* =============================================== */

    done = 1; // The first Bomb-treasure check will start AFTER clean path and player status are printed.

    do
    {
        // Validation check for USER NEXT MOVE
        while (done == 0)
        {
            printf("Next Move [%d-%2d]: ", MIN_inputMove, g1.gamePath);
            scanf("%d", &p1.inputMove);

            if (p1.inputMove < MIN_inputMove || p1.inputMove > g1.gamePath)
            {
                printf("  Out of Range!!!\n");
            }
            else if (p1.pastPositions[p1.inputMove - 1] == 0) // p1.inputMove index start from 1 and p1.pastPositions index start from 0, therefore must minus 1 to align the indexes
            {
                done = 1;
                p1.pastPositions[p1.inputMove - 1] = 1;
                printf("\n");

                // check if user meet BOMB or TREASURE or BOTH or NONE
                if (p1.pastPositions[p1.inputMove - 1] == g1.bomb[p1.inputMove - 1] && p1.pastPositions[p1.inputMove - 1] == g1.treasure[p1.inputMove - 1]) // '&' = meet BOTH
                {
                    g1.pathArrays[p1.inputMove - 1] = '&';
                    p1.lives -= 1;
                    p1.gotTreasure += 1;
                    g1.moves -= 1;
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                }
                else if (p1.pastPositions[p1.inputMove - 1] == g1.bomb[p1.inputMove - 1]) // '!' = meet BOMB
                {
                    g1.pathArrays[p1.inputMove - 1] = '!';
                    p1.lives -= 1;
                    g1.moves -= 1;
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                }
                else if (p1.pastPositions[p1.inputMove - 1] == g1.treasure[p1.inputMove - 1]) // '$' = meet TREASURE
                {
                    g1.pathArrays[p1.inputMove - 1] = '$';
                    p1.gotTreasure += 1;
                    g1.moves -= 1;
                    printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                }
                else // '.' = meet NONE
                {
                    g1.pathArrays[p1.inputMove - 1] = '.';
                    g1.moves -= 1;
                    printf("===============> [.] ...Nothing found here... [.]\n\n");
                }

                // print if player has no more LIVES
                if (p1.lives == 0)
                {
                    printf("No more LIVES remaining!\n\n");
                }

                // print if player has no more MOVES
                if (g1.moves == 0)
                {
                    printf("No more MOVES remaining!\n\n");
                }
            }
            else if (p1.pastPositions[p1.inputMove - 1] == 1)
            {
                done = 1;
                printf("\n===============> Dope! You've been here before!\n\n");
            }
        }

        // print player position
        if (p1.inputMove > 0)
        {
            printf("  ");
            for (i = 0; i < p1.inputMove - 1; i++)
            {
                printf(" ");    // alternative ("%2c", '\0')
            }
            printf("%c\n", p1.playerSymbol);
        }

        if (p1.inputMove == 0)
        {
            // print clean path
            printf("  ");
            for (i = 0; i < g1.gamePath; i++)
            {
                g1.pathArrays[i] = '-';
                printf("%c", g1.pathArrays[i]);
            }
            printf("\n");
        }
        else
        {
            // print new path
            printf("  ");
            for (i = 0; i < g1.gamePath; i++)
            {
                printf("%c", g1.pathArrays[i]);
            }
            printf("\n");
        }

        // print "|" path with ruler (major) marks
        printf("  ");
        for (i = 1; i < g1.gamePath + 1; i++)
        {
            if (i % 10 == 0)
            {
                n += 1;
                printf("%d", n);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        // print ruler (minor) for path length
        printf("  ");
        n = 0;
        for (i = 1; i < g1.gamePath + 1; i++)
        {
            if (i % 10 == 0)
            {
                printf("0");
                n = 0;
            }
            else
            {
                n += 1;
                printf("%d", n);
            }
        }
        printf("\n");

        // print player status
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", p1.lives, p1.gotTreasure, g1.moves);
        printf("+---------------------------------------------------+\n");

        done = 0; // clean path and player status are printed. Time to INITIATE bomb-treasure check!

    } while (p1.lives > 0 && g1.moves > 0);
    printf("\n");

    /* ============================================= */
    /* ================ HUNTING END ================ */
    /* ============================================= */

    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");

    printf("You should play again and try to beat your score!\n\n");

    return 0;
}
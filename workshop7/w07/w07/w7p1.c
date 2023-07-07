/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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
#define mutipleofNUM 5

struct PlayerInfo
{
    char playerSymbol;                  // single character to represent the player
    int lives;                          // number of lives
    int gotTreasure;                    // number of treasure found
    int pastPositions[MAX_gamePath];    // history of all past entered positions entered by the player
};

struct GameInfo
{
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

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    /************************************************/
    /**************** PLAYER SETTING ****************/
    /************************************************/

    struct PlayerInfo p1 = { 0,0,0, {0} };
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

    struct GameInfo g1 = { 0,0,{0},{0} };
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

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 3
#define COLS 3
#define MAX_PLAYERS 7
#define MAX_NAME_LENGTH 50

// Define the symbols and their respective counts and values
#define SYMBOL_COUNT 4
#define SYMBOLS          { '$', '#', '&', '%' }
#define SYMBOLS_VALUES    { 2,   4,   6,   8 }

// Arrays to store player data
char playerNames[MAX_PLAYERS][MAX_NAME_LENGTH];
float playerBalances[MAX_PLAYERS];
int playerGamesPlayed[MAX_PLAYERS];
float playerTotalWinnings[MAX_PLAYERS];
float playerHighestSingleWin[MAX_PLAYERS];
float playerLowestSingleWin[MAX_PLAYERS];
float playerTimePlayed[MAX_PLAYERS]; // Time played in minutes

int numPlayers = 0; // Number of registered players

// Function to find a player by name (linear search)
int findPlayerIndexByName(const char* name) {
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(playerNames[i], name) == 0) {
            return i;
        }
    }
    return -1; // Player not found
}
void clearScreen() {
    system("cls"); // Use "cls" on Windows
}

// Function to display current players
void displayCurrentPlayers() {
    if (numPlayers == 0) {
        printf("\n\n\t\t\t\t\tNo players registered.\n");
        return;
    }

    printf("\n\n\t\t\t\t\tCurrent Players:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("\n\n\t\t\t\t\t- %s (Balance: PHP %.2f)\n", playerNames[i], playerBalances[i]);
    }
}

// Function to spin the slot machine and return the reels
void spin(char reels[COLS][ROWS]) {
    char symbols[] = SYMBOLS; // Symbols pool
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            int randomIndex = rand() % SYMBOL_COUNT; // Generate a random index
            reels[i][j] = symbols[randomIndex]; // Assign a symbol to the reel
        }
    }
}

// Function to check if the user won and calculate winnings
float getWinnings(char rows[ROWS][COLS], float bet, int lines) {
    float winnings = 0;

    for (int row = 0; row < lines; row++) {
        char symbols[COLS];
        int allSame = 1;

        for (int col = 0; col < COLS; col++) {
            symbols[col] = rows[row][col];
            if (col > 0 && symbols[col] != symbols[0]) {
                allSame = 0;
                break;
            }
        }

        if (allSame) {
            char symbol = symbols[0];
            switch (symbol) {
                case '$':
                    winnings += bet * 2;
                    break;
                case '#':
                    winnings += bet * 4;
                    break;
                case '&':
                    winnings += bet * 6;
                    break;
                case '%':
                    winnings += bet * 8;
                    break;
                default:
                    winnings += 0; // Default value for unknown symbols
                    break;
            }
        }
    }
    return winnings;
}

// Function to transpose the reels
void transpose(char reels[COLS][ROWS], char transposed[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transposed[i][j] = reels[j][i];
        }
    }
}

// Function to print the rows
void printRows(char rows[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("\t\t\t\t\t%c", rows[i][j]);
        }
        printf("\n\n\n");
    }
}

// Function to play the slot machine game
void playGame() {
	clearScreen();
    char playerName[MAX_NAME_LENGTH];
    printf("\n\n\t\t\t\t\tEnter your name: ");
    scanf("%s", playerName);

    int playerIndex = findPlayerIndexByName(playerName);
    if (playerIndex == -1) {
        printf("\n\n\t\t\t\t\tPlayer not found! Please input a registered name!\n");
        return;
    }

    while (1) {
    	clearScreen();
        printf("\n\n\t\t\t\t\tYou have a starting balance of PHP 1000. Your current balance is PHP %.2f\n", playerBalances[playerIndex]);
        // Check if the player's balance is zero or negative
        if (playerBalances[playerIndex] <= 0) {
            printf("\n\n\t\t\t\t\tYou are out of funds. Cannot play anymore.\n");
            break;
        }

        float bet;
        int numberOfLines;

        // Get the bet per line
        while (1) {
        	clearScreen();
            printf("\n\n\t\t\t\t\tEnter the bet per line in PHP (Maximum bet: PHP %.2f): ", playerBalances[playerIndex]);
            if (scanf("%f", &bet) != 1 || bet <= 0 || bet > playerBalances[playerIndex]) {
                printf("\n\n\t\t\t\t\tInvalid bet, please try again!\n");
                while (getchar() != '\n'); // Clear input buffer
            } else {
                break;
            }
        }

        // Get the number of lines to bet on
        while (1) {
        	clearScreen();
            printf("\n\n\t\t\t\t\tEnter the number of lines to bet on (1-3): ");
            if (scanf("%d", &numberOfLines) != 1 || numberOfLines <= 0 || numberOfLines > 3) {
                printf("\n\n\t\t\t\t\tInvalid number of lines, please try again!\n");
                while (getchar() != '\n'); // Clear input buffer
            } else {
                break;
            }
        }

        // Calculate the total bet amount
        float totalBet = bet * numberOfLines;

        // Check if the player has sufficient balance for the bet
        if (totalBet > playerBalances[playerIndex]) {
            printf("\n\n\t\t\t\t\tInsufficient balance to place this bet. Please try again with a lower bet.\n");
            continue; // Restart the loop
        }

        // Deduct the total bet amount from the player's balance
        playerBalances[playerIndex] -= totalBet;

        char reels[COLS][ROWS];
        spin(reels);

        char rows[ROWS][COLS];
        transpose(reels, rows);
        printRows(rows);

        float winnings = getWinnings(rows, bet, numberOfLines);

        // Update Highest Single Win
        if (winnings > playerHighestSingleWin[playerIndex]) {
            playerHighestSingleWin[playerIndex] = winnings;
        }

        // Update Lowest Single Win
        if (playerLowestSingleWin[playerIndex] == 0 || winnings < playerLowestSingleWin[playerIndex]) {
            playerLowestSingleWin[playerIndex] = winnings;
        }

        // Add the winnings to the player's balance
        playerBalances[playerIndex] += winnings;

        playerGamesPlayed[playerIndex]++;
        playerTotalWinnings[playerIndex] += winnings;

        printf("\n\n\t\t\t\t\tYou won PHP %.2f\n", winnings);
        printf("\n\n\t\t\t\t\tYour new balance is PHP %.2f\n", playerBalances[playerIndex]);

        // Update Time Played (assuming 5 minutes per game)
        playerTimePlayed[playerIndex] += 5.0;

        char playAgain;
        printf("\n\n\t\t\t\t\tDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        if (playAgain == 'n' || playAgain == 'N') {
            break; // Exit the game loop if the player doesn't want to play anymore
        }
    }
}

// Function to display player statistics
void displayPlayerStats() {
	clearScreen();
    char playerName[MAX_NAME_LENGTH];
    printf("\n\n\t\t\t\t\tEnter the player's name: ");
    scanf("%s", playerName);

    int playerIndex = findPlayerIndexByName(playerName);
    if (playerIndex == -1) {
        printf("\n\n\t\t\t\t\tPlayer not found. Please enter a registered player's name!\n");
        char returnToMenu;
        printf("\n\n\t\t\t\t\tReturn to the menu? (y/n): ");
        scanf(" %c", &returnToMenu);
        if (returnToMenu == 'n' || returnToMenu == 'N') {
            displayPlayerStats(); // Stay in player stats menu
        }
    } else {
        printf("\n\n\t\t\t\t\tPlayer: %s\n", playerNames[playerIndex]);
        printf("\t\t\t\t\tBalance: PHP %.2f\n", playerBalances[playerIndex]);
        printf("\t\t\t\t\tGames Played: %d\n", playerGamesPlayed[playerIndex]);
        printf("\t\t\t\t\tTotal Winnings: PHP %.2f\n", playerTotalWinnings[playerIndex]);

        // Calculate and display Win/Loss Ratio
        if (playerGamesPlayed[playerIndex] > 0) {
            float winLossRatio = (float)playerGamesPlayed[playerIndex] / (playerGamesPlayed[playerIndex] - (playerTotalWinnings[playerIndex] / 1000));
            printf("\t\t\t\t\tWin/Loss Ratio: %.2f\n", winLossRatio);
        } else {
            printf("\t\t\t\t\tWin/Loss Ratio: N/A (No games played)\n");
        }

        // Calculate and display Average Winnings per Game
        if (playerGamesPlayed[playerIndex] > 0) {
            float avgWinningsPerGame = playerTotalWinnings[playerIndex] / playerGamesPlayed[playerIndex];
            printf("\t\t\t\t\tAverage Winnings per Game: PHP %.2f\n", avgWinningsPerGame);
        } else {
            printf("\t\t\t\t\tAverage Winnings per Game: N/A (No games played)\n");
        }

        // Display Highest Single Win
        printf("\t\t\t\t\tHighest Single Win: PHP %.2f\n", playerHighestSingleWin[playerIndex]);

        // Display Lowest Single Win
        printf("\t\t\t\t\tLowest Single Win: PHP %.2f\n", playerLowestSingleWin[playerIndex]);

        // Display Time Played
        printf("\t\t\t\t\tTime Played: %.2f minutes\n", playerTimePlayed[playerIndex]);

        char returnToMenu;
        printf("\n\n\t\t\t\t\tReturn to the menu? (y/n): ");
        scanf(" %c", &returnToMenu);
        if (returnToMenu == 'n' || returnToMenu == 'N') {
            displayPlayerStats(); // Stay in player stats menu
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    while (1) {
        printf("\n\t\t\t\t\tSLOT MACHINE GAME\n");
        printf("\t\t\t\t\t1. Register/Select Player\n");
        printf("\t\t\t\t\t2. Play Slot Machine\n");
        printf("\t\t\t\t\t3. Display Player Stats\n");
        printf("\t\t\t\t\t4. Display Current Players\n");
        printf("\t\t\t\t\t5. Quit\n");

        int choice;
        printf("\t\t\t\t\tEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("\n\n\t\t\t\t\tInvalid input, please try again!\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                {
                    char playerName[MAX_NAME_LENGTH];
                    printf("\n\n\t\t\t\t\tEnter your name: ");
                    scanf("%s", playerName);

                    int playerIndex = findPlayerIndexByName(playerName);
                    if (playerIndex != -1) {
                        printf("\n\n\t\t\t\t\tPlayer already registered!\n");
                    } else if (numPlayers >= MAX_PLAYERS) {
                        printf("\n\n\t\t\t\t\tMaximum number of players reached!\n");
                    } else {
                        strcpy(playerNames[numPlayers], playerName);
                        playerBalances[numPlayers] = 1000; // Set starting balance to 1000
                        playerGamesPlayed[numPlayers] = 0;
                        playerTotalWinnings[numPlayers] = 0;
                        playerHighestSingleWin[numPlayers] = 0;
                        playerLowestSingleWin[numPlayers] = 0;
                        playerTimePlayed[numPlayers] = 0;
                        numPlayers++; // Increment the number of registered players
                        printf("\n\n\t\t\t\t\tPlayer registered successfully!\n");
                        printf("\n\n\t\t\t\t\tYou have a starting balance of PHP 1000.\n");
                    }
                }
                break;
            case 2:
                playGame();
                break;
            case 3:
                displayPlayerStats();
                break;
            case 4:
                displayCurrentPlayers();
                break;
            case 5:
            	clearScreen();
            case 6:
                printf("\n\n\t\t\t\t\tThank you for playing!\n\t\t\t\t\tApplication Developed by:\n\t\t\t\t\tJoshua Uy&Jake Perez");
                exit(0);
            default:
                printf("\n\n\t\t\t\t\tInvalid choice, please select a valid option!\n");
                break;
        }
    }

    return 0;
}
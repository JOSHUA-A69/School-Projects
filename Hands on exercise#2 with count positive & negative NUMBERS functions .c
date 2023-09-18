#include <stdio.h>
#include <stdlib.h> 

// Displays all Elements 
void displayAllElements(int rowSize, int colSize, int elements[rowSize][colSize]) {
    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            printf("%d\t", elements[row][col]);
        }
        printf("\n");
    }
}

// Counts the number of Even numbers in the array
int countEven(int rowSize, int colSize, int elements[rowSize][colSize]) {
    int countEven = 0;

    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            if (elements[row][col] % 2 == 0) {
                countEven++;
            }
        }
    }

    return countEven;
}

// Counts the number of Odd numbers in the array
int countOdd(int rowSize, int colSize, int elements[rowSize][colSize]) {
    int countOdd = 0;

    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            if (elements[row][col] % 2 != 0) {
                countOdd++;
            }
        }
    }

    return countOdd;
}

// Finds and displays the largest number in the specified row
void largestNumberRow(int rowSize, int colSize, int elements[rowSize][colSize], int row) {
    if (row >= 0 && row < rowSize) {
        int max = elements[row][0];
        for (int col = 1; col < colSize; col++) {
            if (max < elements[row][col]) {
                max = elements[row][col];
            }
        }
        printf("Highest Number in row %d: %d\n", row + 1, max);
    } else {
        printf("Invalid row number.\n");
    }
}

// Finds and displays the lowest number in the specified column
void lowestNumberCol(int rowSize, int colSize, int elements[rowSize][colSize], int col) {
    if (col >= 0 && col < colSize) {
        int min = elements[0][col];
        for (int row = 1; row < rowSize; row++) {
            if (min > elements[row][col]) {
                min = elements[row][col];
            }
        }
        printf("Lowest number in column %d: %d\n", col + 1, min);
    } else {
        printf("Invalid column number.\n");
    }
}

int countPositiveNumbers(int rowSize, int colSize, int elements[rowSize][colSize]) {
    int positive_count = 0;
    
    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            if (elements[row][col] > 0) {
                positive_count++;
            }
        }
    }
    return positive_count;
}

int countNegativeNumbers(int rowSize, int colSize, int elements[rowSize][colSize]) {
    int negative_count = 0;
    
    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            if (elements[row][col] < 0) {
                negative_count++;
            }
        }
    }
    return negative_count;
}

// Function for Menu
void mainMenu() {
    // Initialized array 4x6
    int numbers[4][6] = {
        {2, -4, -6, 8, 10, 0},
        {1, -3, 5, -7, 9, 0},
        {1, 2, 3, 4, 5, 6},
        {-10, -9, -8, -7, -6, -5},
    };

    int rowSize = 4;
    int colSize = 6;
    int choice;
    
    do {
        printf("\nMain Menu:\n");
        printf("1. Display All Elements\n");
        printf("2. Count Even Numbers\n");
        printf("3. Count Odd Numbers\n");
        printf("4. Display Highest number in Row\n");
        printf("5. Display Lowest number in Column\n");
        printf("6. Number of Positive Numbers\n");
        printf("7. Number of Negative Numbers\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        system("cls");
        if (choice == 1) {
            displayAllElements(rowSize, colSize, numbers);
        } else if (choice == 2) {
            printf("Number of Even numbers in the Array: %d\n", countEven(rowSize, colSize, numbers));
        } else if (choice == 3) {
            printf("Number of Odd numbers in the Array: %d\n", countOdd(rowSize, colSize, numbers));
        } else if (choice == 4) {
            printf("Enter row number: ");
            int row;
            scanf("%d", &row);
            largestNumberRow(rowSize, colSize, numbers, row - 1);
        } else if (choice == 5) {
            printf("Enter column number: ");
            int col;
            scanf("%d", &col);
            lowestNumberCol(rowSize, colSize, numbers, col - 1);
        } else if (choice == 6) {
            printf("Number of Positive number:%d\n",countPositiveNumbers(rowSize, colSize, numbers));
        } else if (choice == 7) {
            printf("Number of negative number:%d\n",countNegativeNumbers(rowSize, colSize, numbers));
        } else if (choice == 0) {
            printf("Exiting the program.\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int main() {
    mainMenu();
    return 0;
}

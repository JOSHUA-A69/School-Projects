#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

const char* items[] = {
        "24pcs Premium Maki",
        "32pcs Premium Maki",
        "40pcs Premium Maki",
        "56pcs Premium Maki",
        "64pcs Premium Maki",
        "24pcs CM Platter",
        "32pcs CM Platter",
        "40pcs CM Platter",
        "60pcs CM Platter",
        "80pcs CM Platter",
        "40pcs DM Platter",
        "60pcs DM Platter",
        "80pcs DM Platter",
        "100pcs DM Platter",
        "Solo pan",
        "Small pan (2pax)",
        "Medium pan(4-6pax)",
        "Large pan (8-10pax)"
    };

    double prices[] = {
        450.0, 600.0, 750.0, 1050.0, 1200.0, 350.0, 450.0, 550.0, 770.0,
        1120.0, 600.0, 820.0, 1170.0, 1450.0, 130.0, 350.0, 750.0, 1100.0
    };


// Function to display the menu
void displayMenu(const char* items[], const double prices[], int menuSize) {
    printf("\n\t*****WELCOME TO DIVINE SUSHI SHOP*****\n\n");
    printf(" ________________________________________________________\n");
    printf("                 ==MENU==                     \n");
    for (int i = 0; i < menuSize; i++) {
        printf(" [%d] %s %29.2fPhp\n", i + 1, items[i], prices[i]);
    }
    printf("___________________________________________________________\n");
}

// Function to find a menu item by name (case-insensitive)
int findMenuItemByName(const char* items[], int menuSize, const char* itemName) {
    for (int i = 0; i < menuSize; i++) {
        if (strcasecmp(items[i], itemName) == 0) {
            return i; // Return the index of the item
        }
    }
    return -1; // Item not found
}

int main() {
    
    int menuSize = sizeof(items) / sizeof(items[0]);

    displayMenu(items, prices, menuSize);

    char addMore;
    double grandTotal = 0.0;

    do {
        char itemName[100];
        int quantity;

        printf("\nEnter the name of the item you want to buy: ");
        scanf(" %[^\n]", itemName);

        // Convert the input item name to lowercase
        for (int i = 0; itemName[i]; i++) {
            itemName[i] = tolower(itemName[i]);
        }

        int itemIndex = findMenuItemByName(items, menuSize, itemName);

        if (itemIndex == -1) {
            printf("Item not found in the menu.\n");
            continue;
        }

        printf("Enter quantity: ");
        while (scanf("%d", &quantity) != 1 || quantity <= 0) {
            printf("Invalid input. Please enter a positive quantity.\n");
            while (getchar() != '\n'); // Clear input buffer
            printf("Enter quantity: ");
        }

        double totalCost = prices[itemIndex] * quantity;
        printf("\nTotal cost for this item: %.2fPhp\n", totalCost);
        grandTotal += totalCost;

        while (1) {
            printf("\nDo you want to add more items (y/n)? ");
            fflush(stdin);
            addMore = getchar();
            if (addMore == '\n') {
                printf("Invalid input, please enter 'y' or 'n'\n");
            } else if (addMore == 'y' || addMore == 'n') {
                break;
            } else {
                printf("Invalid input, please enter 'y' or 'n'\n");
            }
        }
    } while (addMore == 'y');

    printf("\nGrand total: %.2fPhp\n", grandTotal);

    return 0;
}

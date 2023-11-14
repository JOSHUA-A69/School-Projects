#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Constants for tracking orders
#define MAX_ORDERS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

const char *items[] = {
    "24pcs Premium Maki", "32pcs Premium Maki", "40pcs Premium Maki", "56pcs Premium Maki", "64pcs Premium Maki",
    "24pcs CM Platter", "32pcs CM Platter", "40pcs CM Platter", "60pcs CM Platter", "80pcs CM Platter",
    "40pcs DM Platter", "60pcs DM Platter", "80pcs DM Platter", "100pcs DM Platter", "Solo pan",
    "Small pan (2pax)", "Medium pan(4-6pax)", "Large pan (8-10pax)"
};

double prices[] = {
    450.0, 600.0, 750.0, 1050.0, 1200.0, 350.0, 450.0, 550.0, 770.0,
    1120.0, 600.0, 820.0, 1170.0, 1450.0, 130.0, 350.0, 750.0, 1100.0
};

// Function to display the menu
void displayMenu(const char *items[], const double prices[], int menuSize)
{
    printf("\n\t*****WELCOME TO DIVINE SUSHI SHOP*****\n\n");
    printf(" ________________________________________________________\n");
    printf("                 ==MENU==                     \n");
    for (int i = 0; i < menuSize; i++)
    {
        printf(" [%d] %s %29.2fPhp\n", i + 1, items[i], prices[i]);
    }
    printf("___________________________________________________________\n");
}

// Function to find a menu item by name (case-insensitive)
int findMenuItemByName(const char *items[], int menuSize, const char *itemName)
{
    for (int i = 0; i < menuSize; i++)
    {
        if (strcasecmp(items[i], itemName) == 0)
        {
            return i; // Return the index of the item
        }
    }
    return -1; // Item not found
}

int main()
{
    char customerNames[MAX_ORDERS][MAX_NAME_LENGTH];
    char itemNames[MAX_ORDERS][MAX_NAME_LENGTH];
    int quantities[MAX_ORDERS];
    double totalCosts[MAX_ORDERS];
    char orderTimes[MAX_ORDERS][30];
    char customerAddresses[MAX_ORDERS][MAX_ADDRESS_LENGTH];

    int menuSize = sizeof(items) / sizeof(items[0]);

    displayMenu(items, prices, menuSize);

    char addMore;
    double grandTotal = 0.0;
    int orderCount = 0;

    do
    {
        time_t now = time(NULL);
        strftime(orderTimes[orderCount], sizeof(orderTimes[orderCount]), "%Y-%m-%d %H:%M:%S", localtime(&now));

        printf("\nEnter your name: ");
        scanf("%s", customerNames[orderCount]);

        printf("Enter your address: ");
        scanf(" %[^\n]", customerAddresses[orderCount]);

        printf("Enter the name of the item you want to buy: ");
        scanf(" %[^\n]", itemNames[orderCount]);

        // Convert the input item name to lowercase
        for (int i = 0; itemNames[orderCount][i]; i++)
        {
            itemNames[orderCount][i] = tolower(itemNames[orderCount][i]);
        }

        int itemIndex = findMenuItemByName(items, menuSize, itemNames[orderCount]);

        if (itemIndex == -1)
        {
            printf("Item not found in the menu.\n");
            continue;
        }

        printf("Enter quantity: ");
        while (scanf("%d", &quantities[orderCount]) != 1 || quantities[orderCount] <= 0)
        {
            printf("Invalid input. Please enter a positive quantity.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            printf("Enter quantity: ");
        }

        totalCosts[orderCount] = prices[itemIndex] * quantities[orderCount];
        printf("\nTotal cost for this item: %.2fPhp\n", totalCosts[orderCount]);
        grandTotal += totalCosts[orderCount];

        while (1)
        {
            printf("\nDo you want to add more items (y/n)? ");
            fflush(stdin);
            addMore = getchar();
            if (addMore == '\n')
            {
                printf("Invalid input, please enter 'y' or 'n'\n");
            }
            else if (addMore == 'y' || addMore == 'n')
            {
                break;
            }
            else
            {
                printf("Invalid input, please enter 'y' or 'n'\n");
            }
        }

        orderCount++;

    } while (addMore == 'y' && orderCount < MAX_ORDERS);

    printf("\nGrand total: %.2fPhp\n", grandTotal);

    // Display order details
    printf("\nOrder details:\n");
    for (int i = 0; i < orderCount; i++)
    {
        printf("\nOrder #%d\n", i + 1);
        printf("Name: %s\n", customerNames[i]);
        printf("Address: %s\n", customerAddresses[i]);
        printf("Item: %s\n", itemNames[i]);
        printf("Quantity: %d\n", quantities[i]);
        printf("Total Cost: %.2fPhp\n", totalCosts[i]);
        printf("Order Time: %s\n", orderTimes[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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

// Struct to represent order details
struct OrderDetails {
    char customerName[MAX_NAME_LENGTH];
    char itemName[MAX_NAME_LENGTH];
    int quantity;
    double totalCost;
    char orderTime[30];
    char customerAddress[MAX_ADDRESS_LENGTH];
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
    struct OrderDetails orders[MAX_ORDERS];

    int menuSize = sizeof(items) / sizeof(items[0]);

    displayMenu(items, prices, menuSize);

    char addMore;
    double grandTotal = 0.0;
    int orderCount = 0;

    do
    {
        time_t now = time(NULL);
        strftime(orders[orderCount].orderTime, sizeof(orders[orderCount].orderTime), "%Y-%m-%d %H:%M:%S", localtime(&now));

        printf("\nEnter your name: ");
        scanf("%s", orders[orderCount].customerName);

        printf("Enter your address: ");
        scanf(" %[^\n]", orders[orderCount].customerAddress);

        printf("Enter the name of the item you want to buy: ");
        scanf(" %[^\n]", orders[orderCount].itemName);

        // Convert the input item name to lowercase
        for (int i = 0; orders[orderCount].itemName[i]; i++)
        {
            orders[orderCount].itemName[i] = tolower(orders[orderCount].itemName[i]);
        }

        int itemIndex = findMenuItemByName(items, menuSize, orders[orderCount].itemName);

        if (itemIndex == -1)
        {
            printf("Item not found in the menu.\n");
            continue;
        }

        printf("Enter quantity: ");
        while (scanf("%d", &orders[orderCount].quantity) != 1 || orders[orderCount].quantity <= 0)
        {
            printf("Invalid input. Please enter a positive quantity.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            printf("Enter quantity: ");
        }

        orders[orderCount].totalCost = prices[itemIndex] * orders[orderCount].quantity;
        printf("\nTotal cost for this item: %.2fPhp\n", orders[orderCount].totalCost);
        grandTotal += orders[orderCount].totalCost;

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
        printf("Name: %s\n", orders[i].customerName);
        printf("Address: %s\n", orders[i].customerAddress);
        printf("Item: %s\n", orders[i].itemName);
        printf("Quantity: %d\n", orders[i].quantity);
        printf("Total Cost: %.2fPhp\n", orders[i].totalCost);
        printf("Order Time: %s\n", orders[i].orderTime);
    }

    return 0;
}

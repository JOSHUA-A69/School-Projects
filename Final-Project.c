#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to clear the console screen
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#define MAX_ORDERS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_ITEM_NAME_LENGTH 100
#define CONTACT_NUMBER_LENGTH 12 // Including null terminator

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
struct OrderDetails
{
    char customerName[MAX_NAME_LENGTH];
    char itemName[MAX_ITEM_NAME_LENGTH];
    int quantity;
    double totalCost;
    char orderTime[30];
    char customerAddress[MAX_ADDRESS_LENGTH];
    char contactNumber[CONTACT_NUMBER_LENGTH];
};

// Global variable for sorted indices
int sortedIndices[sizeof(items) / sizeof(items[0])];

// Function to display the menu
void displayMenu(const char *items[], const double prices[], int menuSize)
{
    clearScreen();
    printf("\n\t*****WELCOME TO DIVINE SUSHI SHOP*****\n\n");
    printf(" ________________________________________________________\n");
    printf("                 ==MENU==                     \n");

    // Sort menu by price
    for (int i = 0; i < menuSize; i++)
    {
        sortedIndices[i] = i;
    }

    // Bubble Sort based on prices
    for (int i = 0; i < menuSize - 1; i++)
    {
        for (int j = 0; j < menuSize - i - 1; j++)
        {
            if (prices[sortedIndices[j]] > prices[sortedIndices[j + 1]])
            {
                int temp = sortedIndices[j];
                sortedIndices[j] = sortedIndices[j + 1];
                sortedIndices[j + 1] = temp;
            }
        }
    }

    // Display sorted menu
    for (int i = 0; i < menuSize; i++)
    {
        int index = sortedIndices[i];
        printf(" [%d] %-30s %.2fPhp\n", i + 1, items[index], prices[index]);
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

// Function to edit an existing order
void editOrder(struct OrderDetails *order)
{
    printf("\nEnter new quantity for %s: ", order->itemName);
    while (scanf("%d", &order->quantity) != 1 || order->quantity <= 0)
    {
        printf("Invalid input. Please enter a positive quantity: ");
        while (getchar() != '\n')
            ; // Clear input buffer
    }

    // Recalculate total cost based on the new quantity
    order->totalCost = prices[findMenuItemByName(items, sizeof(items) / sizeof(items[0]), order->itemName)] * order->quantity;

    printf("\nOrder edited successfully!\n");
}

// Function to insert a new order
void insertOrder(struct OrderDetails *orders, int *orderCount)
{
    if (*orderCount < MAX_ORDERS)
    {
        struct OrderDetails newOrder;

        time_t now = time(NULL);
        strftime(newOrder.orderTime, sizeof(newOrder.orderTime), "%Y-%m-%d %H:%M:%S", localtime(&now));

        printf("\nEnter your name: ");
        scanf(" %[^\n]", newOrder.customerName);

        printf("Enter your address: ");
        scanf(" %[^\n]", newOrder.customerAddress);

        // Validate contact number
        do
        {
            printf("Enter your contact number (11 digits): ");
            scanf(" %11s", newOrder.contactNumber);

            if (strlen(newOrder.contactNumber) != 11 || !isdigit(newOrder.contactNumber[0]))
            {
                printf("Invalid input. Please enter a valid 11-digit contact number.\n");
            }

        } while (strlen(newOrder.contactNumber) != 11 || !isdigit(newOrder.contactNumber[0]));

        int itemIndex;
        do
        {
            // Display the menu
            displayMenu(items, prices, sizeof(items) / sizeof(items[0]));

            printf("Enter the name of the item you want to buy\n(NOTE:It will keep repeating if you input anything that is not found in the menu.): ");
            scanf(" %[^\n]", newOrder.itemName);

            // Convert the input item name to lowercase
            for (int i = 0; newOrder.itemName[i]; i++)
            {
                newOrder.itemName[i] = tolower(newOrder.itemName[i]);
            }

            itemIndex = findMenuItemByName(items, sizeof(items) / sizeof(items[0]), newOrder.itemName);

            if (itemIndex == -1)
            {
                printf("Item not found in the menu. Please enter a valid item name.\n");
            }
            else
            {
                printf("You selected: %s\n", newOrder.itemName);

                printf("Enter quantity: ");
                while (scanf("%d", &newOrder.quantity) != 1 || newOrder.quantity <= 0)
                {
                    printf("Invalid input. Please enter a positive quantity: ");
                    while (getchar() != '\n')
                        ; // Clear input buffer
                }

                newOrder.totalCost = prices[itemIndex] * newOrder.quantity;

                orders[*orderCount] = newOrder;
                (*orderCount)++;

                printf("\nOrder inserted successfully!\n");
            }
        } while (itemIndex == -1);
    }
    else
    {
        printf("\nMaximum orders reached. Cannot insert more orders.\n");
    }
}

// Function to delete an existing order
void deleteOrder(struct OrderDetails *orders, int *orderCount, int index)
{
    if (index >= 0 && index < *orderCount)
    {
        printf("\nOrder #%d deleted successfully!\n", index + 1);

        // Shift remaining orders to fill the gap
        for (int i = index; i < *orderCount - 1; i++)
        {
            orders[i] = orders[i + 1];
        }

        (*orderCount)--;
    }
    else
    {
        printf("\nInvalid order index. Deletion failed.\n");
    }
}

// Function to list all orders
void listOrders(struct OrderDetails *orders, int orderCount)
{
    clearScreen();
    printf("\nOrder details:\n");
    for (int i = 0; i < orderCount; i++)
    {
        printf("\nOrder #%d\n", i + 1);
        printf("Name: %s\n", orders[i].customerName);
        printf("Contact Number: %s\n", orders[i].contactNumber);
        printf("Address: %s\n", orders[i].customerAddress);
        printf("Item: %s\n", orders[i].itemName);
        printf("Quantity: %d\n", orders[i].quantity);
        printf("Total Cost: %.2fPhp\n", orders[i].totalCost);
        printf("Order Time: %s\n", orders[i].orderTime);
    }
}

int main()
{
    struct OrderDetails orders[MAX_ORDERS];

    int orderCount = 0;

    displayMenu(items, prices, sizeof(items) / sizeof(items[0]));

    char addMore;
    double grandTotal = 0.0;

    do
    {
        // Move the initial order details display here
        printf("\nEnter your name: ");
        scanf(" %[^\n]", orders[orderCount].customerName);

        // Validate contact number
        do
        {
            printf("Enter your contact number (11 digits): ");
            scanf(" %11s", orders[orderCount].contactNumber);

            if (strlen(orders[orderCount].contactNumber) != 11 || !isdigit(orders[orderCount].contactNumber[0]))
            {
                printf("Invalid input. Please enter a valid 11-digit contact number.\n");
            }

        } while (strlen(orders[orderCount].contactNumber) != 11 || !isdigit(orders[orderCount].contactNumber[0]));

        printf("Enter your address: ");
        scanf(" %[^\n]", orders[orderCount].customerAddress);

        int itemIndex;
        do
        {
            // Display the menu
            displayMenu(items, prices, sizeof(items) / sizeof(items[0]));

            printf("Enter the name of the item you want to buy\n(NOTE:It will keep repeating if you input anything that is not found in the menu.):");
            scanf(" %[^\n]", orders[orderCount].itemName);

            // Convert the input item name to lowercase
            for (int i = 0; orders[orderCount].itemName[i]; i++)
            {
                orders[orderCount].itemName[i] = tolower(orders[orderCount].itemName[i]);
            }

            itemIndex = findMenuItemByName(items, sizeof(items) / sizeof(items[0]), orders[orderCount].itemName);

            if (itemIndex == -1)
            {
                printf("Item not found in the menu. Please enter a valid item name.\n");
            }
            else
            {
                printf("You selected: %s\n", orders[orderCount].itemName);

                printf("Enter quantity: ");
                while (scanf("%d", &orders[orderCount].quantity) != 1 || orders[orderCount].quantity <= 0)
                {
                    printf("Invalid input. Please enter a positive quantity: ");
                    while (getchar() != '\n')
                        ; // Clear input buffer
                }

                orders[orderCount].totalCost = prices[itemIndex] * orders[orderCount].quantity;
                grandTotal += orders[orderCount].totalCost;

                // Set the order time here
                time_t now = time(NULL);
                strftime(orders[orderCount].orderTime, sizeof(orders[orderCount].orderTime), "%Y-%m-%d %H:%M:%S", localtime(&now));

                printf("\nOrder inserted successfully!\n");
            }
        } while (itemIndex == -1);

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
    listOrders(orders, orderCount);

    // Allow the user to perform additional operations
    int operation;
    printf("\nChoose an operation:\n");
    printf("1. Edit an order\n");
    printf("2. Insert a new order\n");
    printf("3. Delete an order\n");
    printf("4. List all orders\n");
    printf("0. Exit\n");

    while (scanf("%d", &operation) != 1 || (operation < 0 || operation > 4))
    {
        printf("Invalid input. Please enter a valid operation number: ");
        while (getchar() != '\n')
            ; // Clear input buffer
    }

    while (operation != 0)
    {
        switch (operation)
        {
        case 1:
            // Edit an existing order
            printf("\nEnter the number of the order to edit: ");
            int editIndex;
            while (scanf("%d", &editIndex) != 1 || (editIndex < 1 || editIndex > orderCount))
            {
                printf("Invalid input. Please enter a valid order number: ");
                while (getchar() != '\n')
                    ; // Clear input buffer
            }
            editOrder(&orders[editIndex - 1]);
            break;
        case 2:
            // Insert a new order
            insertOrder(orders, &orderCount);
            break;
        case 3:
            // Delete an existing order
            printf("\nEnter the number of the order to delete: ");
            int deleteIndex;
            while (scanf("%d", &deleteIndex) != 1 || (deleteIndex < 1 || deleteIndex > orderCount))
            {
                printf("Invalid input. Please enter a valid order number: ");
                while (getchar() != '\n')
                    ; // Clear input buffer
            }
            deleteOrder(orders, &orderCount, deleteIndex - 1);
            break;
        case 4:
            // List all orders
            listOrders(orders, orderCount);
            break;
        default:
            printf("\nInvalid operation. Please enter a valid operation number.\n");
            break;
        }

        // Prompt for the next operation
        printf("\nChoose an operation (0 to exit): ");
        while (scanf("%d", &operation) != 1 ||(operation < 0 || operation > 4))
        {
            printf("Invalid input. Please enter a valid operation number: ");
            while (getchar() != '\n')
                ; // Clear input buffer
        }
    }
    printf("\n\nOrder taken successfully!\n\n");
    printf("\n\nThank you for using this ordering system program.\n");
    printf("This program is developed by Joshua Russel Uy and Jake Perez.");
    return 0;
}

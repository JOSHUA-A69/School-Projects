#include <stdio.h>
#include <string.h>

struct BankAccount {
char clientName[100];
char clientContactNumber[12]; 
int accountNumber;
 float balance; 
};

void acceptClient(struct BankAccount *account);
void displayClient(const struct BankAccount *account);
void withdrawAmount(struct BankAccount *account);
void depositAmount(struct BankAccount *account);

int main() {
    struct BankAccount client;
    int choice;

    acceptClient(&client);

    do {
        printf("\nMenu:\n");
        printf("[1] Display Client Information\n");
        printf("[2] Deposit\n");
        printf("[3] Withdraw\n");
        printf("[0] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayClient(&client);
                break;
            case 2:
                depositAmount(&client);
                break;
            case 3:
                withdrawAmount(&client);
                break;
            case 0:
                printf("Made by Joshua Russel Uy\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

void acceptClient(struct BankAccount *account) {
    printf("Enter your Name: ");
    scanf(" %[^\n]s", account->clientName);

    printf("Enter your contact number (11 digits): ");
    scanf("%11s", account->clientContactNumber); 

    printf("Enter your Account number (5 digits): ");
    scanf("%d", &account->accountNumber);

    do {
        printf("Enter Initial Balance (should not be lower than 500.00): ");
        scanf("%f", &account->balance);

        if (account->balance < 500.00) {
            printf("Invalid! Initial Balance should not be lower than 500.00\n");
        }
    } while (account->balance < 500.00);
}

void displayClient(const struct BankAccount *account) {
    printf("Client Information\n");
    printf("Client Name: %s\n", account->clientName);
    printf("Client Contact Number: %s\n", account->clientContactNumber);
    printf("Client Account Number: %d\n", account->accountNumber);
    printf("Client Balance: %.2f\n", account->balance);
}

void withdrawAmount(struct BankAccount *account) {
    float amount;

    do {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("Invalid! Amount should be greater than 0\n");
        } else if (account->balance - amount < 500.00) {
            printf("Invalid! Balance after withdrawal should not be lower than 500.00\n");
        }
    } while (amount <= 0 || account->balance - amount < 500.00);

    // Update balance
    account->balance -= amount;
    printf("Withdrawal successful. Updated balance: %.2f\n", account->balance);
}

void depositAmount(struct BankAccount *account) {
    float amount;

    do {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("Invalid! Amount should be greater than 0\n");
        }
    } while (amount <= 0);

    account->balance += amount;
    printf("Deposit successful. Updated balance: %.2f\n", account->balance);
}


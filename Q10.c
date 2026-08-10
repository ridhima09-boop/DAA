#include <stdio.h>

struct Transaction {
    char type[20];
    float amount;
};

int main() {
    float balance = 10000, amount;
    struct Transaction t[5];
    int count = 0;
    int choice, i;

    while (1) {
        printf("\n\n--- ATM MENU ---");
        printf("\n1. Check Balance");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Last 5 Transactions");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Balance = %.2f", balance);
        }

        else if (choice == 2) {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if (amount > 0) {
                balance += amount;

                if (count < 5) {
                    sprintf(t[count].type, "Deposit");
                    t[count].amount = amount;
                    count++;
                }

                printf("Deposit successful.");
            }
        }

        else if (choice == 3) {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if (amount <= balance && amount > 0) {
                balance -= amount;

                if (count < 5) {
                    sprintf(t[count].type, "Withdrawal");
                    t[count].amount = amount;
                    count++;
                }

                printf("Withdrawal successful.");
            }
            else {
                printf("Insufficient balance.");
            }
        }

        else if (choice == 4) {
            printf("\nLast transactions:\n");

            for (i = 0; i < count; i++)
                printf("%s : %.2f\n", t[i].type, t[i].amount);
        }

        else if (choice == 5) {
            printf("Thank you!");
            break;
        }

        else {
            printf("Invalid choice.");
        }
    }

    return 0;
}

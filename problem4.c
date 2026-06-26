#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 10

struct Account
{
    int accNo;
    char name[30];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount();
void displayAccounts();
void depositMoney();
void withdrawMoney();
void generateReport();

int main()
{
    int choice;

    printf("Banking Management System\n");

    while (1)
    {
        printf("\n1. Create Account");
        printf("\n2. Display Accounts");
        printf("\n3. Deposit");
        printf("\n4. Withdraw");
        printf("\n5. Report");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount();
            break;

        case 2:
            displayAccounts();
            break;

        case 3:
            depositMoney();
            break;

        case 4:
            withdrawMoney();
            break;

        case 5:
            generateReport();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

void createAccount()
{
    static int accountCounter = 1000;

    if (totalAccounts >= MAX_ACCOUNTS)
    {
        printf("Database Full\n");
        return;
    }

    accounts[totalAccounts].accNo = accountCounter++;

    printf("Enter Name: ");
    scanf("%29s", accounts[totalAccounts].name);

    printf("Enter Balance: ");
    scanf("%f", &accounts[totalAccounts].balance);

    totalAccounts++;
}

void displayAccounts()
{
    if (totalAccounts == 0)
    {
        printf("No accounts found.\n");
        return;
    }

    for (int i = 0; i < totalAccounts; i++)
    {
        printf("\nAccount No : %d", accounts[i].accNo);
        printf("\nName : %s", accounts[i].name);
        printf("\nBalance : %.2f\n", accounts[i].balance);
    }
}

void depositMoney()
{
    int accNo;
    float amount;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter Amount: ");
    scanf("%f", &amount);

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accNo == accNo)
        {
            accounts[i].balance += amount;
            printf("Deposit Successful.\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");
}

void withdrawMoney()
{
    int accNo;
    float amount;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter Amount: ");
    scanf("%f", &amount);

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accNo == accNo)
        {
            found = 1;

            if (accounts[i].balance >= amount)
            {
                accounts[i].balance -= amount;
                printf("Withdrawal Successful.\n");
            }
            else
            {
                printf("Insufficient Balance.\n");
            }

            break;
        }
    }

    if (!found)
        printf("Account not found.\n");
}

void generateReport()
{
    if (totalAccounts == 0)
    {
        printf("No accounts available.\n");
        return;
    }

    float total = 0;
    float highest = accounts[0].balance;
    float lowest = accounts[0].balance;

    for (int i = 0; i < totalAccounts; i++)
    {
        total += accounts[i].balance;

        if (accounts[i].balance > highest)
            highest = accounts[i].balance;

        if (accounts[i].balance < lowest)
            lowest = accounts[i].balance;
    }

    printf("\nTotal Balance : %.2f", total);
    printf("\nAverage Balance : %.2f", total / totalAccounts);
    printf("\nHighest Balance : %.2f", highest);
    printf("\nLowest Balance : %.2f", lowest);
    printf("\nTotal Accounts : %d\n", totalAccounts);
}

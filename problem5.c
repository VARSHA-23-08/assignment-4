#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book
{
    int bookId;
    char title[50];
    char author[30];
    float price;
};

struct Book books[20];
int totalBooks = 0;

void addBook();
void displayBooks();
void issueBook();
void returnBook();
void generateReport();

int main()
{
    int choice;

    printf("Library Management System\n");

    while (1)
    {
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Report");
        printf("\n6. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            issueBook();
            break;

        case 4:
            returnBook();
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

void addBook()
{
    static int bookCounter = 100;

    if (totalBooks >= 20)
    {
        printf("Library Full\n");
        return;
    }

    books[totalBooks].bookId = bookCounter++;

    printf("Enter Title: ");
    scanf("%49s", books[totalBooks].title);

    printf("Enter Author: ");
    scanf("%29s", books[totalBooks].author);

    printf("Enter Price: ");
    scanf("%f", &books[totalBooks].price);

    totalBooks++;
}

void displayBooks()
{
    int i;

    if (totalBooks == 0)
    {
        printf("No books available.\n");
        return;
    }

    for (i = 0; i < totalBooks; i++)
    {
        printf("\nBook ID : %d", books[i].bookId);
        printf("\nTitle   : %s", books[i].title);
        printf("\nAuthor  : %s", books[i].author);
        printf("\nPrice   : %.2f\n", books[i].price);
    }
}

void issueBook()
{
    int id, i;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < totalBooks; i++)
    {
        if (books[i].bookId == id)
        {
            books[i].price -= 10;
            printf("Book Issued.\n");
            return;
        }
    }

    printf("Book not found.\n");
}

void returnBook()
{
    int id, i;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < totalBooks; i++)
    {
        if (books[i].bookId == id)
        {
            books[i].price += 10;
            printf("Book Returned.\n");
            return;
        }
    }

    printf("Book not found.\n");
}

void generateReport()
{
    if (totalBooks == 0)
    {
        printf("No books available.\n");
        return;
    }

    float highest = books[0].price;
    float lowest = books[0].price;
    float totalPrice = 0;

    int i;

    for (i = 0; i < totalBooks; i++)
    {
        totalPrice += books[i].price;

        if (books[i].price > highest)
            highest = books[i].price;

        if (books[i].price < lowest)
            lowest = books[i].price;
    }

    printf("Highest Price = %.2f\n", highest);
    printf("Lowest Price = %.2f\n", lowest);
    printf("Average Price = %.2f\n", totalPrice / totalBooks);
    printf("Total Books = %d\n", totalBooks);
}

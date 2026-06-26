
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    int rollNo;
    char name[20];
    float marks;
};

struct Student students[5];
int totalStudents = 0;

void addStudent();
void displayStudents();
float calculateAverage();
void generateReport();

int main()
{
    int choice;

    printf("Student Management System\n");

    while (1)
    {
        printf("\n1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Average Marks\n");
        printf("4. Report\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            printf("Average = %.2f\n", calculateAverage());
            break;

        case 4:
            generateReport();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

void addStudent()
{
    if (totalStudents >= 5)
    {
        printf("Database Full\n");
        return;
    }

    students[totalStudents].rollNo = totalStudents + 1;

    printf("Enter Name: ");
    scanf("%19s", students[totalStudents].name);

    printf("Enter Marks: ");
    scanf("%f", &students[totalStudents].marks);

    totalStudents++;
}

void displayStudents()
{
    int i;

    for (i = 0; i < totalStudents; i++)
    {
        printf("\nRoll No : %d\n", students[i].rollNo);
        printf("Name : %s\n", students[i].name);
        printf("Marks : %.2f\n", students[i].marks);
    }
}

float calculateAverage()
{
    if (totalStudents == 0)
        return 0.0;

    float total = 0;
    int i;

    for (i = 0; i < totalStudents; i++)
    {
        total += students[i].marks;
    }

    return total / totalStudents;
}

void generateReport()
{
    if (totalStudents == 0)
    {
        printf("No student data available.\n");
        return;
    }

    float highest = students[0].marks;
    float lowest = students[0].marks;

    int i;

    for (i = 1; i < totalStudents; i++)
    {
        if (students[i].marks > highest)
            highest = students[i].marks;

        if (students[i].marks < lowest)
            lowest = students[i].marks;
    }

    printf("Highest = %.2f\n", highest);
    printf("Lowest = %.2f\n", lowest);
    printf("Total Students = %d\n", totalStudents);
}

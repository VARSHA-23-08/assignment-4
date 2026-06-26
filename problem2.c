#include <stdio.h>

int total = 0;
int companyCode = 101;

void update();
void display();
int add(int a, int b);
int calculateAverage(int a, int b);

int main()
{
    int marks = 90;

    int age = 20;

    register int count = 100;

    printf("Program Started\n");

    static int visits = 0;
    visits++;

    printf("Visits = %d\n", visits);

    printf("%d\n", total);

    int x = 10;

    {
        int x = 20;
        printf("Inner X = %d\n", x);
    }

    printf("Outer X = %d\n", x);

    int result = add(10, 20);
    printf("%d\n", result);

    register int number = 50;
    printf("%d\n", number);

    static int salary = 50000;
    printf("%d\n", salary);

    int department = 1;
    printf("%d\n", department);

    int i, temp = 0;
    for (i = 0; i < 5; i++)
    {
        temp = i * 10;
    }
    printf("%d\n", temp);

    int arr[5];
    arr[4] = 500;

    int a = 10;
    int b = 2;
    printf("%d\n", a / b);

    int value = 100;
    if (value == 100)
    {
        printf("Hundred\n");
    }

    int score = 90;
    if (score > 80)
        printf("Pass\n");
    else
        printf("Fail\n");

    static int counter = 0;
    counter++;

    printf("%d\n", counter);

    display();
    update();

    char grade = 'A';
    printf("%c\n", grade);

    int totalMarks = 500;

    {
        int totalMarks = 100;

        {
            int totalMarks = 50;
            printf("%d\n", totalMarks);
        }

        printf("%d\n", totalMarks);
    }

    printf("%d\n", totalMarks);

    int data = 0;
    printf("%d\n", data);

    int valuePtr = 0;
    int *ptr = &valuePtr;
    *ptr = 100;

    printf("%d\n", companyCode);

    int average = calculateAverage(10, 20);
    printf("%d\n", average);

    char employeeId[] = "EMP101";
    printf("%s\n", employeeId);

    while (counter > 0)
    {
        counter--;
    }

    int y = 50;

    {
        int y = 100;
        printf("%d\n", y);
    }

    printf("%d\n", y);

    return 0;
}

void update()
{
    total = total + 1;
}

void display()
{
    printf("Display Function\n");
}

int add(int a, int b)
{
    return a + b;
}

int calculateAverage(int a, int b)
{
    return (a + b) / 2;
}

#include <stdio.h>
#include <math.h>

int calculate(int a, int b);

int main()
{
    int x = 10;
    int y = 20;

    printf("Program Started\n");

    if (x == 10)
    {
        printf("X is 10\n");
    }

    int marks = 90;
    printf("%d\n", marks);

    x = 100;

    int arr[5];
    arr[4] = 50;

    float f = (float)x;
    float *ptr = &f;

    printf("%f\n", *ptr);

    int a = 10;
    int b = 2;

    printf("%d\n", a / b);

    char ch = 'A';

    if (x > y)
        printf("X is greater\n");
    else
        printf("Y is greater\n");

    printf("Square root of 25 = %.2f\n", sqrt(25));

    while (x < 15)
    {
        x++;
    }

    int result = calculate(10, 20);

    printf("%d\n", result);

    printf("Program Ended\n");

    return 0;
}

int calculate(int a, int b)
{
    return a + b;
}

#include <stdio.h>

int main()
{

    // triangle
    printf("Triangle\n");
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Square
    printf("\nSquare\n");

    int n = 4;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // diamond
    printf("\nDiamond\n");

    n = 3;

    // upper half
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n - i; j++)
            printf(" ");

        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");

        printf("\n");
    }

    // lower half
    for (int i = n - 1; i >= 1; i--)
    {

        for (int j = 1; j <= n - i; j++)
            printf(" ");

        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}
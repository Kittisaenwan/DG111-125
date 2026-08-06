#include <stdio.h>

int main()
{

    int rows = 3;
    int cols = 5;
    int count = 1;

    for (int i = 0; i < rows; i++)
    {

        // top border
        for (int j = 0; j < cols; j++)
        {
            printf("+---");
        }
        printf("+\n");

        // numbers
        printf("|");
        for (int j = 0; j < cols; j++)
        {
            printf("%2d |", count);
            count++;
        }
        printf("\n");
    }

    // bottom border
    for (int j = 0; j < cols; j++)
    {
        printf("+---");
    }
    printf("+\n");

    return 0;
}
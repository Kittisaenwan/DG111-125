#include <stdio.h>

int main()
{
    int sum;

    // วิธีที่ 1 for loop
    sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", i);
        sum += i;
    }
    printf("\nSum = %d\n\n", sum);

    // วิธีที่ 2 while loop
    sum = 0;
    int i = 1;

    while (i <= 10)
    {
        printf("%d ", i);
        sum += i;
        i++;
    }
    printf("\nSum = %d\n\n", sum);

    // วิธีที่ 3 do-while loop
    sum = 0;
    i = 1;

    do
    {
        printf("%d ", i);
        sum += i;
        i++;
    } while (i <= 10);

    printf("\nSum = %d\n", sum);

    return 0;
}
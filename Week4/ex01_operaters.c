#include <math.h>
#include <stdio.h>
int main()
{
    int a = 10 / 3;
    float b = 10.0 / 3;
    float c = (float)10 / 3;
    int d = 10 % 3;
    int e = -7 % 3;
    int f = 7 % -3;

    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);
    printf("d = %d\n", d);
    printf("e = %d\n", e);
    printf("f = %d\n", f);

    int x = 5;
    printf("x++ = %d\n", x++);
    printf("x = %d\n", x);
    x = 5;
    printf("++x = %d\n", ++x);
    printf("x = %d\n", x);

    printf("2 + 3 * 4 = %d\n", 2 + 3 * 4);
    printf("(2 + 3) * 4 = %d\n", (2 + 3) * 4);
    printf("10 - 2 - 3 = %d\n", 10 - 2 - 3);
    printf("2*3 + 4*5 = %d\n", 2 * 3 + 4 * 5);

    return 0;
}

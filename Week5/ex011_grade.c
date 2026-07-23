#include <stdio.h>
int main()
{
    int grade;
    printf("Enter your grade: ");
    scanf("%d", &grade);

    if (grade >= 80)
    {
        printf("You got an A! (4.0 GPA)-pass\n");
    }
    else if (grade >= 75)
    {
        printf("You got a B+! (3.5 GPA) -pass\n");
    }
    else if (grade >= 70)
    {
        printf("You got a B! (3.0 GPA) -pass\n");
    }
    else if (grade >= 65)
    {
        printf("You got a C+! (2.5 GPA) -pass\n");
    }
    else if (grade >= 60)
    {
        printf("You got a C! (2.0 GPA) -pass\n");
    }
    else if (grade >= 55)
    {
        printf("You got a D+! (1.5 GPA) -pass\n");
    }
    else if (grade >= 50)
    {
        printf("You got a D! (1.0 GPA) -pass\n");
    }
    else
    {
        printf("You got an F! (0.0 GPA) -failed\n");
    }

    return 0;
}
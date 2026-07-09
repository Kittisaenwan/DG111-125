#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    printf("=== Enter Data ===\n");
    char name[100];
    int age;
    float gpa;
    char fav_subject[100];

    printf("Name: ");
    scanf("%s", name);

    printf("Age: ");
    scanf("%d", &age);

    printf("GPA: ");
    scanf("%f", &gpa);

    printf("Favorite Subject: ");
    scanf("%s", fav_subject);

    printf("=== Personal Info card ===\n");
    printf("┌─────────────────────────┐ \n");
    printf("│ Name: %s                │\n", name);
    printf("│ Age: %d Years old    │\n", age);
    printf("│ GPA: %.2f               │\n", gpa);
    printf("│ Favorite Subject: %s     │\n", fav_subject);
    printf("└─────────────────────────┘ \n");

    return 0;
}
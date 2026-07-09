#include <stdio.h>
int main()
{

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

    // แสดงข้อมูลที่ป้อน
    printf("\n=== Personal Information ===\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Favorite Subject: %s\n", fav_subject);

    return 0;
}
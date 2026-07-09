#include <stdio.h>
int main()
{

    printf("=== Enter Data ===\n");
    char Character_name[100];
    int Max_HP[250];
    int Attack_power[75];
    int Defence[100];
    int level[100];

    printf("Name: ");
    scanf("%s", Character_name);

    printf("Max HP: ");
    scanf("%d", &Max_HP[0]);

    printf("Attack Power: ");
    scanf("%d", &Attack_power[0]);

    printf("Defence: ");
    scanf("%d", &Defence[0]);

    printf("Level: ");
    scanf("%d", &level[0]);

    printf("\n=== Character Status ===\n");
    printf("NAME      : %s\n", Character_name);
    printf("HP        : %d\n", Max_HP[0]);
    printf("ATK       : %d\n", Attack_power[0]);
    printf("DEF       : %d\n", Defence[0]);
    printf("LVL       : %d\n", level[0]);

    return 0;
}
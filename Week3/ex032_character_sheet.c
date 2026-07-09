#include <stdio.h>
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    printf("=== Create Character ===\n");

    char char_name[100];
    int max_hp;
    int atk;
    int def;
    int level;

    printf("Character Name : ");
    scanf("%s", char_name);

    printf("Max HP : ");
    scanf("%d", &max_hp);

    printf("Attack Power : ");
    scanf("%d", &atk);

    printf("Defense Power : ");
    scanf("%d", &def);

    printf("Level : ");
    scanf("%d", &level);

    int power_score = (atk * 2 + def + max_hp / 10);

    printf("===  CHARACTER SHEET ===\n");
    printf("╔═════════════════════════════════════════════╗\n");
    printf("╠ %-10s : %-25s      ║\n", "Name", char_name);
    printf("╠═════════════════════════════════════════════╣\n");
    printf("║ %-10s : %-25d      ║\n", "Level", level);
    printf("║ %-10s : %d/%-25d   ║\n", "HP ", max_hp, max_hp);
    printf("║ %-10s : %-25d      ║\n", "Attack", atk);
    printf("║ %-10s : %-25d      ║\n", "Defense", def);
    printf("╠═════════════════════════════════════════════╣\n");
    printf("║ HP BAR : [ [████████████████████] 100%      ║\n");
    printf("║ %-10s : %-24d      ║\n", "Power Score", power_score);
    printf("╚═════════════════════════════════════════════╝\n");

    return 0;
}
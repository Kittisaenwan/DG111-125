#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int max_hp;
    int damage;
    int poisoned_input;
    _Bool is_poisoned;
    int attack_count;
    int hp;
    int filled;

    // Input
    printf("Max HP: ");
    scanf("%d", &max_hp);

    printf("Damage Taken: ");
    scanf("%d", &damage);

    printf("Poisoned (0/1): ");
    scanf("%d", &poisoned_input);
    is_poisoned = poisoned_input;

    printf("Attack Count: ");
    scanf("%d", &attack_count);

    // Calculate HP
    hp = max_hp - damage;
    if (hp < 0)
    {
        hp = 0;
    }

    printf("=== Character Status ===\n");

    // HP Bar (Challenge)
    filled = hp * 10 / max_hp;

    printf("HP : [");
    for (int i = 0; i < 10; i++)
    {
        if (i < filled)
            printf("█");
        else
            printf("-");
    }
    printf("] %d/%d", hp, max_hp);

    // State
    if (hp <= 0)
    {
        printf("\nState: DEAD\n");
    }
    else if (hp * 100 < max_hp * 25)
    {
        printf(" CRITICAL!");
        printf("\nState: CRITICAL\n");
    }
    else if (is_poisoned)
    {
        printf("\nState: POISONED\n");
    }
    else
    {
        printf("\nState: NORMAL\n");
    }

    // Ultimate
    if (attack_count > 0 && attack_count % 5 == 0)
    {
        printf("Ultimate Ready! (Attack #%d)\n", attack_count);
    }

    return 0;
}

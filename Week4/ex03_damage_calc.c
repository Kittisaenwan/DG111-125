#include <math.h>
#include <stdio.h>
int main(void)
{
    int damage;
    int attack;
    int enemy_defense;
    int hit_number;

    printf("=== Damage calculator ===\n");
    printf("Enter the attack value: ");
    scanf("%d", &attack);
    printf("Enter the enemy defense value: ");
    scanf("%d", &enemy_defense);
    printf("Enter the Hit number value: ");
    scanf("%d", &hit_number);
    printf("Enter the Damage value: ");
    scanf("%d", &damage);

    int base_damage = attack - enemy_defense;
    int critical_hit = hit_number % 5 == 0;
    int critical_damage = (int)ceil((float)base_damage * 1.5f);

    if (critical_hit)
    {
        printf("Critical hit! Damage dealt: %d\n", critical_damage);
    }
    else
    {
        printf("Damage dealt: %d\n", base_damage);
    }

    return 0;
}
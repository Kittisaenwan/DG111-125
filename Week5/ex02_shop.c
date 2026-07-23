#include <stdio.h>

int main()
{
    int gold = 900;
    int choice;
    int price = 0;
    int swordBought = 0;
    int armorBought = 0;

    printf("=== ITEM SHOP ===\n");
    printf("Gold: %d\n\n", gold);

    printf("1. Health Potion  -  50 Gold (+50 HP)\n");
    printf("2. Mana Potion    -  80 Gold (+30 MP)\n");
    printf("3. Iron Sword     - 500 Gold (+20 ATK)\n");
    printf("4. Leather Armor  - 300 Gold (+15 DEF)\n");
    printf("5. Exit\n\n");

    // Buy 2 items
    for (int i = 0; i < 2; i++)
    {

        printf("Select item: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            price = 50;

            if (gold < price)
            {
                printf("Not enough Gold!\n\n");
                break;
            }

            gold -= price;
            printf("\n=== Purchase ===\n");
            printf("Health Potion: %d Gold\n", price);
            printf("Remaining: %d Gold\n", gold);
            printf("HP Bonus: +50\n\n");
            break;

        case 2:
            price = 80;

            if (gold < price)
            {
                printf("Not enough Gold!\n\n");
                break;
            }

            gold -= price;
            printf("\n=== Purchase ===\n");
            printf("Mana Potion: %d Gold\n", price);
            printf("Remaining: %d Gold\n", gold);
            printf("MP Bonus: +30\n\n");
            break;

        case 3:
            price = 500;

            // Bundle discount
            if (armorBought)
            {
                price = price - (price * 10 / 100);
                printf("Warrior Bundle! 10%% Discount\n");
            }

            if (gold < price)
            {
                printf("Not enough Gold!\n\n");
                break;
            }

            gold -= price;
            swordBought = 1;

            printf("\n=== Purchase ===\n");
            printf("Iron Sword: %d Gold\n", price);
            printf("Remaining: %d Gold\n", gold);
            printf("ATK Bonus: +20\n\n");
            break;

        case 4:
            price = 300;

            if (swordBought)
            {
                price = price - (price * 10 / 100);
                printf("Warrior Bundle! 10%% Discount\n");
            }

            if (gold < price)
            {
                printf("Not enough Gold!\n\n");
                break;
            }

            gold -= price;
            armorBought = 1;

            printf("\n=== Purchase ===\n");
            printf("Leather Armor: %d Gold\n", price);
            printf("Remaining: %d Gold\n", gold);
            printf("DEF Bonus: +15\n\n");
            break;

        case 5:
            printf("Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice!\n\n");
        }
    }

    // Logical operator &&
    if (swordBought && armorBought)
    {
        printf("You own the Warrior Bundle!\n");
    }

    return 0;
}
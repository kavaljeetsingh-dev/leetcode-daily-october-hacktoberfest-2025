#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int skill;
    int mana;
} Potion;

int cmp(const void *a, const void *b) {
    return ((Potion*)a)->skill - ((Potion*)b)->skill;
}

int min_time_to_brew_potions(int skill[], int mana[], int n) {
    Potion potions[n];
    for (int i = 0; i < n; i++) {
        potions[i].skill = skill[i];
        potions[i].mana = mana[i];
    }
    qsort(potions, n, sizeof(Potion), cmp);
    int total_time = 0, current_skill = 0;
    for (int i = 0; i < n; i++) {
        if (current_skill < potions[i].skill) {
            total_time += potions[i].skill - current_skill;
            current_skill = potions[i].skill;
        }
        total_time += potions[i].mana;
        current_skill += potions[i].skill;
    }
    return total_time;
}

int main() {
    int skill[] = {2, 3, 1};
    int mana[] = {5, 6, 4};
    int n = 3;
    printf("%d\n", min_time_to_brew_potions(skill, mana, n));
    return 0;
}

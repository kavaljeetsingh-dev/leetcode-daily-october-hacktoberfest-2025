#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a potion with skill requirement and mana cost
typedef struct {
    int skill;
    int mana;
} Potion;

// Comparison function for qsort — sorts potions by skill in ascending order
int cmp(const void *a, const void *b) {
    return ((Potion*)a)->skill - ((Potion*)b)->skill;
}

// Function to calculate the minimum total time required to brew all potions
int min_time_to_brew_potions(int skill[], int mana[], int n) {
    Potion potions[n]; // Create an array of Potion structs

    // Fill the potions array with skill and mana values
    for (int i = 0; i < n; i++) {
        potions[i].skill = skill[i];
        potions[i].mana = mana[i];
    }

    // Sort the potions by skill using qsort
    qsort(potions, n, sizeof(Potion), cmp);

    int total_time = 0;    // Total time required
    int current_skill = 0; // Current accumulated skill level

    // Iterate through each potion after sorting
    for (int i = 0; i < n; i++) {

        // If current skill is less than the potion's required skill,
        // spend extra time to reach that skill
        if (current_skill < potions[i].skill) {
            total_time += potions[i].skill - current_skill;
            current_skill = potions[i].skill;
        }

        // Brew the potion — adds mana (time cost)
        total_time += potions[i].mana;

        // Increase current skill after successfully brewing the potion
        current_skill += potions[i].skill;
    }

    // Return the total time after brewing all potions
    return total_time;
}

// Main function for testing
int main() {
    int skill[] = {2, 3, 1}; // Skill requirements for potions
    int mana[] = {5, 6, 4};  // Mana (time) cost for potions
    int n = 3;               // Number of potions

    // Print the result — total minimum time to brew all potions
    printf("%d\n", min_time_to_brew_potions(skill, mana, n));

    return 0;
}

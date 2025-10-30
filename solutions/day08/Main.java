import java.util.*;

// Main class
public class Main {

    // Inner class to represent a Potion with skill and mana requirements
    static class Potion {
        int skill, mana;
        Potion(int s, int m) {
            skill = s;
            mana = m;
        }
    }

    // Function to calculate minimum total time to brew all potions
    static int minTimeToBrewPotions(int[] skill, int[] mana) {
        int n = skill.length;

        // Create an array of Potion objects (pairing skill and mana)
        Potion[] potions = new Potion[n];
        for (int i = 0; i < n; i++)
            potions[i] = new Potion(skill[i], mana[i]);

        // Sort potions by their skill requirement in ascending order
        Arrays.sort(potions, Comparator.comparingInt(p -> p.skill));

        int totalTime = 0;      // Total time spent brewing potions
        int currentSkill = 0;   // Current accumulated skill

        // Iterate through each potion in sorted order
        for (Potion p : potions) {

            // If current skill is less than required, spend time to reach that skill
            if (currentSkill < p.skill) {
                totalTime += p.skill - currentSkill;
                currentSkill = p.skill;
            }

            // Brew the potion (costs mana time)
            totalTime += p.mana;

            // Increase current skill after brewing
            currentSkill += p.skill;
        }

        // Return the total time needed to brew all potions
        return totalTime;
    }

    // Main method for testing
    public static void main(String[] args) {
        int[] skill = {2, 3, 1};
        int[] mana = {5, 6, 4};

        // Output the result of the computation
        System.out.println(minTimeToBrewPotions(skill, mana));
    }
}

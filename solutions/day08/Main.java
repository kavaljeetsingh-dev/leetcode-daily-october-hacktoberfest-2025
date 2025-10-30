import java.util.*;

public class Main {
    static class Potion {
        int skill, mana;
        Potion(int s, int m) { skill = s; mana = m; }
    }

    static int minTimeToBrewPotions(int[] skill, int[] mana) {
        int n = skill.length;
        Potion[] potions = new Potion[n];
        for (int i = 0; i < n; i++) potions[i] = new Potion(skill[i], mana[i]);
        Arrays.sort(potions, Comparator.comparingInt(p -> p.skill));
        int totalTime = 0, currentSkill = 0;
        for (Potion p : potions) {
            if (currentSkill < p.skill) {
                totalTime += p.skill - currentSkill;
                currentSkill = p.skill;
            }
            totalTime += p.mana;
            currentSkill += p.skill;
        }
        return totalTime;
    }

    public static void main(String[] args) {
        int[] skill = {2, 3, 1};
        int[] mana = {5, 6, 4};
        System.out.println(minTimeToBrewPotions(skill, mana));
    }
}

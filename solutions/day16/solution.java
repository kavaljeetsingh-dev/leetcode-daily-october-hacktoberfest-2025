import java.util.*;

class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        int ans = 0;
        int[] count = new int[value];

        for (int num : nums) {
            int x = ((num % value) + value) % value;
            count[x]++;
        }

        while (count[ans % value] > 0) {
            count[ans % value]--;
            ans++;
        }

        return ans;
    }
}

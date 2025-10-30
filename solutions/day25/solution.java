class Solution {
    public int totalMoney(int n) {
        int[] week = {1, 2, 3, 4, 5, 6, 7};
        int k = 1; 
        int j = 0; 
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (i <= 6) {
                total += week[i];
            } else {
                total += week[j] + k;
                j++;
                if (j > 6) {
                    j = 0;
                    k++;
                }
            }
        }
        return total;
    }
}

class Solution {
    public String findLexSmallestString(String s, int a, int b) {
        int n = s.length();
        boolean[] vis = new boolean[n];
        String res = s;
        s = s + s;

        for (int i = 0; !vis[i]; i = (i + b) % n) {
            vis[i] = true;

            for (int j = 0; j < 10; j++) {
                int kLimit = (b % 2 == 0) ? 0 : 9;

                for (int k = 0; k <= kLimit; k++) {
                    char[] t = s.substring(i, i + n).toCharArray();

                    // Add 'a' to odd indices
                    for (int p = 1; p < n; p += 2) {
                        t[p] = (char) ('0' + (t[p] - '0' + j * a) % 10);
                    }

                    // Add 'a' to even indices if rotation makes them accessible
                    for (int p = 0; p < n; p += 2) {
                        t[p] = (char) ('0' + (t[p] - '0' + k * a) % 10);
                    }

                    String candidate = new String(t);
                    if (candidate.compareTo(res) < 0) {
                        res = candidate;
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findLexSmallestString("5525", 9, 2)); 
        System.out.println(sol.findLexSmallestString("74", 5, 1));   
        System.out.println(sol.findLexSmallestString("0011", 4, 2)); 
    }
}

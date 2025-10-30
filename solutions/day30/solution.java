class Solution {
    public int minNumberOperations(int[] target) {
        int operations = target[0]; 
       
        for (int i = 1; i < target.length; i++) {
            if (target[i] > target[i - 1]) {
                operations += target[i] - target[i - 1];
            }
        }
        
        return operations;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] testCases = {
            {1, 2, 3, 2, 1}, 
            {3, 1, 1, 2},    
            {3, 1, 5, 4, 2}  
        };
        for (int[] t : testCases) {
            System.out.println("Input: " + java.util.Arrays.toString(t) + 
                               " → Output: " + sol.minNumberOperations(t));
        }
    }
}

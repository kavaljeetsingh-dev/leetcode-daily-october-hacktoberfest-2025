class Solution {
    public int numberOfBeams(String[] bank) {
        int prevCount = 0;  
        int beams = 0;      
        for (String row : bank) {
            int currCount = 0;  
            for (char c : row.toCharArray()) {
                if (c == '1') currCount++;
            }
            if (currCount == 0) continue;
            beams += prevCount * currCount;
            prevCount = currCount;
        }

        return beams;
    }
}

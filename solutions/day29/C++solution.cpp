// Language used : C++
// 3370. Smallest Number With All Set Bits
// Time complexity: O(n log n)
// Space complexity: O(1)

class Solution {
public:
    int smallestNumber(int n) {

        // Loop indefinitely until we find the number with all bits set to 1
        while (true) {
            int a = n;
            bool allOnes = true;  // Flag to check if all bits are 1

            // Check each bit of 'a'
            while (a) {
                // If we find a 0 bit, then it's not all ones
                if ((a & 1) == 0) {
                    allOnes = false;
                    break;  // No need to check remaining bits
                }
                // Right shift 'a' to check the next bit
                a = a >> 1;
            }

            // If all bits were 1, return the number
            if (allOnes == true) {
                return n;
            }

            // Otherwise, check the next number
            n++;
        }
        return -1;
    }
};

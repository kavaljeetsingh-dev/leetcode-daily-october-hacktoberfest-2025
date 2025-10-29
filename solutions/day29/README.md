🧩 Problem Overview

Given an integer n, the goal is to find the smallest number greater than or equal to n whose binary representation contains only 1s (for example, 1 (1), 3 (11), 7 (111), 15 (1111), etc.).

💡 Approach / Solution Explanation

Start from the given number n.

For each number, check whether all bits in its binary form are 1:

Use bitwise AND (a & 1) to check the least significant bit.

If a 0 bit is found, stop checking that number.

Right shift (a >> 1) to move to the next bit.

If all bits are 1, return that number.

Otherwise, increment n and repeat.

This ensures the first number encountered with all bits set to 1 is returned.

⏱️ Complexity

Time Complexity: O((m - n) * log m) → worst case ≈ O(n log n)

Space Complexity: O(1)


Second Solution:
Problem Overview
 * ========================================
 * Given an integer n, the goal is to find the smallest number greater than 
 * or equal to n whose binary representation contains only 1s 
 * (for example, 1 (1), 3 (11), 7 (111), 15 (1111), etc.).
 * 
 * ========================================
 * 💡 Approach / Solution Explanation
 * ========================================
 * We use a mathematical formula to directly calculate the result:
 * 
 * 1. Find the number of bits needed to represent n:
 *    - Use log2(n) to find the position of the highest set bit
 *    - Add 1 to get the total bits needed for the next power of 2
 * 
 * 2. Calculate 2^k where k is the number of bits:
 *    - Use left shift operation: (1 << k) which equals 2^k
 * 
 * 3. Subtract 1 to get all bits set to 1:
 *    - 2^k - 1 gives us a number with k bits all set to 1
 * 
 * Example Walkthrough:
 * - Input: n = 5 (binary: 101)
 * - log2(5) = 2.32, int(2.32) = 2
 * - Bits needed: 2 + 1 = 3
 * - Calculate: (1 << 3) = 8 (binary: 1000)
 * - Result: 8 - 1 = 7 (binary: 111) ✓
 * 
 * Pattern of numbers with all bits set:
 * - 1 = 2^1 - 1 (binary: 1)
 * - 3 = 2^2 - 1 (binary: 11)
 * - 7 = 2^3 - 1 (binary: 111)
 * - 15 = 2^4 - 1 (binary: 1111)
 * - 31 = 2^5 - 1 (binary: 11111)
 * 
 * ========================================
 * ⏱️ Complexity
 * ========================================
 * Time Complexity: O(1)
 * - log2() operation is constant time
 * - Bit shift and arithmetic operations are constant time
 * - No loops or iterations needed
 * 
 * Space Complexity: O(1)
 * - Only using a fixed number of variables
 * - No extra data structures or dynamic memory allocation
 * ========================================

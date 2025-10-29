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
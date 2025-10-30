pub struct Solution;

impl Solution {
    /// Returns the minimum number of operations to form a target array from an array of zeros.
    /// In one operation, you can choose any subarray and increment each value by one.
    pub fn min_number_operations(target: Vec<i32>) -> i32 {
        let n = target.len();

        // The number of operations is determined by the total "increase" in height
        // across the array, starting from zero.

        // 1. The first element (target[0]) must be built up from 0, which requires exactly target[0] operations.
        let mut ans = target[0];

        // 2. Iterate through the rest of the array, comparing each element to its predecessor.
        for i in 1..n {
            // We only add the positive difference (the increase).
            ans += (target[i] - target[i - 1]).max(0);
        }
        ans
    }
}

fn main() {
    let test_cases = vec![
        (vec![1, 2, 3, 2, 1], 3), // Output: 3
        (vec![3, 1, 1, 2], 4),    // Output: 4
        (vec![3, 1, 5, 4, 2], 7), // Output: 7
    ];

    println!("--- Minimum Number of Operations ---");
    for (target, expected) in test_cases {
        let result = Solution::min_number_operations(target.clone());
        println!(
            "Input: {:?}, Output: {}, Expected: {}",
            target, result, expected
        );
        assert_eq!(result, expected);
    }
}

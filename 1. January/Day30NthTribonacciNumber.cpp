/**
 * @file Day30NthTribonacciNumber.cpp
 * @author Ginny Dang
 * @brief 1137. N-th Tribonacci Number (https://leetcode.com/problems/n-th-tribonacci-number/description/)
 * @version 0.1
 * @date 2023-01-29
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int tribonacci(int n)
    {
        // Edge case handling
        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;

        // Normal case
        int prev3 = 0; // n-3
        int prev2 = 1; // n-2
        int prev1 = 1; // n-1
        int tribonacciSum = 0;

        for (int i = 3; i <= n; i++)
        {
            tribonacciSum = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = tribonacciSum;
        }

        return tribonacciSum;
    }
};

// Time Complexity: O(1) or O(35) to be exact
// Space Complexity: O(1)
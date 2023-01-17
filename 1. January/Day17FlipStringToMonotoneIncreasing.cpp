/**
 * @file Day17FlipStringToMonotoneIncreasing.cpp
 * @author Ginny Dang
 * @brief 926. Flip String to Monotone Increasing (https://leetcode.com/problems/flip-string-to-monotone-increasing/description/)
 * @version 0.1
 * @date 2023-01-16
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New idea learned from the Official Solution
 * Approach 1: Dynamic Windows
 * - Consider the 2 substrings as 2 windows on the original string
 * -- Initially, the left window is empty and the right window contains the whole original string.
 * -- At each step, the left window's size increases by one and the right window's size decreases by 1.
 *    We want to change all the characters in the left window into '0' and all the characters in the right window into '1'.
 * - We enumerate each left-right window configuration,
 *   the number of flips to make the string monotone increasing is the sum of the number of '1's in the left window and the number of '0's in the right window.
 * - Save the smallest value.
 */

/**
 * @brief Algorithm learned from the Official Solution
 * - Count the number of '0's in string s.
 * - Let m, which is the number of flips needed when the left window is empty and the right window is the whole string, be the above value.
 * - Set result = m.
 * - Scan the input string 's' again
 * -- For each character '0', decrease m by 1 and replace result with m if m is smaller.
 * -- For each character '1', increase m by 1.
 * - Return result.
 */

class Solution1
{
public:
    int minFlipsMonoIncr(string s)
    {
        int m = 0; // the number of flips needed when the left window is empty and the right window is the whole string
        for (char c : s)
            if (c == '0')
                m++;

        int result = m;
        for (char c : s)
        {
            if (c == '0')
            {
                m--;
                result = min(result, m);
            }
            else
                m++;
        }
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * @brief New idea learned from the Official Solution
 * Approach 2: Dynamic Programming
 * - Let dp[i] represent the minimum number of flips to make the prefix of s of length i
 * - Set the base case dp[0] = 0
 * - Let num1s be the number of 1's from the begining of the string to right before i
 * - For each step i in the range [1, s.length()]
 * -- If s[i - 1] = 1 -> Min num of flips is 0 and num1s increments
 * -- If s[i - 1] = 0
 * --- If we don't flip s[i] -> Need to flips all num1s 1's before as well
 * --- If we flip s[i] -> dp[i] = dp[i - 1] + 1
 * - Return dp[s.length()]
 */

/**
 * @brief Naive implementation
 */

class Solution2
{
public:
    int minFlipsMonoIncr(string s)
    {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 0;
        int num1s = s[0] == 1 ? 1 : 0; // the number of character 1s in so far
        for (int i = 1; i <= s.length(); i++)
        {
            if (s[i - 1] == '1')
            {
                dp[i] = dp[i - 1];
                num1s++;
            }
            else
                dp[i] = min(num1s, dp[i - 1] + 1);
        }
        return dp[s.length()];
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

/**
 * @brief Optimized implementation with no extra space
 */

class Solution3
{
public:
    int minFlipsMonoIncr(string s)
    {
        int minFlips = 0;
        int num1s = s[0] == 1 ? 1 : 0; // the number of character 1s in so far

        for (int i = 1; i <= s.length(); i++)
        {
            if (s[i - 1] == '1')
                num1s++;
            else
                minFlips = min(num1s, minFlips + 1);
        }

        return minFlips;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

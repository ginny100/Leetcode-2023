/**
 * @file Day14LongestPalindromicSubsequence.cpp
 * @author Ginny Dang
 * @brief 516. Longest Palindromic Subsequence (https://leetcode.com/problems/longest-palindromic-subsequence/description/)
 * @version 0.1
 * @date 2023-04-13
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
private:
    int topDownDp(string &s, int left, int right, vector<vector<int>> &lps)
    {
        if (lps[left][right] != 0)
            return lps[left][right];

        if (left == right)
            lps[left][right] = 1;
        else if (right - left == 1)
        {
            if (s[left] == s[right])
                lps[left][right] = 2;
            else
                lps[left][right] = 1;
        }
        else if (left < right)
        {
            if (s[left] != s[right])
                lps[left][right] = max(topDownDp(s, left + 1, right, lps), topDownDp(s, left, right - 1, lps));
            else
                lps[left][right] = 2 + topDownDp(s, left + 1, right - 1, lps);
        }

        return lps[left][right];
    }

public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> lps(n, vector<int>(n));
        return topDownDp(s, 0, n - 1, lps);
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
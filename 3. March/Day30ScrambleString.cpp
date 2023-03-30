/**
 * @file Day30ScrambleString.cpp
 * @author Ginny Dang
 * @brief 87. Scramble String (https://leetcode.com/problems/scramble-string/description/)
 * @version 0.1
 * @date 2023-03-30
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        vector dp(n + 1, vector(n, vector<int>(n)));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[1][i][j] = s1[i] == s2[j];

        for (int length = 2; length < n + 1; length++)
            for (int i = 0; i < n + 1 - length; i++)
                for (int j = 0; j < n + 1 - length; j++)
                    for (int newLength = 1; newLength < length; newLength++)
                        if ((dp[newLength][i][j] && dp[length - newLength][i + newLength][j + newLength]) || (dp[newLength][i][j + length - newLength] && dp[length - newLength][i + newLength][j]))
                            dp[length][i][j] = true;

        return dp[n][0][0];
    }
};

// Time complexity: O(n^4)
// Space complexity: O(n^3)
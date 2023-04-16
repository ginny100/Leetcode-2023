/**
 * @file Day16NumberOfWaysToFormATargetStringGivenADictionary.cpp
 * @author Ginny Dang
 * @brief 1639. Number of Ways to Form a Target String Given a Dictionary (https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/)
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        const int alphabet = 26;
        const int mod = 1e9 + 7;

        int m = target.size();
        int k = words[0].size();

        vector<vector<int>> count(alphabet, vector<int>(k));
        for (int i = 0; i < k; i++)
            for (const string &word : words)
                count[word[i] - 'a'][i]++;

        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i < m)
                {
                    dp[i + 1][j + 1] += count[target[i] - 'a'][j] * dp[i][j];
                    dp[i + 1][j + 1] %= mod;
                }
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= mod;
            }
        }

        return dp[m][k];
    }
};

// Time Complexity: O(n * k + m * k)
// Space Complexity: O(m * k) or O(26k + m * k) to be exact
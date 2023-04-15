/**
 * @file Day15MaximumValueOfKCoinsFromPiles.cpp
 * @author Ginny Dang
 * @brief 2218. Maximum Value of K Coins From Piles (https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/)
 * @version 0.1
 * @date 2023-04-14
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));

        for (int i = 1; i <= n; i++)
        {
            for (int coins = 0; coins <= k; coins++)
            {
                int currSum = 0;
                for (int currCoins = 0; currCoins <= min((int)piles[i - 1].size(), coins); currCoins++)
                {
                    if (currCoins > 0)
                        currSum += piles[i - 1][currCoins - 1];
                    dp[i][coins] = max(dp[i][coins], dp[i - 1][coins - currCoins] + currSum);
                }
            }
        }

        return dp[n][k];
    }
};

// Time Complexity: O(k * s)
// Space Complexity: O(n * k)
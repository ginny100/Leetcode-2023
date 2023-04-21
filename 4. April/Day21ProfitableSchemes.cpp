/**
 * @file Day21ProfitableSchemes.cpp
 * @author Ginny Dang
 * @brief 879. Profitable Schemes (https://leetcode.com/problems/profitable-schemes/description/)
 * @version 0.1
 * @date 2023-04-20
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
private:
    int mod = 1e9 + 7;
    int memo[101][101][101];

    int find(int pos, int count, int profit, int n, int minProfit, vector<int> &group, vector<int> &profits)
    {
        if (pos == group.size())
            return profit >= minProfit;

        if (memo[pos][count][profit] != -1)
            return memo[pos][count][profit];

        int numWays = find(pos + 1, count, profit, n, minProfit, group, profits);
        if (count + group[pos] <= n)
            numWays += find(pos + 1, count + group[pos], min(minProfit, profit + profits[pos]), n, minProfit, group, profits);

        return memo[pos][count][profit] = numWays % mod;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        memset(memo, -1, sizeof(memo));
        return find(0, 0, 0, n, minProfit, group, profit);
    }
};

// Time Complexity: O(N * M * K)
// Space Complexity: O(N * M * K)
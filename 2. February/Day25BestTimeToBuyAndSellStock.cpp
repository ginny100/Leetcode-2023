/**
 * @file Day25BestTimeToBuyAndSellStock.cpp
 * @author Ginny Dang
 * @brief 121. Best Time to Buy and Sell Stock (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)
 * @version 0.1
 * @date 2023-02-24
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> profit(n, vector(3, INT_MAX));

        for (int i = 0; i < n; i++)
        {
            // No sell or buy
            profit[i][0] = 0;
            // Buy
            if (i == 0)
                profit[i][1] = prices[i];
            else
                profit[i][1] = min(profit[i - 1][1], prices[i]);
            // Sell after buy
            if (i == 0)
                profit[i][2] = 0;
            else
                profit[i][2] = max(prices[i] - profit[i][1], profit[i - 1][2]);
        }

        return profit[n - 1][2];
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
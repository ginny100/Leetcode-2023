/**
 * @file Day28MinimumCostForTickets.cpp
 * @author Ginny Dang
 * @brief 983. Minimum Cost For Tickets (https://leetcode.com/problems/minimum-cost-for-tickets/description/)
 * @version 0.1
 * @date 2023-03-27
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> memo(n, -1);
        int durations[] = {1, 7, 30};

        return calcCost(n, 0, days, costs, memo, durations);
    }

    int calcCost(int &n, int i, vector<int> &days, vector<int> &costs, vector<int> &memo, int (&durations)[3])
    {
        if (i >= n)
            return 0;
        if (memo[i] != -1)
            return memo[i];

        int ans = INT_MAX;
        int j = i;
        for (int k = 0; k < 3; k++)
        {
            while (j < n && days[j] < days[i] + durations[k])
                j++;
            ans = min(ans, calcCost(n, j, days, costs, memo, durations) + costs[k]);
        }

        memo[i] = ans;
        return ans;
    }
};

// Time Complexity: O(N) where N is the number of unique days
// Space Complexity: O(N)
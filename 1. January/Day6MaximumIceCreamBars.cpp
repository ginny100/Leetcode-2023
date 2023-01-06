/**
 * @file Day6MaximumIceCreamBars.cpp
 * @author Ginny Dang
 * @brief 1833. Maximum Ice Cream Bars (https://leetcode.com/problems/maximum-ice-cream-bars/description/)
 * @version 0.1
 * @date 2023-01-05
 *
 * @copyright Copyright (c) 2023
 *
 */

// As the input array's element's range is not very large, we can use counting sort.

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> counts(maxCost + 1, 0);
        for (int cost : costs)
            counts[cost]++;

        int bars = 0;
        int total = 0;
        int count = 0; // keep track of the number of bars we can buy for each cost with our remaining money
        for (int cost = 1; cost < counts.size(); cost++)
        {
            if (counts[cost] == 0)
                continue;
            if (cost > coins)
                break;
            // Either we can pick all ice creams of 'cost' or we will be limited by remaining 'coins'.
            count = min(counts[cost], coins / cost);
            coins -= count * cost;
            bars += count;
        }
        return bars;
    }
};

// Time complexity: O(N + M) where N is the length of the input array, and M is the maximum element in it.
// Space complexity: O(M)
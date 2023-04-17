/**
 * @file Day17KidsWithTheGreatestNumberOfCandies.cpp
 * @author Ginny Dang
 * @brief 1431. Kids With the Greatest Number of Candies (https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/)
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int n = candies.size();
        vector<bool> result(n, false);

        int maxCandies = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < n; i++)
            if (candies[i] + extraCandies >= maxCandies)
                result[i] = true;

        return result;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
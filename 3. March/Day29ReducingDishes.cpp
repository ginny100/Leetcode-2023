/**
 * @file Day29ReducingDishes.cpp
 * @author Ginny Dang
 * @brief 1402. Reducing Dishes (https://leetcode.com/problems/reducing-dishes/description/)
 * @version 0.1
 * @date 2023-03-29
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        int curr = 0;
        int currSumA = 0;
        for (int i = 0; i < n; i++)
        {
            curr += satisfaction[i] * (i + 1);
            currSumA += satisfaction[i];
        }

        int result = curr;
        for (int i = 0; i < n - 1; i++)
        {
            int next = curr - currSumA;
            result = max(result, next);
            curr = next;
            currSumA -= satisfaction[i];
        }

        result = max(result, 0);
        return result;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
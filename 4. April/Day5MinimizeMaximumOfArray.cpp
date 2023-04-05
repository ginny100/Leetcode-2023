/**
 * @file Day5MinimizeMaximumOfArray.cpp
 * @author Ginny Dang
 * @brief 2439. Minimize Maximum of Array (https://leetcode.com/problems/minimize-maximum-of-array/description/)
 * @version 0.1
 * @date 2023-04-04
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        long long prefixSum = 0;

        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];
            ans = max(ans, (prefixSum + i) / (i + 1));
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
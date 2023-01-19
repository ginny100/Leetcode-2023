/**
 * @file Day19SubarraySumsDivisibleByK.cpp
 * @author Ginny Dang
 * @brief 974. Subarray Sums Divisible by K (https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)
 * @version 0.1
 * @date 2023-01-18
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int result = 0;
        int n = nums.size();
        int prefixMod = 0; // the remainder when the sum of the elements of a subarray that start from index 0 is divided by k
        vector<int> modGroups(k, 0);

        modGroups[0] = 1;

        for (int i = 0; i < n; i++)
        {
            prefixMod = (prefixMod + nums[i] % k + k) % k;
            result += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }

        return result;
    }
};

// Time Complexity: O(n + k)
// Space Complexity: O(k)
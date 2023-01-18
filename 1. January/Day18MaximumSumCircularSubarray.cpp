/**
 * @file Day18MaximumSumCircularSubarray.cpp
 * @author Ginny Dang
 * @brief 918. Maximum Sum Circular Subarray (https://leetcode.com/problems/maximum-sum-circular-subarray/description/)
 * @version 0.1
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Idea
 * - 2 types of subarrays
 * -- Type 1: Subarray in the middle
 * -- Type 2: Subarray split across
 * - Find the max sum subarray in the middle
 * - Find the max sum subarray split across
 * -- Find the min sum subarray in the middle
 * --- In [0, len(nums) - 1]
 * --- In [1, len(nums)]
 * -- sum(nums) - min_sum
 * -> Finalize the max sum
 */

class Solution
{
public:
    int maxSubarraySum(vector<int> &nums)
    {
        int maxSum = nums[0];
        int maxSoFar = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            maxSoFar = max(maxSoFar + nums[i], nums[i]);
            maxSum = max(maxSum, maxSoFar);
        }

        return maxSum;
    }

    int minSubarraySum(vector<int> &nums, int start, int end)
    {
        int minSum = nums[start];
        int minSoFar = nums[start];

        for (int i = start + 1; i <= end; i++)
        {
            minSoFar = min(minSoFar + nums[i], nums[i]);
            minSum = min(minSum, minSoFar);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        // Edge case
        if (nums.size() == 1)
            return nums[0];

        // Find the max sum subarray in the middle
        int maxSum1 = maxSubarraySum(nums);

        // Find the min sum subarray in the middle
        int minSum1 = minSubarraySum(nums, 0, nums.size() - 2);
        int minSum2 = minSubarraySum(nums, 1, nums.size() - 1);

        // Find the max sum subarray split across
        int maxSum2 = accumulate(nums.begin(), nums.end(), 0) - min(minSum1, minSum2);

        return max(maxSum1, maxSum2);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
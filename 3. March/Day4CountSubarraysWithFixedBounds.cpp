/**
 * @file Day4CountSubarraysWithFixedBounds.cpp
 * @author Ginny Dang
 * @brief 2444. Count Subarrays With Fixed Bounds (https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/)
 * @version 0.1
 * @date 2023-03-03
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long count = 0;
        int lastMinK = -1;
        int lastMaxK = -1;
        int lastOutOfRange = -1;

        for (int end = 0; end < nums.size(); end++)
        {
            if (nums[end] == minK)
                lastMinK = end;
            if (nums[end] == maxK)
                lastMaxK = end;
            if (nums[end] > maxK || nums[end] < minK)
                lastOutOfRange = end;

            count += max(min(lastMinK, lastMaxK) - lastOutOfRange, 0);
        }

        return count;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
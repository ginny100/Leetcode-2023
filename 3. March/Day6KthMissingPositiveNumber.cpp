/**
 * @file Day6KthMissingPositiveNumber.cpp
 * @author Ginny Dang
 * @brief 1539. Kth Missing Positive Number (https://leetcode.com/problems/kth-missing-positive-number/description/)
 * @version 0.1
 * @date 2023-03-05
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k < arr[0])
            return k;

        k -= arr[0] - 1;

        for (int i = 0; i < n - 1; i++)
        {
            int missingNums = arr[i + 1] - arr[i] - 1; // The number of missing positive integers between arr[i] and arr[i + 1]
            if (k <= missingNums)
                return arr[i] + k;
            else
                k -= missingNums;
        }

        return arr[n - 1] + k;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
/**
 * @file Day21NumberOfZeroFilledSubarrays.cpp
 * @author Ginny Dang
 * @brief 2348. Number of Zero-Filled Subarrays (https://leetcode.com/problems/number-of-zero-filled-subarrays/description/)
 * @version 0.1
 * @date 2023-03-20
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Main formula
 * - Calculate the total number of subarrays of an array:
 * -- Total subarrays = n * (n + 1) / 2
 * --- n is the length of the array
 * --- There are n subarrays of length 1,
 *               n-1 subarrays of length 2,
 *               n-2 subarrays of length 3,
 *               .....
 *               1 subarray of length n.
 * => The total number of subarrays is the sum of these subarrays, which is equal to n * (n + 1) / 2.
 */

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long result = 0;
        long long numConsecZeros = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                numConsecZeros++;
            else
            {
                result += numConsecZeros * (numConsecZeros + 1) / 2;
                numConsecZeros = 0;
            }
        }

        if (numConsecZeros != 0)
            result += numConsecZeros * (numConsecZeros + 1) / 2;

        return result;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
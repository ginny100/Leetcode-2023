/**
 * @file Day6ShuffleTheArray.cpp
 * @author Ginny Dang
 * @brief 1470. Shuffle the Array (https://leetcode.com/problems/shuffle-the-array/description/)
 * @version 0.1
 * @date 2023-02-05
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New algorithm learned from the Official Solution
 * - Iterate on the nums array from index i = n to 2 * n - 1:
 * -- Store the element y_(i+1), that is, nums[i] with x_(i+1) at index (i - n), using bit manipulation.
 * - Iterate from index n - 1 to 0, and at each index i:
 * -- Extract both firstNumber and secondNumber using bit manipulation and store them at their respective indices 2 * i and 2 * i + 1 in the nums array.
 * - Return the nums array.
 */

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        for (int i = n; i < 2 * n; i++)
            nums[i - n] |= (nums[i] << 10); // Storing 2 number at the same element

        int allOnes = pow(2, 10) - 1; // '0000000000 1111111111' in decimal.

        for (int i = n - 1; i >= 0; i--)
        {
            int firstNumber = nums[i] & allOnes;
            int secondNumber = nums[i] >> 10;

            nums[i * 2] = firstNumber;
            nums[i * 2 + 1] = secondNumber;
        }

        return nums;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
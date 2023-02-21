/**
 * @file Day21SingleElementInASortedArray.cpp
 * @author Ginny Dang
 * @brief 540. Single Element in a Sorted Array (https://leetcode.com/problems/single-element-in-a-sorted-array/description/)
 * @version 0.1
 * @date 2023-02-20
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // Edge case
        /* Given the constraints, arrays with only 2 elements are considered invalid input */
        if (nums.size() == 1)
            return nums[0];

        // Normal cases
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            bool halvesAreEven = (right - mid) % 2 == 0;
            // If mid’s partner is to the right
            if (nums[mid] == nums[mid + 1])
            {
                // The halves were originally even
                if (halvesAreEven)
                    left = mid + 2;
                // The halves were originally odd
                else
                    right = mid - 1;
            }
            // If mid’s partner is to the left
            else if (nums[mid] == nums[mid - 1])
            {
                // The halves were originally even
                if (halvesAreEven)
                    right = mid - 2;
                // The halves were originally odd
                else
                    left = mid + 1;
            }
            // If mid does not have a partner
            else
                return nums[mid];
        }

        return nums[left];
    }
};

// Time Complexity: O(logN)
// Space Complexity: O(1)
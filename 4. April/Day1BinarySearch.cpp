/**
 * @file Day1BinarySearch.cpp
 * @author Ginny Dang
 * @brief 704. Binary Search (https://leetcode.com/problems/binary-search/description/)
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }
};

// Time Complexity: O(logN)
// Space Complexity: O(1)
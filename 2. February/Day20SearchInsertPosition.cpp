/**
 * @file Day20SearchInsertPosition.cpp
 * @author Ginny Dang
 * @brief 35. Search Insert Position (https://leetcode.com/problems/search-insert-position/description/)
 * @version 0.1
 * @date 2023-02-19
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target > nums[nums.size() - 1])
            return nums.size();
        else if (target < nums[0])
            return 0;

        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
            {
                if (nums[mid + 1] > target)
                    return mid + 1;
                left = mid + 1;
            }
            else
            {
                if (nums[mid - 1] < target)
                    return mid;
                right = mid - 1;
            }
        }

        return -1;
    }
};

// Time Complexity: O(logN)
// Space Complexity: O(1)
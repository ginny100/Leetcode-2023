/**
 * @file Day1SortAnArray.cpp
 * @author Ginny Dang
 * @brief 912. Sort an Array (https://leetcode.com/problems/sort-an-array/)
 * @version 0.1
 * @date 2023-02-28
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * Merge Sort Solution - Short version
 * segment [l, r)
 *
 * merge_sort(arr, start, end) calls itself with smaller arrays merge_sort(arr, start, mid) and merge_sort(arr, mid+1, end).
 * The two subarrays are sorted when the recursive call ends so we end up with two sorted arrays, arr[start...mid] and arr[mid+1...end].
 */

class Solution
{
private:
    void merge(vector<int> &nums, int start, int mid, int end)
    {
        int size1 = mid - start + 1;
        int size2 = end - mid;
        int left[size1], right[size2];

        for (int i = 0; i < size1; i++)
            left[i] = nums[i + start];
        for (int j = 0; j < size2; j++)
            right[j] = nums[j + mid + 1];

        // Merge sorted arrays left and right into arr[start...end]
        int l = 0;     // ptr of left subarray
        int r = 0;     // ptr of right subarray
        int a = start; // ptr of the full size arrays

        while (l < size1 && r < size2)
        {
            if (left[l] < right[r])
                nums[a++] = left[l++];
            else
                nums[a++] = right[r++];
        }

        // Either left or right subarray will exhaust first, we'll copy the remaining to nums
        while (l < size1)
            nums[a++] = left[l++];
        while (r < size2)
            nums[a++] = right[r++];
    }

private:
    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return;

        int mid = (start + end) / 2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        merge(nums, start, mid, end);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(N)
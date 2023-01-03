/**
 * @file Day3DeleteColumnsToMakeSorted.cpp
 * @author Ginny Dang
 * @brief 944. Delete Columns to Make Sorted (https://leetcode.com/problems/delete-columns-to-make-sorted/description/)
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int result = 0;
        int n = strs.size();      // rows
        int m = strs[0].length(); // columns

        for (int i = 0; i < m; i++)
        {
            bool deleted = false; // each column can only be deleted once
            for (int j = 1; j < n; j++)
            {
                if (strs[j][i] < strs[j - 1][i] && !deleted)
                {
                    result++;
                    deleted = true;
                }
            }
        }

        return result;
    }
};

// Time Complexity: O(m * n)
// Space Complexity: O(1)
/**
 * @file Day20NonDecreasingSubsequences.cpp
 * @author Ginny Dang
 * @brief 491. Non-decreasing Subsequences (https://leetcode.com/problems/non-decreasing-subsequences/description/)
 * @version 0.1
 * @date 2023-01-20
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    void search(vector<int> &nums, set<vector<int>> &subsequences, int k, int n, vector<int> &subsequence, bool wasChosen)
    {
        if (k == n)
        {
            if (subsequence.size() >= 2)
                subsequences.insert(subsequence);
        }
        else
        {
            // Include nums[k] in the current subset
            if (!(k - 1 >= 0 && nums[k] == nums[k - 1] && !wasChosen))
            {
                if (subsequence.empty() || subsequence[subsequence.size() - 1] <= nums[k])
                {
                    subsequence.push_back(nums[k]);
                    search(nums, subsequences, k + 1, n, subsequence, true);
                    subsequence.pop_back();
                }
            }
            // Dont include nums[k] in the current subset
            search(nums, subsequences, k + 1, n, subsequence, false);
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> subsequences;
        vector<int> subsequence;
        search(nums, subsequences, 0, n, subsequence, false);
        return vector<vector<int>>(subsequences.begin(), subsequences.end());
    }
};

// Time Complexity: ~O(2^N * N * log(2^N)) (worst case)
// Space Complexity: ~O(2^N * N) (worst case)
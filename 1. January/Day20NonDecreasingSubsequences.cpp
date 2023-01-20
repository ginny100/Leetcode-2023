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

/**
 * @brief Backtracking with set
 */

class Solution1
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

/**
 * @brief Optimizing backtracking with unordered map
 */
class Solution2
{
public:
    void search(vector<int> &nums, vector<vector<int>> &subsequences, int k, int n, vector<int> &subsequence, int lastChosen, unordered_map<int, int> &lastAppearance)
    {
        if (k == n)
        {
            if (subsequence.size() >= 2)
                subsequences.push_back(subsequence);
        }
        else
        {
            // search(nums, subsequences, k + 1, n, subsequence, false);
            bool isSkipped = false;
            // Check if nums[k] is skipped
            if (lastAppearance.count(nums[k]) && lastAppearance[nums[k]] > lastChosen)
                isSkipped = true;
            int oldLastAppearance = -1;
            if (lastAppearance.count(nums[k]))
                oldLastAppearance = lastAppearance[nums[k]];
            lastAppearance[nums[k]] = k;
            if (isSkipped)
                search(nums, subsequences, k + 1, n, subsequence, lastChosen, lastAppearance);
            else
            {
                // Include nums[k] in the current subset
                if (subsequence.empty() || subsequence[subsequence.size() - 1] <= nums[k])
                {
                    subsequence.push_back(nums[k]);
                    search(nums, subsequences, k + 1, n, subsequence, k, lastAppearance);
                    subsequence.pop_back();
                }
                // Dont include nums[k] in the current subset
                search(nums, subsequences, k + 1, n, subsequence, lastChosen, lastAppearance);
            }
            lastAppearance[nums[k]] = oldLastAppearance;
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> subsequences;
        vector<int> subsequence;
        unordered_map<int, int> lastAppearance;
        search(nums, subsequences, 0, n, subsequence, -1, lastAppearance);
        return subsequences;
    }
};

// Time Complexity: ~O(2^N * N) (worst case)
// Space Complexity: ~O(2^N * N) (worst case)
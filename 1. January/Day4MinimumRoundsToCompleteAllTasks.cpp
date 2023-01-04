/**
 * @file Day4MinimumRoundsToCompleteAllTasks.cpp
 * @author Ginny Dang
 * @brief 2244. Minimum Rounds to Complete All Tasks (https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/)
 * @version 0.1
 * @date 2023-01-03
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int rounds = 0;
        unordered_map<int, int> difficulties;

        for (int task : tasks)
            difficulties[task]++;

        for (auto pair : difficulties)
        {
            if (pair.second == 1)
                return -1;
            else if (pair.second % 3 == 0)
                rounds += (pair.second / 3);
            else
                rounds += (pair.second / 3) + 1;
        }
        return rounds;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
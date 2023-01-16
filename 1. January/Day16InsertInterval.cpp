/**
 * @file Day16InsertInterval.cpp
 * @author Ginny Dang
 * @brief 57. Insert Interval (https://leetcode.com/problems/insert-interval/description/)
 * @version 0.1
 * @date 2023-01-16
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        int start = newInterval[0];
        int end = newInterval[1];

        for (auto &interval : intervals)
        {
            if (newInterval[0] > interval[1] || newInterval[1] < interval[0])
            {
                if (interval[0] < start)
                    result.push_back(interval);
            }
            else
            {
                start = min(start, interval[0]);
                end = max(end, interval[1]);
            }
        }

        result.push_back({start, end});

        for (auto &interval : intervals)
        {
            if (interval[0] > end)
                result.push_back(interval);
        }

        return result;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
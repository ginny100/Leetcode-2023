/**
 * @file Day5MinimumNumberOfArrowsToBurstBalloons.cpp
 * @author Ginny Dang
 * @brief 452. Minimum Number of Arrows to Burst Balloons (https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)
 * @version 0.1
 * @date 2023-01-04
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    static bool sortcol(const vector<int> &v1, const vector<int> &v2)
    {
        if (v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] < v2[0];
    }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        // Corner case handling
        if (points.size() == 1)
            return 1;

        // Sort by 1st column
        sort(points.begin(), points.end(), sortcol);

        // Count number of arrows
        int curr_start = points[0][0];
        int curr_end = points[0][1];
        int arrows = 1;
        for (int i = 1; i < points.size(); i++)
        {
            curr_start = max(curr_start, points[i][0]);
            curr_end = min(curr_end, points[i][1]);
            if (curr_start > curr_end)
            {
                arrows++;
                curr_start = points[i][0];
                curr_end = points[i][1];
            }
        }
        return arrows;
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(1)
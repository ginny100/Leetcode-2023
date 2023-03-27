/**
 * @file Day27MinimumPathSum.cpp
 * @author Ginny Dang
 * @brief 64. Minimum Path Sum (https://leetcode.com/problems/minimum-path-sum/description/)
 * @version 0.1
 * @date 2023-03-26
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> min_path_sum(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    grid[i][j] = grid[0][0];
                else if (((i - 1 >= 0) && (i - 1 < m)) && ((j - 1 >= 0) && (j - 1 < n)))
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
                else if ((i - 1) < 0 || (i - 1) >= m)
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                else
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
            }
        }

        return grid[m - 1][n - 1];
    }
};

// Time Complexity: O(MN)
// Space Complexity: O(1)
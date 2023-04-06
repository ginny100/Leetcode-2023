/**
 * @file Day6NumberOfClosedIslands.cpp
 * @author Ginny Dang
 * @brief 1254. Number of Closed Islands (https://leetcode.com/problems/number-of-closed-islands/description/)
 * @version 0.1
 * @date 2023-04-05
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
private:
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {-1, 1, 0, 0};

    int bfs(vector<vector<int>> &grid, int row, int col, int rows, int cols)
    {
        int isClosed = 1;
        queue<pair<int, int>> q;

        grid[row][col] = -1;
        q.push({row, col});

        while (!q.empty())
        {
            int curRow = q.front().first, curCol = q.front().second;
            q.pop();

            if ((curRow == 0) || (curRow == rows - 1) || (curCol == 0) || (curCol == cols - 1))
                isClosed = 0;

            for (int i = 0; i < 4; i++)
            {
                int nextRow = curRow + dr[i], nextCol = curCol + dc[i];
                if ((0 <= nextRow && nextRow < rows) && (0 <= nextCol && nextCol < cols) && grid[nextRow][nextCol] == 0)
                {
                    grid[nextRow][nextCol] = -1;
                    q.push({nextRow, nextCol});
                }
            }
        }

        return isClosed;
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int result = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    result += bfs(grid, i, j, m, n);

        return result;
    }
};

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
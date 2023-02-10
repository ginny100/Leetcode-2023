/**
 * @file Day10AsFarFromLandAsPossible.cpp
 * @author Ginny Dang
 * @brief 1162. As Far from Land as Possible (https://leetcode.com/problems/as-far-from-land-as-possible/description/)
 * @version 0.1
 * @date 2023-02-09
 *
 * @copyright Copyright (c) 2023
 *
 */

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

class Solution
{
public:
    int calcDist(int x0, int y0, int x1, int y1)
    {
        return abs(x0 - x1) + abs(y0 - y1);
    }

    int bfs(int n, vector<vector<int>> &grid)
    {
        // Init
        int maxDist = INT_MIN;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Add all sources to the queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Calculate the distances
        while (q.size())
        {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextRow = curRow + dr[i];
                int nextCol = curCol + dc[i];
                if ((nextRow >= 0 && nextRow < n) && (nextCol >= 0 && nextCol < n) && (dist[nextRow][nextCol] == INT_MAX))
                {
                    dist[nextRow][nextCol] = dist[curRow][curCol] + calcDist(curRow, curCol, nextRow, nextCol);
                    grid[nextRow][nextCol] = 1;
                    q.push({nextRow, nextCol});
                }
            }
        }

        // Make sure that there's no unvisited cell
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    return -1;

        // Find the maximum distance
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                maxDist = max(maxDist, dist[i][j]);

        return maxDist;
    }

    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int maxDist = bfs(n, grid);
        return maxDist == 0 ? -1 : maxDist;
    }
};

// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
/**
 * @file Day24SnakesAndLadders.cpp
 * @author Ginny Dang
 * @brief 909. Snakes and Ladders (https://leetcode.com/problems/snakes-and-ladders/description/)
 * @version 0.1
 * @date 2023-01-23
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Idea
 * - Make a new n x n board filled with numbers following the Boustrophedon style
 * -- 1st row (bottom row) left -> right
 * -- 2nd row right -> left
 * -- ...
 * -- nth row (top row):
 * ---- if n is odd: left -> right
 * ---- else: right -> left
 * count: level of the current cell
 * - Graph:
 * -- Vertices: all cells in the grid
 * -- Edges: cur -> cur_next
 *           + cur_next lie between [cur + 1, min(cur + 6, n** 2)]
 *             if cur_next == -1 -> stop the current jump -> edge: cur -> cur_next
 *             if cur_next is a snake or ladder -> jump to the destination of that snake or ladder -> edge: cur -> dest(cur_next)
 * - Find shortest path -> Do BFS from the starting point only
 */

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        // Create a new grid in Boustrophedon style
        int n = board.size();
        int cells = pow(n, 2);
        vector<vector<int>> newGrid(n, vector<int>(n, 0)); // Store all levels of all cell
        int count = 1;                                     // Level of the current cell

        // Fill the new grid with numbers
        int dir = 1; // 1 means left -> right, -1 means right -> left
        for (int i = n - 1; i > -1; i--)
        {
            // Left to right
            if (dir == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    newGrid[i][j] = count;
                    count++;
                }
            }
            // Right to left
            else
            {
                for (int j = n - 1; j > -1; j--)
                {
                    newGrid[i][j] = count;
                    count++;
                }
            }
            // Change direction after filling out each line
            dir *= -1;
        }

        // Save the coordinates of n^2 cells
        vector<vector<int>> coordinates(cells + 1, vector<int>());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                coordinates[newGrid[i][j]].push_back(i);
                coordinates[newGrid[i][j]].push_back(j);
            }
        }

        // Traverse every vertex (cell)
        vector<vector<int>> neighbors(cells + 1, vector<int>());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int curr = newGrid[i][j];
                for (int k = curr + 1; k <= min(curr + 6, cells); k++)
                {
                    // Neither snake nor ladder starting at cur_next
                    if (board[coordinates[k][0]][coordinates[k][1]] == -1)
                        neighbors[curr].push_back(k);
                    // Either snake or ladder starting at cur_next
                    else
                        neighbors[curr].push_back(board[coordinates[k][0]][coordinates[k][1]]); // cur -> cur_next -> board[coordinates[k][0]][coordinates[k][1]]
                }
            }
        }

        // BFS
        vector<int> moves(cells + 1, -1); // moves[i] is the min number of moves from 1 to i
        queue<int> q;
        q.push(1);
        moves[1] = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int neighbor : neighbors[curr])
            {
                if (moves[neighbor] == -1)
                {
                    moves[neighbor] = moves[curr] + 1;
                    q.push(neighbor);
                }
            }
        }

        return moves[cells];
    }
};

// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
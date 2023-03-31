/**
 * @file Day31NumberOfWaysOfCuttingAPizza.cpp
 * @author Ginny Dang
 * @brief 1444. Number of Ways of Cutting a Pizza (https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/)
 * @version 0.1
 * @date 2023-03-31
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int ways(vector<string> &pizza, int k)
    {
        const int mod = 1e9 + 7;
        int rows = pizza.size();
        int cols = pizza[0].size();
        vector apples(rows + 1, vector<int>(cols + 1));
        vector f(rows, vector<int>(cols));

        for (int row = rows - 1; row > -1; row--)
        {
            for (int col = cols - 1; col > -1; col--)
            {
                apples[row][col] = (pizza[row][col] == 'A') + apples[row + 1][col] + apples[row][col + 1] - apples[row + 1][col + 1];
                f[row][col] = (apples[row][col] > 0);
            }
        }

        for (int remain = 1; remain < k; remain++)
        {
            vector g(rows, vector<int>(cols));

            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    for (int nextRow = row + 1; nextRow < rows; nextRow++)
                        if (apples[row][col] - apples[nextRow][col] > 0)
                            (g[row][col] += f[nextRow][col]) %= mod; // prevent overflow

                    for (int nextCol = col + 1; nextCol < cols; nextCol++)
                        if (apples[row][col] - apples[row][nextCol] > 0)
                            (g[row][col] += f[row][nextCol]) %= mod; // prevent overflow
                }
            }

            f = g;
        }

        return f[0][0];
    }
};

// Time complexity: O(k * m * n * (m + n)) where m is the number of rows and n is the number of columns
// Space complexity: O(m * n) where m is the number of rows and n is the number of columns
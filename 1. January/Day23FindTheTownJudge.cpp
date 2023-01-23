/**
 * @file Day23FindTheTownJudge.cpp
 * @author Ginny Dang
 * @brief 997. Find the Town Judge (https://leetcode.com/problems/find-the-town-judge/description/)
 * @version 0.1
 * @date 2023-01-22
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int judge = -1;
        vector<int> indegrees(n + 1, 0);
        vector<int> outdegrees(n + 1, 0);

        for (auto conn : trust)
        {
            indegrees[conn[1]]++;
            outdegrees[conn[0]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (indegrees[i] == n - 1 && outdegrees[i] == 0)
            {
                judge = i;
                break;
            }
        }

        return judge;
    }
};

// Time Complexity: O(E)
// Space Complexity: O(N)
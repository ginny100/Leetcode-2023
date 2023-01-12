/**
 * @file Day11MinimumTimeToCollectAllApplesInATree.cpp
 * @author Ginny Dang
 * @brief 1443. Minimum Time to Collect All Apples in a Tree (https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/)
 * @version 0.1
 * @date 2023-01-11
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int dfs(int start, vector<vector<int>> &graph, vector<bool> &hasApple, vector<bool> &visited, int seconds)
    {
        visited[start] = true;

        for (int neighbor : graph[start])
        {
            if (visited[neighbor])
                continue;

            seconds += dfs(neighbor, graph, hasApple, visited, 0);

            if (hasApple[neighbor])
                hasApple[start] = true;
        }

        if (start != 0 && hasApple[start])
            seconds += 2;

        return seconds;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n, vector<int>());

        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return dfs(0, graph, hasApple, visited, 0);
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
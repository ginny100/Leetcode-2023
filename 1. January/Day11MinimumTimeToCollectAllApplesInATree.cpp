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
    int dfs(int start, vector<vector<int>> &graph, vector<bool> &hasApple, vector<int> &visited, int seconds)
    {
        // cout << "start = " << start << "\n";
        visited[start] = 1;

        for (int neighbor : graph[start])
        {
            if (visited[neighbor] == 1)
                continue;
            // cout << "  neighbor = " << neighbor << " of " << start << "\n";
            if (visited[neighbor] == 0)
                seconds += dfs(neighbor, graph, hasApple, visited, 0);
            if (hasApple[neighbor])
                hasApple[start] = true;
            // cout << "-> seconds of " << start << " = " << seconds << " after visiting " << neighbor << "\n";
        }

        visited[start] = 2;

        if (start != 0 && hasApple[start])
        {
            // cout << "seconds + 2 at start " << start << "\n";
            seconds += 2;
        }

        return seconds;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<int> visited(n, 0);
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
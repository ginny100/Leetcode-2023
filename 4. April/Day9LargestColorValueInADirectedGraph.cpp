/**
 * @file Day9LargestColorValueInADirectedGraph.cpp
 * @author Ginny Dang
 * @brief 1857. Largest Color Value in a Directed Graph (https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/)
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
private:
    int dfs(int node, string &colors, vector<vector<int>> &graph, vector<vector<int>> &count, vector<bool> &visited, vector<bool> &inStack)
    {
        if (inStack[node])
            return INT_MAX;
        if (visited[node])
            return count[node][colors[node] - 'a'];

        inStack[node] = true;
        visited[node] = true;

        for (auto &neighbor : graph[node])
        {
            if (dfs(neighbor, colors, graph, count, visited, inStack) == INT_MAX)
                return INT_MAX;

            for (int i = 0; i < 26; i++)
                count[node][i] = max(count[node][i], count[neighbor][i]);
        }

        count[node][colors[node] - 'a']++;
        inStack[node] = false;

        return count[node][colors[node] - 'a'];
    }

public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.length();
        int m = edges.size();
        vector<vector<int>> graph(n);
        for (auto &edge : edges)
            graph[edge[0]].push_back(edge[1]);

        vector<vector<int>> count(n, vector<int>(26));
        vector<bool> visited(n);
        vector<bool> inStack(n);
        int result = 0; // maximum frequency of a color in a the graph
        for (int i = 0; i < n; i++)
            result = max(result, dfs(i, colors, graph, count, visited, inStack));

        return result == INT_MAX ? -1 : result;
    }
};

// Time complexity: O(m + n) or O(26m + 26n) to be exact
// Space complexity: O(m + n) or O(m + 26n) to be exact
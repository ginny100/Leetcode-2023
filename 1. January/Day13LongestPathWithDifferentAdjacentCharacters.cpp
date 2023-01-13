/**
 * @file Day13LongestPathWithDifferentAdjacentCharacters.cpp
 * @author Ginny Dang
 * @brief 2246. Longest Path With Different Adjacent Characters (https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/)
 * @version 0.1
 * @date 2023-01-12
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Idea learned from the discussion forum
 * Every recursion cycle has 2 largest branches.
 * The sum of these branches and 1 (meaning the start node of the cycle) can be the longest path we need.
 */

/**
 * @brief Algorithm learned from the discussion forum
 * Start from the source node
 * For each recursion cycle starting from each node
 * - Keep track of the 2 largest branches starting from the current node
 * - Iterate over each of the current node' children
 * --- For each child, call dfs on it to calc its longest result path
 * --- If the current child has the same letter as its parent, skip it
 * --- Otherwise
 * ------ Update the values of the 2 longest branches
 * ------ Update the final answer
 */

class Solution
{
public:
    int result;

    int dfs(int start, vector<vector<int>> &graph, vector<bool> &visited, string &s)
    {
        visited[start] = true;

        int max_length1 = 0; // 1st largest branch of start node
        int max_length2 = 0; // 2nd largest branch of start node

        for (int neighbor : graph[start])
        {
            if (visited[neighbor])
                continue;
            int prev_lenght = dfs(neighbor, graph, visited, s);
            if (s[neighbor] == s[start])
                continue;
            if (prev_lenght > max_length1)
            {
                max_length2 = max_length1;
                max_length1 = prev_lenght;
            }
            else
                max_length2 = max(max_length2, prev_lenght);
        }

        result = max(result, 1 + max_length1 + max_length2);

        return 1 + max_length1;
    }

    int longestPath(vector<int> &parent, string s)
    {
        result = 1;

        int n = parent.size();
        vector<bool> visited(n, false);

        vector<vector<int>> graph(n, vector<int>());
        for (int i = 1; i < n; i++)
        {
            graph[parent[i]].push_back(i);
            graph[i].push_back(parent[i]);
        }

        dfs(0, graph, visited, s);

        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
/**
 * @file Day12NumberOfNodesInTheSubTreeWithTheSameLabel.cpp
 * @author Ginny Dang
 * @brief 1519. Number of Nodes in the Sub-Tree With the Same Label (https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/)
 * @version 0.1
 * @date 2023-01-12
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    void dfs(int start, string &labels, vector<int> &label_freq, vector<int> &ans, vector<vector<int>> &tree_graph, vector<bool> &visited)
    {
        visited[start] = true;
        ans[start] = label_freq[labels[start] - 'a'];
        label_freq[labels[start] - 'a'] += 1;

        for (int neighbor : tree_graph[start])
        {
            if (visited[neighbor])
                continue;
            dfs(neighbor, labels, label_freq, ans, tree_graph, visited);
        }

        ans[start] = label_freq[labels[start] - 'a'] - ans[start];
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<int> ans(n, 0);
        vector<bool> visited(n, false);
        vector<vector<int>> tree_graph(n, vector<int>());
        vector<int> label_freq(26, 0);

        for (auto edge : edges)
        {
            tree_graph[edge[0]].push_back(edge[1]);
            tree_graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, labels, label_freq, ans, tree_graph, visited);

        return ans;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
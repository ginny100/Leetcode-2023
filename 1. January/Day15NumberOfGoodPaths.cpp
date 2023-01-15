/**
 * @file Day15NumberOfGoodPaths.cpp
 * @author Ginny Dang
 * @brief 2421. Number of Good Paths (https://leetcode.com/problems/number-of-good-paths/description/)
 * @version 0.1
 * @date 2023-01-15
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Idea learned from the official solution
 * Nodes whose values are equal to the smallest value cannot form any good path with length greater than 1 -> Sort all nodes by their values
 * Start from the smallest value X
 * - Find all components of nodes whose values are equal to X
 * - For each component of N nodes with value X, the number of good paths starting and ending at value X is N * (N - 1) / 2
 * Move to the very next higher value X + 1
 * - Add all nodes whose values are X + 1 to the components found in the previous step
 * - Repeat the same process as in the previous step to compute all good paths starting with the value of X + 1
 * - The node with value X can serve as intermediate nodes in a good path starting and ending with value X + 1
 * Continue with other values in order. After finishing all iterations, we'll have a complete tree
 */

class DisjointSetUnion
{
private:
    vector<int> parent, rank;

public:
    DisjointSetUnion(int size)
    {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int find_set(int v)
    {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    void union_set(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);

        if (u == v)
            return;
        else if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
};

class Solution
{
public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        vector<vector<int>> graph(n, vector<int>());
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        map<int, vector<int>> valuesToNodes;
        for (int node = 0; node < n; node++)
            valuesToNodes[vals[node]].push_back(node);

        DisjointSetUnion dsu(n);
        int result = 0;

        for (auto &[value, nodes] : valuesToNodes)
        {
            for (int node : nodes)
                for (int neighbor : graph[node])
                    if (vals[node] >= vals[neighbor])
                        dsu.union_set(node, neighbor);

            unordered_map<int, int> group;

            for (int node : nodes)
                group[dsu.find_set(node)]++;

            for (auto &[aSet, size] : group)
                result += (size * (size + 1) / 2);
        }
        return result;
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(N)
/**
 * @file Day25CountUnreachablePairsOfNodesInAnUndirectedGraph.cpp
 * @author Ginny Dang
 * @brief 2316. Count Unreachable Pairs of Nodes in an Undirected Graph (https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/)
 * @version 0.1
 * @date 2023-03-25
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int bfs(int start, vector<vector<int>> &graph, vector<bool> &visited)
    {
        int size = 0;
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            size++;
            for (int v : graph[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return size;
    }

    long long count(int n, vector<int> &sizes)
    {
        if (sizes.size() == 1)
            return 0;

        long long totalSizes = 0;
        long long sumSizes = 0;

        for (int size : sizes)
        {
            totalSizes += (long long)size * size;
            sumSizes += size;
        }

        return 0.5 * (sumSizes * sumSizes - totalSizes);
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        // Build graph
        vector<vector<int>> graph(n, vector<int>());
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Count the number of connected components within the graph
        vector<bool> visited(n, false);
        vector<int> sizes;

        for (int i = 0; i < n; i++)
            if (!visited[i])
                sizes.push_back(bfs(i, graph, visited));

        // Find the number of pairs
        return count(n, sizes);
    }
};

// Time Complexity: O(N + E) where N is the number of nodes, E is the number of edges
// Space Complexity: O(N + E) where N is the number of nodes, E is the number of edges
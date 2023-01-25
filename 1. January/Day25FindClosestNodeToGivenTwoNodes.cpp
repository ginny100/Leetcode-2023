/**
 * @file Day25FindClosestNodeToGivenTwoNodes.cpp
 * @author Ginny Dang
 * @brief 2359. Find Closest Node to Given Two Nodes (https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/)
 * @version 0.1
 * @date 2023-01-24
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Idea
 * - BFS from node1 to find distances from it to all other nodes
 * - BFS from node2 to find distances from it to all other nodes
 * - Filter out nodes that can be reached from both node1 and node2
 * -- For each of these nodes, find max(dist1[i], dist2[i])
 * -- Get the min of these above values
 */

class Solution
{
public:
    vector<int> calcDistances(int node, vector<vector<int>> &graph, int n)
    {
        vector<int> dist(n, -1);
        queue<int> q;

        dist[node] = 0;
        q.push(node);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (graph[curr].size() && dist[graph[curr][0]] == -1)
            {
                dist[graph[curr][0]] = dist[curr] + 1;
                q.push(graph[curr][0]);
            }
        }

        return dist;
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i++)
            if (edges[i] != -1)
                graph[i].push_back(edges[i]);

        vector<int> dist1 = calcDistances(node1, graph, n);
        vector<int> dist2 = calcDistances(node2, graph, n);
        int minMutualDist = 10e5;
        for (int i = 0; i < n; i++)
            if (dist1[i] != -1 && dist2[i] != -1)
                minMutualDist = min(minMutualDist, max(dist1[i], dist2[i]));

        for (int i = 0; i < n; i++)
            if (dist1[i] != -1 && dist2[i] != -1)
                if (max(dist1[i], dist2[i]) == minMutualDist)
                    return i;

        return -1;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
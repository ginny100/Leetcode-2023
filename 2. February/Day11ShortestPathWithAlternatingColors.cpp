/**
 * @file Day11ShortestPathWithAlternatingColors.cpp
 * @author Ginny Dang
 * @brief 1129. Shortest Path with Alternating Colors (https://leetcode.com/problems/shortest-path-with-alternating-colors/description/)
 * @version 0.1
 * @date 2023-02-11
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New thing I've learned from this challenge
 * How to create an unordered_map of pairs in C++? (https://www.geeksforgeeks.org/how-to-create-an-unordered_map-of-pairs-in-c/)
 */

class Solution
{
public:
    // A hash function used to hash a pair of any kind
    struct hash_pair
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);

            if (hash1 != hash2)
                return hash1 ^ hash2;

            // If hash1 == hash2, their XOR is zero.
            return hash1;
        }
    };

    void bfs(vector<vector<pair<int, int>>> &graph, int start, vector<int> &weights)
    {
        queue<vector<int>> q; // Each element looks like {point, level, color}
        q.push({start, 0, -1});
        unordered_map<pair<int, int>, bool, hash_pair> visited;

        visited[{start, 0}] = true; // 0 indicates a red edge
        visited[{start, 1}] = true; // 1 indicates a blue edge

        while (!q.empty())
        {
            int point = q.front()[0];
            int level = q.front()[1];
            int color = q.front()[2];
            q.pop();

            for (auto &neighbor : graph[point])
            {
                if (color == -1 || color != neighbor.second)
                {
                    if (!visited.count(neighbor))
                    {
                        visited[neighbor] = true;
                        weights[neighbor.first] = min(weights[neighbor.first], level + 1);
                        q.push({neighbor.first, level + 1, neighbor.second});
                    }
                }
            }
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        // Build a special graph
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        //// Add all red edges. Each red edge is denoted as 0
        for (auto &redEdge : redEdges)
            graph[redEdge[0]].push_back({redEdge[1], 0});
        //// Add all blue edges. Each blue edge is denoted as 1
        for (auto &blueEdge : blueEdges)
            graph[blueEdge[0]].push_back({blueEdge[1], 1});

        // Initialize all weights as infinities except for the 1st one
        vector<int> weights(n, INT_MAX);
        weights[0] = 0;

        // Apply BFS
        //// BFS
        bfs(graph, 0, weights);
        //// Reassign those weights that are uncalculable
        for (int i = 0; i < weights.size(); i++)
            if (weights[i] == INT_MAX)
                weights[i] = -1;
        //// Result
        return weights;
    }
};

// Time Complexity: O(N + E) where N is the number of nodes and E is the total number of blue and red edges
// Space Complexity: O(N + E) where N is the number of nodes and E is the total number of blue and red edges
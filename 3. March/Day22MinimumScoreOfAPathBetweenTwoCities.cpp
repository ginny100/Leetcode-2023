/**
 * @file Day22MinimumScoreOfAPathBetweenTwoCities.cpp
 * @author Ginny Dang
 * @brief 2492. Minimum Score of a Path Between Two Cities (https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/)
 * @version 0.1
 * @date 2023-03-21
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        int score = INT_MAX;

        // Build graph
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto &road : roads)
        {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        // Apply BFS
        vector<bool> visited(n + 1);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto &road : graph[curr])
            {
                score = min(score, road.second);
                if (!visited[road.first])
                {
                    visited[road.first] = true;
                    q.push(road.first);
                }
            }
        }

        return score;
    }
};

// Time Complexity: O(N + E)
// Space Complexity: O(N + E)
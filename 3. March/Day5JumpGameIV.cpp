/**
 * @file Day5JumpGameIV.cpp
 * @author Ginny Dang
 * @brief 1345. Jump Game IV (https://leetcode.com/problems/jump-game-iv/description/)
 * @version 0.1
 * @date 2023-03-05
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New thing I've learned from this challenge
 * Why "imaginary" graph?
 * - If we had an actual graph, for each node, we will store all of its connections of 3 types. However:
 * - Types 1 and 2 are trivial to determine -> No need to store in the graph
 * - Type 3 connections are too costly to store
 * => There's no actual graph built here.
 * - Instead, they key player here is the queue. Each node only needs to present in the queue once.
 */

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 1)
            return 0;

        // Build value-positions map
        unordered_map<int, vector<int>> valuePosMap;
        for (int i = 0; i < n; i++)
            valuePosMap[arr[i]].push_back(i);

        // BFS on the "imaginary" graph to find the shortest path from 0 -> n - 1
        queue<int> q;
        vector<int> stepsToReach(n, -1);

        q.push(0);
        stepsToReach[0] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            // Handle type 1 connections
            if (u - 1 >= 0 && stepsToReach[u - 1] == -1)
            {
                q.push(u - 1);
                stepsToReach[u - 1] = stepsToReach[u] + 1;
            }

            // Handle type 2 connections
            if (u + 1 < n && stepsToReach[u + 1] == -1)
            {
                q.push(u + 1);
                stepsToReach[u + 1] = stepsToReach[u] + 1;
            }

            // Handle type 3 connections
            vector<int> valuePos = valuePosMap[arr[u]];
            while (!valuePos.empty())
            {
                int lastPos = valuePos[valuePos.size() - 1];
                valuePos.pop_back();
                if (lastPos != u && stepsToReach[lastPos] == -1)
                {
                    q.push(lastPos);
                    stepsToReach[lastPos] = stepsToReach[u] + 1;
                }
            }
            valuePosMap[arr[u]].clear();
        }

        return stepsToReach[n - 1];
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
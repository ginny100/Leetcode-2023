/**
 * @file Day12MinimumFuelCostToReportToTheCapital.cpp
 * @author Ginny Dang
 * @brief 2477. Minimum Fuel Cost to Report to the Capital (https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/)
 * @version 0.1
 * @date 2023-02-12
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    long long dfs(int start, int seats, vector<vector<int>> &graph, vector<int> &numNodes, int parent = -1)
    {
        long long cost = 0;

        for (int neighbor : graph[start])
        {
            if (neighbor == parent)
                continue;
            cost += dfs(neighbor, seats, graph, numNodes, start);
            cost += numNodes[neighbor] / seats;
            if (numNodes[neighbor] % seats != 0)
                cost++;
            numNodes[start] += numNodes[neighbor];
        }

        return cost;
    }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        // Init
        long long fuelCost = 0;
        int n = roads.size() + 1;
        vector<int> numNodes(n, 1); // Number of nodes in each subtree

        // Build graph
        vector<vector<int>> graph(n, vector<int>());
        for (auto &road : roads)
        {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        // Calculate costs to travel from 0 to any other nodes
        fuelCost += dfs(0, seats, graph, numNodes);
        return fuelCost;
    }
};

// Time Complexity: O(N + E)
// Space Complexity: O(N + E)
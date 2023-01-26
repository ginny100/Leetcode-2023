/**
 * @file Day26CheapestFlightsWithinKStops.cpp
 * @author Ginny Dang
 * @brief 787. Cheapest Flights Within K Stops (https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)
 * @version 0.1
 * @date 2023-01-25
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New idea learned from the Official Solution
 * - This problem limits the number of stops to k -> No need to search the paths with lengths greater than k + 1.
 * - BFS can be used for this problem because the number of levels to be explored is bounded by k.
 * - We perform a level-wise iteration over the nodes.
 * -- We explore all the nodes at the present level (say l) before moving on to the nodes at the next level (l + 1).
 * --- This level would correspond to the number of stops that would be limited by k.
 * -- When we move from a level of l to l + 1, we will increase the stops by 1.
 * --- We are allowed a maximum of k stops, which means we could go up to a maximum level of k + 1 from the src node, trying to reach dst at the minimum price.
 * - We can maintain an array dist which stores the minimum price to reach each node.
 * -- When we want to move to a node, we only consider edges where the total price after traversing the edge is less than the currently calculated dist[node].
 */

class Solution
{
public:
    int bfs(int n, vector<vector<pair<int, int>>> &graph, vector<int> &dist, int src, int dst, int k)
    {
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (stops <= k && !q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto [u, uDist] = q.front();
                q.pop();
                for (auto &[v, vPrice] : graph[u])
                {
                    if (vPrice + uDist < dist[v])
                    {
                        dist[v] = vPrice + uDist;
                        q.push({v, dist[v]});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (auto &flight : flights)
            graph[flight[0]].push_back({flight[1], flight[2]});

        vector<int> dist(n, numeric_limits<int>::max());
        return bfs(n, graph, dist, src, dst, k);
    }
};

// Time Complexity: O(N + EK)
// Space Complexity: O(N + EK)
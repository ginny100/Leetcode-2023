/**
 * @file Day24ReorderRoutesToMakeAllPathsLeadToTheCityZero.cpp
 * @author Ginny Dang
 * @brief 1466. Reorder Routes to Make All Paths Lead to the City Zero (https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/)
 * @version 0.1
 * @date 2023-03-23
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
private:
    static const int MAX = 50001;

    int dfs(int start, int numChanges, unordered_map<int, unordered_set<int> *> &graph, unordered_map<int, unordered_set<int> *> &outdegrees, bool (&visited)[MAX])
    {
        visited[start] = true;

        for (int neighbor : *(graph[start]))
        {
            if (!visited[neighbor])
            {
                if (outdegrees[start]->count(neighbor))
                    numChanges++;
                numChanges = dfs(neighbor, numChanges, graph, outdegrees, visited);
            }
        }

        return numChanges;
    }

public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        int changes = 0;
        unordered_map<int, unordered_set<int> *> outdegrees;
        unordered_map<int, unordered_set<int> *> graph;
        bool visited[MAX] = {false};

        for (auto &conn : connections)
        {
            int u = conn[0];
            int v = conn[1];

            if (!outdegrees.count(u))
                outdegrees[u] = new unordered_set<int>;

            if (!outdegrees.count(v))
                outdegrees[v] = new unordered_set<int>;

            outdegrees[u]->insert(v);
            if (!graph.count(u))
            {
                graph[u] = new unordered_set<int>;
                visited[u] = false;
            }

            graph[u]->insert(v);
            if (!graph.count(v))
            {
                graph[v] = new unordered_set<int>;
                visited[v] = false;
            }

            graph[v]->insert(u);
        }

        for (int i = 0; i < graph.size(); i++)
            if (!visited[i])
                changes = dfs(0, changes, graph, outdegrees, visited);

        // Deallocate the memory to ensure that there are no memory leaks or null pointer errors
        for (auto &kv : outdegrees)
            delete kv.second;

        for (auto &kv : graph)
            delete kv.second;

        return changes;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
/**
 * @file Day23NumberOfOperationsToMakeNetworkConnected.cpp
 * @author Ginny Dang
 * @brief 1319. Number of Operations to Make Network Connected (https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/)
 * @version 0.1
 * @date 2023-03-22
 *
 * @copyright Copyright (c) 2023
 *
 */

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        size.resize(n, 1);
    };

    int findSet(int v)
    {
        return v == parent[v] ? v : parent[v] = findSet(parent[v]);
    }

    bool unionSets(int u, int v)
    {
        int parentU = findSet(u);
        int parentV = findSet(v);

        if (parentU == parentV)
            return false;

        if (size[parentU] > size[parentV])
            swap(parentU, parentV);

        parent[parentU] = parentV;
        size[parentV] += size[parentU];

        return true;
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet dsu = DisjointSet(n);
        int good = 0;
        int bad = 0;

        for (auto &conn : connections)
        {
            int u = conn[0];
            int v = conn[1];

            if (dsu.unionSets(u, v))
                good++;
            else
                bad++;
        }

        if (bad >= n - 1 - good)
            return n - 1 - good;
        return -1;
    }
};

// Time Complexity: O(N + E)
// Space Complexity: O(N)
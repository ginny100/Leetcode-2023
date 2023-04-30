/**
 * @file Day30RemoveMaxNumberOfEdgesToKeepGraphFullyTraversable.cpp
 * @author Ginny Dang
 * @brief 1579. Remove Max Number of Edges to Keep Graph Fully Traversable (https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/)
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> componentSize;
    int components;

public:
    DisjointSet(int n)
    {
        components = n;

        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            componentSize.push_back(1);
        }
    }

    int findParent(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = findParent(parent[x]);
    }

    int performUnion(int x, int y)
    {
        x = findParent(x);
        y = findParent(y);

        if (x == y)
            return 0;

        if (componentSize[x] > componentSize[y])
        {
            componentSize[x] += componentSize[y];
            parent[y] = x;
        }
        else
        {
            componentSize[y] += componentSize[x];
            parent[x] = y;
        }

        components--;
        return 1;
    }

    bool isConnected()
    {
        return components == 1;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DisjointSet Alice(n);
        DisjointSet Bob(n);
        int edgesRequired = 0;

        for (vector<int> &edge : edges)
            if (edge[0] == 3)
                edgesRequired += (Alice.performUnion(edge[1], edge[2]) | Bob.performUnion(edge[1], edge[2]));

        for (vector<int> &edge : edges)
        {
            if (edge[0] == 1)
                edgesRequired += Alice.performUnion(edge[1], edge[2]);
            else if (edge[0] == 2)
                edgesRequired += Bob.performUnion(edge[1], edge[2]);
        }

        if (Alice.isConnected() && Bob.isConnected())
            return edges.size() - edgesRequired;

        return -1;
    }
};

// Time Complexity: O(E * alpha(N))
// Space Complexity: O(N)
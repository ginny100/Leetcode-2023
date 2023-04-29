/**
 * @file Day29CheckingExistenceOfEdgeLengthLimitedPaths.cpp
 * @author Ginny Dang
 * @brief 1697. Checking Existence of Edge Length Limited Paths (https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/)
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

class DisjointSet
{
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int size)
    {
        parent = vector<int>(size);
        rank = vector<int>(size);

        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] != u)
            parent[u] = find(parent[u]);

        return parent[u];
    }

    void join(int u, int v)
    {
        int parentU = find(u);
        int parentV = find(v);

        if (parentU == parentV)
            return;

        if (rank[parentU] > rank[parentV])
            parent[parentV] = parentU;
        else if (rank[parentU] < rank[parentV])
            parent[parentU] = parentV;
        else
        {
            parent[parentU] = parentV;
            rank[parentV]++;
        }
    }

    bool areConnected(int u, int v)
    {
        int parentU = find(u);
        int parentV = find(v);

        return parentU == parentV;
    }
};

class Solution
{
private:
    bool static compare(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        DisjointSet dsu(n);
        int queriesCount = queries.size();
        vector<bool> answer(queriesCount);
        vector<vector<int>> queriesWithIndex(queriesCount);

        for (int i = 0; i < queriesCount; ++i)
        {
            queriesWithIndex[i] = queries[i];
            queriesWithIndex[i].push_back(i);
        }

        sort(edgeList.begin(), edgeList.end(), compare);
        sort(queriesWithIndex.begin(), queriesWithIndex.end(), compare);

        int edgesIndex = 0;
        for (auto &query : queriesWithIndex)
        {
            int p = query[0];
            int q = query[1];
            int limit = query[2];
            int queryOriginalIndex = query[3];

            while (edgesIndex < edgeList.size() && edgeList[edgesIndex][2] < limit)
            {
                int u = edgeList[edgesIndex][0];
                int v = edgeList[edgesIndex][1];
                dsu.join(u, v);
                edgesIndex += 1;
            }

            answer[queryOriginalIndex] = dsu.areConnected(p, q);
        }

        return answer;
    }
};

// Time Complexity: O(n + eloge + qlogq)
// Space Complexity: O(n + q)
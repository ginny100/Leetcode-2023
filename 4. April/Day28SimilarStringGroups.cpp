/**
 * @file Day28SimilarStringGroups.cpp
 * @author Ginny Dang
 * @brief 839. Similar String Groups (https://leetcode.com/problems/similar-string-groups/description/)
 * @version 0.1
 * @date 2023-04-28
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
private:
    void bfs(int node, vector<vector<int>> &adj, vector<bool> &visit)
    {
        queue<int> q;

        q.push(node);
        visit[node] = true;

        while (!q.empty())
        {
            node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (!visit[neighbor])
                {
                    visit[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    bool isSimilar(string &a, string &b)
    {
        int diff = 0;

        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                diff++;

        return diff == 0 || diff == 2;
    }

public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isSimilar(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visit(n);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                bfs(i, adj, visit);
                count++;
            }
        }

        return count;
    }
};

// Time Complexity: O(n^2 * m)
// Space Complexity: O(n^2)
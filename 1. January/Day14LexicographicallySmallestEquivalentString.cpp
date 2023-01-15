/**
 * @file Day14LexicographicallySmallestEquivalentString.cpp
 * @author Ginny Dang
 * @brief 1061. Lexicographically Smallest Equivalent String (https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/)
 * @version 0.1
 * @date 2023-01-13
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief High level idea
 * Using Disjoint Set - Union Find
 * For each set, the smallest letter is the parent
 */

#define MAX 26

class DisjointSet
{
private:
    int parent[MAX];

public:
    void make_set(int v)
    {
        parent[v] = v;
    }

    int find_set(int v)
    {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    void union_sets(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);

        if (u == v)
            return;

        int minParent = min(u, v);
        int maxParent = max(u, v);
        parent[maxParent] = minParent;
    }
};

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.length();
        DisjointSet dsu = DisjointSet();

        for (int i = 0; i < MAX; i++)
            dsu.make_set(i);

        for (int i = 0; i < n; i++)
            dsu.union_sets(s1[i] - 'a', s2[i] - 'a');

        string result = "";
        for (int i = 0; i < baseStr.length(); i++)
        {
            int rep = dsu.find_set(baseStr[i] - 'a'); // representative aka parent of each set
            result += (char)('a' + rep);
        }

        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1) or O(2 * 26) to be exact
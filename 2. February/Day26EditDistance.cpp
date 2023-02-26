/**
 * @file Day26EditDistance.cpp
 * @author Ginny Dang
 * @brief 72. Edit Distance (https://leetcode.com/problems/edit-distance/description/)
 * @version 0.1
 * @date 2023-02-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#define MAXM 500
#define MAXN 500

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        int L[MAXM + 1][MAXN + 1];

        if (m == 0)
            return n;
        if (n == 0)
            return m;

        for (int i = 1; i <= m; i++)
            L[i][0] = i;

        for (int j = 1; j <= n; j++)
            L[0][j] = j;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    L[i][j] = L[i - 1][j - 1];
                else
                    L[i][j] = min(L[i - 1][j], min(L[i][j - 1], L[i - 1][j - 1])) + 1;
            }
        }

        return L[m][n];
    }
};

// Time Complexity: O(MN)
// Space Complexity: O(MN)
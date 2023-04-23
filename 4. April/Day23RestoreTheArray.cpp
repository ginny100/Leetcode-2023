/**
 * @file Day23RestoreTheArray.cpp
 * @author Ginny Dang
 * @brief 1416. Restore The Array (https://leetcode.com/problems/restore-the-array/description/)
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Note:
 * - I was not able to come up with the solution to this problem.
 * - I refered to this post https://leetcode.com/problems/restore-the-array/solutions/585552/java-c-dfs-memoization-clean-code/?orderBy=most_votes
 */

class Solution
{
private:
    int mod = 1e9 + 7;
    int dfs(const string &s, long k, int i, vector<int> &dp)
    {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 0;
        long num = 0;

        for (int j = i; j < s.size(); j++)
        {
            num = num * 10 + s[j] - '0';
            if (num > k)
                break;
            ans += dfs(s, k, j + 1, dp);
            ans %= mod;
        }
        return dp[i] = ans;
    }

public:
    int numberOfArrays(string s, int k)
    {
        vector<int> dp(s.size(), -1);
        return dfs(s, k, 0, dp);
    }
};

// Time Complexity: O(n * log10(k))
// Space Complexity: O(n)
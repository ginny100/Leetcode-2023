/**
 * @file Day31BestTeamWithNoConflicts.cpp
 * @author Ginny Dang
 * @brief 1626. Best Team With No Conflicts (https://leetcode.com/problems/best-team-with-no-conflicts/description/)
 * @version 0.1
 * @date 2023-01-31
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief High level idea: Dynamic Programming "Longest increasing subsequence"
 */

class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        // Gather all {age : score} pairs
        vector<pair<int, int>> ageToScore;
        for (int i = 0; i < n; i++)
            ageToScore.push_back({ages[i], scores[i]});

        // Sort by ages
        sort(ageToScore.begin(), ageToScore.end());

        vector<int> lnds(n, 0); // lnds[i] is the max total score ending at i
        for (int i = 0; i < n; i++)
        {
            lnds[i] = ageToScore[i].second;
            for (int j = 0; j < i; j++)
                if (ageToScore[j].second <= ageToScore[i].second)
                    lnds[i] = max(lnds[i], lnds[j] + ageToScore[i].second);
        }

        return *max_element(lnds.begin(), lnds.end());
    }
};

// Time Complexity: O(N^2)
// Space Complexity: O(N)
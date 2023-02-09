/**
 * @file Day9NamingACompany.cpp
 * @author Ginny Dang
 * @brief 2306. Naming a Company (https://leetcode.com/problems/naming-a-company/description/)
 * @version 0.1
 * @date 2023-02-08
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New algorithm learned from the Official Solution
 * - Group words in ideas by their initials in initial_group, an array of sets of length 26, and initialize answer as 0.
 * - Iterate over every pair of groups. For each group i and j, get the number of suffixes num_of_mutual that appears in both groups.
 * - We can swap every distinct suffix in group i with every distinct suffix in group j, increment answer by 2 * (len(group[i]) - num_of_mutual) * (len(group[j]) - num_of_mutual)
 * - Return answer.
 */

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        long long answer = 0;
        unordered_set<string> initialGroup[26];

        for (string &idea : ideas)
            initialGroup[idea[0] - 'a'].insert(idea.substr(1));

        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                int numOfMutual = 0;
                for (auto &ideaA : initialGroup[i])
                    if (initialGroup[j].count(ideaA))
                        numOfMutual++;

                answer += 2LL * (initialGroup[i].size() - numOfMutual) * (initialGroup[j].size() - numOfMutual);
            }
        }

        return answer;
    }
};

// Time Complexity: O(M * N) where N is the number of words in ideas and M is the average length of a word.
// Space Complexity: O(M * N) where N is the number of words in ideas and M is the average length of a word.
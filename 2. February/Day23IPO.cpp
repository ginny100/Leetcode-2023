/**
 * @file Day23IPO.cpp
 * @author Ginny Dang
 * @brief 502. IPO (https://leetcode.com/problems/ipo/description/)
 * @version 0.1
 * @date 2023-02-23
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++)
            projects.emplace_back(capital[i], profits[i]);
        sort(projects.begin(), projects.end());

        priority_queue<std::pair<int, int>> pq; // {profits, capital}
        int lastPos = -1;
        for (int i = 0; i < n; i++)
        {
            if (projects[i].first <= w)
            {
                pq.push({projects[i].second, projects[i].first}); // when pushing into the max heap, it should be {profits[i], capital[i]} because we want to compare by profit and take the maximum one
                lastPos = i;
            }
            else
                break;
        }
        if (pq.empty())
            return w;

        for (int i = 0; i < min(k, n); i++)
        {
            w += pq.top().first;
            pq.pop();

            for (int j = lastPos + 1; j < n; j++)
            {
                if (projects[j].first <= w)
                {
                    pq.push({projects[j].second, projects[j].first});
                    lastPos = j;
                }
                else
                    break;
            }

            if (pq.empty())
                break;
        }
        return w;
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(N)
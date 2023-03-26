/**
 * @file Day26LongestCycleInAGraph.cpp
 * @author Ginny Dang
 * @brief 2360. Longest Cycle in a Graph (https://leetcode.com/problems/longest-cycle-in-a-graph/description/)
 * @version 0.1
 * @date 2023-03-26
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int cycleLength(int start, vector<int> &level, vector<int> &edges, int &prevLevel)
    {
        int length = -1;
        int curr = start;

        while (curr != -1)
        {
            if (level[curr] == 0)
                level[curr] = ++prevLevel;
            else if (level[curr] >= level[start])
            {
                length = prevLevel - level[curr] + 1;
                break;
            }
            else
                break;

            curr = edges[curr]; // cur = cur->next
        }

        return length;
    }

    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<int> level(n, 0);
        int result = -1;
        int prevLevel = 0;

        for (int i = 0; i < n; i++)
            if (level[i] == 0)
                result = max(result, cycleLength(i, level, edges, prevLevel));

        return result;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
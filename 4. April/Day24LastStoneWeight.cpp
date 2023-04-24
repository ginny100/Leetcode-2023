/**
 * @file Day24LastStoneWeight.cpp
 * @author Ginny Dang
 * @brief 1046. Last Stone Weight (https://leetcode.com/problems/last-stone-weight/description/)
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>, less<int>> hq;

        for (int stone : stones)
            hq.push(stone);

        while (hq.size() != 1)
        {
            int top0 = hq.top();
            hq.pop();
            int top1 = hq.top();
            int newTop = top0 - top1;
            hq.pop();
            hq.push(newTop);
        }

        return hq.top();
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
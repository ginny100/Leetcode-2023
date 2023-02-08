/**
 * @file Day8JumpGameII.cpp
 * @author Ginny Dang
 * @brief 45. Jump Game II (https://leetcode.com/problems/jump-game-ii/description/)
 * @version 0.1
 * @date 2023-02-07
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> minJumps(n, INT_MAX);
        minJumps[0] = 0; // No need to jump to the starting point

        // Considering each pos i
        for (int i = 0; i < n; i++)
        {
            // Optimize by not considering all positions that sure cannot reach i with 1 jump
            int minJ;
            minJ = i > 1000 ? i - 1000 : 0;
            // Considering all positions j's before i
            for (int j = minJ; j < i; j++)
            {
                // Check if pos i can be reached fro the current pos j
                if (nums[j] >= (i - j))
                    minJumps[i] = min(minJumps[i], minJumps[j] + 1);
                // Otherwise, go to the next pos j to find min_jumps[i]
            }
        }

        return minJumps[n - 1];
    }
};

// Time Complexity: O(1000*N) or O(10^3 * 10^4) -> O(10^7)
// Space Complexity: O(N)
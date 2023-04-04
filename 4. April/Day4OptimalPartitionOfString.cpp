/**
 * @file Day4OptimalPartitionOfString.cpp
 * @author Ginny Dang
 * @brief 2405. Optimal Partition of String (https://leetcode.com/problems/optimal-partition-of-string/description/)
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int partitionString(string s)
    {
        vector<int> lastSeen(26, -1); // stores the most recent position of each character
        int count = 1;                // number of substrings formed so far
        int substringStart = 0;       // the starting index of the substring currently under consideration

        for (int i = 0; i < s.length(); i++)
        {
            if (lastSeen[s[i] - 'a'] >= substringStart)
            {
                count++;
                substringStart = i;
            }
            lastSeen[s[i] - 'a'] = i;
        }

        return count;
    }
};

// Time complexity: O(n)
// Space complexity: O(1) or O(26) to be exact
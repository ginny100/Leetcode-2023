/**
 * @file Day11RemovingStarsFromAString.cpp
 * @author Ginny Dang
 * @brief 2390. Removing Stars From a String (https://leetcode.com/problems/removing-stars-from-a-string/description/)
 * @version 0.1
 * @date 2023-04-10
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    string removeStars(string s)
    {
        vector<char> stack;

        for (char c : s)
        {
            if (c == '*')
            {
                if (!stack.empty())
                    stack.pop_back();
            }
            else
                stack.push_back(c);
        }

        return string(stack.begin(), stack.end());
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
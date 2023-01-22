/**
 * @file Day22PalindromePartitioning.cpp
 * @author Ginny Dang
 * @brief 131. Palindrome Partitioning (https://leetcode.com/problems/palindrome-partitioning/description/)
 * @version 0.1
 * @date 2023-01-22
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool isPalindrome(string &s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left] != s[right])
                return false;
            else
            {
                left++;
                right--;
            }
        }

        return true;
    }

    void search(string &s, int start, vector<int> &breakPoints, vector<vector<string>> &palindromeLists)
    {
        if (start == s.length())
        {
            vector<string> palindromes;
            int last = 0;
            for (int bp : breakPoints)
            {
                palindromes.push_back(s.substr(last, bp - last + 1));
                last = bp + 1;
            }
            palindromeLists.push_back(palindromes);
        }
        else
        {
            // Break point right after start
            if (isPalindrome(s, breakPoints.size() ? breakPoints[breakPoints.size() - 1] + 1 : 0, start))
            {
                breakPoints.push_back(start);
                search(s, start + 1, breakPoints, palindromeLists);
                breakPoints.pop_back();
            }
            // No break point right after start
            if (start != s.length() - 1)
                search(s, start + 1, breakPoints, palindromeLists);
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> palindromeLists;
        vector<int> breakPoints; // ending points of all palindrome substrings

        search(s, 0, breakPoints, palindromeLists);

        return palindromeLists;
    }
};

// Time Complexity: O(2^N * N)
// Space Complexity: O(2^N * N)
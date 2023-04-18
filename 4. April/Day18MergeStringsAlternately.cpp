/**
 * @file Day18MergeStringsAlternately.cpp
 * @author Ginny Dang
 * @brief 1768. Merge Strings Alternately (https://leetcode.com/problems/merge-strings-alternately/description/)
 * @version 0.1
 * @date 2023-04-17
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result = "";
        int n = min(word1.length(), word2.length());
        int ptr = 0;

        while (ptr < n)
        {
            result += word1[ptr];
            result += word2[ptr];
            ptr++;
        }

        if (ptr <= word1.length() - 1)
            result += word1.substr(ptr);

        if (ptr <= word2.length() - 1)
            result += word2.substr(ptr);

        return result;
    }
};

// Time Complexity: O(M + N) where M and N are the lengths of 2 words
// Space Complexity: O(1)
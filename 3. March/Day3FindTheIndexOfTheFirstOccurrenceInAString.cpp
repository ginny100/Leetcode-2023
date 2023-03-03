/**
 * @file Day3FindTheIndexOfTheFirstOccurrenceInAString.cpp
 * @author Ginny Dang
 * @brief 28. Find the Index of the First Occurrence in a String (https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.length();
        int n = needle.length();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i + j >= m) || (haystack[i + j] != needle[j]))
                    break;
                if (j + 1 == n)
                    return i;
            }
        }

        return -1;
    }
};

// Time Complexity: O(M*N)
// Space Complexity: O(1)
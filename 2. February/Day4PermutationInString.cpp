/**
 * @file Day4PermutationInString.cpp
 * @author Ginny Dang
 * @brief 567. Permutation in String (https://leetcode.com/problems/permutation-in-string/description/)
 * @version 0.1
 * @date 2023-02-04
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool match(int s1Map[], int s2Map[])
    {
        for (int i = 0; i < 26; i++)
            if (s1Map[i] > s2Map[i])
                return false;
        return true;
    }

    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        int s1Map[26] = {};
        int s2Map[26] = {};

        for (int i = 0; i < s1.length(); i++)
        {
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++)
        {
            if (match(s1Map, s2Map))
                return true;

            s2Map[s2[i + s1.length()] - 'a']++;
            s2Map[s2[i] - 'a']--;
        }

        return match(s1Map, s2Map);
    }
};

// Time Complexity: O(max(min(M, N), (M - N))) where M = s1.length(), N = s2.length()
// Space Complexity: O(1)
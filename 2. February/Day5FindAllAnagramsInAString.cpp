/**
 * @file Day5FindAllAnagramsInAString.cpp
 * @author Ginny Dang
 * @brief 438. Find All Anagrams in a String (https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)
 * @version 0.1
 * @date 2023-02-05
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool match(int mapS[], int mapP[])
    {
        for (int i = 0; i < 26; i++)
            if (mapS[i] != mapP[i])
                return false;
        return true;
    }

    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;

        if (p.length() > s.length())
            return result;

        int mapS[26] = {};
        int mapP[26] = {};

        for (char c : p)
            mapP[c - 'a']++;

        for (int i = 0; i < p.length(); i++)
            mapS[s[i] - 'a']++;

        for (int i = 1; i + p.length() <= s.length(); i++)
        {
            if (match(mapS, mapP))
                result.push_back(i - 1);
            mapS[s[i - 1] - 'a']--;
            mapS[s[i + p.length() - 1] - 'a']++;
        }

        if (match(mapS, mapP))
            result.push_back(s.length() - p.length());

        return result;
    }
};

// Time Complexity: O(26 * N)
// Space Complexity: O(1) or O(26) to be exact
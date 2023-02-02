/**
 * @file Day2VerifyingAnAlienDictionary.cpp
 * @author Ginny Dang
 * @brief 953. Verifying an Alien Dictionary (https://leetcode.com/problems/verifying-an-alien-dictionary/description/)
 * @version 0.1
 * @date 2023-02-01
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> charToRank;
        for (int i = 0; i < order.length(); i++)
            charToRank.insert({order[i], i});

        for (int i = 1; i < words.size(); i++)
        {
            string word1 = words[i - 1];
            string word2 = words[i];
            int minLength = min(word1.length(), word2.length());
            for (int j = 0; j < minLength; j++)
            {
                // cout << word1[j] << " " << word2[j] << "\n";
                if (charToRank[word1[j]] > charToRank[word2[j]])
                    return false;
                else if (charToRank[word1[j]] == charToRank[word2[j]])
                {
                    if (j == minLength - 1)
                        if (word1.length() > word2.length())
                            return false;
                    continue;
                }
                else
                    break;
            }
        }
        return true;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
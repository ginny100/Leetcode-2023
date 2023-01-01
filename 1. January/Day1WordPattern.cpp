/**
 * @file Day1WordPattern.cpp
 * @author Ginny Dang
 * @brief 290. Word Pattern (https://leetcode.com/problems/word-pattern/)
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        // Split the given string into words
        stringstream ss(s);
        string word;
        vector<string> words;
        while (getline(ss, word, ' '))
        {
            words.push_back(word);
        }

        if (words.size() != pattern.length())
            return false;

        // Match each letter in pattern to a word
        map<char, string> charToWord;
        for (int i = 0; i < pattern.length(); i++)
        {
            if (charToWord.count(pattern[i]))
            {
                if (charToWord[pattern[i]].compare(words[i]) != 0)
                    return false;
            }
            else
                charToWord[pattern[i]] = words[i];
        }

        // Match each word to a letter in pattern
        map<string, char> wordToChar;
        for (int i = 0; i < words.size(); i++)
        {
            if (wordToChar.count(words[i]))
            {
                if (wordToChar[words[i]] != pattern[i])
                    return false;
            }
            else
                wordToChar[words[i]] = pattern[i];
        }

        // Compare
        for (auto pair : charToWord)
            if (pair.first != wordToChar[pair.second])
                return false;

        return true;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
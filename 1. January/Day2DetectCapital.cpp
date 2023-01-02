/**
 * @file Day2DetectCapital.cpp
 * @author Ginny Dang
 * @brief 520. Detect Capital (https://leetcode.com/problems/detect-capital/description/)
 * @version 0.1
 * @date 2023-01-02
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        auto allUpper = [](int start, int end, string word) -> bool
        {
            for (int i = start; i <= end; i++)
                if (islower(word[i]))
                    return false;
            return true;
        };

        auto allLower = [](int start, int end, string word) -> bool
        {
            for (int i = start; i <= end; i++)
                if (isupper(word[i]))
                    return false;
            return true;
        };

        bool capFirst = isupper(word[0]);
        if (capFirst)
            return (allUpper(0, word.length() - 1, word) || allLower(1, word.length() - 1, word));
        else
            return allLower(1, word.length() - 1, word);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
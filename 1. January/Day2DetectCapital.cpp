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
        auto allUpper = [](string str) -> bool
        {
            for (char c : str)
                if (islower(c))
                    return false;
            return true;
        };

        auto allLower = [](string str) -> bool
        {
            for (char c : str)
                if (isupper(c))
                    return false;
            return true;
        };

        bool capFirst = isupper(word[0]);
        if (capFirst)
            return (allUpper(word) || allLower(word.substr(1)));
        else
            return allLower(word.substr(1));
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
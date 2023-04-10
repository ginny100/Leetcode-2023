/**
 * @file Day10ValidParentheses.cpp
 * @author Ginny Dang
 * @brief 20. Valid Parentheses (https://leetcode.com/problems/valid-parentheses/description/)
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
private:
    char opening(char c)
    {
        if (c == ')')
            return '(';
        if (c == ']')
            return '[';
        if (c == '}')
            return '{';
        return '\n'; // Default returned value for the compiler to run, with the given constraints, this value will never be returned
    }

public:
    bool isValid(string s)
    {
        stack<char> S;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                S.push(s[i]);
            else
            {
                if (S.empty())
                    return false;
                char c = S.top();
                if (c != opening(s[i]))
                    return false;
                S.pop();
            }
        }
        return S.empty();
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
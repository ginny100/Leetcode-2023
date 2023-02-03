/**
 * @file Day3ZigzagConversion.cpp
 * @author Ginny Dang
 * @brief 6. Zigzag Conversion (https://leetcode.com/problems/zigzag-conversion/description/)
 * @version 0.1
 * @date 2023-02-02
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string result;
        int increment = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++)
        {
            for (int j = i; j < s.length(); j += increment)
            {
                result += s[j];
                if (i > 0 && i < numRows - 1 && j + increment - 2 * i < s.length())
                    result += s[j + increment - 2 * i];
            }
        }
        return result;
    }
};

// Time Complexity: O(M * N)
// Space Complexity: O(1)
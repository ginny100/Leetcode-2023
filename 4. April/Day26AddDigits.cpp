/**
 * @file Day26AddDigits.cpp
 * @author Ginny Dang
 * @brief 258. Add Digits (https://leetcode.com/problems/add-digits/description/)
 * @version 0.1
 * @date 2023-04-25
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)
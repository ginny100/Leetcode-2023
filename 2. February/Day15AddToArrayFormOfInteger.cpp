/**
 * @file Day15AddToArrayFormOfInteger.cpp
 * @author Ginny Dang
 * @brief 989. Add to Array-Form of Integer (https://leetcode.com/problems/add-to-array-form-of-integer/description/)
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int cur = k;
        int carry = 0;
        vector<int> newNum;

        for (int i = num.size() - 1; i > -1; i--)
        {
            // cout << cur << "\n";
            // cout << num[i] << " " << cur % 10 << " " << carry << "\n";
            int currDigit = num[i] + (cur % 10) + carry;

            if (currDigit > 9 || i == 0)
                carry = currDigit / 10;
            else
                carry = 0;

            newNum.push_back(currDigit % 10);
            cur /= 10;
            // cout << cur << "\n" << "\n";
        }

        cur += carry;
        while (cur / 10 != 0)
        {
            newNum.push_back(cur % 10);
            cur /= 10;
        }
        if (cur != 0)
            newNum.push_back(cur);

        reverse(newNum.begin(), newNum.end());

        return newNum;
    }
};

// Time Complexity: O(max(N,logK))
// Space Complexity: O(max(N,logK))
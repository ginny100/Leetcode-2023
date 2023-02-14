/**
 * @file Day14AddBinary.cpp
 * @author Ginny Dang
 * @brief 67. Add Binary (https://leetcode.com/problems/add-binary/description/)
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int maxLength = max(a.length(), b.length());
        while (a.length() != maxLength)
            a = '0' + a;
        while (b.length() != maxLength)
            b = '0' + b;

        int carry = 0;
        string answer = "";
        for (int i = maxLength - 1; i > -1; i--)
        {
            int currSumDigit = int(a[i] - '0') + int(b[i] - '0') + carry;
            answer = to_string(currSumDigit % 2) + answer;
            carry = currSumDigit / 2;
            cout << currSumDigit << " " << carry << "\n";
        }

        if (carry == 1)
            answer = '1' + answer;

        return answer;
    }
};

// Time Complexity: O(max(M, N))
// Space Complexity: O(max(M, N))
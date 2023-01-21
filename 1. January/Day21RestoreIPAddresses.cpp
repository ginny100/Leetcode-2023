/**
 * @file Day21RestoreIPAddresses.cpp
 * @author Ginny Dang
 * @brief 93. Restore IP Addresses (https://leetcode.com/problems/restore-ip-addresses/description/)
 * @version 0.1
 * @date 2023-01-21
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool valid(string &s, int start, int length)
    {
        return length == 1 || (s[start] != '0' && (length < 3 || s.substr(start, length) <= "255"));
    }

    void search(string &s, int start, vector<int> &dots, vector<string> &ips)
    {
        int remainingLength = s.length() - start;        // the string length we want to process
        int remainingNumberOfIntegers = 4 - dots.size(); // number of integers we have left to form

        // Make sure that each integer has 0 to 3 digits
        if (remainingLength > remainingNumberOfIntegers * 3 || remainingLength < remainingNumberOfIntegers)
            return;

        if (remainingNumberOfIntegers == 1)
        {
            if (valid(s, start, remainingLength))
            {
                string ip = "";
                int last = 0;
                for (int dot : dots)
                {
                    ip += s.substr(last, dot) + '.';
                    last += dot;
                }
                ip += s.substr(start);
                ips.push_back(ip);
            }
            return;
        }

        for (int pos = 1; pos <= min(3, remainingLength); pos++)
        {
            dots.push_back(pos);
            if (valid(s, start, pos))
                search(s, start + pos, dots, ips);
            dots.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ips;
        vector<int> dots; // saves distances for the dots we have added so far

        search(s, 0, dots, ips);

        return ips;
    }
};

// Time Complexity: O(M^N * N)
// Space Complexity: O(MN)
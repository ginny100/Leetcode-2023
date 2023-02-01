/**
 * @file Day1GreatestCommonDivisorOfStrings.cpp
 * @author Ginny Dang
 * @brief 1071. Greatest Common Divisor of Strings (https://leetcode.com/problems/greatest-common-divisor-of-strings/description/)
 * @version 0.1
 * @date 2023-01-31
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool isDivisor(string t, string s)
    {
        if (s.length() % t.length() != 0)
            return false;

        for (int i = 0; i < s.length(); i += t.size())
        { // O(N)
            string u = s.substr(i, t.length());
            if (t.compare(u) != 0)
                return false;
        }

        return true;
    }

    string gcdOfStrings(string str1, string str2)
    {
        if (str1.length() < str2.length())
            swap(str1, str2);

        for (int i = str2.length(); i >= 0; i--)
        { // O(N)
            if (str1.length() % (i + 1) == 0 && str2.length() % (i + 1) == 0)
            {
                string str3 = str2.substr(0, i + 1);
                if (isDivisor(str3, str2) && isDivisor(str3, str1))
                    return str3;
                /* str3 is the longest possible candidate and
                   lengths of those strings which are shorter than it are divisors of str3.length
                   If str3 is not the gcd of str1 and str2,
                   those strings described above can't be either
                   -> we can stop the check here */
                break;
            }
        }

        return "";
    }
};

// Time Complexity: O(m+n)
// Space Complexity: O(max(m,n))
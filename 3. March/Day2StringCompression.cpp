/**
 * @file Day2StringCompression.cpp
 * @author Ginny Dang
 * @brief 443. String Compression (https://leetcode.com/problems/string-compression/description/)
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        if (chars.size() == 1)
            return 1;

        int groupStart = 0;
        int nextChar = 0;
        while (groupStart < chars.size())
        {
            // Determine the current group and its length
            int groupEnd = groupStart;
            while (groupEnd + 1 < chars.size() && chars[groupStart] == chars[groupEnd + 1])
                groupEnd++;
            int groupLength = groupEnd - groupStart + 1;
            string groupLengthStr = to_string(groupLength);

            // Compress the current group and add it to the chars array
            chars[nextChar++] = chars[groupStart];
            if (groupLength != 1)
                for (int i = 0; i < groupLengthStr.size(); i++)
                    chars[nextChar++] = groupLengthStr[i];

            // Update the start and end of the new group
            groupStart = groupEnd + 1;
        }

        while (nextChar < chars.size())
            chars.pop_back();

        return chars.size();
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
/**
 * @file Day12SimplifyPath.cpp
 * @author your name (you@domain.com)
 * @brief 71. Simplify Path (https://leetcode.com/problems/simplify-path/description/)
 * @version 0.1
 * @date 2023-04-11
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
private:
    vector<string> split(const string &s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);

        while (getline(tokenStream, token, delimiter))
            tokens.push_back(token);

        return tokens;
    }

public:
    string simplifyPath(string path)
    {
        vector<string> splittedPaths = split(path, '/');
        vector<string> levels;
        string canonicalPath = "/";

        for (auto &path : splittedPaths)
        {
            cout << path << "\n";
            if (path == "" || path == ".")
                continue;
            else if (path == "..")
            {
                if (levels.size() != 0)
                    levels.pop_back();
            }
            else
                levels.push_back(path);
        }

        for (int i = 0; i < levels.size(); i++)
        {
            canonicalPath += levels[i];
            if (i != levels.size() - 1)
                canonicalPath += "/";
        }

        return canonicalPath;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
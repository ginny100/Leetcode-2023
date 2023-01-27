/**
 * @file Day27ConcatenatedWords.cpp
 * @author Ginny Dang
 * @brief 472. Concatenated Words (https://leetcode.com/problems/concatenated-words/description/)
 * @version 0.1
 * @date 2023-01-27
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New idea learned from the Official Solution
 * - For each word, construct an implicit graph
 * -- All prefixes are nodes. Each prefix aka node is represented by its length in range [0, word.length]
 * -- There're (word.length + 1) nodes in each graph
 * -- There's a directed edge from node i to node j, if there're prefixes i and j such that
 * ---- 0 <= i < j <= word.length and
 * ---- prefix j = prefix i + word in the input
 * - DFS on each word's graph
 * -- Add that word to the answer if
 * ---- The node word.length can be reached from node 0 in the graph
 */

class Solution
{
public:
    bool dfs(string &word, int prefixLength, vector<bool> &visited, unordered_set<string> &allWords)
    {
        if (prefixLength == word.length())
            return true;

        if (visited[prefixLength])
            return false;

        visited[prefixLength] = true;

        /*
         * prefixLength = 0 -> None of the non-empty prefix/nodes has been explored
         * prefixLength > 0 -> Some of the non-empty prefix/nodes have been explored
         */
        for (int i = word.length() - (prefixLength == 0 ? 1 : 0); i > prefixLength; i--)
        {
            // The prefix represented by the current prefixLength + 1 of the given words
            // becomes one of the remaining prefixes
            if (allWords.count(word.substr(prefixLength, i - prefixLength)) && dfs(word, i, visited, allWords))
                return true;
        }

        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> concatenatedWords;
        unordered_set<string> allWords(words.begin(), words.end());

        for (string &word : words)
        {
            vector<bool> visited(word.length() + 1, false);
            if (dfs(word, 0, visited, allWords))
                concatenatedWords.push_back(word);
        }

        return concatenatedWords;
    }
};

// Time Complexity: O(M^3 * N)
// Space Complexity: O(M * N)
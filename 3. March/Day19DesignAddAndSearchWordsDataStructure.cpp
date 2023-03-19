/**
 * @file Day19DesignAddAndSearchWordsDataStructure.cpp
 * @author Ginny Dang
 * @brief 211. Design Add and Search Words Data Structure (https://leetcode.com/problems/design-add-and-search-words-data-structure/description/)
 * @version 0.1
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

class WordDictionary
{
private:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> children;
        int countWords;

        TrieNode() : countWords(0) {}

        ~TrieNode()
        {
            for (auto &child : children)
                delete child.second;
        }
    };

    TrieNode *root;

    // O(26^3)
    bool dfs(TrieNode *currNode, int level, string &word)
    {
        if (level == word.length())
            return currNode->countWords > 0;
        else
        {
            if (word[level] == '.')
            {
                for (const auto &child : currNode->children)
                    if (dfs(child.second, level + 1, word))
                        return true;
            }
            else
            {
                if (currNode->children.count(word[level]))
                    if (dfs(currNode->children[word[level]], level + 1, word))
                        return true;
            }
        }
        return false;
    }

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    ~WordDictionary()
    {
        delete root;
    }

    // O(25)
    void addWord(string word)
    {
        TrieNode *currNode = root;
        for (char letter : word)
        {
            if (!currNode->children.count(letter))
                currNode->children[letter] = new TrieNode();
            currNode = currNode->children[letter];
        }
        currNode->countWords++;
    }

    // O(26^3)
    bool search(string word)
    {
        return dfs(root, 0, word);
    }
};

// Time Complexity: O(26^3) for search(), O(N) for addWord() where N is the length of the input word
// Space Complexity: O(N)

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

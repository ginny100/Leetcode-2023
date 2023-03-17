/**
 * @file Day17ImplementTriePrefixTree.cpp
 * @author Ginny Dang
 * @brief 208. Implement Trie (Prefix Tree) (https://leetcode.com/problems/implement-trie-prefix-tree/description/)
 * @version 0.1
 * @date 2023-03-16
 *
 * @copyright Copyright (c) 2023
 *
 */

class Trie
{
private:
    // The nested structure representing a node
    struct TrieNode
    {
        // Properties
        unordered_map<char, TrieNode *> children;
        bool isWord;

        // Constructor
        TrieNode() : isWord(false) {}

        // Destructor
        ~TrieNode()
        {
            for (auto &child : children)
                delete child.second;
        }
    };

    TrieNode *root;

    // Helper method to find the last node in the sequence of characters in the input string
    // O(L) where L is the length of the prefix
    const TrieNode *find(const string &prefix) const
    {
        const TrieNode *currNode = root;
        for (char ch : prefix)
        {
            if (!currNode->children.count(ch))
                return nullptr;
            currNode = currNode->children.at(ch);
        }
        return currNode;
    }

public:
    // Constructor
    Trie()
    {
        root = new TrieNode();
    }

    // Destructor
    ~Trie()
    {
        delete root;
    }

    // Method to insert a word into the trie
    // O(L) where L is the length of the word
    void insert(string word)
    {
        TrieNode *currNode = root;
        for (char ch : word)
        {
            if (!currNode->children.count(ch))
                currNode->children[ch] = new TrieNode();
            currNode = currNode->children[ch];
        }
        currNode->isWord = true;
    }

    // Method to search for a word in the trie
    // O(L) where L is the length of the word
    bool search(string word)
    {
        const TrieNode *node = find(word);
        return node && node->isWord;
    }

    // Method to check if prefix belongs to any existing word in the trie
    // O(L) where L is the length of the prefix
    bool startsWith(string prefix)
    {
        return find(prefix) != nullptr;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(max_string_length) or O(2000) due to the given constraint

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
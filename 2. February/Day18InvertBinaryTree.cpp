/**
 * @file Day18InvertBinaryTree.cpp
 * @author Ginny Dang
 * @brief 226. Invert Binary Tree (https://leetcode.com/problems/invert-binary-tree/description/)
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root || (!root->left && !root->right))
            return root;
        if (root->left)
            invertTree(root->left);
        if (root->right)
            invertTree(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
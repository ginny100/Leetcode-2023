/**
 * @file Day9BinaryTreePreorderTraversal.cpp
 * @author Ginny Dang
 * @brief 144. Binary Tree Preorder Traversal (https://leetcode.com/problems/binary-tree-preorder-traversal/description/)
 * @version 0.1
 * @date 2023-01-09
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return vector<int>();
        else
        {
            vector<int> node_values;
            node_values.push_back(root->val);
            vector<int> left_children = preorderTraversal(root->left);
            node_values.insert(node_values.end(), left_children.begin(), left_children.end());
            vector<int> right_children = preorderTraversal(root->right);
            node_values.insert(node_values.end(), right_children.begin(), right_children.end());
            return node_values;
        }
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
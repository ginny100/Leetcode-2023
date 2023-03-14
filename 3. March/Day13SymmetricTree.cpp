/**
 * @file Day13SymmetricTree.cpp
 * @author Ginny Dang
 * @brief 101. Symmetric Tree (https://leetcode.com/problems/symmetric-tree/description/)
 * @version 0.1
 * @date 2023-03-12
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
    bool compareSubtrees(TreeNode *root1, TreeNode *root2)
    {
        // Base cases
        if (!root1 && !root2)
            return true;
        else if (!root1 || !root2)
            return false;
        // Normal case
        else if (root1->val != root2->val)
            return false;
        else
            return compareSubtrees(root1->left, root2->right) && compareSubtrees(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        // Root has no children
        if (!root->left && !root->right)
            return true;
        // Root has some children
        return compareSubtrees(root->left, root->right);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
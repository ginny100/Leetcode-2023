/**
 * @file Day16MaximumDepthOfBinaryTree.cpp
 * @author Ginny Dang
 * @brief 104. Maximum Depth of Binary Tree (https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)
 * @version 0.1
 * @date 2023-02-15
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
    int findDepth(TreeNode *node, int depth, int maxDepth)
    {
        if (!node)
            return 0;
        else if (!node->left && !node->right)
        {
            maxDepth = max(maxDepth, depth);
        }
        else
        {
            int maxLeftDepth = findDepth(node->left, depth + 1, maxDepth);
            int maxRightDepth = findDepth(node->right, depth + 1, maxDepth);
            maxDepth = max(maxLeftDepth, maxRightDepth);
        }
        return maxDepth;
    }

    int maxDepth(TreeNode *root)
    {
        return findDepth(root, 1, 0);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
/**
 * @file Day17MinimumDistanceBetweenBSTNodes.cpp
 * @author Ginny Dang
 * @brief 783. Minimum Distance Between BST Nodes (https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/)
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
    pair<int, int> findMostNodes(TreeNode *root, int &result)
    {
        if (!root)
            return {};

        int minLeft = INT_MAX, maxLeft = INT_MIN;
        int minRight = INT_MAX, maxRight = INT_MIN;

        if (root->left)
        {
            pair<int, int> leftPair = findMostNodes(root->left, result);
            minLeft = leftPair.first;
            maxLeft = leftPair.second;
            result = min(result, abs(root->val - maxLeft));
        }
        else
            minLeft = root->val;

        if (root->right)
        {
            pair<int, int> rightPair = findMostNodes(root->right, result);
            minRight = rightPair.first;
            maxRight = rightPair.second;
            result = min(result, abs(root->val - minRight));
        }
        else
            maxRight = root->val;

        return {minLeft, maxRight};
    }

    int minDiffInBST(TreeNode *root)
    {
        int result = INT_MAX;
        findMostNodes(root, result);
        return result;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
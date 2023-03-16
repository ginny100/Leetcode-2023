/**
 * @file Day16ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
 * @author Ginny Dang
 * @brief 106. Construct Binary Tree from Inorder and Postorder Traversal (https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/)
 * @version 0.1
 * @date 2023-03-15
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
private:
    int treeSize;
    unordered_map<int, int> inMap;

    TreeNode *helpBuildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd)
    {
        // Base case
        if (inStart > inEnd)
            return NULL;
        // Normal cases
        //// Determine the current root node
        int curRootVal = postorder[postEnd];
        int inRootPos = inMap[curRootVal];
        TreeNode *curRoot = new TreeNode(curRootVal, NULL, NULL);
        // Define the range of the left and right subtrees of the current root
        //// Range of the left subtree in Inorder
        int inLeftStart = inStart;
        int inLeftEnd = inRootPos - 1;
        int leftTreeSize = (inLeftEnd - inLeftStart) + 1;
        //// Range of the right subtree in Inorder
        int inRightStart = inRootPos + 1;
        int inRightEnd = inEnd;
        //// Range of the left subtree in Postorder
        int postLeftStart = postStart;
        int postLeftEnd = postLeftStart + leftTreeSize - 1;
        //// Range of the right subtree in Postorder
        int postRightStart = postLeftEnd + 1;
        int postRightEnd = postEnd - 1;
        // Construct the left and right subtrees of the current root
        curRoot->left = helpBuildTree(inorder, inLeftStart, inLeftEnd, postorder, postLeftStart, postLeftEnd);
        curRoot->right = helpBuildTree(inorder, inRightStart, inRightEnd, postorder, postRightStart, postRightEnd);
        return curRoot;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // Edge case
        if (inorder.size() == 1)
            return new TreeNode(inorder[0], NULL, NULL);
        // Normal cases
        treeSize = inorder.size();
        for (int i = 0; i < treeSize; i++)
            inMap[inorder[i]] = i;
        return helpBuildTree(inorder, 0, treeSize - 1, postorder, 0, treeSize - 1);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
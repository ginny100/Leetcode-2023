/**
 * @file Day15.CheckCompletenessOfABinaryTree.cpp
 * @author Ginny Dang
 * @brief 958. Check Completeness of a Binary Tree (https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/)
 * @version 0.1
 * @date 2023-03-15
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New thing I've learned from this challenge
 * - Check if a binary tree is a Complete Binary Tree using BFS
 * -- At each level, check whether the left and right child nodes of the current node exist
 * ---- If left != NULL and right = NULL
 * ------> Mark the node as the last node
 * ---- If right != NULL and left = NULL
 * ------> Return false as a binary tree cannot have a right child without a left child
 * ---- If there's any node found after the last node has been found or there's a node with only 1 child
 * ------> Return false as this is not a complete binary tree
 * ---- If we reach the end of the tree without any issues
 * ------> Return true.
 * -- Use a boolean variable to keep track of whether we have already found the last node
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
    bool isCompleteTree(TreeNode *root)
    {
        // Base case: No node -> no level -> complete
        if (!root)
            return true;

        // Normal case: Check level by level from left to right with BFS
        queue<TreeNode *> q;
        q.push(root);
        bool lastNodeFound = false;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                if (lastNodeFound)
                    return false;
                q.push(curr->left);
            }
            else
                lastNodeFound = true;

            if (curr->right)
            {
                if (lastNodeFound)
                    return false;
                q.push(curr->right);
            }
            else
                lastNodeFound = true;
        }

        return true;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
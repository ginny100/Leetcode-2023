/**
 * @file Day19BinaryTreeZigzagLevelOrderTraversal.cpp
 * @author Ginny Dang
 * @brief 103. Binary Tree Zigzag Level Order Traversal (https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)
 * @version 0.1
 * @date 2023-02-18
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>();

        vector<TreeNode *> curLevel;
        curLevel.push_back(root);

        vector<vector<int>> zigzag;
        zigzag.push_back({root->val});

        int direction = -1;

        while (curLevel.size())
        {
            // Find all nodes of the next level
            vector<TreeNode *> temp(curLevel.size());
            copy(curLevel.begin(), curLevel.end(), temp.begin());
            curLevel.clear();
            direction *= -1;
            for (auto &node : temp)
            {
                if (node->left)
                    curLevel.push_back(node->left);
                if (node->right)
                    curLevel.push_back(node->right);
            }
            // Append all node vals of the current level to zigzag based on direction
            vector<int> tempVals;
            if (direction == 1)
                for (int i = curLevel.size() - 1; i > -1; i--)
                    tempVals.push_back(curLevel[i]->val);
            else
                for (int i = 0; i < curLevel.size(); i++)
                    tempVals.push_back(curLevel[i]->val);
            // Append the current level to the zigzag traversal
            if (tempVals.size())
                zigzag.push_back(tempVals);
        }

        return zigzag;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
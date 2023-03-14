/**
 * @file Day14SumRootToLeafNumbers.cpp
 * @author Ginny Dang
 * @brief 129. Sum Root to Leaf Numbers (https://leetcode.com/problems/sum-root-to-leaf-numbers/description/)
 * @version 0.1
 * @date 2023-03-13
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
    int allPathsSum = 0;

public:
    void rootToLeaf(TreeNode *curNode, vector<int> &curPath)
    {
        // curNode is NULL
        if (!curNode)
            return;
        // Add the curNode to curPath
        curPath.push_back(curNode->val);
        // curNode is the leaf node
        if (!curNode->left && !curNode->right)
        {
            string currPathSum = "";
            for (int num : curPath)
                currPathSum += to_string(num);
            this->allPathsSum += stoi(currPathSum);
        }
        // cur_node is not the leaf node
        else
        {
            // Explore left branch of cur_node
            if (curNode->left)
                rootToLeaf(curNode->left, curPath);
            // Explore right branch of cur_node
            if (curNode->right)
                rootToLeaf(curNode->right, curPath);
        }
        // Backtrack
        curPath.pop_back();
    }

    int sumNumbers(TreeNode *root)
    {
        vector<int> curPath;
        rootToLeaf(root, curPath);
        return this->allPathsSum;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(H)
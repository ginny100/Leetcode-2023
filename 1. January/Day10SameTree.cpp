/**
 * @file Day10SameTree.cpp
 * @author Ginny Dang
 * @brief 100. Same Tree (https://leetcode.com/problems/same-tree/description/)
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New thing I've learned from this challenge
 * If the 2 first conditions in this code were in reversed order, the whole program would be ruined in
 * if (!p && !q) MUST go before else if (!p || !q)
 * This is due to the nature of C++
 *
 * Checking (!p || !q) before (!p && !q) causes the problem because if both p and q are null,
 * the condition (!p || !q) returns false right away due to p is null without even considering whether q is null or not.
 * Meanwhile, if both p and q are null, we should return true.
 * Therefore, the "tighter" condition, which is (!p && !q) must come first.
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // Both trees are none
        if (!p && !q)
            return true;
        // 1 of the 2 trees is none
        else if (!p || !q)
            return false;
        // Both trees are not none
        // cout << p->val << " " << q->val << "\n";
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
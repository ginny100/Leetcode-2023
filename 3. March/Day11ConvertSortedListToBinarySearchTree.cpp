/**
 * @file Day11ConvertSortedListToBinarySearchTree.cpp
 * @author Ginny Dang
 * @brief 109. Convert Sorted List to Binary Search Tree (https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/)
 * @version 0.1
 * @date 2023-03-10
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    // O(logN)
    TreeNode *buildBST(vector<int> &nodeVals, int start, int end)
    {
        // Edge cases
        if (start == end)
            return new TreeNode(nodeVals[start]);
        else if (start > end)
            return NULL;

        // Normal cases
        int mid = (start + end) / 2;
        TreeNode *bst = new TreeNode(nodeVals[mid]);
        bst->left = buildBST(nodeVals, start, mid - 1);
        bst->right = buildBST(nodeVals, mid + 1, end);
        return bst;
    }

    // O(N)
    TreeNode *sortedListToBST(ListNode *head)
    {
        // Gather values of all nodes in the linked list
        vector<int> nodeVals;
        ListNode *curr = head;
        while (curr)
        {
            nodeVals.push_back(curr->val);
            curr = curr->next;
        }

        // Build BST
        int n = nodeVals.size();
        TreeNode *bst = buildBST(nodeVals, 0, n - 1);
        return bst;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
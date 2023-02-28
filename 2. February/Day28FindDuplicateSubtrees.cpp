/**
 * @file Day28FindDuplicateSubtrees.cpp
 * @author Ginny Dang
 * @brief 652. Find Duplicate Subtrees (https://leetcode.com/problems/find-duplicate-subtrees/)
 * @version 0.1
 * @date 2023-02-27
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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> tripletToId;
        unordered_map<int, int> count;
        vector<TreeNode *> result;

        function<int(TreeNode *)> traverse = [&tripletToId, &count, &result, &traverse](TreeNode *node) -> int
        {
            if (node == nullptr)
                return 0;

            string triplet = to_string(traverse(node->left)) + "," + to_string(node->val) + "," + to_string(traverse(node->right));

            if (!tripletToId.count(triplet))
                tripletToId[triplet] = tripletToId.size() + 1;

            int id = tripletToId[triplet];
            count[id]++;
            if (count[id] == 2)
                result.push_back(node);

            return id;
        };

        traverse(root);
        return result;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
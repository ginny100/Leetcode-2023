/**
 * @file Day20MaximumWidthOfBinaryTree.cpp
 * @author Ginny Dang
 * @brief 662. Maximum Width of Binary Tree (https://leetcode.com/problems/maximum-width-of-binary-tree/description/)
 * @version 0.1
 * @date 2023-04-20
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int maxWidth = 0;
        list<pair<TreeNode *, long long>> queue;
        queue.push_back({root, 0});

        while (!queue.empty())
        {
            pair<TreeNode *, long long> head = queue.front();
            int currLevelSize = queue.size();
            pair<TreeNode *, long long> curr;

            for (int i = 0; i < currLevelSize; i++)
            {
                curr = queue.front();
                queue.pop_front();
                TreeNode *node = curr.first;

                if (node->left != nullptr)
                    queue.push_back({node->left, static_cast<int>(2LL * curr.second)});

                if (node->right != nullptr)
                    queue.push_back({node->right, static_cast<int>(2LL * curr.second + 1)});
            }

            maxWidth = max(maxWidth, static_cast<int>(curr.second - head.second + 1LL));
        }

        return maxWidth;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
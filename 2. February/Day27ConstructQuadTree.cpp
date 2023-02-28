/**
 * @file Day27ConstructQuadTree.cpp
 * @author Ginny Dang
 * @brief 427. Construct Quad Tree (https://leetcode.com/problems/construct-quad-tree/description/)
 * @version 0.1
 * @date 2023-02-27
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    Node *generateNode(vector<vector<int>> &grid, int x1, int y1, int length)
    {
        // If the grid size is 1 -> return a leaf node
        if (length == 1)
            return new Node(grid[x1][y1], true);

        // 4 sub-matrices
        Node *topLeft = generateNode(grid, x1, y1, length / 2);
        Node *topRight = generateNode(grid, x1, y1 + length / 2, length / 2);
        Node *bottomLeft = generateNode(grid, x1 + length / 2, y1, length / 2);
        Node *bottomRight = generateNode(grid, x1 + length / 2, y1 + length / 2, length / 2);

        // If these 4 nodes are leaf nodes and have the same value -> return a leaf node with that same value
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
            return new Node(topLeft->val, true);

        // If these 4 nodes are not the same -> return a non-leaf node
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node *construct(vector<vector<int>> &grid)
    {
        return generateNode(grid, 0, 0, grid.size());
    }
};

// Time Complexity: O(N^2)
// Space Complexity: O(logN)
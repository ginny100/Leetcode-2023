/**
 * @file Day8CloneGraph.cpp
 * @author Ginny Dang
 * @brief 133. Clone Graph (https://leetcode.com/problems/clone-graph/description/)
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
private:
    Node *clonedNodes[101];

    void dfs(Node *u)
    {
        clonedNodes[u->val] = new Node(u->val);
        clonedNodes[u->val]->neighbors = vector<Node *>();

        for (auto v : u->neighbors)
        {
            if (!clonedNodes[v->val])
                dfs(v);
            Node *newU = clonedNodes[u->val];
            Node *newV = clonedNodes[v->val];
            newU->neighbors.push_back(newV);
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;

        dfs(node);

        return clonedNodes[node->val];
    }
};

// Time Complexity : O(N + M)
// Space Complexity : O(N)
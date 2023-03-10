/**
 * @file Day10LinkedListRandomNode.cpp
 * @author Ginny Dang
 * @brief 382. Linked List Random Node (https://leetcode.com/problems/linked-list-random-node/description/)
 * @version 0.1
 * @date 2023-03-10
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief New thing I've learned from this challenge
 * Reservoir Sampling method
 * References: https://www.youtube.com/watch?v=A1iwzSew5QY&t=1s
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
class Solution
{
    ListNode *head;

public:
    Solution(ListNode *head)
    {
        this->head = head;
    }

    int getRandom()
    {
        int scope = 1, chosenValue = 0;
        ListNode *curr = this->head;

        while (curr)
        {
            // Decide whether to include the element in the reservoir
            /* rand() % scope will be 0 only if rand() returns 0 or some multiple of scope */
            if (rand() % scope == 0)
                chosenValue = curr->val;
            // Move to the next node
            scope++;
            curr = curr->next;
        }

        return chosenValue;
    }
};

// Time Complexity: O(N) for getRandom()
// Space Complexity: O(1)

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
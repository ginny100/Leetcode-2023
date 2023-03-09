/**
 * @file Day9LinkedListCycleII.cpp
 * @author Ginny Dang
 * @brief 142. Linked List Cycle II (https://leetcode.com/problems/linked-list-cycle-ii/description/)
 * @version 0.1
 * @date 2023-03-08
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = NULL;
        while (fast->next && fast->next->next && slow->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                meet = slow;
                break;
            }
        }

        if (!meet)
            return NULL;

        ListNode *start = head;
        while (start != meet)
        {
            start = start->next;
            meet = meet->next;
        }
        return start;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
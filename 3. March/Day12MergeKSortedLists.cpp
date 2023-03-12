/**
 * @file Day12MergeKSortedLists.cpp
 * @author Ginny Dang
 * @brief 23. Merge k Sorted Lists (https://leetcode.com/problems/merge-k-sorted-lists/description/)
 * @version 0.1
 * @date 2023-03-11
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
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Define a custom comparison function
        auto cmp = [](pair<int, int> a, pair<int, int> b)
        {
            return a.first > b.first;
        };

        // Create a heap of {value, index} pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        for (int i = 0; i < lists.size(); i++)
            if (lists[i])
                minHeap.push({lists[i]->val, i});

        // Merge lists
        ListNode *curr = new ListNode();
        ListNode *dummy = curr;
        while (!minHeap.empty())
        {
            int idx = minHeap.top().second;
            minHeap.pop();

            curr->next = lists[idx];
            curr = curr->next;
            lists[idx] = lists[idx]->next;

            if (lists[idx])
                minHeap.push({lists[idx]->val, idx});
        }

        return dummy->next;
    }
};

// Time Complexity: O(Nlogk) where N is the number of nodes in the final linked list, k is the number of linked lists.
// Space Complexity: O(N) for creating a new linked list. O(k) for the priority queue. N is the number of nodes in the final linked list, k is the number of linked lists.
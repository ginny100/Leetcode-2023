/**
 * @file Day13ValidateStackSequences.cpp
 * @author Ginny Dang
 * @brief 946. Validate Stack Sequences (https://leetcode.com/problems/validate-stack-sequences/description/)
 * @version 0.1
 * @date 2023-04-12
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        vector<int> stack;
        int front = 0;

        for (int num : pushed)
        {
            stack.push_back(num);

            while (!stack.empty() && stack[stack.size() - 1] == popped[front])
            {
                stack.pop_back();
                front++;
            }
        }

        return stack.empty();
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
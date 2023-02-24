/**
 * @file Day24MinimizeDeviationInArray.cpp
 * @author Ginny Dang
 * @brief 1675. Minimize Deviation in Array (https://leetcode.com/problems/minimize-deviation-in-array/description/?orderBy=most_votes)
 * @version 0.1
 * @date 2023-02-24
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> evens; // a max heap
        int minimum = INT_MAX;     // keeps track of the smallest element in evens
        for (int num : nums)
        {
            if (num % 2 != 0)
                num *= 2;
            evens.push(num);
            minimum = min(minimum, num);
        }

        int minDeviat = INT_MAX;
        while (!evens.empty())
        {
            int maximum = evens.top();
            evens.pop();
            minDeviat = min(minDeviat, maximum - minimum);
            if (maximum % 2 == 0)
            {
                evens.push(maximum / 2);
                minimum = min(minimum, maximum / 2);
            }
            else
                break;
        }
        return minDeviat;
    }
};

// Time Complexity: O(Klog⁡(N)) = O(Nlog⁡(M)log⁡(N))
// Space Complexity: O(N)

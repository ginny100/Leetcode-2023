/**
 * @file Day22CapacityToShipPackagesWithinDDays.cpp
 * @author Ginny Dang
 * @brief 1011. Capacity To Ship Packages Within D Days (https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/)
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int countDays(int capacity, vector<int> &weights)
    {
        int total = 0, count = 1;

        for (int weight : weights)
        {
            if (total + weight <= capacity)
                total += weight;
            else
            {
                total = weight;
                count++;
            }
        }

        return count;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int possibleDaysNeeded = countDays(mid, weights); // O(N)
            if (possibleDaysNeeded <= days)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};

// Time Complexity: O(N*log(M*N/D-M)) where N is the length of weights, M is the maximum element in weights, D is the number of days
// Space Complexity: O(1)
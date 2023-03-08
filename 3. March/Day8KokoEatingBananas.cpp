/**
 * @file Day8KokoEatingBananas.cpp
 * @author Ginny Dang
 * @brief 875. Koko Eating Bananas (https://leetcode.com/problems/koko-eating-bananas/description/)
 * @version 0.1
 * @date 2023-03-07
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool canEatInTime(vector<int> &piles, int k, int h)
    {
        long long hours = 0;

        for (int pile : piles)
        {
            long long div = (long long)pile / k;
            hours += div;
            if (pile % k != 0)
                hours += 1;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canEatInTime(piles, mid, h))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};

// Time Complexity: O(NlogM). N is the number of piles and M is the range of K (left to right)
// Space Complexity: O(1)
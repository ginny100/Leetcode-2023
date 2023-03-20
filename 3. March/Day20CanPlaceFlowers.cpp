/**
 * @file Day20CanPlaceFlowers.cpp
 * @author Ginny Dang
 * @brief 605. Can Place Flowers (https://leetcode.com/problems/can-place-flowers/description/)
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int numPlots = flowerbed.size();

        // Edge case
        if (numPlots == 1)
        {
            // Cannot place any flower in that only spot
            if (flowerbed[0] == 1)
                return n == 0;
            // Can only place 1 flower in that only spot
            else
                return n <= 1;
        }

        // Normal case
        if (flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            n--;
        }

        if (flowerbed[numPlots - 1] == 0 && flowerbed[numPlots - 2] == 0)
        {
            flowerbed[numPlots - 1] = 1;
            n -= 1;
        }

        for (int i = 1; i < numPlots - 1; i++)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n <= 0;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
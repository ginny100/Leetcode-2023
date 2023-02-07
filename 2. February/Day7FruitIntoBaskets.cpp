/**
 * @file Day7FruitIntoBaskets.cpp
 * @author Ginny Dang
 * @brief 904. Fruit Into Baskets (https://leetcode.com/problems/fruit-into-baskets/description/)
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int left = 0;
        unordered_map<int, int> unique;
        int maxLength = 0;

        for (int right = 0; right < fruits.size(); right++)
        {
            unique[fruits[right]]++;
            if (unique.size() > 2)
            {
                unique[fruits[left]]--;
                if (!unique[fruits[left]])
                    unique.erase(fruits[left]);
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
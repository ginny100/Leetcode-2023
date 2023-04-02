/**
 * @file Day2SuccessfulPairsOfSpellsAndPotions.cpp
 * @author Ginny Dang
 * @brief 2300. Successful Pairs of Spells and Potions (https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/)
 * @version 0.1
 * @date 2023-04-01
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
private:
    int countPairs(int currSpell, vector<int> &potions, int numPotions, long long success)
    {
        int left = 0;
        int right = numPotions - 1;
        int smallestPotionPos = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if ((long long)currSpell * potions[mid] < success)
                left = mid + 1;
            else
            {
                if ((mid - 1 < 0) || (mid - 1 >= 0 && (long long)currSpell * potions[mid - 1] < success))
                {
                    smallestPotionPos = mid;
                    break;
                }
                else if (mid - 1 >= 0 && (long long)currSpell * potions[mid - 1] >= success)
                    right = mid - 1;
            }
        }

        return smallestPotionPos == -1 ? 0 : numPotions - smallestPotionPos;
    }

public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size();
        int m = potions.size();
        vector<int> result(n, 0);

        sort(potions.begin(), potions.end()); // O(MlogM)

        for (int i = 0; i < n; i++)
        {
            if (spells[i] >= success)
                result[i] = m;
            else
                result[i] = countPairs(spells[i], potions, m, success);
        }

        return result;
    }
};

// Time Complexity: O(max(M, N)logM)
// Space Complexity: O(1)
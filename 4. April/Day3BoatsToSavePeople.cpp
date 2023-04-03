/**
 * @file Day3BoatsToSavePeople.cpp
 * @author Ginny Dang
 * @brief 881. Boats to Save People (https://leetcode.com/problems/boats-to-save-people/description/)
 * @version 0.1
 * @date 2023-04-03
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());

        int numBoats = 0;
        int left = 0;
        int right = people.size() - 1;

        while (left <= right)
        {
            if (people[left] + people[right] <= limit)
                left++;
            right--;
            numBoats++;
        }

        return numBoats;
    }
};

// Time Complexity: O(Nlog⁡N)
// Space Complexity: O(log⁡N)
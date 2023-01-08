/**
 * @file Day7GasStation.cpp
 * @author Ginny Dang
 * @brief 134. Gas Station (https://leetcode.com/problems/gas-station/description/)
 * @version 0.1
 * @date 2023-01-07
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int start = 0;
        int end = 0;

        while (start < n)
        {
            end = start;
            bool updatedEnd = false;
            int remainingGas = gas[start];
            while (remainingGas - cost[end % n] >= 0)
            {
                updatedEnd = true;
                remainingGas -= cost[end % n];
                remainingGas += gas[++end % n];
                if (end == start + n)
                    break;
            }
            if (updatedEnd && end == start + n)
            {
                cout << "Done line 8"
                     << "\n";
                return start;
            }
            start = ++end;
        }

        return -1;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
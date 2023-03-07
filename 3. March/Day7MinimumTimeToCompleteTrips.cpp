/**
 * @file Day7MinimumTimeToCompleteTrips.cpp
 * @author Ginny Dang
 * @brief 2187. Minimum Time to Complete Trips (https://leetcode.com/problems/minimum-time-to-complete-trips/description/)
 * @version 0.1
 * @date 2023-03-06
 *
 * @copyright Copyright (c) 2023
 *
 */

class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long left = *min_element(time.begin(), time.end());
        long long right = (long long)*max_element(time.begin(), time.end()) * totalTrips;
        long long minTime = LONG_LONG_MAX;

        // find the smallest amount of time in which all buses can complete a number of trips >= totalTrips in the sorted range [left, right]
        // numTrips(l) <= ... <= numTrips(i) <= numTrips(i + 1) <= ... <= numTrips(right)
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long trips = 0;
            for (int t : time)
                trips += mid / t;
            if (trips >= totalTrips)
            {
                right = mid - 1;
                minTime = mid;
            }
            else
                left = mid + 1;
        }

        return minTime;
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(1)
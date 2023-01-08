/**
 * @file Day8MaxPointsOnALine.cpp
 * @author Ginny Dang
 * @brief 149. Max Points on a Line (https://leetcode.com/problems/max-points-on-a-line/description/)
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Idea learned from the official solution
 * For a fixed point points[i], consider all other points points[j] and calculate the atan2 for each vector points[j] - points[i] (the vector with the magnitudes (points[j].x - points[i].x, points[j].y - points[i].y)).
 * Then find the maximum number of times some angle value occurs among the calculated values. One can use a hash map for this.
 */

/**
 * @brief Algorithm learned from the official solution
 * For each points[i], maintain a hash map cnt to count the angles.
 * - For each j ≠ i, calculate the atan2 of the vector points[j] - points[i] and add this value to the current hash map.
 * - Let k be the maximum number of occurrences of some angle value in the hash map.
 * - Update the answer with k+1. (+1 because the point points[i] also lies on the line, and we must include it in the answer.)
 */

/**
 * @brief New thing I've learned from this challenge
 * The atan2 built-in function in C++ (https://cplusplus.com/reference/cmath/atan2/)
 * - double atan2(double y, double x);
 * - Compute arc tangent with two parameters
 * - Returns the principal value of the arc tangent of y/x, expressed in radians.
 */

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        if (points.size() == 1)
            return 1;

        int result = 2;

        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> cnt; // keep track of the frequencies of different arc tangent values

            for (int j = 0; j < points.size(); j++)
                if (j != i)
                    cnt[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;

            for (auto pair : cnt)
                result = max(result, pair.second + 1);
        }

        return result;
    }
};

// Time Complexity: O(N^2)
// Space Complexity: O(N)
/**
 * @file Day13CountOddNumbersInAnIntervalRange.cpp
 * @author Ginny Dang
 * @brief 1523. Count Odd Numbers in an Interval Range (https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/)
 * @version 0.1
 * @date 2023-02-12
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Idea
 * - For each inclusive range containing more than 1 number, say n numbers, we always have n/2 pairs of 1 odd and 1 even.
 * - If n is odd, there's 1 standalone number not in a pair
 * -- If low is odd, then n is odd if and only if high is odd as well. Therefore, the number of odds in the range [low, high] is n/2 + 1, i.e., the standalone number is odd and is counted.
 * -- If low is even, then n is odd if and only if high is even as well. Therefore, the number of odds in the range [low, high] is n/2, i.e., the standalone number is even and is not counted.
 * - If n is even, the number of odds in the range [low, high] is equal to the number of pairs, i.e., n/2.
 */

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int n = high - low + 1; // number of numbers in range [low, high] inclusive
        int pairs = n / 2;      // number of pairs of 1 even number and 1 one odd number
        if (low % 2 == 1 && high % 2 == 1)
            return pairs + 1;
        return pairs;
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)
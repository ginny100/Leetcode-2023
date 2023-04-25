/**
 * @file Day25SmallestNumberInInfiniteSet.cpp
 * @author Ginny Dang
 * @brief 2336. Smallest Number in Infinite Set (https://leetcode.com/problems/smallest-number-in-infinite-set/description/)
 * @version 0.1
 * @date 2023-04-24
 *
 * @copyright Copyright (c) 2023
 *
 */

class SmallestInfiniteSet
{
private:
    unordered_set<int> isPresent;
    priority_queue<int, vector<int>, greater<int>> addedInts;
    int currInt;

public:
    SmallestInfiniteSet()
    {
        currInt = 1;
    }

    int popSmallest()
    {
        int ans;

        if (!addedInts.empty())
        {
            ans = addedInts.top();
            isPresent.erase(ans);
            addedInts.pop();
        }
        else
        {
            ans = currInt;
            currInt += 1;
        }

        return ans;
    }

    void addBack(int num)
    {
        if (currInt <= num || isPresent.find(num) != isPresent.end())
            return;

        addedInts.push(num);
        isPresent.insert(num);
    }
};

// Time Complexity: O((m+n)*logn)
// Space Complexity: O(n)

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
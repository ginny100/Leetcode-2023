/**
 * @file Day28DataStreamAsDisjointIntervals.cpp
 * @author Ginny Dang
 * @brief 352. Data Stream as Disjoint Intervals (https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/)
 * @version 0.1
 * @date 2023-01-28
 *
 * @copyright Copyright (c) 2023
 *
 */

class SummaryRanges
{
    unordered_set<int> nums;
    vector<vector<int>> intervals;

public:
    SummaryRanges() {}

    void addNum(int value)
    {
        // value has already been added to nums
        if (nums.count(value))
            return;

        // value has not been added to nums
        nums.insert(value);

        // value is the very first element to be added
        if (intervals.empty())
        {
            intervals.push_back({value, value});
            return;
        }

        // value is not the very first element to be added -> adjust existing intervals
        vector<vector<int>> newIntervals;
        int pivot = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            // value is within the range [a - 1, b + 1] inclusively
            if (value >= intervals[i][0] - 1 && value <= intervals[i][1] + 1)
            {
                if (value == intervals[i][0] - 1)
                    intervals[i][0] = value;
                else if (value == intervals[i][1] + 1)
                    intervals[i][1] = value;
                newIntervals.push_back(intervals[i]);
                pivot = i + 1;
                break;
            }
            // value is somewhere strictly before [a, b] inclusively
            else if (value < intervals[i][0] - 1)
            {
                newIntervals.push_back({value, value});
                newIntervals.push_back(intervals[i]);
                pivot = i + 1;
                break;
            }
            // value is somewhere strictly after [a, b] inclusively
            else if (value > intervals[i][1] + 1)
            {
                newIntervals.push_back(intervals[i]);
                if (i == intervals.size() - 1 || value < intervals[i + 1][0])
                {
                    newIntervals.push_back({value, value});
                    pivot = i + 1;
                    break;
                }
            }
        }

        vector<int> lastNew = newIntervals.size() ? newIntervals[newIntervals.size() - 1] : vector<int>();
        vector<int> pivotOld = pivot < intervals.size() ? intervals[pivot] : vector<int>();
        vector<int> nextNew = vector<int>();
        if (lastNew.size() && pivotOld.size())
        {
            if (lastNew[1] == pivotOld[0] - 1)
            {
                nextNew.push_back(lastNew[0]);
                nextNew.push_back(pivotOld[1]);
                newIntervals.pop_back();
                newIntervals.push_back(nextNew);
                pivot++;
            }
        }

        for (int i = pivot; i < intervals.size(); i++)
            newIntervals.push_back(intervals[i]);

        intervals = newIntervals;
    }

    vector<vector<int>> getIntervals()
    {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

// Time Complexity: O(3x10e4N)
// Space Complexity: O(3x10e4N)
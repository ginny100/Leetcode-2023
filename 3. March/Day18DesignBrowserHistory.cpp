/**
 * @file Day18DesignBrowserHistory.cpp
 * @author Ginny Dang
 * @brief 1472. Design Browser History (https://leetcode.com/problems/design-browser-history/description/)
 * @version 0.1
 * @date 2023-03-17
 *
 * @copyright Copyright (c) 2023
 *
 */

class BrowserHistory
{
private:
    vector<string> curPages;
    int curIdx;
    int lastIdx;

public:
    BrowserHistory(string homepage)
    {
        curPages.push_back(homepage);
        curIdx = 0;
        lastIdx = 0;
    }

    // O(1)
    void visit(string url)
    {
        curIdx++;
        if (curPages.size() > curIdx)
            curPages[curIdx] = url;
        else
            curPages.push_back(url);
        lastIdx = curIdx;
    }

    // O(1)
    string back(int steps)
    {
        curIdx = max(curIdx - steps, 0);
        return curPages[curIdx];
    }

    // O(1)
    string forward(int steps)
    {
        curIdx = min(curIdx + steps, lastIdx);
        return curPages[curIdx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

// Time Complexity: O(1)
// Space Complexity: O(N)
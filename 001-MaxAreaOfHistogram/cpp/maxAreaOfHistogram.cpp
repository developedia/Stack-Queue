#include <bits/stdc++.h>
using namespace std;

// Given histogram
int histogram[] = {6, 2, 5, 4, 5, 1, 6};
int n = sizeof(histogram) / sizeof(int);

// Update maxArea
int updateMaxArea(int maxArea, stack<int> &stk, int rightMost) {
    int h = histogram[stk.top()];
    stk.pop();
    int l = stk.empty() ? 0 : stk.top() + 1;
    int r = rightMost - 1;
    return max(maxArea, h * (r - l + 1));
}

// Get maximum rectangular area in O(n) time
int getMaxRectangularArea() {
    stack<int> stk;
    int maxArea = 0;

    // Push all the elements in the stack exactly once
    for (int rightMost = 0; rightMost < n; rightMost++) {
        while (!stk.empty() && histogram[stk.top()] > histogram[rightMost]) {
            maxArea = updateMaxArea(maxArea, stk, rightMost);
        }
        stk.push(rightMost);
    }

    // Pop elements out of the stack until it's empty
    while (!stk.empty()) {
        maxArea = updateMaxArea(maxArea, stk, n);
    }

    return maxArea;
}

int main() {
    cout << getMaxRectangularArea() << endl;

    return 0;
}

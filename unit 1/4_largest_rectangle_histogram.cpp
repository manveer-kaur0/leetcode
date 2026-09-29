#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Approach: Monotonic Increasing Stack
// Intuition: Find the maximum width for each bar.
// Time: O(n)
// Space: O(n)

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= heights.size(); i++) {
        int current = (i == heights.size()) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] > current) {
            int height = heights[st.top()];
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        if (i < heights.size())
            st.push(i);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Largest Rectangle: "
         << largestRectangleArea(heights);

    return 0;
}
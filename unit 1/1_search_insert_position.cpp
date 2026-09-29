#include <iostream>
#include <vector>
using namespace std;

// Approach: Binary Search
// Intuition: Find target; if not found, low gives insertion position.
// Time: O(log n)
// Space: O(1)

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << "Index: " << searchInsert(nums, target);

    return 0;
}
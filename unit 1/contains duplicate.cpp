#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
============================================================
PROBLEM: CONTAINS DUPLICATE II
LEETCODE: 219
============================================================

Given an integer array nums and an integer k, return true
if there are two distinct indices i and j such that:

    nums[i] == nums[j]

AND

    |i - j| <= k

Example:

nums = [1, 2, 3, 1]
k = 3

The number 1 appears at index 0 and index 3.

|3 - 0| = 3

Since 3 <= 3, answer is TRUE.


============================================================
INTUITION
============================================================

We need to find duplicate numbers and check how far apart
their indices are.

Instead of comparing every pair of elements, we can remember
the LAST INDEX at which each number appeared.

Example:

nums = [1, 2, 3, 1]

When we see the first 1:
    1 -> index 0

When we see the second 1:
    current index = 3
    previous index = 0

    difference = 3 - 0 = 3

If difference <= k, we return true.


============================================================
APPROACH
============================================================

1. Create an unordered_map.

   It stores:

       number -> latest index

2. Traverse the array.

3. If the current number already exists in the map:
       calculate the distance between current index
       and previous index.

4. If distance <= k:
       return true.

5. Update the number's index in the map.

6. If no suitable duplicate is found:
       return false.


============================================================
TIME COMPLEXITY
============================================================

O(n)

We visit every element once.

unordered_map gives average O(1) lookup.


============================================================
SPACE COMPLEXITY
============================================================

O(n)

In the worst case, the map stores all n elements.
============================================================
*/


bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    // Map stores the latest index of every number
    unordered_map<int, int> lastIndex;

    // Traverse the array
    for (int i = 0; i < nums.size(); i++)
    {
        // Check if this number was seen before
        if (lastIndex.find(nums[i]) != lastIndex.end())
        {
            // Calculate distance between the two indices
            int difference = i - lastIndex[nums[i]];

            // If distance is within k, duplicate is valid
            if (difference <= k)
            {
                return true;
            }
        }

        // Store/update the latest index
        lastIndex[nums[i]] = i;
    }

    // No valid duplicate found
    return false;
}


int main()
{
    // Example input
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    bool answer = containsNearbyDuplicate(nums, k);

    cout << "Array: ";

    for (int x : nums)
    {
        cout << x << " ";
    }

    cout << "\nk = " << k << endl;

    cout << "Answer: ";

    if (answer)
        cout << "true";
    else
        cout << "false";

    return 0;
}
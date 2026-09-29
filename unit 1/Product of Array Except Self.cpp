#include <iostream>
#include <vector>
using namespace std;

/*
============================================================
PROBLEM: PRODUCT OF ARRAY EXCEPT SELF
LEETCODE: 238
============================================================

Given an integer array nums, return an array where:

    answer[i] = product of every element except nums[i]

Example:

nums = [1, 2, 3, 4]

For index 0:
    2 * 3 * 4 = 24

For index 1:
    1 * 3 * 4 = 12

For index 2:
    1 * 2 * 4 = 8

For index 3:
    1 * 2 * 3 = 6

Answer:

[24, 12, 8, 6]


============================================================
INTUITION
============================================================

For every element, we need:

    Product of elements on LEFT
                 *
    Product of elements on RIGHT

Example:

nums = [1, 2, 3, 4]

For 3:

LEFT:
    1 * 2 = 2

RIGHT:
    4

Therefore:

    2 * 4 = 8


============================================================
APPROACH
============================================================

We use TWO passes.

-------------------- PASS 1 --------------------

Calculate the product of everything to the LEFT.

For:

    [1, 2, 3, 4]

The left products are:

    [1, 1, 2, 6]

Why?

Index 0:
    Nothing on left -> 1

Index 1:
    1 -> 1

Index 2:
    1 * 2 -> 2

Index 3:
    1 * 2 * 3 -> 6


-------------------- PASS 2 --------------------

Traverse from RIGHT to LEFT.

Calculate the product of everything to the RIGHT.

Multiply that value with the existing answer.


============================================================
WHY NOT USE DIVISION?
============================================================

A simple idea would be:

    total product / nums[i]

But this creates problems when nums contains zero.

The prefix + suffix method works correctly even with zeroes.


============================================================
TIME COMPLEXITY
============================================================

O(n)

We traverse the array twice.

O(n) + O(n) = O(n)


============================================================
SPACE COMPLEXITY
============================================================

O(1) EXTRA SPACE

We only use a few variables apart from the output array.

The output array itself requires O(n) space.


============================================================
*/


vector<int> productExceptSelf(vector<int>& nums)
{
    int n = nums.size();

    // Answer array initially contains 1
    vector<int> answer(n, 1);

    // -------------------------------------------------------
    // PASS 1: Store product of all elements to the LEFT
    // -------------------------------------------------------

    int prefix = 1;

    for (int i = 0; i < n; i++)
    {
        // Store left product
        answer[i] = prefix;

        // Update prefix for the next position
        prefix = prefix * nums[i];
    }

    // -------------------------------------------------------
    // PASS 2: Multiply by product of elements to the RIGHT
    // -------------------------------------------------------

    int suffix = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        // Multiply left product with right product
        answer[i] = answer[i] * suffix;

        // Update suffix for the next position
        suffix = suffix * nums[i];
    }

    return answer;
}


int main()
{
    vector<int> nums = {1, 2, 3, 4};

    vector<int> answer = productExceptSelf(nums);

    cout << "Input: ";

    for (int x : nums)
    {
        cout << x << " ";
    }

    cout << "\nOutput: ";

    for (int x : answer)
    {
        cout << x << " ";
    }

    return 0;
}
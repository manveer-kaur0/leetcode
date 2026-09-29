#include <iostream>
using namespace std;

/*
============================================================
PROBLEM: PALINDROME LINKED LIST
LEETCODE: 234
============================================================

Given the head of a singly linked list, determine whether
the linked list is a palindrome.

A palindrome reads the same forward and backward.

Example:

    1 -> 2 -> 2 -> 1

Forward:
    1 2 2 1

Backward:
    1 2 2 1

Therefore, it is a palindrome.


Example:

    1 -> 2 -> 3

Forward:
    1 2 3

Backward:
    3 2 1

Therefore, it is NOT a palindrome.


============================================================
INTUITION
============================================================

A singly linked list cannot be traversed backward easily.

So instead of trying to move backward, we:

    1. Find the middle of the linked list.
    2. Reverse the second half.
    3. Compare the first half with the reversed second half.


Example:

    1 -> 2 -> 3 -> 2 -> 1

After finding the middle:

    First half:
    1 -> 2 -> 3

    Second half:
    2 -> 1

Reverse second half:

    1 -> 2


Now compare:

    1 == 1
    2 == 2

Therefore, palindrome.


============================================================
APPROACH
============================================================

STEP 1:
Use TWO POINTERS.

slow moves one node at a time.

fast moves two nodes at a time.

When fast reaches the end, slow is around the middle.


STEP 2:
Reverse the second half of the linked list.


STEP 3:
Compare nodes from:

    beginning of list

with:

    beginning of reversed second half


If all values match:
    return true

Otherwise:
    return false.


============================================================
TIME COMPLEXITY
============================================================

O(n)

We traverse the linked list a few times,
but each traversal is linear.


============================================================
SPACE COMPLEXITY
============================================================

O(1)

We only use pointers.

No extra array or stack is used.


============================================================
*/


// Node structure for the linked list
struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};


// ------------------------------------------------------------
// FUNCTION TO REVERSE A LINKED LIST
// ------------------------------------------------------------

ListNode* reverseList(ListNode* head)
{
    ListNode* previous = nullptr;
    ListNode* current = head;

    while (current != nullptr)
    {
        // Save the next node
        ListNode* nextNode = current->next;

        // Reverse the current node's pointer
        current->next = previous;

        // Move previous forward
        previous = current;

        // Move current forward
        current = nextNode;
    }

    // Previous becomes the new head
    return previous;
}


// ------------------------------------------------------------
// CHECK WHETHER LINKED LIST IS PALINDROME
// ------------------------------------------------------------

bool isPalindrome(ListNode* head)
{
    // Empty list or one-node list is always palindrome
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    // --------------------------------------------------------
    // STEP 1: FIND THE MIDDLE
    // --------------------------------------------------------

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        // Slow moves one step
        slow = slow->next;

        // Fast moves two steps
        fast = fast->next->next;
    }

    // --------------------------------------------------------
    // STEP 2: REVERSE SECOND HALF
    // --------------------------------------------------------

    ListNode* secondHalf = reverseList(slow);

    // First pointer starts from beginning
    ListNode* firstHalf = head;

    // --------------------------------------------------------
    // STEP 3: COMPARE BOTH HALVES
    // --------------------------------------------------------

    while (secondHalf != nullptr)
    {
        if (firstHalf->val != secondHalf->val)
        {
            return false;
        }

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}


// ------------------------------------------------------------
// PRINT LINKED LIST
// ------------------------------------------------------------

void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val;

        if (head->next != nullptr)
        {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}


// ------------------------------------------------------------
// MAIN FUNCTION
// ------------------------------------------------------------

int main()
{
    /*
        Creating:

        1 -> 2 -> 2 -> 1
    */

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);

    head->next->next = new ListNode(2);

    head->next->next->next = new ListNode(1);

    cout << "Linked List: ";
    printList(head);

    bool answer = isPalindrome(head);

    cout << "Is Palindrome: ";

    if (answer)
        cout << "true";
    else
        cout << "false";

    return 0;
}
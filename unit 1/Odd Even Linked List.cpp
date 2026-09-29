#include <iostream>
using namespace std;

/*
============================================================
PROBLEM: ODD EVEN LINKED LIST
LEETCODE: 328
============================================================

Given the head of a singly linked list, group all nodes with
ODD INDICES together followed by nodes with EVEN INDICES.

IMPORTANT:

Odd/even refers to the POSITION of the node,
NOT the value stored inside the node.

Example:

    1 -> 2 -> 3 -> 4 -> 5

Positions:

    1    2    3    4    5
    O    E    O    E    O

After rearranging:

    1 -> 3 -> 5 -> 2 -> 4


============================================================
INTUITION
============================================================

We can create two separate chains:

ODD:

    1 -> 3 -> 5

EVEN:

    2 -> 4

Then connect them:

    1 -> 3 -> 5 -> 2 -> 4


We do NOT create new nodes.

We simply change the existing next pointers.


============================================================
APPROACH
============================================================

We maintain three pointers:

    odd
    even
    evenHead


odd:
    Points to the current odd-position node.

even:
    Points to the current even-position node.

evenHead:
    Stores the first even node so that we can connect
    the odd list to the even list at the end.


For:

    1 -> 2 -> 3 -> 4 -> 5

Initially:

    odd = 1
    even = 2
    evenHead = 2


Then rearrange the links:

    1 -> 3 -> 5

    2 -> 4


Finally:

    odd->next = evenHead

Result:

    1 -> 3 -> 5 -> 2 -> 4


============================================================
TIME COMPLEXITY
============================================================

O(n)

Every node is visited once.


============================================================
SPACE COMPLEXITY
============================================================

O(1)

Only a few pointers are used.

No extra array or linked list is created.


============================================================
*/


// Node structure
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
// ODD EVEN LINKED LIST FUNCTION
// ------------------------------------------------------------

ListNode* oddEvenList(ListNode* head)
{
    // If list has 0 or 1 node, nothing needs to be changed
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // First node is odd
    ListNode* odd = head;

    // Second node is even
    ListNode* even = head->next;

    // Save the first even node
    // We need this later to connect odd list with even list
    ListNode* evenHead = even;


    // Continue while an even node and the next odd node exist
    while (even != nullptr && even->next != nullptr)
    {
        // Connect current odd node to next odd node
        odd->next = even->next;

        // Move odd pointer forward
        odd = odd->next;


        // Connect current even node to next even node
        even->next = odd->next;

        // Move even pointer forward
        even = even->next;
    }


    // Connect the end of odd list to beginning of even list
    odd->next = evenHead;

    return head;
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

        1 -> 2 -> 3 -> 4 -> 5
    */

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);

    head->next->next = new ListNode(3);

    head->next->next->next = new ListNode(4);

    head->next->next->next->next = new ListNode(5);


    cout << "Original List: ";
    printList(head);


    // Rearrange the linked list
    head = oddEvenList(head);


    cout << "After Odd-Even Rearrangement: ";
    printList(head);


    return 0;
}
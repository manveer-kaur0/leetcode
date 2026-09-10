#include <iostream>
#include <stack>
using namespace std;

// Approach: Use two stacks
// Intuition: Reverse elements to achieve FIFO.
// Time: O(1) amortized
// Space: O(n)

class MyQueue {
    stack<int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << endl;
    cout << "Removed: " << q.pop() << endl;
    cout << "Front: " << q.peek();

    return 0;
}
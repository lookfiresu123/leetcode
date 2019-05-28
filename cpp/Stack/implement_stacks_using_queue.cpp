#include <deque>

class Stack {
private:
    std::deque<int> dq;
public:
    // Push element x onto stack.
    void push(int x) {
        dq.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        dq.pop_back();
    }

    // Get the top element.
    int top() {
        return dq.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return dq.empty();
    }
};

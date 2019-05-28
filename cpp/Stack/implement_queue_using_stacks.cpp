#include <deque>

class Queue {
private:
    std::deque<int> dq;
public:
    // Push element x to the back of queue.
    void push(int x) {
        dq.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        dq.pop_front();
    }

    // Get the front element.
    int peek(void) {
        return dq.front();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return dq.empty();
    }
};

#include <iostream>
#include <vector>
#include <climits>

class MinStack {
private:
    std::vector<int> vec;
    std::vector<int> min;
public:
    MinStack() {
        min.push_back(INT_MAX);
    }

    void push(int x) {
        vec.push_back(x);
        if (x < min.back())
            min.push_back(x);
        else
            min.push_back(min.back());
    }

    void pop() {
        vec.pop_back();
        min.pop_back();
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        return min.back();
    }
};

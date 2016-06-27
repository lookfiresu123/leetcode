#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        deque<int> current, previous;
        vector<int> result;
        if (rowIndex < 0)
            return result;
        else if (rowIndex == 0) {
            result.push_back(1);
            return result;
        } else if (rowIndex == 1) {
            result.push_back(1);
            result.push_back(1);
            return result;
        } else {
            previous.push_back(1);
            previous.push_back(1);
            for (int i = 2 ; i <= rowIndex ; ++i) {
                current.push_back(1);
                for (deque<int>::size_type j = 1 ; j < previous.size() ; ++j)
                    current.push_back(previous[j-1] + previous[j]);
                current.push_back(1);
                //clear previous, then copy current to previous and clear current
                while (!previous.empty())
                    previous.pop_front();
                while (!current.empty()) {
                    previous.push_back(current.front());
                    current.pop_front();
                }
            }
            while (!previous.empty()) {
                result.push_back(previous.front());
                previous.pop_front();
            }
            return result;
        }
    }
};

int main() {
    return 0;
}

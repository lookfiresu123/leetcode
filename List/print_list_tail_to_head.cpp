#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void printList_helper(vector<int> &vec, struct ListNode *head) {
        if (head) {
            printList_helper(vec, head->next);
            vec.push_back(head->val);
        }
    }

    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> vec;
        printList_helper(vec, head);
        return vec;
    }
};

void print(vector<int> &vec) {
    for (vector<int>::iterator it = vec.begin() ; it != vec.end() ; ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(0), *cur = head, *new_node = NULL;
    for (int i = 1 ; i < 10 ; ++i) {
        new_node = new ListNode(i);
        cur->next = new_node;
        cur = cur->next;
    }
    cout << "print from tail to head" << endl;
    Solution sol;
    vector<int> vec = sol.printListFromTailToHead(head);
    print(vec);
    return 0;
}

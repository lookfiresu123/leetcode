#include <climits>
#include <deque>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        deque<ListNode *> dq1, dq2;
        ListNode *cur = head;
        ListNode *node = new ListNode(INT_MIN), *prev = node;
        while (cur) {
            if (cur->val < x)
                dq1.push_back(cur);
            else
                dq2.push_back(cur);
            cur = cur->next;
        }

        while (!dq1.empty()) {
            prev->next = dq1.front();
            prev = prev->next;
            dq1.pop_front();
        }
        while (!dq2.empty()) {
            prev->next = dq2.front();
            prev = prev->next;
            dq2.pop_front();
        }

        prev->next = NULL;

        head = node->next;
        delete node;
        return head;
    }
};

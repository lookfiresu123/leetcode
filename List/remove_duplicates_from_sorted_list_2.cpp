#include <iostream>
#include <stack>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *node = new ListNode(INT_MAX);
        node->next = head;
        ListNode *cur = head, *next = cur->next, *prev = node;
        stack<ListNode *> stk;
        while (next) {
            if (cur->val == next->val)
                next = next->next;
            else if (cur->next != next) {
                for (ListNode *start = cur ; start != next ; start = start->next)
                    stk.push(start);
                prev->next = next;
                cur = next;
                next = next->next;

                // delete all node
                while (!stk.empty()) {
                    delete stk.top();
                    stk.pop();
                }
            } else {
                prev = cur;
                cur = next;
                next = next->next;
            }
        }
        // delete the last duplicate case
        if (cur->next != next) {
            for (ListNode *start = cur ; start != next ; start = start->next)
                stk.push(start);
            prev->next = next;

            // delete all node
            while (!stk.empty()) {
                delete stk.top();
                stk.pop();
            }
        }

        head = node->next;
        delete node;
        return head;
    }
};

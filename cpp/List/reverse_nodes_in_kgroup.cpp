#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = new ListNode(0);
        node->next = head;
        ListNode *cur = head, *prev = node;
        stack<ListNode *> stk;
        ListNode *tmp = NULL;
        while (cur) {
            // push node to stack
            stk.push(cur);
            cur = cur->next;
            if (stk.size() == k) {
                // pop node from stack
                while (!stk.empty()) {
                    tmp = stk.top();
                    stk.pop();
                    prev->next = tmp;
                    prev = prev->next;
                }
            }
        }
        tmp = NULL;
        // clear the stack
        while (!stk.empty()) {
            tmp = stk.top();
            stk.pop();
        }
        prev->next = tmp;
        ListNode *ret = node->next;
        delete node;
        return ret;
    }
};

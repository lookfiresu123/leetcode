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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        int cnt = 0;
        ListNode *cur = head, *tmp;
        stack<ListNode *> stk;
        while (cur) {
            ++cnt;
            stk.push(cur);
            cur = cur->next;
        }
        int t = k % cnt;
        for (int i = 0 ; i < t ; ++i) {
            tmp = stk.top();
            stk.pop();
            tmp->next = head;
            head = tmp;
            stk.top()->next = NULL;
        }
        return head;
    }
};

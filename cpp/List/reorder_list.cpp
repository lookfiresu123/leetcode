#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // except the case of n < 2
        if (!head || !head->next || !head->next->next)
            return ;
        ListNode *first = head, *second = head;
        while (second->next) {
            first = first->next;
            second = second->next;
            if (second->next)
                second = second->next;
        }
        // reverse list[n/2 .. n]
        ListNode *prev = first, *cur = first->next, *next;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        first->next = NULL;
        ListNode *tmp1, *tmp2, *start1 = head, *start2 = prev;
        while (start2->next) {
            tmp1 = start1, tmp2 = start2;
            start1 = start1->next, start2 = start2->next;
            tmp1->next = tmp2;
            tmp2->next = start1;
        }
    }
};

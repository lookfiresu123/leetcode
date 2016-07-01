#include <iostream>

/* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode *current = head;
        ListNode *prev = NULL, *next = current->next;
        int i;
        for (i = 1 ; i < m ; ++i) {
            prev = current;
            current = current->next;
            next = current->next;
        }
        ListNode *start = current, *tmp = NULL;
        while (i++ < n) {
            tmp = next->next;
            next->next = current;
            current = next;
            next = tmp;
        }
        start->next = next;
        if (prev) {
            prev->next = current;
            return head;
        }
        return current;
    }
};

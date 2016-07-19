#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)  return true;

        // divide the list into left and right
        ListNode *left = head, *right = head;
        while (right->next) {
            left = left->next;
            right = right->next;
            if (right->next)  right = right->next;
        }
        // now left is in the mid, and right is in the tail
        // exchange the right
        ListNode *cur = left->next, *prev = left, *next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // compare the left and right
        ListNode *mid = left;
        mid->next = NULL;
        left = head, right = prev;
        while (left != mid) {
            if (left->val != right->val)    return false;
            left = left->next;
            right = right->next;
        }

        return true;

    }
};

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int delay = 0 - n;
        ListNode *first = head, *second = NULL;
        while (first) {
            if (delay == -1)
                second = head;
            else if (delay > -1)
                second = second->next;
            first = first->next;
            ++delay;
        }
        if (second) {
            if (second == head)
                head = head->next;
            else {
                ListNode *p = head;
                while (p->next != second)
                    p = p->next;
                p->next = second->next;
            }
            delete second;
        }
        return head;
    }
};

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    ListNode *head = new ListNode(0), *cur = head, *new_node = NULL;
    for (int i = 1 ; i < 10 ; ++i) {
        new_node = new ListNode(i);
        cur->next = new_node;
        cur = cur->next;
    }
    Solution sol;
    head = sol.removeNthFromEnd(head, 1);
    printList(head);
    return 0;
}

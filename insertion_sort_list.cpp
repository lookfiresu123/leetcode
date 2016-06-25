#include <climits>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *new_node = new ListNode(INT_MIN);
        new_node->next = head;
        ListNode *current = head, *parent_p = NULL, *parent_current = new_node, *p = NULL;
        while (current) {
            for (p = new_node ; p != current && p->val <= current->val ; p = p->next)
                parent_p = p;
            // parrent -> p -> .. -> current ==> parrent -> current -> p -> ...
            if (p != current) {
                parent_p->next = current;
                parent_current->next = current->next;
                current->next = p;
                current = parent_current->next;
            } else {
                parent_current = current;
                current = current->next;
            }
        }
        head = new_node->next;
        delete new_node;
        return head;
    }
};

int main() {
    return 0;
}

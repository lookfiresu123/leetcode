#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return head;
        ListNode *first = head, *second = first->next;
        ListNode *prev = new ListNode(0);
        ListNode *copy = prev;
        ListNode *tmp = NULL;
        prev->next = first;

        while (second) {
            first->next = second->next;
            second->next = first;
            prev->next = second;

            tmp = first;
            first = second;
            second = tmp;

            if (!(second = second->next))
                break;
            first = first->next;
            prev = prev->next;
            second = second->next;
            first = first->next;
            prev = prev->next;
        }

        head = copy->next;
        delete copy;
        return head;
    }
};

int main() {
    return 0;
}

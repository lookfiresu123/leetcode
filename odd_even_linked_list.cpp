#include <cstdlib>
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
    ListNode* oddEvenList(ListNode* head) {
        deque<ListNode *> dq_odd;
        deque<ListNode *> dq_even;
        deque<ListNode *> dq_result;
        ListNode *current = head;
        int count = 1;
        while (current) {
            if ((count % 2) == 1)
                dq_odd.push_back(current);
            else
                dq_even.push_back(current);
            current = current->next;
            ++ count;
        }
        while (!dq_odd.empty()) {
            dq_result.push_back(dq_odd.front());
            dq_odd.pop_front();
        }
        while (!dq_even.empty()) {
            dq_result.push_back(dq_even.front());
            dq_even.pop_front();
        }
        deque<ListNode *>::size_type i;
        if (head)
            head = dq_result[0];
        else
            return NULL;
        for (deque<ListNode *>::size_type i = 0 ; i < dq_result.size() ; ++i)
            cout << dq_result[i]->val << " ";
        cout << endl;
        for (current = head, i = 1 ; i < dq_result.size() ; current = current->next, ++i)
            current->next = dq_result[i];
        current->next = NULL;
        return head;
    }
};

int main () {
    ListNode *head = NULL, *current = head;
    for (int i = 1 ; i < 9 ; ++i) {
        if(i == 1) {
            current = new ListNode(i);
            head = current;
        } else {
            current->next = new ListNode(i);
            current = current->next;
        }
    }
    // test head
    for (current = head ; current ; current = current->next)
        cout << current->val << " ";
    cout << endl;

    // processing
    Solution sol;
    head = sol.oddEvenList(head);

    // test head again
    for (current = head ; current ; current = current->next)
        cout << current->val << " ";
    cout << endl;

    return 0;
}

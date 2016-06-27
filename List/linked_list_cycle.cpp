#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *run_p1(ListNode *start) {     // p1以速度1往前跑
        return start->next;
    }

    ListNode *run_p2(ListNode *start) {     // p2以速度2往前跑
        if (start->next)
            return start->next->next;
        return start->next;
    }

    bool hasCycle(ListNode *head) {
        // 方法：两个人以不同速度从相同起点往前跑，若有环，则两人必定的会再次相遇
        ListNode *p1 = head, *p2 = head;
        while (p1 && p2) {
            p1 = run_p1(p1);
            p2 = run_p2(p2);
            if (p1 && p2 && p1 == p2)
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    ListNode *head = NULL, *new_node = NULL, *current = NULL;
    for (int i = 0 ; i < 10 ; ++i) {
        new_node = new ListNode(i);
        if (i == 0) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = current->next;
            // if (i == 9)     // 制造一个环
               //  current->next = head;
        }
    }
    if (sol.hasCycle(head))
        cout << "has cycle" << endl;
    else
        cout << "has no cycle" << endl;
    return 0;
}

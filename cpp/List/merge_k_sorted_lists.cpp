#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// recursive merge
class Solution_1 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        while (lists.size() > 1) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr)   return l2;
        if (l2 == nullptr)   return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

// using priority queue
class Solution_2 {
public:
    // N elements -> NlgN
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [](ListNode *x, ListNode *y){ return x->val > y->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);
        for (auto list : lists) {
            auto cur = list;
            while (cur) {
                q.push(cur);
                cur = cur->next;
            }
        }
        ListNode *node = new ListNode(0);
        ListNode *cur = node;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
        }
        cur->next = NULL;
        auto ret = node->next;
        delete node;
        return ret;
    }
};

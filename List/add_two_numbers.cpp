#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> tmp1, tmp2;
        ListNode *cur1 = l1, *cur2 = l2;
        while (cur1) {
            tmp1.push_back(cur1->val);
            cur1 = cur1->next;
        }
        while (cur2) {
            tmp2.push_back(cur2->val);
            cur2 = cur2->next;
        }
        int sz1 = tmp1.size(), sz2 = tmp2.size();
        int sz = sz1 < sz2 ? sz2 : sz1;
        for (int i = sz1 ; i < sz ; ++i)
            tmp1.push_back(0);
        for (int i = sz2 ; i < sz ; ++i)
            tmp2.push_back(0);
        // reverse tmp1 and tmp2
        for (int i = 0, j = sz-1 ; i < j ; ++i, --j) {
            swap(tmp1, i, j);
            swap(tmp2, i, j);
        }
        // store result
        vector<int> tmp(sz+1, 0);
        int carry = 0, t;
        for (int i = sz ; i > 0 ; --i) {
            t = tmp1[i-1] + tmp2[i-1] + carry;
            tmp[i] = t % 10;
            carry = t / 10;
        }
        tmp[0] = carry;
        // reverse tmp
        for (int i = 0, j = sz ; i < j ; ++i, --j)
            swap(tmp, i, j);
        // reduce tmp
        if (tmp.back() == 0)
            tmp.pop_back();
        // create list
        ListNode *head = NULL;
        if (!tmp.empty()) {
            head = new ListNode(tmp[0]);
            ListNode *cur = head;
            for (int i = 1 ; i < tmp.size() ; ++i) {
                cur->next = new ListNode(tmp[i]);
                cur = cur->next;
            }
        }
        return head;
    }
private:
    void swap(vector<int> &vec, int i, int j) {
        int tmp = vec[i];
        vec[i] = vec[j];
        vec[j] = tmp;
    }
};

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法如下：
// 一开始使用两个指针first和second，其中first每走一步，则second走两步，直到
// first == second为止。假设此时first走了k步，链表起点到环起点的距离为s，环起点
// 到两指针第一次碰面的地点距离为m，则有k = s+m+nr -> s = k-m-ir。又由于2k-k =
// jr -> k = jr，因此有s = (j-i)r-m -> s = nr-m，由此可得当指针first从起点走起
// ，与此同时second从第一次碰面地点按同样的速率走，两者会在环起点第一次碰面。

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        while (first && second) {
            first = first->next;
            second = second->next;
            if (second)
                second = second->next;
            if (first == second)
                break;
        }
        if (!first || !second)
            return NULL;
        // 此时first和second都在环内
        first = head;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};

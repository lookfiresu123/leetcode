#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        auto cur = head;
        vector<RandomListNode *> vec;
        unordered_map<RandomListNode *, int> mymap; // {RandomListNode *, int} -> {pointer, index}
        int i = 0;
        while (cur) {
            mymap[cur] = i++;
            vec.push_back(cur);
            cur = cur->next;
        }
        vector<RandomListNode *> tmp;
        RandomListNode *node = new RandomListNode(0);
        cur = node;
        for (auto pointer : vec) {
            cur->next = new RandomListNode(pointer->label);
            cur = cur->next;
            tmp.push_back(cur);
        }
        int sz = tmp.size();
        for (int i = 0 ; i < sz ; ++i) {
            auto random_pointer = vec[i]->random;
            if (random_pointer)
                tmp[i]->random = tmp[mymap[random_pointer]];
        }
        auto ret = node->next;
        delete node;
        return ret;
    }
};

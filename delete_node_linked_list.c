#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
 * only gives the points -- node, if head -> node_1 -> node_2 -> ... -> node_n
 * and assume the args is node_2, then we can not access node_1 because there is not
 * a next point that point to it, thus we can not change node_1->next , so if we
 * just change as node = node->next , then *(node_1->next) can be anything.
 *
 * as we know the memory store theory, we can copy node_3 to node_2, and remove the
 * original node_3
 */

void deleteNode(struct ListNode* node) {
    struct ListNode *temp = node->next;
    *node = *node->next;
    free(temp);
}

int main(void){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = head;
    struct ListNode *node;
    int pos = 6;
    int i;
    for(i=0;i<10;i++){
        current->val = i;
        current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(i == pos)
            node = current;
        current = current->next;
    }
    current->val = i;
    current->next = NULL;
    deleteNode(node);
    return 0;
}

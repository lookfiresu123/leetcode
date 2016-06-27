#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    /* find the length of the list */
    struct ListNode *current = head;
    struct ListNode *result = head;
    int length = 0;
    int i;
    struct ListNode *temp;
    if(!head)
        return NULL;
    while(current){
        length++;
        current = current->next;
    }
    current = head;
    /* if the node to be removed is the last node but is not the first node  */
    if(n == 1 && length > 1){
        for(i = 1;i < length - 1;i++)
            current = current->next;
        temp = current->next;
        current->next = NULL;
        free(temp);
    }
    /* if the node to be removed is the first node */
    else if(n == length){
        result = current->next;
        free(current);
    }
    /* if the node to be removed is neither the first node or the last node */
    else{
        /* find the position of the node to be removed */
        int pos = length - n + 1;
        for(i = 1;i < pos-1;i++){
            current = current->next;
        }
        /* at this time ,current is the previous node of node_n */
        temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    return result;
}

int main(void){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = head;
    struct ListNode *result;
    int i;
    for(i = 0;i < 10;i++){
        current->val = i;
        current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current = current->next;
    }
    current->val = i;
    current->next = NULL;
    int n = 4;
    result = removeNthFromEnd(head,n);
    return 0;
}

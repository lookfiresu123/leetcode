#include<stdio.h>
#include<stdlib.h>

/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     struct ListNode *next;
 ** };
 **/

//#define num 5

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *current = head;
    struct ListNode *current_prev;
    int i = 0;
    struct ListNode *new_head = head;
    struct ListNode *temp;
    if(!current)
        return new_head;
    else{
        current = new_head;
        while(current){
            if(current->val == val && current == new_head){
                temp = current;
                current = current->next;
                new_head = current;
                free(temp);
            }
            else if(current->val == val && current != new_head){
                temp = current;
                current_prev->next = current->next;
                current = current->next;
                free(temp);
            }
            else if(current->val != val && current == new_head){
                current_prev = current;
                current = current->next;
            }
            else{
                current_prev = current;
                current = current->next;
            }
        }
        return new_head;
    }
}

int main(void){
    struct ListNode *head;
    struct ListNode *current = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
    head = current;
    struct ListNode *new_head;
    int i,val,num;
    printf("input for num\n");
    scanf("%d",&num);
    for(i=1;i<num;i++){
        //current = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
        // if(i == 1)
        //     head = current;
        printf("input current->val\n");
        scanf("%d",&current->val);
        //current->next = NULL;
        current->next = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
        current = current->next;
    }
    printf("input current->val\n");
    scanf("%d",&current->val);
    current->next = NULL;
    printf("input val\n");
    scanf("%d",&val);
    new_head = removeElements(head,val);
    for(current = new_head;current != NULL;current = current->next)
        printf("%d ",current->val);
    return 0;
}

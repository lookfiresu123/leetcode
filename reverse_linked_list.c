#include<stdio.h>
#include<stdlib.h>
/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     struct ListNode *next;
 ** };
 **/

//首尾相连，使之成为循环链表，保留头和尾节点的指针

int store_prev;
int store_next;

struct ListNode {
    int val;
    struct ListNode *next;
};

void replace(struct ListNode* current){
    //store_prev = current->val;
    store_next = current->next->val;
    current->next->val = store_prev;
    store_prev = store_next;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *current = head,*tail = head;
    int temp;
    int sum = 0;//节点总数
    //找到尾节点，并算出节点总数
    while(current){
        tail = current;
        sum++;
        current = current->next;
    }
    if(sum == 0)//head为NULL的情况 
        return head;

    //head不为NULL的情况
    //添加链接tail->next = head;
    //tail->next = head;
    
    int i;
    struct ListNode *head_temp = head;
    for(i=0;i<sum-1;i++){
        //添加链接
        tail->next = head_temp;
        current = head_temp;
        store_prev = current->val;// set init num
        while(current->next != head_temp){
            replace(current);
            current = current->next;
        }
        replace(current);
        //删除链接
        tail->next = NULL;
        head_temp = head_temp->next;
    }

    //删除链接
    // tail->next = NULL;
    return head;
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
        printf("input current->val\n");
        scanf("%d",&current->val);
        current->next = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
        current = current->next;
    }
    printf("input current->val\n");
    scanf("%d",&current->val);
    current->next = NULL;
    new_head = reverseList(head);
    for(current = new_head;current != NULL;current = current->next)
        printf("%d ",current->val);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     struct ListNode *next;
 ** };
 **/

struct ListNode {
    int val;
    struct ListNode *next;
};

//使用归并排序（归并排序时间复杂度为n*log(n),空间复杂度为O(1)）

/* 分割一个链表为两部分，通过指针返回结果，使用快慢指针  */
void FrontBackSplit(struct ListNode* source,  struct ListNode** frontRef, struct ListNode** backRef){
    struct ListNode *fast,*slow;
    if (source==NULL || source->next==NULL){
        *frontRef = source;
        *backRef = NULL;
    }
    else{
        slow = source;
        fast = source->next;
        /*fast移动2个节点，slow移动1个节点*/
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        /*slow在中间位置的前面*/
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

/* 合并2个已经排序的链表 */
struct ListNode *sortedMerge(struct ListNode *a,struct ListNode *b){
    struct ListNode *result = NULL;
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    /* 递归调用  */
    if(a->val <= b->val){
        result = a;
        result->next = sortedMerge(a->next,b);
    }
    else{
        result = b;
        result->next = sortedMerge(a,b->next);
    }
    return result;
}


void mergesort(struct ListNode** headref) {
    struct ListNode *temp_head = *headref;
    struct ListNode *a,*b;
    if(temp_head == NULL || temp_head->next == NULL)
        return;
    FrontBackSplit(temp_head,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *headref = sortedMerge(a,b);
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode *result = head;
    mergesort(&result);
    return result;
}


int main(void){
    int num,val;
    struct ListNode *head,*frontRef,*backRef;
    struct ListNode *current;
    printf("input num\n");
    scanf("%d",&num);
    int i = 0;
    while(i<num){
        printf("input val\n");
        scanf("%d",&val);
        if(i == 0){
            current = (struct ListNode *)malloc(sizeof(struct ListNode));
            head = current;
            current->val = val;
            current->next = NULL;
        }
        else{
            current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            current->next->val = val;
            current->next->next = NULL;
            current = current->next;
        }
        
        i++;
    }
    struct ListNode *result = sortList(head);
    return 0;
}

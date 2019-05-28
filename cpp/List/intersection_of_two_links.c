#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,struct ListNode *headB) {
    struct ListNode *current_A = headA;
    struct ListNode *current_B = headB;
    int length_A = 0;
    int length_B = 0;
    int gap = 0;
    struct ListNode *result = NULL;
    /* calculate the length of list A and list B */
    while(current_A){
        length_A++;
        current_A = current_A->next;
    }
    while(current_B){
        length_B++;
        current_B = current_B->next;
    }
    current_A = headA;
    current_B = headB;
    /* cal the gap of length_A and length_B, because if they have the same node, it must be the gap node  */
    gap = length_A - length_B;
    if(gap >= 0){
        while(gap != 0){
            current_A = current_A->next;
            gap--;
        }
    }
    else{
        gap = 0 - gap;
        while(gap != 0){
             current_B = current_B->next;
             gap--;
        }
    }
    while(current_A && current_B){
        if(current_A == current_B){
            result = current_A;
            break;
        }
        current_A = current_A->next;
        current_B = current_B->next;
    }
    return result;
}

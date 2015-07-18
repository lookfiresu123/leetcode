#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool determine(struct ListNode** head) {
    bool flag = true;
    struct ListNode *current = *head;
    struct ListNode *prev = *head;
    struct ListNode *second_head = *head;
    struct ListNode *first_head = *head;//mid is the mid number or the mid-1 number
    struct ListNode *tail = *head;
    struct ListNode *second_current;
    struct ListNode *first_current = *head;
    struct ListNode *after;
    struct ListNode *second_tail;
    struct ListNode *mid = *head;
    struct ListNode *mid_prev = *head;
    int sum = 0;
    if(!current)
	    return true;
    while(current){
        sum++;
        prev = current;
        current = current->next;
        if(current){
	    mid_prev = mid;
            mid = mid->next;
            sum++;
            prev = current;
            current = current->next;
        }
    }
    if(sum % 2 == 0)
	mid = mid_prev;
    second_tail = mid->next;
    tail = prev;

    //exchange the second list
    second_head = tail;
    current = second_tail;
    prev = mid;
    while(current){
        after = current->next;
        current->next = prev;
       // prev->next = NULL;
        prev = current;
        current = after;
    }
    mid->next = NULL;
    //second_head = prev;
    for(second_current = second_head;second_current != mid;second_current = second_current->next){
        if(second_current->val != first_current->val){
            flag = false;
            break;
        }
        first_current = first_current->next;
    }
    return flag;
}

bool isPalindrome(struct ListNode *head) {
    bool result = determine(&head);
    return result;
}

int main(){
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
    if(isPalindrome(head))
	printf("true\n");
    else
	printf("false\n");
    return 0;
}

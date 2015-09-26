/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_sorted_list.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月26日 18时40分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};
 
#define N 10000
static int store_nums[N];
static int count = 0;

bool IsExisted (int value) {
    int i;
    for (i = 0 ; i < count ; i++) {
        if (value == store_nums[i])
            return true;
    }
    store_nums[count++] = value;
    return false;
}

void Del_Node (struct ListNode **current) {
    struct ListNode *temp = (*current)->next;
    free(*current);
    *current = temp;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode **pos_prev = &head;
    while (*pos_prev) {
        if ( IsExisted((*pos_prev)->val) )
            Del_Node(pos_prev);
        if (*pos_prev) 			// when the *pos_prev is not the pointer of the tail node
        	pos_prev = &(*pos_prev)->next;
    }
    return head;
}

void Insert_List (struct ListNode **head_ptr, int value) {
	while (*head_ptr)
		head_ptr = &(*head_ptr)->next;
	*head_ptr = malloc(sizeof(**head_ptr));
	(*head_ptr)->val = value;
	(*head_ptr)->next = NULL;
}

int main (void) {
	struct ListNode *head = NULL;
	Insert_List(&head, 1);
	Insert_List(&head, 2);
	struct ListNode *current = head;
	while (current) {
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
	head = deleteDuplicates(head);
	current = head;
	while (current) {
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
	return 0;
}

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
#include <time.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *result = NULL, *current_result = result;
    struct ListNode *current, *previous;
    for (previous = NULL, current = head ; current ; current = current->next) {
        if (!previous || previous->val != current->val) {
            // copy to result
            if (previous == NULL) {
                current_result = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
                result = current_result;
                current_result->val = current->val;
                current_result->next = NULL;
            } else {
                current_result->next = (struct ListNode *)malloc(1 * sizeof(struct ListNode));
                current_result = current_result->next;
                current_result->val = current->val;
                current_result->next = NULL;
            }
        }
        previous = current;
    }
    return result;
}

int main (void) {
    size_t n = 100;
    struct ListNode *head = NULL, *new_node = NULL, *previous = NULL;
    srand(time(NULL));
    int i;
    for (i = 0 ; i < n ; i++) {
        new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (i == 0) {
            head = new_node;
            new_node->val = rand() % 2;
        } else {
            previous->next = new_node;
            new_node->val = previous->val + rand() % 2;
        }
        // new_node->val = rand() % 100;
        new_node->next = NULL;
        previous = new_node;
    }
    struct ListNode *current = NULL;
    for (current = head ; current ; current = current->next)
        printf("%d, ", current->val);
    printf("\n--------------------------------------\n");
    struct ListNode *result = deleteDuplicates(head);
    struct ListNode *current_result = NULL;
    for (current_result = result ; current_result ; current_result = current_result->next)
        printf("%d, ", current_result->val);
    free(head);
    free(result);
    return 0;
}

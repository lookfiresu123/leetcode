#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *new;
    struct ListNode *current_l1 = l1;
    struct ListNode *current_l2 = l2;
    struct ListNode **new_p = &new;

    for ( ; ; ) {
        if (current_l1 && current_l2) {
           *new_p = current_l1->val <= current_l2->val ? current_l1 : current_l2;
            if (*new_p == current_l1)
                current_l1 = current_l1->next;
            else
                current_l2 = current_l2->next;
            new_p = &(*new_p)->next;
        } else
            break;
    }
    if (! current_l1) {
        while (current_l2) {
            *new_p = current_l2;
            current_l2 = current_l2->next;
            new_p = &(*new_p)->next;
        }
    } else {
        while (current_l1) {
            *new_p = current_l1;
            current_l1 = current_l1->next;
            new_p = &(*new_p)->next;
        }
    }
    *new_p = NULL;

    return new;
}

int main (void) {
    int array1[1] = { 2 };
    int array2[1] = { 1 };
    int i;
    struct ListNode *l1, *l2;
    struct ListNode *new, *current;
    for (i = 0 ; i < 1 ; i++) {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = array1[i];
        new->next = NULL;
        if (i == 0) {
            l1 = new;
            current = l1;
        } else {
            current->next = new;
            current = current->next;
        }
    }
    for (i = 0 ; i < 1 ; i++) {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = array2[i];
        new->next = NULL;
        if (i == 0) {
            l2 = new;
            current = l2;
        } else {
            current->next = new;
            current = current->next;
        }
    }
    struct ListNode *result;
    result = mergeTwoLists(l1, l2);
    current = result;
    while (current) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("\n");
    return 0;
}

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/* Definition for a binary tree node.*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define QUEUE_TYPE struct TreeNode *          // 队列元素的类型
#define QUEUE_SIZE 100          // 队列中元素的最大数量
#define ARRAY_SIZE (QUEUE_SIZE + 1)         // 数组的长度 = 元素最大数量 + 1

static QUEUE_TYPE queue_array[ARRAY_SIZE];
static size_t front = 0;
static size_t rear = ARRAY_SIZE - 1;

bool is_empty (void);
bool is_full (void);
QUEUE_TYPE first (void);
void insert_queue (QUEUE_TYPE value);
QUEUE_TYPE delete_queue (void);

/* insert an element : modify the rear and insert it behind the rear */
void insert_queue (QUEUE_TYPE value) {
    if ( is_full() == true)
        perror("the queue is full");
    else {
        rear = (rear + 1) % ARRAY_SIZE;
        queue_array[rear] = value;
    }
}

/* delete an element : modify the front and return the element  */
QUEUE_TYPE delete_queue (void) {
    if ( is_empty() == true) {
        perror("the queue is empty");
        return (QUEUE_TYPE)0;
    } else {
        QUEUE_TYPE ret = queue_array[front];
        front = (front + 1) % ARRAY_SIZE ;
        return ret;
    }
}

/* get the element at the front */
QUEUE_TYPE first (void) {
    if ( is_empty() == true ) {
        perror("the queue is empty");
        return (QUEUE_TYPE)0;
    } else
        return queue_array[front];
}

bool is_empty (void) {
    return (rear + 1) % ARRAY_SIZE == front ? true : false;
}

bool is_full (void) {
    return (rear + 2) % ARRAY_SIZE == front ? true : false;
}

void clear (QUEUE_TYPE *buffer, int length) {
	int i;
	for (i = 0 ; i < length ; i++)
		buffer[i] = NULL;
}

bool compare (QUEUE_TYPE *buffer, int count) {
	int left = 0;
	int right = count - 1;
	while (left <= right) {
		if ((buffer[left] && (! buffer[right])) || ((! buffer[left]) && buffer[right]))
			return false;
		else if (buffer[left] && buffer[right]) {
			if (buffer[left]->val != buffer[right]->val)
				return false;
		}
		left++;
		right--;
	}
	return true;
}

bool isSymmetric(struct TreeNode* root) {
	QUEUE_TYPE buffer[1000];
	clear(buffer, 1000);
    // 广度优先遍历树
    int level = 1;
    int sum = 0;
    //int count;
    insert_queue(root);
    sum += 1;		// sum of nodes
    int i = 0;
	while (! is_empty()) {
		if (sum == (int)pow(2, (double)level) - 1) {
			level += 1;
			clear(buffer, 1000);
			i = 0;
		}
        buffer[i] = delete_queue();
        // if (! compare(buffer, i))
        // return false;
        if (buffer[i]) {
        	insert_queue(buffer[i]->left);
        	insert_queue(buffer[i]->right);
        	sum += 2;
        }
        i++;
        if (i == (int)pow(2, (double)(level-2))) {
        	if (! compare(buffer, i))
        		return false;
        }
    }
	return true;
}

int main (void) {
	// create tree
    struct TreeNode *root;
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 1;

    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->left = NULL;
    root->left->right->val = 3;

    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = 2;
    root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->left->val = 3;
    root->right->right = NULL;

    bool result = isSymmetric(root);
    if (result == true)
    	printf("true\n");
    else
    	printf("false\n");
	return 0;
}

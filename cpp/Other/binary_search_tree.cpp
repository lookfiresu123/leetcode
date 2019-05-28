#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right, *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Tree {
public:
    Tree() : root(NULL) {}
    ~Tree() { myFree(root); }
    void inorderPrint() {
        inorderPrint_helper(root);
        cout << endl;
    }
    void insert(int x) { root = insert_helper(NULL, root, x); }
    TreeNode *findMin() { return findMin_helper(root); }
    TreeNode *findMax() { return findMax_helper(root); }
    int size() { return size_helper(root); }
    int height() { return height_helper(root); }
    TreeNode *findSuccessor(TreeNode *node);
    TreeNode *findPredecessor(TreeNode *node);
    TreeNode *binary_search(int x) { return binary_search_helper(root, x); }
private:
    TreeNode *root;
    TreeNode *findMin_helper(TreeNode *tree_node);
    TreeNode *findMax_helper(TreeNode *tree_node);
    TreeNode *insert_helper(TreeNode *parent_node, TreeNode *tree_node, int x);
    void myFree(TreeNode *tree_node);
    void inorderPrint_helper(TreeNode *tree_node);
    int size_helper(TreeNode *tree_node);
    int height_helper(TreeNode *tree_node);
    TreeNode *binary_search_helper(TreeNode *tree_node, int x);
};

void Tree::inorderPrint_helper(TreeNode *tree_node) {
    if (tree_node) {
        inorderPrint_helper(tree_node->left);
        cout << tree_node->val << " ";
        inorderPrint_helper(tree_node->right);
    }
}

int Tree::size_helper(TreeNode *tree_node) {
    if (!tree_node)
        return 0;
    else
        return 1 + size_helper(tree_node->left) + size_helper(tree_node->right);
}

void Tree::myFree(TreeNode *tree_node) {
    if (tree_node) {
        myFree(tree_node->left);
        myFree(tree_node->right);
        delete tree_node;
        tree_node = NULL;
    }
}

TreeNode *Tree::insert_helper(TreeNode *parent_node, TreeNode *tree_node, int x) {
    if (!tree_node) {
        tree_node = new TreeNode(x);
        tree_node->parent = parent_node;
    } else if (x < tree_node->val)
        tree_node->left = insert_helper(tree_node, tree_node->left, x);
    else
        tree_node->right = insert_helper(tree_node, tree_node->right, x);
    return tree_node;
}

TreeNode *Tree::findMin_helper(TreeNode *tree_node) {
    TreeNode *cur = tree_node;
    if (!cur)
        return NULL;
    while (cur->left)
        cur = cur->left;
    return cur;
}

TreeNode *Tree::findMax_helper(TreeNode *tree_node) {
    TreeNode *cur = tree_node;
    if (!cur)
        return NULL;
    while (cur->right)
        cur = cur->right;
    return cur;
}

int Tree::height_helper(TreeNode *tree_node) {
    if (!tree_node)
        return -1;
    int height_left = height_helper(tree_node->left);
    int height_right = height_helper(tree_node->right);
    int tmp = height_left > height_right ? height_left : height_right;
    return 1 + tmp;
}

TreeNode *Tree::findSuccessor(TreeNode *node) {
    if (!node)
        return NULL;
    else if (node->right)
        return findMin_helper(node->right);
    else {
        TreeNode *p = node->parent, *cur = node;
        while (p && cur == p->right) {
            cur = p;
            p = p->parent;
        }
        return p;
    }
}

TreeNode *Tree::findPredecessor(TreeNode *node) {
    if (!node)
        return NULL;
    else if (node->left)
        return findMax_helper(node->left);
    else {
        TreeNode *p = node->parent, *cur = node;
        while (p && cur == p->left) {
            cur = p;
            p = p->parent;
        }
        return p;
    }
}

TreeNode *Tree::binary_search_helper(TreeNode *tree_node, int x) {
    if (!tree_node)
        return NULL;
    else if (x == tree_node->val)
        return tree_node;
    else if (x < tree_node->val)
        return binary_search_helper(tree_node->left, x);
    else
        return binary_search_helper(tree_node->right, x);
}

int main() {
    Tree binary_search_tree;
    binary_search_tree.insert(21);
    binary_search_tree.insert(19);
    binary_search_tree.insert(30);
    binary_search_tree.insert(31);
    binary_search_tree.insert(81);
    binary_search_tree.insert(29);
    binary_search_tree.inorderPrint();
    cout << "the min element is : " << binary_search_tree.findMin()->val << endl;
    cout << "the max element is : " << binary_search_tree.findMax()->val << endl;
    cout << "the size of tree is : " << binary_search_tree.size() << endl;
    cout << "the height of tree is : " << binary_search_tree.height() << endl;
    cout << "the successor of 29 is : " << binary_search_tree.findSuccessor(binary_search_tree.binary_search(29))->val << endl;
    cout << "the predecessor of 29 is : " << binary_search_tree.findPredecessor(binary_search_tree.binary_search(29))->val << endl;
    return 0;
}

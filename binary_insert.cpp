#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree {
public:
    Tree() : root(NULL) {}
    ~Tree() { myFree(root); }
    void inorderPrint() {
        inorderPrint_helper(root);
        cout << endl;
    }
    void insert(int x) { root = insert_helper(root, x); }
    TreeNode *findMin();
    TreeNode *findMax();
    int size() { return size_helper(root); }
    int height() { return height_helper(root); }
private:
    TreeNode *root;
    TreeNode *insert_helper(TreeNode *tree_node, int x);
    void myFree(TreeNode *tree_node);
    void inorderPrint_helper(TreeNode *tree_node);
    int size_helper(TreeNode *tree_node);
    int height_helper(TreeNode *tree_node);
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

TreeNode *Tree::insert_helper(TreeNode *tree_node, int x) {
    if (!tree_node)
        tree_node = new TreeNode(x);
    else if (x < tree_node->val)
        tree_node->left = insert_helper(tree_node->left, x);
    else
        tree_node->right = insert_helper(tree_node->right, x);
    return tree_node;
}

TreeNode *Tree::findMin() {
    TreeNode *cur = root;
    if (!cur)
        return NULL;
    while (cur->left)
        cur = cur->left;
    return cur;
}

TreeNode *Tree::findMax() {
    TreeNode *cur = root;
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

int main() {
    Tree binary_search_tree;
    binary_search_tree.insert(21);
    binary_search_tree.insert(19);
    binary_search_tree.insert(30);
    binary_search_tree.insert(31);
    binary_search_tree.insert(81);
    binary_search_tree.inorderPrint();
    cout << "the min element is : " << binary_search_tree.findMin()->val << endl;
    cout << "the max element is : " << binary_search_tree.findMax()->val << endl;
    cout << "the size of tree is : " << binary_search_tree.size() << endl;
    cout << "the height of tree is : " << binary_search_tree.height() << endl;
    return 0;
}

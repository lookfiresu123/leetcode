# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isUnivalTree(self, root):
        if root == None or (root.left == None and root.right == None):
            return True
        if root.left == None:
            return root.val == root.right.val and self.isUnivalTree(root.right)
        if root.right == None:
            return root.val == root.left.val and self.isUnivalTree(root.left)
        b = (root.right.val == root.val and root.left.val == root.val)
        return self.isUnivalTree(root.right) and self.isUnivalTree(root.left) and b

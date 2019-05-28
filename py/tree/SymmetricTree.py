# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSymmetricHelper(self, leftTree, rightTree):
        if leftTree == None and rightTree == None:
            return True
        if leftTree == None or rightTree == None:
            return False
        return (leftTree.val == rightTree.val
               and self.isSymmetricHelper(leftTree.left, rightTree.right)
               and self.isSymmetricHelper(leftTree.right, rightTree.left))
    
    def isSymmetric(self, root):
        if root == None:
            return True
        return self.isSymmetricHelper(root.left, root.right)

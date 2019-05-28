# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def invertTree(self, root):
        if root != None:
            invertedLeftTree = self.invertTree(root.left)
            invertedRightTree = self.invertTree(root.right)
            root.right = invertedLeftTree
            root.left = invertedRightTree   
        return root

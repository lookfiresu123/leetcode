# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def binaryTreePathsHelper(self, root, s, vec):
        if root.left == None and root.right == None:
            vec.append("{}{}".format(s, root.val))
        s += "{}->".format(root.val)
        if root.left != None:
            sLeft = s
            self.binaryTreePathsHelper(root.left, sLeft, vec)
        if root.right != None:
            sRight = s
            self.binaryTreePathsHelper(root.right, sRight, vec)
            
        
    def binaryTreePaths(self, root):
        if root == None:
            return None
        vec = []
        s = ""
        self.binaryTreePathsHelper(root, s, vec)
        return vec

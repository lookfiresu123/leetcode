# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isBalancedHelper(self, root):
        if root == None:
            return True, 0
        boolLeft, highLeft = self.isBalancedHelper(root.left)
        boolRight, highRight = self.isBalancedHelper(root.right)
        b = (boolLeft and boolRight and abs(highLeft - highRight) <= 1)
        high = 1 + max(highLeft, highRight)
        return b, high        
        
    def isBalanced(self, root):
        if root == None:
            return True
        b, high = self.isBalancedHelper(root)
        return b

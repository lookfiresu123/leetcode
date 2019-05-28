# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def getPath(self, root, x, vec):
        if root != None:
            vec.append(root)
            if root.val < x:
                self.getPath(root.right, x, vec)
            elif root.val > x:
                self.getPath(root.left, x, vec)
        
    def lowestCommonAncestor(self, root, p, q):
        vecp = []
        vecq = []
        self.getPath(root, p.val, vecp)
        self.getPath(root, q.val, vecq)
        n = min(len(vecp), len(vecq))
        res = None
        for i in range(0, n):
            if vecp[i].val != vecq[i].val:
                return res
            res = vecp[i]
        return res

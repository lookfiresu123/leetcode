# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def middleSearch(self, vec, root):
        if root != None:
            self.middleSearch(vec, root.left)
            vec.append(root.val)
            self.middleSearch(vec, root.right)
        
    def rangeSumBST(self, root, L, R):
        vec = []
        sum = 0
        self.middleSearch(vec, root)
        indexL = vec.index(L)
        indexR = vec.index(R)
        for i in range(indexL, indexR+1):
            sum += vec[i]
        return sum

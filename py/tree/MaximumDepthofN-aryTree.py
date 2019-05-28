# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children

class Solution(object):
    def maxDepth(self, root):
        if root == None:
            return 0
        maxSubDepth = 0
        for x in root.children:
            maxSubDepth = max(maxSubDepth, self.maxDepth(x))
        return 1 + maxSubDepth

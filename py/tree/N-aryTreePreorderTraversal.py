# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children

class Solution(object):
    def preorderHelper(self, root, vec):
        if root != None:
            vec.append(root.val)
            for x in root.children:
                self.preorderHelper(x, vec)
    
    def preorder(self, root):
        vec = []
        self.preorderHelper(root, vec)
        return vec

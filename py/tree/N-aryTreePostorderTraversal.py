# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children

class Solution(object):
    def postorderHelper(self, root, vec):
        if root != None:
            for x in root.children:
                self.postorderHelper(x, vec)
            vec.append(root.val)
    
    def postorder(self, root):
        vec = []
        self.postorderHelper(root, vec)
        return vec

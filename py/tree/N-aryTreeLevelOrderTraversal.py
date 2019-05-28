import Queue
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children

class Solution(object):
    def levelOrder(self, root):
        if root == None:
            return []
        parentQueue = Queue.Queue()
        childQueue = Queue.Queue()
        parentQueue.put(root)
        queues = [parentQueue, childQueue]
        vec = []
        i = 0
        curQueue = None
        while True:
            curQueue = queues[i%2]
            nextQueue = queues[(i+1)%2]
            if curQueue.empty():
                break
            tmp = []
            while not curQueue.empty():
                t = curQueue.get()
                tmp.append(t.val)
                for x in t.children:
                    if x != None:
                        nextQueue.put(x)
            vec.append(tmp)
            i += 1
        return vec

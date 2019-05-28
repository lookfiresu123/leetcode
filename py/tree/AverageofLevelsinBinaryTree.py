import Queue
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def averageOfLevels(self, root):
        parentQueue = Queue.Queue()
        childQueue = Queue.Queue()
        parentQueue.put(root)
        queues = [parentQueue, childQueue]
        i = 0
        res = []
        while True:
            curQueue = queues[i%2]
            nextQueue = queues[(i+1)%2]
            if curQueue.empty():
                break
            sums = 0
            cnt = 0
            while not curQueue.empty():
                t = curQueue.get()
                sums += t.val
                cnt += 1
                if t.left != None:
                    nextQueue.put(t.left)
                if t.right != None:
                    nextQueue.put(t.right)
            res.append(float(sums)/cnt)
            i += 1
        return res

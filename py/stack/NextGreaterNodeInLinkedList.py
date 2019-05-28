# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def nextLargerNodes(self, head):
        if head == None:
            return []
        if head.next == None:
            return [0]
        stack = []
        inputs = []
        cur = head
        while cur != None:
            inputs.append(cur.val)
            cur = cur.next
        outputs = [0 for x in range(0, len(inputs))]
        for i in range(0, len(inputs)):
            x = inputs[i]
            if stack == [] or inputs[stack[-1]] >= x:
                stack.append(i)
                continue
            while len(stack) > 0 and inputs[stack[-1]] < x:
                outputs[stack.pop()] = x
            stack.append(i)
        return outputs
        
if __name__ == "__main__":
    solution = Solution()
    solution.nextLargerNodes(None)

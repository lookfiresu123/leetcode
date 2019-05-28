# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        prevHead = ListNode(0)
        prevHead.next = head
        prevSlow = prevHead
        quick = head
        slow = head
        while quick != None:
            quick = quick.next
            if n > 0:
                n -= 1
                continue
            prevSlow = prevSlow.next
            slow = slow.next
        prevSlow.next = slow.next
        del slow
        curHead = prevHead.next
        del prevHead
        return curHead

if __name__ == "__main__":
    solution = Solution()
    s = None
    solution.intToRoman(s)

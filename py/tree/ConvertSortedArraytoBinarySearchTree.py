# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedArrayToBSTHelper(self, nums, lo, hi):
        if lo > hi:
            return None
        if lo == hi:
            return TreeNode(nums[lo])
        mid = lo + (hi - lo)/2
        t = TreeNode(nums[mid])
        t.left = self.sortedArrayToBSTHelper(nums, lo, mid-1)
        t.right = self.sortedArrayToBSTHelper(nums, mid+1, hi)
        return t
  
    def sortedArrayToBST(self, nums):
        n = len(nums)
        return self.sortedArrayToBSTHelper(nums, 0, n-1)

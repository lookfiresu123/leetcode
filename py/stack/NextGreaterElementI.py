class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        stack = []
        mymap = {}
        res = []
        for x in nums2:
            while stack != [] and stack[-1] < x:
                y = stack.pop()
                mymap[y] = x
            stack.append(x)
        for x in stack:
            mymap[x] = -1
        for x in nums1:
            res.append(mymap[x])
        return res

class Solution(object):
    def threeSumClosest(self, nums, target):
        nums.sort()
        n = len(nums)
        i = 0
        res = 0
        minDiff = 2**31-1
        while i < n-2:
            if i > 0 and nums[i] == nums[i-1]:
                i += 1
                continue
            left = i+1
            right = n-1
            while left < right:
                curSum = nums[i]+nums[left]+nums[right]
                diff = abs(curSum - target)
                if diff == 0:
                    return curSum
                if diff < minDiff:
                    minDiff = diff
                    res = curSum
                if curSum < target:
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    left += 1
                elif curSum > target and left < right:
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    right -= 1
            i += 1
        return res

if __name__ == "__main__":
    solution = Solution()
    s = [13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6]
    target = -59
    solution.threeSumClosest(s, target)

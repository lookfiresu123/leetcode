class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        n = len(nums)
        if n < 3:
            return []
        i = 0
        res = []
        while i < n-2:
            if i > 0 and nums[i] == nums[i-1]:
                i += 1
                continue
            left = i+1
            right = n-1
            while left < right:
                curSum = nums[i] + nums[left] + nums[right]
                if curSum == 0:
                    tmp = [nums[i], nums[left], nums[right]]
                    res.append(tmp)
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif curSum < 0:
                    left += 1
                else:
                    right -= 1
            i += 1
        return res

if __name__ == "__main__":
    solution = Solution()
    s = [-1,0,1,2,-1,-4]
    print solution.threeSum(s)

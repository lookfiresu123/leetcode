class Solution(object):
    def reverse(self, x):
        if x == 0 - 2**31:
            return 0
        y = abs(x)
        tmp = 0
        hi = 2**31 - 1
        while y != 0:
            if (hi-y%10)/10.0 >= float(tmp):
                tmp = 10 * tmp + y % 10
                y /= 10
            else:
                return 0
        if x < 0:
            tmp = 0 - tmp
        return tmp

if __name__ == "__main__":
    solution = Solution()
    s = 123
    print solution.isPalindrome(s)

class Solution(object):
    def isPalindrome(self, s):
        x = "".join([a for a in s if a.isalpha() or a.isdigit()])
        y = x.lower()
        left = 0
        right = len(y)-1
        while left <= right:
            if y[left] == y[right]:
                left += 1
                right -= 1
            else:
                break
        return left > right

if __name__ == "__main__":
    solution = Solution()
    s = "0P"
    print solution.isPalindrome(s)

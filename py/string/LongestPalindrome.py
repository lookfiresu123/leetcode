class Solution(object):
    def expandCenter(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1

    def longestPalindrome(self, s):
        start = 0
        end = 0
        for i in range(len(s)):
            len1 = self.expandCenter(s, i, i)
            len2 = self.expandCenter(s, i, i+1)
            length = max(len1, len2)
            if length > end - start + 1:
                start = i - (length-1)/2
                end = i + length/2
        return s[start:end+1]
            
if __name__ == "__main__":
    solution = Solution()
    s = "abacdfgdcaba"
    print solution.longestPalindrome(s)

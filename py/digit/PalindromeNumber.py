class Solution(object):
    def isPalindrome(self, x):
        if x / 10 == 0:
            return True
        if x < 0 or x % 10 == 0:
            return False
        t = x
        vec = []
        while t != 0:
            vec.append(t%10)
            t /= 10
        n = len(vec)
        mid = n/2
        i = 0
        while i < mid:
            if vec[i] != vec[n-1-i]:
                return False
            i += 1
        return True
        
if __name__ == "__main__":
    solution = Solution()
    s = "121"
    print solution.isPalindrome(s)

class Solution(object):
    def isValid(self, S):
        if len(S) < 3:
            return False
        stack = []
        for x in S:
            stack.append(x)
            if len(stack) < 3:
                continue
            if stack[-1] == 'c' and stack[-2] == 'b' and stack[-3] == 'a':
                stack.pop()
                stack.pop()
                stack.pop()
        if len(stack) == 0:
            return True
        return False

if __name__ == "__main__":
    solution = Solution()
    solution.isValid("aabcbc")

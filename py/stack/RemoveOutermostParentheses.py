class Solution(object):
    def removeOuterParentheses(self, S):
        stack = []
        lefts = []
        rights = []
        left = 0
        right = 0
        res = ''
        for i in range(0, len(S)):
            x = S[i]
            if x == '(':
                stack.append(x)
            else:
                stack.pop()
            if len(stack) == 0:
                right = i
                lefts.append(left)
                rights.append(right)
                left = right + 1
        for i in range(len(lefts)):
            left = lefts[i]
            right = rights[i]
            tmp = S[left+1:right]
            res += tmp
        return res

if __name__ == "__main__":
    solution = Solution()
    S = "(()())(())(()(()))"
    solution.removeOuterParentheses(S)

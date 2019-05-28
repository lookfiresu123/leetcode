class Solution(object):
    def removeDuplicates(self, S):
        stack = []
        for x in S:
            if stack == [] or stack[-1] != x:
                stack.append(x)
            else:
                stack.pop()
        return "".join(stack)

if __name__ == "__main__":
    solution = Solution()
    S = "abbaca"
    solution.removeDuplicates(S)

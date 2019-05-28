class Solution(object):
    def isPair(self, x, y):
        b1 = (x == '{' and y == '}')
        b2 = (x == '(' and y == ')')
        b3 = (x == '[' and y == ']')
        return b1 or b2 or b3
    
    def isValid(self, s):
        stack = []
        for x in s:
            if len(stack) == 0 or self.isPair(stack[-1], x) == False:
                stack.append(x)
            else:
                stack.pop()
        return stack == []

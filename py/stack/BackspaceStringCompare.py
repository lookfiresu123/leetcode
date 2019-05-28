class Solution(object):
    def backspaceCompare(self, S, T):
        stackS = []
        stackT = []
        for x in S:
            if x == '#':
                if stackS != []:
                    stackS.pop()
            else:
                stackS.append(x)
        for x in T:
            if x == '#':
                if stackT != []:
                    stackT.pop()
            else:
                stackT.append(x)
        return stackS == stackT

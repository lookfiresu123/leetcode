class Solution(object):
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ''
        if len(strs) == 1:
            return strs[0]
        minLen = len(strs[0])
        for i in range(1, len(strs)):
            x = len(strs[i])
            if x < minLen:
                minLen = x
        isSame = True
        n = len(strs)
        sz = 0
        for i in range(0, minLen):
            isSame == True
            p = strs[0][i]
            for j in range(1, n):
                if p != strs[j][i]:
                    isSame = False
                    break
            if isSame == False:
                break
            sz = i + 1
        return strs[0][0:sz]
        
if __name__ == "__main__":
    solution = Solution()
    s = ["dog","racecar","car"]
    print solution.intToRoman(s)

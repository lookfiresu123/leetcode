class Solution(object):
    def letterCombinationsHelper(self, vec, digits, cur, last, digitToAlpha):
        tmp = digitToAlpha[digits[cur]]
        if cur == 0:
            for x in tmp:
                vec.append(x)
        else:
            sz = len(tmp)
            n = len(vec)
            for i in range(1, sz):
                for j in range(0, n):
                    vec.append(vec[j])
            for i in range(0, sz):
                for j in range(0, n):
                    vec[i*n+j] += tmp[i] 
        if cur == last:
            return
        self.letterCombinationsHelper(vec, digits, cur+1, last, digitToAlpha)
        
    def letterCombinations(self, digits):
        n = len(digits)
        digitToAlpha = {'2':['a','b','c'],
                        '3':['d','e','f'],
                        '4':['g','h','i'],
                        '5':['j','k','l'],
                        '6':['m','n','o'],
                        '7':['p','q','r','s'],
                        '8':['t','u','v'],
                        '9':['w','x','y','z']}
        if digits == "":
            return []
        vec = []
        self.letterCombinationsHelper(vec, digits, 0, n-1, digitToAlpha)
        vec.sort()
        return vec

if __name__ == "__main__":
    solution = Solution()
    s = "234"
    print solution.letterCombinations(s)

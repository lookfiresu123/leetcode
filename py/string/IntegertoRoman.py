class Solution(object):
    def select(self, x, ratio):
        tmp = []
        if x == 4 or x == 9:
            return [x*(10**ratio)]
        if x >= 1 and x <= 4:
            while x > 0:
                tmp.append(1*(10**ratio))
                x -= 1
        else:
            tmp.append(5*(10**ratio))
            x -= 5
            while x > 0:
                tmp.append(1*(10**ratio))
                x -= 1
        return tmp       
        
    def intToRoman(self, num):
        specialDict = {4:'IV', 9:'IX', 40:'XL', 90:'XC', 400:'CD', 900:'CM'}
        normalDict = {1:'I', 5:'V', 10:'X', 50:'L', 100:'C', 500:'D', 1000:'M'}
        vec = []
        while num != 0:
            x = num % 10
            vec.append(x)
            num /= 10
        n = len(vec)-1
        res = ''
        while n >= 0:
            if vec[n] == 0:
                n -= 1
                continue
            lst = self.select(vec[n], n)
            for y in lst:
                if y in specialDict:
                    res += specialDict[y]
                else:
                    res += normalDict[y]
            n -= 1
        return res

if __name__ == "__main__":
    solution = Solution()
    s = 101
    print solution.intToRoman(s)

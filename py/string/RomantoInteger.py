class Solution(object):
    def romanToInt(self, s):
        specialDict = {'IV':' 4 ', 'IX':' 9 ', 'XL':' 40 ', 'XC':' 90 ', 'CD':' 400 ', 'CM':' 900 '}
        normalDict = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        cur = s
        next = ''
        for key in specialDict:
            next = cur.replace(key, specialDict[key])
            cur = next
        cur.strip(' ')
        vec = cur.split(' ')
        res = 0
        for x in vec:
            if x.isdigit() == False:
                for y in x:
                    res += normalDict[y]
            else:
                res += int(x)
        return res

if __name__ == "__main__":
    solution = Solution()
    s = "LVIII"
    print solution.romanToInt(s)

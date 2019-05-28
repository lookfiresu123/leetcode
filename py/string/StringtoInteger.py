class Solution(object):
    def myAtoi(self, str):
        n = len(str)
        hasFindDigit = False
        isPositive = True
        tmp = 0
        hi = 2**31 - 1
        lo = 0 - 2**31
        for i in range(0, n):
            if str[i] == ' ' and hasFindDigit == False:
                continue
            if hasFindDigit == False:
                hasFindDigit = True
                if str[i] != '-' and str[i] != '+' and str[i].isdigit() == False:
                    return 0
                if (str[i] == '-' or str[i] == '+') and (i == n-1 or str[i+1].isdigit() == False):
                    return 0
                if str[i] == '-':
                    isPositive = False
                if str[i].isdigit() == True:
                    tmp = 10 * tmp + int(str[i])
            else:
                if str[i].isdigit() == True:
                    x = int(str[i])
                    if (hi-x)/10.0 < float(tmp):
                        if isPositive == False and (tmp == 214748364 and x == 8) and (i == n-1 or str[i+1].isdigit() == False):
                            return lo                         
                        if isPositive == True:
                            return hi
                        else:
                            return lo
                    tmp = 10 * tmp + x
                else:
                    break
        if isPositive == False:
            tmp = 0 - tmp
        return tmp

if __name__ == "__main__":
    solution = Solution()
    s = "   +0 123"
    print solution.myAtoi(s)

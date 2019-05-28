class Solution(object):
    def convert(self, s, numRows):
        if numRows == 1:
            return s
        n = len(s)
        i = 1
        tmp = ''
        while i <= numRows:
            j = i-1
            # 第一行或最后一行
            if j == 0 or j == numRows-1:
                jump = 2*(numRows-1)
                while j < n:
                    tmp += s[j]
                    j += jump
            # 中间的行
            else:
                jump1 = 2*(numRows-i)
                jump2 = 2*(numRows-1)-jump1
                jumps = [jump1, jump2]
                index = 0
                while j < n:
                    tmp += s[j]
                    j += jumps[index % 2]
                    index += 1
            i += 1
        return tmp

if __name__ == "__main__":
    solution = Solution()
    s = "LDREOEIIECIHNTSG"
    print solution.convert(s, 4)

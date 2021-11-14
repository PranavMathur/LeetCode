from math import log2

class Solution:
    def findIntegers(self, n):
        fibs = [1, 2]
        append = fibs.append
        a, b = 1, 2
        for i in range(int(log2(n))):
            a, b = b, a+b
            append(b)
        count = 0
        while n >= 0:
            if n <= 1:
                count += n + 1
                break
            if n == 3:
                count += 3
                break
            mag = int(log2(n))
            count += fibs[mag]
            if n & (2 ** (mag - 1)):
                count += fibs[mag - 1]
                break
            else:
                n -= 2 ** mag
        return count
#32 ms (90%ile), 14.2 MB (61%ile)

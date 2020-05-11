class Solution:
    def myPow(self, x: float, n: int) -> float:
        ret = 1.0
        i = int(n)
        while i != 0:
            if i & 1 == 1:
                ret *= x
            x *= x
            i = int(i / 2)
        if n < 0:
            return 1.0 / ret
        else:
            return ret

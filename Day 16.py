# Pow(x, n)

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        smallAns = self.myPow(x, int(float(n)/2))
        if n < 0:
            x = 1 / x
        if n & 1:
            return smallAns * smallAns * x
        else:
            return smallAns * smallAns
        
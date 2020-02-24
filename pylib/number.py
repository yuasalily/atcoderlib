"""pythonで整数処理"""

def divisors(n):
    """約数の配列を返す"""
    yakusu = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            yakusu.append(i)
            if i * i != n:
                yakusu.append(n // i)
    return yakusu

class ModInt:
    """mod計算を勝手にやってくれるクラス"""
    def __init__(self, x, mod=1000000007):
        self.x = x % mod
        self.mod = mod

    def __repr__(self):
        return str(self.x)

    def __add__(self, other):
        if isinstance(other, self.__class__):
            return self.__class__(self.x + (other.x % self.mod))
        else:
            return self.__class__(self.x + (other % self.mod))

    def __sub__(self, other):
        if isinstance(other, self.__class__):
            return self.__class__(self.x - (other.x % self.mod) if \
                (self.x - (other.x % self.mod)) > 0 else (self.x - (other.x % self.mod)) + self.mod)
        else:
            return self.__class__(self.x - (other % self.mod) if \
                (self.x - (other % self.mod)) > 0 else (self.x - (other % self.mod)) + self.mod)

    def __mul__(self, other):
        if isinstance(other, self.__class__):
            return self.__class__(self.x * (other.x % self.mod))
        else:
            return self.__class__(self.x * (other % self.mod))

    def __truediv__(self, other):
        return self.__class__(self.x * other.inv().x)

    def __pow__(self, other):
        if isinstance(other, self.__class__):
            return self.__class__(pow(self.x, other.x, self.mod))
        else:
            return self.__class__(pow(self.x, other, self.mod))

    def inv(self):
        return self.__class__(pow(self.x, self.mod - 2, self.mod))

def modcomb(n, r, mod=1000000007):
    """
    nCrを返す。
    ModIntが必要。
    1 <= r <= n <= modが必要。
    """
    x = ModInt(1, mod)
    y = ModInt(1, mod)
    for i in range(r):
        x = x * (n - i)
        y = y * (i + 1)
    return x / y
        
if __name__ == "__main__":
    pass
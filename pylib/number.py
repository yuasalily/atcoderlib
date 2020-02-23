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
        return self.__class__(self.x + (other.x % self.mod))

    def __sub__(self, other):
        return self.__class__(self.x - (other.x % self.mod) if \
            (self.x - (other.x % self.mod)) > 0 else (self.x - (other.x % self.mod)) + self.mod)

    def __mul__(self, other):
        return self.__class__(self.x * (other.x % self.mod))

    def __truediv__(self, other):
        return self.__class__(self.x * pow(other.x, self.mod - 2, self.mod))

    def __pow__(self, other):
        return self.__class__(pow(self.x, other.x, self.mod))
        

if __name__ == "__main__":
    a = ModInt(5)
    b = ModInt(2)
    print(a**b)
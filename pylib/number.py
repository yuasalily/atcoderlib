"""pythonで整数処理"""

def divisors(n):
    yakusu = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            yakusu.append(i)
            if i * i != n:
                yakusu.append(n // i)
    return yakusu

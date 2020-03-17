#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
using namespace std;
//c++で整数処理

//mod計算用のクラス
class ModInt{
public:
    long long int x;
    long long int mod;
	ModInt(){}
    ModInt(long long int _x, long long int _mod = 1000000007){
        this->x = _x % _mod;
        this->mod = _mod;
    }
	ModInt operator+(ModInt other){
		return ModInt(this->x + (other.x % this->mod),this->mod);
	}
	ModInt operator-(ModInt other){
		long long int res = this->x - (other.x % this->mod);
		if (res < 0) return ModInt(res + this->mod, this->mod);
		return ModInt(res);
	}
	ModInt operator*(ModInt other){
		return ModInt(this->x * (other.x % this->mod),this->mod);
	}
	ModInt operator/(ModInt other){
		return ModInt(*this * other.inv());
	}
	ModInt pow(long long int n){
		ModInt res(1, this->mod), a(this->x, this->mod);
		while (n){
			if (n & 1){
				res = res * a;
			}
			n >>= 1;
			a = a * a;
		}
		return res;
	}
	ModInt inv(){
		return ModInt(this->pow(this->mod - 2));
	}
	void disp(){
		cout << this->x << endl;
	}
};
ostream& operator<<(ostream& stream, const ModInt m){
	stream << to_string(m.x);
	return stream;
}

//mod nCrを返す関数.ModIntが必要.
ModInt modcomb(long long int n, long long int r, long long int _mod = 1000000007){
	ModInt x(1, _mod), y(1, _mod);
	for (long long int i = 0; i < r; i++){
		x = x * ModInt(n - i);
		y = y * ModInt(i + 1);
	}
	return x / y;
}

//重複組み合わせ(nHr)を返す.modcomb,ModIntが必要
ModInt H(long long int n, long long int r, long long int _mod = 1000000007){
	return modcomb(n + r - 1, r, _mod);
}

//mod nCrを返す関数.何回も計算するときはこっち.未検証
long long int modcomb(int n, int r, int mod = 1000000007){
	if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
	static int flag = 1;
	static vector<long long int> fac(n+1,1);
	static vector<long long int> finv(n+1,1);
	static vector<long long int> inv(n+1,1);
	if (flag){
		for (int i = 2; i < n+1; i++){
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - inv[mod%i] * (mod / i) % mod;
			finv[i] = finv[i - 1] * inv[i] % mod;
  		}
		flag = 0;
	}
    return fac[n] * (finv[r] * finv[n - r] % mod) % mod;
}

//累積和を返す関数.
vector<int> csum(vector<int> a){
	vector<int> res(a.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
	{
		res[i + 1] = res[i] + a[i];
	}
	return res;
}

//2次元累積和を返す関数
vector<vector<int>> csum2d(vector<vector<int>> a){
	vector<vector<int>> res(a.size() + 1, vector<int>(a[0].size() + 1, 0));
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			res[i + 1][j + 1] = res[i][j + 1] + res[i + 1][j] - res[i][j] + a[i][j];
		}
	}
	return res;
}

//最大公約数を返す関数.未検証
long long int gcd(long long int x, long long int y){
    if (x < y) swap(x,y);
    while (y > 0){
        long long int r = x % y;
        x = y;
        y = r;
    }
    return x;
}
//最小公倍数を返す関数.未検証
long long int lcm(long long int x, long long int y){
    return x * y / gcd(x,y);
}

//素数かどうかを判定する関数.
int isprime(long long int n){
	if (n == 1) return 0;
    for (long long int i=2;i*i <= n;i++){
        if (n % i == 0) return 0;
    }
    return 1;
}
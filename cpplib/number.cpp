#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<map>
#include<set>
using namespace std;
//c++で整数処理

//mod計算用のクラス
// ModInt a = {1,1000000007}みたいな定義もできる.
//modがデフォルト(1000000007)じゃない場合は(ModInt)a+(int)xみたいなものに注意.デフォルトを書き換えれば大丈夫.
//「各メンバーに対して、コピーコンストラクターあるいは代入演算子を順に呼び出す」 という仕様になっている.
// (int)1 + (ModInt)10 みたいなことは出来ない.非メンバで定義する必要がある（と思う）.
class ModInt{
public:
    long long int x;
    long long int mod;
	ModInt(){}
    ModInt(long long int _x, long long int _mod = 1000000007){
        this->x = ((_x % _mod) + _mod) % _mod;
        this->mod = _mod;
    }
	ModInt operator-() const {
		return ModInt(-this->x, this->mod);
	}
	ModInt operator+(const ModInt &other) const {
		return ModInt(this->x + (other.x % this->mod), this->mod);
	}
	ModInt operator+=(const ModInt &other){
		*this = *this + other;
		return *this;
	}
	ModInt operator-(const ModInt &other) const {
		long long int res = this->x - (other.x % this->mod);
		if (res < 0) return ModInt(res + this->mod, this->mod);
		return ModInt(res, this->mod);
	}
	ModInt operator-=(const ModInt &other) {
		*this = *this - other;
		return *this;
	}
	ModInt operator*(const ModInt &other) const {
		return ModInt(this->x * (other.x % this->mod),this->mod);
	}
	ModInt operator*=(const ModInt &other) {
		*this = *this * other;
		return *this;
	}
	ModInt operator/(const ModInt &other) const {
		return ModInt(*this * other.inv());
	}
	ModInt operator/=(const ModInt &other) {
		*this = *this / other;
		return *this;
	}
	ModInt pow(long long int n) const {
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
	ModInt inv() const {
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

//mod nCrを返す関数.何回も計算するときはこっち.ModIntが必要.
class modcomb{
	public:
		vector<ModInt> fact;
		vector<ModInt> ifact;
		modcomb(){}
		modcomb(int n){
			this->fact.resize(n + 1, ModInt(1));
			this->ifact.resize(n + 1, ModInt(1));
			for (int i = 1; i <= n;i++)
				this->fact[i] = this->fact[i - 1] * i;
			this->ifact[n] = fact[n].inv();
			for (int i = n; i >= 1; --i)
				this->ifact[i - 1] = ifact[i] * i;
		}
		ModInt operator()(int n, int k){
			if (k < 0 || k > n)
				return 0;
			return this->fact[n] * this->ifact[k] * this->ifact[n - k];
		}
};

//重複組み合わせ(nHr)を返す.modcomb,ModIntが必要
ModInt H(long long int n, long long int r, long long int _mod = 1000000007){
	return modcomb(n + r - 1, r, _mod);
}

//nCrを返す関数.
long long int comb(long long int n, long long int r){
	long long int x = 1, y = 1;
	if (n-r < r) r = n - r;
	for (long long int i = 0; i < r; i++)
	{
		x = x * (n - i);
		y = y * (i + 1);
	}
	return x / y;
}

//繰り返し2乗法を用いたべき乗.x^nを返す.
long long int pow(long long int x,long long int n){
	long long int res = 1;
	while (n)
	{
		if (n&1){
			res *= x;
		}
		n >>= 1;
		x = x * x;
	}
	return res;
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

//最大公約数を返す関数.
long long int gcd(long long int x, long long int y){
    if (x < y) swap(x,y);
    while (y > 0){
        long long int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

//最小公倍数を返す関数.gcdが必要.
long long int lcm(long long int x, long long int y){
	return x / gcd(x, y) * y;
}

//素数かどうかを判定する関数.
int isprime(long long int n){
	if (n == 1) return 0;
    for (long long int i=2;i*i <= n;i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

//nの約数を返す関数.sortされてない.
vector<long long int> divisors(long long int n){
	vector<long long int> res;
	for (long long int i = 1; i * i <= n;i++){
		if (n % i == 0){
			res.push_back(i);
			if(i * i != n){
				res.push_back(n / i);
			}
		}
	}
	return res;
}

//aとbの公約数を列挙する.divisors,gcdが必要.sortされていない.
vector<long long int> common_divisors(long long int a, long long int b){
	long long int g = gcd(a, b);
	return divisors(g);
}

//素因数分解をする関数.
map<long long int, int> prime_factorization(long long int a)
{
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}

//与えられた配列の最小公倍数を返す.返り値は素因数分解された形.long*longがオーバーフローするときはこっちを使う.aによっては遅い.
//prime_factorizationが必要.
map<long long int,int> lcm(vector<long long int> &a){
	int n = a.size();
	map<long long int, int> res;
	for (long long int i = 0; i < n; i++)
	{
		map<long long int, int> t = prime_factorization(a[i]);
		for (auto x:t){
			res[x.first] = max(res[x.first], x.second);
		}
	}
	return res;
}

//オイラーのファイ関数.1からnまででnと互いに素のものを返す.
int totient(long long int n){
	map<long long int, int> a = prime_factorization(n);
	for (auto x:a)
	{
		n = n / x.first * (x.first - 1);
	}
	return n;
}
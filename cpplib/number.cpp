#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
using namespace std;

class ModInt{
    public:
    long long int x;
    long long int mod;
	ModInt(){cout << "test";}
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
ModInt modcomb(long long int n, long long int r, long long int _mod = 1000000007){
	ModInt x(1, _mod), y(1, _mod);
	for (long long int i = 0; i < r; i++){
		x = x * ModInt(n - i);
		y = y * ModInt(i + 1);
	}
	return x / y;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
using namespace std;
//c++でクエリ処理.union findはgraph.cppにある.

//セグメント木のテンプレ.RMQ.
//findでは[a,b)の範囲で返す.[a,b]でないことに注意.
class SegmentTree{
	public:
		int n;
		vector<int> node;
		int inf = (1LL << 31) - 1;
		
		SegmentTree(vector<int> v){
			int sz = v.size();
			this->n = 1;
			while(n < sz)
				n = n * 2;
			this->node.resize(2 * n - 1, this->inf);
			for (int i = 0; i < sz; i++)
				node[i + n - 1] = v[i];
			for (int i = n - 2; i >= 0; i--)
				node[i] = min(node[2 * i + 1], node[2 * i + 2]); 
		}
		void update(int x, int val){
			x += n - 1;
			node[x] = val;
			while(x > 0){
				x = (x - 1) / 2;
				node[x] = min(node[2 * x + 1], node[2 * x + 2]);
			}
		}
		int find(int a, int b, int k = 0, int l = 0, int r = -1){
			if (r < 0)
				r = n;
			if (r <= a || b <= l)
				return this->inf;
			if (a <= l && r <= b)
				return node[k];
			int lv = this->find(a, b, 2 * k + 1, l, (l + r) / 2);
			int rv = this->find(a, b, 2 * k + 2, (l + r) / 2, r);
			return min(lv, rv);

		}
};

//遅延評価セグ木のテンプレ.あんまりわかってない.
class LazySegmentTree{
	public:
		int n;
		vector<int> node,lazy;
		int inf = 0;
		
		LazySegmentTree(vector<int> v){
			int sz = v.size();
			this->n = 1;
			while(n < sz)
				n = n * 2;
			this->node.resize(2 * n - 1, this->inf);
			this->lazy.resize(2 * n - 1, this->inf);
			for (int i = 0; i < sz; i++)
				node[i + n - 1] = v[i];
			for (int i = n - 2; i >= 0; i--)
				node[i] = node[2 * i + 1] + node[2 * i + 2]; 
		}
		void eval(int k, int l, int r){
			if(this->lazy[k] != 0){
				this->node[k] += this->lazy[k];
				if(r - l > 1){
					this->lazy[2 * k + 1] += this->lazy[k] / 2;
					this->lazy[2 * k + 2] += this->lazy[k] / 2;
				}
				this->lazy[k] = 0;
			}
		}
		void update(int a, int b, long long int val, int k = 0, int l = 0, int r = -1)
		{
			if (r < 0)
				r = n;
			this->eval(k, l, r);
			if (r <= a || b <= l)
				return;
			if (a <= l && r <= b){
				lazy[k] += (r - l) * val;
				this->eval(k, l, r);
			} else {
				this->update(a, b, val, 2 * k + 1, l, (l + r) / 2);
				this->update(a, b, val, 2 * k + 2, (l + r) / 2, r);
				node[k] = node[2 * k + 1] + node[2 * k + 2];
			}
		}
		long long int find(int a, int b, int k = 0, int l = 0, int r = -1){
			if (r < 0)
				r = n;
			if (r <= a || b <= l)
				return this->inf;
			eval(k, l, r);
			if (a <= l && r <= b)
				return node[k];
			long long int lv = this->find(a, b, 2 * k + 1, l, (l + r) / 2);
			long long int rv = this->find(a, b, 2 * k + 2, (l + r) / 2, r);
			return lv + rv;
		}
};

//まだコピペしてきただけ.
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
};
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
//c++でグラフ理論

//深さ優先探索のテンプレ.デフォルトでは参照渡ししたsetに探索済みの頂点が格納される.
//graphは隣接リスト
void dfs(vector<vector<int>> &graph, int v, set<int> &seen){
	seen.insert(v);
	for (int i=0;i<graph[v].size();i++){
		int nxt = graph[v][i];
		if (seen.count(nxt)) continue;
		dfs(graph, nxt, seen);
	}
}

//幅優先探索のテンプレ.デフォルトではstartからの距離を返す.
//graphは隣接リスト
vector<int> bfs(vector<vector<int>> &graph,int start){
	queue<int> todo;
	vector<int> dist(graph.size(),-1);
	dist[start] = 0;
	todo.push(start);
	while(!todo.empty()){
		int now = todo.front();
		todo.pop();
		for (int i=0;i<graph[now].size();i++){
			int nxt = graph[now][i];
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[now] + 1;
			todo.push(nxt);
		}
	}
	return dist;
}

//UnionFind木のテンプレ.parentには根のindexが入っている.
//根には自身のindexが入っている.
class UnionFind{
public:
	vector<int> parent;
	UnionFind(){}
	UnionFind(int n){
		this->parent = vector<int>(n);
		for (int i = 0; i < n; i++){
			this->parent[i] = i;
		}
	}
	int root(int x){
		if (this->parent[x] == x) return x;
		this->parent[x] = root(this->parent[x]);
		return this->parent[x];
	}
	int unite(int x, int y){
		int rx = this->root(x);
		int ry = this->root(y);
		if (rx == ry) return true;
		this->parent[rx] = ry;
		return false;
	}
	int same(int x, int y){
		int rx = this->root(x);
		int ry = this->root(y);
		return rx == ry;
	}
};

//連結成分のサイズがわかるUnionFind木のテンプレ.parentには根のindexが入っている.
//根には連結成分の大きさが入っている.
class SizeUnionFind{
public:
	vector<int> _size;
	SizeUnionFind(){}
	SizeUnionFind(int n){
		this->_size = vector<int>(n,-1);
	}
	int root(int x){
		if (this->_size[x] < 0) return x;
		this->_size[x] = root(this->_size[x]);
		return this->_size[x];
	}
	int unite(int x, int y){
		int rx = this->root(x);
		int ry = this->root(y);
		if (rx == ry) return true;
		this->_size[ry] += this->_size[rx];
		this->_size[rx] = ry;
		return false;
	}
	int same(int x, int y){
		int rx = this->root(x);
		int ry = this->root(y);
		return rx == ry;
	}
	int size(int x){
		return -this->_size[this->root(x)];
	}
};

//ワーシャルフロイト法のテンプレ.graphに最短経路が格納される.inf + const = inf に気を付ければ大丈夫
//graphは隣接行列
void WF(vector<vector<int>> &graph){
	int n = graph.size();
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}


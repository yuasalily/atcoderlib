#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<bitset>
#include<iomanip>
#include<cctype>
using namespace std;
//c++でグラフ理論

//深さ優先探索のテンプレ.デフォルトでは参照渡ししたsetに探索済みの頂点が格納される.
//graphは隣接リスト.vは探索開始地点.seenは空のセット
void dfs(vector<vector<int>> &graph, int v, set<int> &seen){
	seen.insert(v);
	for (int i=0;i<graph[v].size();i++){
		int nxt = graph[v][i];
		if (seen.count(nxt)) continue;
		dfs(graph, nxt, seen);
	}
}

//幅優先探索のテンプレ.デフォルトではstartからの距離を返す.
//graphは隣接リスト.startは探索開始地点
vector<int> bfs(vector<vector<int>> &graph, int start){
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
//根には連結成分のサイズが入っている.nはノード数.
class UnionFind{
public:
	vector<int> parent;
	UnionFind(){}
	UnionFind(int n){
		this->parent = vector<int>(n,-1);
	}
	int root(int x){
		if (this->parent[x] < 0) return x;
		this->parent[x] = root(this->parent[x]);
		return this->parent[x];
	}
	int unite(int x, int y){
		int rx = this->root(x);
		int ry = this->root(y);
		if (rx == ry) return false;
		if (this->parent[rx] > this->parent[ry]) swap(rx, ry);
		this->parent[rx] += this->parent[ry];
		this->parent[ry] = rx;
		return true;
	}
	int same(int x, int y){
		int rx = this->root(x);
		int ry = this->root(y);
		return rx == ry;
	}
	int size(int x){
		return -this->parent[this->root(x)];
	}
};


//クラスカル法.UnionFindが必要.最小全域木の重みの総和を返す.
//nはノード数.queは(weight,from,to)の順に格納された順序付き待ち行列.
// int v, e; cin >> v >> e;
// 	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> que;
// 	for (int i = 0; i < e; i++){
// 		int s, t, w; cin >> s >> t >> w;
// 		que.push({w,s,t});
// 	}
int kruskal(int n, priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> que){
	UnionFind uf(n);
	int weight = 0;
	while(!que.empty()){
		vector<int> now = que.top();
		que.pop();
		if (!uf.same(now[1],now[2])){
			uf.unite(now[1],now[2]);
			weight += now[0];
		}
	}
	return weight;
}
//重みがdoubleバーション
double kruskal(int n, priority_queue<tuple<double,int,int>,vector<tuple<double,int,int>>,greater<tuple<double,int,int>>> que){
	UnionFind uf(n);
	double weight = 0;
	while(!que.empty()){
		tuple<double, int, int> now = que.top();
		que.pop();
		if (!uf.same(get<1>(now),get<2>(now))){
			uf.unite(get<1>(now), get<2>(now));
			weight += get<0>(now);
		}
	}
	return weight;
}


//ダイクストラ法のテンプレ.
//graphはコスト付きの隣接リスト(node,costの順にpairに格納).
//startからの最短距離が格納されたvectorを返す.
// int v,e,r; cin >> v >> e >> r; /*v:#頂点数,b:#辺の数,r:開始地点*/
// vector<vector<pair<int,int>>> graph(v,vector<pair<int,int>>());
// for (int i = 0; i < e;i++){
// 	int a,b,c; cin >> a >> b >> c; /*a:from,b:to,c:cost*/
// 	graph[a].push_back(pair<int,int>(b,c));
// }
vector<int> dijkstra(vector<vector<pair<int,int>>> graph, int start){
	int inf = 2001001000;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	vector<int> dist(graph.size(),inf);
	dist[start] = 0;
	que.push(pair<int,int>(0,start));
	while(!que.empty()){
		pair<int,int> now = que.top();
		que.pop();
		int c = now.first, from = now.second;
		if (dist[from] < c) continue;
		for (int i = 0; i < graph[from].size(); i++){
			int to = graph[from][i].first, cost = graph[from][i].second;
			if (dist[to] > dist[from] + cost){
				dist[to] = dist[from] + cost;
				que.push(pair<int,int>(dist[to],to));
			}
		}
	}
	return dist;
}

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


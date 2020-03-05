## 競技プログラミング用のライブラリ

### 中身
#### pylib
##### number.py
* def divisors(n) \n
nの約数のリストを返す関数
* class ModInt 
mod計算用クラス <br>
* def modcomb(n, r, mod=1000000007)
mod nCrを返す関数 

#### cpplib
##### number.cpp
* class ModInt 
mod計算用クラス
* ModInt modcomb(long long int n, long long int r, long long int _mod = 1000000007)
mod nCrを返す関数
##### graph.cpp
* void dfs(vector<vector<int>> &graph, int v, set<int> &seen)
深さ優先探索のテンプレ
* vector<int> bfs(vector<vector<int>> &graph,int start)
幅優先探索のテンプレ
* class UnionFind
UnionFindのクラス
* SizeUnionFind
連結成分のサイズを持ったUnionFind
* void WF(vector<vector<int>> &graph)
ワーシャルフロイト法


### その他メモ
* i in setは速い
* PyPyはPythonより速い
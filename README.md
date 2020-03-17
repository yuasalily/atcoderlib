## 競技プログラミング用のライブラリ

### 中身
#### pylib
##### number.py
* divisors(n) : nの約数のリストを返す関数
* ModInt : mod計算用クラス
* modcomb : mod nCrを返す関数 

#### cpplib
##### number.cpp
* ModInt : mod計算用クラス
* modcomb : mod nCrを返す関数
* H : 重複組み合わせを返す関数
* csum : 累積和を返す関数
* csum2d : 2次元累積和を返す関数

##### graph.cpp
* dfs : 深さ優先探索のテンプレ
* bfs : 幅優先探索のテンプレ
* UnionFind : UnionFindのクラス
* kruskal : クラスカル法
* SizeUnionFind : 連結成分のサイズを持ったUnionFind
* dijkstra : ダイクストラ法
* WF : ワーシャルフロイト法


### その他メモ
* i in setは速い.
* PyPyはPythonより速い.ただし，メモリは食いがち.
* 先頭、末尾付近のみ処理のならdequeを使う.
* 計算誤差がありそうなときはちゃんとDecimalを使おう.もしくは整数に直せれば直す.
* 2次元vectorもsortできる.
## 競技プログラミング用のライブラリ

### 中身
#### pylib
##### number.py
* divisors(n) : nの約数のリストを返す関数
* ModInt : mod計算用クラス
* modcomb : mod nCrを返す関数 

#### cpplib
##### dp.cpp
* LIS : 最長増加部分列の長さを返す関数
* LCS : 最長部分共通列を返す関数.

##### graph.cpp
* dfs : 深さ優先探索のテンプレ
* bfs : 幅優先探索のテンプレ
* UnionFind : UnionFindのクラス
* kruskal : クラスカル法(重みがint,doubleの2パターン)
* dijkstra : ダイクストラ法
* WF : ワーシャルフロイト法

##### number.cpp
* ModInt : mod計算用クラス
* modcomb : mod nCrを返す関数とクラス
* H : 重複組み合わせを返す関数
* comb : nCrを返す関数
* pow : 繰り返し2乗法をを用いてべき乗を返す関数
* csum : 累積和を返す関数
* csum2d : 2次元累積和を返す関数
* gcd : 最大公約数を返す関数
* lcm : 最小公倍数を返す関数
* isprime : 素数かどうかを判定する関数
* divisors : 約数を返す関数
* common_divisors : 公約数を返す関数
* prime_factorization : 素因数分解をする関数
* lcm : 与えられた配列の最小公倍数を返す関数(上記のlcmとは別物)
* totient : オイラーのファイ関数

##### query.cpp
* SegmentTree : セグ木のテンプレ
* LazySegmentTree : 遅延評価セグ木のテンプレ
* BIT Binary Indexed : Treeのテンプレ

### その他メモ（ハマったこととか）
* i in setは速い.
* PyPyはPythonより速い.ただし，メモリは食いがち.再帰はPyPyのほうが遅いらしい.
* 先頭、末尾付近のみ処理のならdequeを使う.c++ならランダムアクセスもできる.
* 計算誤差がありそうなときはDecimalを使う.もしくは整数に直せれば直す.
* 多次元vectorもsortできる.
* REが起きたときは大抵メモリが原因.問題が1始まりでプログラムが0始まりの時に-1を忘れるとか.
* intに入りきらないものに注意.式の途中にint * intがあるのは見落としやすい. 実行時間が長いもののみWAの時はだいたいこれ.
* if (...) continue;は結構ミスる.
* 桁DPは関係あるところだけメモすればok.完全な条件外はifではじく.
* xorは桁ごとに見るとわかりやすい.
* 約数や素因数はグリッドで考えるとわかりやすい.
* vec.insert(...)はO(n).最大値や最小値しか見ないならpriority queueを使う.
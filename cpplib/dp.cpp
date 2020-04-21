#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
const int inf = 1001001000;

//最長増加部分列の長さを返す.
int LIS(vector<int> a){
	vector<int> dp(a.size(),inf);
	for (int i = 0; i< a.size(); i++){
		dp[lower_bound(dp.begin(),dp.end(),a[i]) - dp.begin()] = a[i];
	}
	for (int i = dp.size() - 1; i >= 0;i--){
		if (dp[i] != inf) return i+1;
	}
	return 0;
}

//最長部分共通列を返す.
string LCS(string s, string t){
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < t.size(); j++)
		{
			if(s[i] == t[j]){
				dp[i + 1][j + 1] = max({dp[i + 1][j], dp[i][j + 1], dp[i][j] + 1});
			} else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	string ans = "";
	int i = s.size();
	int j = t.size();
	while(0 < i && 0 < i){
		if (dp[i][j] == dp[i-1][j]){
			i--;
		} else if (dp[i][j] == dp[i][j-1]){
			j--;
		} else {
			i--;
			j--;
			ans = s[i] + ans;
		}
	}
	return ans;
}
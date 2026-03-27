#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
int son[N][26],cnt[N],idx = 0;
int k = 0;
string str;
void insert(){
	int p = 0;
	for(int i = 0;i < str.size();i ++){
		int u = str[i] - 'a';
		if(!son[p][u]){
			son[p][u] = ++ idx;
		}
		p = son[p][u];
		cnt[p] ++;
	}
	
}
void solve(){
	int n;
	cin >> n;
	for(int i = 1;i <= 2 * n;i ++){
		cin >> str;
		insert();
	}
	i64 ans = 0;
	for(int i = 0;i <= idx;i ++){
		ans += 1LL * (cnt[i] / 2) * ((cnt[i] + 1) / 2);
	}
	cout << ans << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
//	cin >> t;
	
	while(t --){
		solve();
	}
	
	return 0;
}

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using i64 = long long;
using ld = long double;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	set<int> st;
	vector<int> ans(n + 1);
	for(int i = 1;i <= n;i ++){
		int x;
		cin >> x;
		st.insert(x);
		ans[i] = 1e9;
	}
	for(auto x : st){
		ans[x] = 1;
		for(int j = 1;j * x <= n;j ++){
			ans[x * j] = min(ans[x * j],ans[x] + ans[j]);
		}
	}
	for(int i = 1;i <= n;i ++){
		if(ans[i] == 1e9){
			cout << "-1 ";
		}else{
			cout << ans[i] << " ";
		}
	}
	cout << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	cin >> t;
	
	while(t --){
		solve();
	}
	
	return 0;
}

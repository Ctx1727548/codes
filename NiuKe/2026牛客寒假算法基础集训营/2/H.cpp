#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	map<int,int> mp;
	i64 ans = 0;
	for(int i = 1;i <= n;i ++){
		i64 x = i - mp[a[i]];
		i64 y = n - i + 1;
		mp[a[i]] = i;
		i64 res = (1 + y) * y / 2;
		res *= x;
		ans += res;
	}
	cout << ans << "\n";
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


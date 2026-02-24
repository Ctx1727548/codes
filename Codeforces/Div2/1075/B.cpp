#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
void solve(){
	int n;
	i64 x;
	cin >> n >> x;
	vector<i64> a(n),b(n),c(n);
	i64 res = 0;
	i64 k = 0;
	for(int i = 0;i < n;i ++){
		cin >> a[i] >> b[i] >> c[i];
		res += 1LL * a[i] * (b[i] - 1);
		if(a[i] * b[i] >= c[i]){
			k = max(k,a[i] * b[i] - c[i]);
		}
	}
	if(res >= x){
		cout << "0\n";
	}else{
		if(!k){
			cout << "-1\n";
		}else{
//			cout << x << " " << res << " " << k << endl;
			cout << (x - res + k - 1) / k << "\n";
		}
	}
	
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

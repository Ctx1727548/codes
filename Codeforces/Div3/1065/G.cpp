#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
const int mod1 = 1e6 + 3;
i64 jc[mod1 + 10];
i64 ksm(i64 a,i64 b){
	i64 res = 1;
	while(b){
		if(b & 1){
			res = res * a % mod1;
		}
		b >>= 1;
		a = a * a % mod1;
	}
	return res;
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	vector<int> b(n + 1);
	int cnt = 1e9;
	for(int i = 1;i <= n;i ++){
		cin >> b[i];
		cnt = min(cnt,b[i] / a[i]);
	}
	cnt = log2(cnt);
	i64 tmp = 0;
	i64 ans = 1;
	tmp += cnt;
	for(int i = 1;i <= cnt;i ++){
		int k = 0;
		for(int j = 1;j <= n;j ++){
			k += b[j] % 2;
			b[j] /= 2;
		}
		tmp += k;
		ans *= jc[k];
		ans %= mod1;
	}
	i64 sum = 0;
	for(int i = 1;i <= n;i ++){
		sum += b[i] - a[i];
	}
	tmp += sum;
	i64 res = (sum < mod1 ? jc[sum] : 0);
	
	for(int i = 1;i <= n;i ++){
		res *= ksm(jc[b[i] - a[i]],mod1 - 2);
		res %= mod1;
	}
	ans *= res;
	ans %= mod1;
	cout << tmp << " " << ans << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	jc[0] = 1;
	for(int i = 1;i <= mod1;i ++){
		jc[i] = (jc[i - 1] * i) % mod1;
	}
	int t = 1;
	cin >> t;
	
	while(t --){
		solve();
	}
	
	return 0;
}

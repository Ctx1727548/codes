#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int a[1010][1010];
void solve(){
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1;i <= n;i ++){
		if(cnt & 1){
			for(int j = i;j <= n;j ++){
				a[i][j] = 1;
				a[j][i] = 1;
			}
		}
		cnt ++;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
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

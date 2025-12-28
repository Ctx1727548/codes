#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
void solve(){
	int n,k,l,r;
	cin >> n >> k >> l >> r;
	vector<int> a(n + 1);
	map<int,int> mp;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	i64 ans = 0;
	vector<int> al(n + 1),ar(n + 1);
	int cnt = 0;
	for(int i = 1,j = 1;i <= n - l + 1;i ++){
		while(j - i + 1 <= r && j <= n){
			mp[a[j]] ++;
			if(mp[a[j]] == 1){
				cnt ++;
			}
			int x = j - i + 1;
			if(x >= l && x <= r){
//				cout << i << " " << (int)mp.size() << "\n\n";
				if(cnt == k){
					al[i] = j;
					j ++;
					break;
				}else if(cnt > k){
					mp[a[j]] --;
					if(mp[a[j]] == 0){
						cnt --;
					}
					break;
				}
			}
			j ++;
		}
		j --;
		mp[a[j]] --;
		if(mp[a[j]] == 0){
			cnt --;
		}
		if(!al[i]){
			al[i] = 1e9;
		}
//		cout << al[i] << "\n";
//		cout << i << " " << (int)mp.size() << "\n";
		mp[a[i]] --;
		if(mp[a[i]] == 0){
			cnt --;
		}
	}
	mp.clear();
	cnt = 0;
//	cout << "\n\n";
	for(int i = 1,j = 1;i <= n - l + 1;i ++){
		while(j - i + 1 <= r && j <= n){
			mp[a[j]] ++;
			if(mp[a[j]] == 1){
				cnt ++;
			}
			int x = j - i + 1;
			if(x >= l && x <= r){
				if(cnt == k){
					ar[i] = j;
				}else if(cnt > k){
					mp[a[j]] --;
					if(mp[a[j]] == 0){
						cnt --;
					}
					break;
				}
			}
			j ++;
		}
		j --;
		mp[a[j]] --;
		if(mp[a[j]] == 0){
			cnt --;
		}
//		cout << ar[i] << "\n";
		mp[a[i]] --;
		if(mp[a[i]] == 0){
			cnt --;
		}
		
	}
	for(int i = 1;i <= n - l + 1;i ++){
		ans += max(ar[i] - al[i] + 1,0);
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

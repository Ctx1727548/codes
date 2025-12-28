#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
void solve(){
	int n,x,y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	vector<int> p(n);
	i64 res = 0;
	for(int i = 0;i < n;i ++){
		cin >> p[i];
		res += p[i];
	}
	if(res > x + y){
		cout << "NO\n";
		return;
	}
	if(s == string(n,'0') || s == string(n,'1')){
		if(s == string(n,'1')){
			swap(x,y);
		}
		i64 sumx = 0;
		for(int i = 0;i < n;i ++){
			sumx += p[i] / 2 + 1;
		}
		if(sumx > x || y + n > x){
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
		return;
	}
	i64 sumx = 0,sumy = 0;
	for(int i = 0;i < n;i ++){
		if(s[i] == '0'){
			sumx += p[i] / 2 + 1;
		}else{
			sumy += p[i] / 2 + 1;
		}
	}
	if(sumx <= x && sumy <= y){
		cout << "YES\n";
	}else{
		cout << "NO\n";
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

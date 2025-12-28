#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n,m,a[N];
vector<int> v;
int f;
struct node{
	int ch[2];
	int s;
}tr[N * 22];
int root[N],idx;
void build(int &x,int l,int r){
	x = ++ idx;
	if(l == r){
		return;
	}
	int m = l + r >> 1;
	build(tr[x].ch[0],l,m);  
	build(tr[x].ch[1],m + 1,r);
}
void insert(int x,int &y,int l,int r,int v){
	y = ++ idx;
	tr[y] = tr[x];
	tr[y].s ++;
	if(l == r){
		return;
	}
	int m = l + r >> 1;
	if(v <= m){
		insert(tr[x].ch[0],tr[y].ch[0],l,m,v);
	}else{
		insert(tr[x].ch[1],tr[y].ch[1],m + 1,r,v);
	} 
}
void query(int x,int y,int l,int r,int k){
	if(l == r){
		cout << v[l - 1] << " ";
		f = 1;
		return;
	}
	int c1 = tr[tr[y].ch[0]].s - tr[tr[x].ch[0]].s;
	int c2 = tr[tr[y].ch[1]].s - tr[tr[x].ch[1]].s;
	int m = l + r >> 1;
	if(k < c1){
		query(tr[x].ch[0],tr[y].ch[0],l,m,k);
	}
	if(k < c2){
		query(tr[x].ch[1],tr[y].ch[1],m + 1,r,k);
	}
}
int getid(int x){
	return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
void solve(){ 
	cin >> n >> m;
	v.clear();
	idx = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		root[i] = 0;
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int vn = v.size();
//	cout << vn << "\n";
//	build(root[0],1,vn);
	for(int i = 1;i <= n;i ++){
//		cout << getid(a[i]) << "\n";
		insert(root[i - 1],root[i],1,vn,getid(a[i]));
	}
//	return;
	while(m --){
		f = 0;
		int l,r;
		set<int> st;
		cin >> l >> r;
		int k = (r - l + 1) / 3;
		query(root[l - 1],root[r],1,vn,k);
		if(!f){
			cout << "-1";
		}
		cout << "\n";
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

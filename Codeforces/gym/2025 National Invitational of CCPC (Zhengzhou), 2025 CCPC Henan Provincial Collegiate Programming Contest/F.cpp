#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using i64 = long long;
using ld = long double;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void solve(){
	int n,m;
	cin >> n >> m;
	vector<string> s(n + 1);
	for(int i = 1;i <= n;i ++){
		cin >> s[i];
		s[i] = '?' + s[i];
	}
	vector<vector<int>> dp1(n + 2,vector<int>(m + 2));
	vector<vector<int>> dp2(n + 2,vector<int>(m + 2));
	
	auto bfs = [&](int x,int y) -> vector<vector<int>>{
		vector<vector<int>> vis(n + 2,vector<int>(m + 2));
		vector<vector<int>> dis(n + 2,vector<int>(m + 2,1e9));
		queue<pair<int,int>> q;
		vector<pair<int,int>> a;
		q.push({x,y});
		vis[x][y] = 1;
		while(!q.empty()){
			auto [xx,yy] = q.front();
			q.pop();
			a.push_back({xx,yy});
			for(int i = 0;i < 4;i ++){
				int ex = dx[i] + xx;
				int ey = dy[i] + yy;
				if(ex >= 1 && ex <= n && ey >= 1 && ey <= m){
					if(!vis[ex][ey] && s[ex][ey] == '.'){
						q.push({ex,ey});
						vis[ex][ey] = 1;
					}
				}
			}
		}
		for(auto [xx,yy] : a){
			dis[xx][yy] = 0;
			q.push({xx,yy});
		}
		while(!q.empty()){
			auto [xx,yy] = q.front();
			q.pop();
			for(int i = 0;i < 4;i ++){
				int ex = xx + dx[i];
				int ey = yy + dy[i];
				if(ex >= 1 && ex <= n && ey >= 1 && ey <= m){
					if(dis[ex][ey] == 1e9){
						dis[ex][ey] = dis[xx][yy] + 1;
						q.push({ex,ey});
					}
				}				
			}
		}
		return dis;
	};
	dp1 = bfs(1,1);
	dp2 = bfs(n,m);
	int ans = 1e9;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			ans = min(dp1[i][j] + dp2[i][j] - 1,ans);
		}
	}
	ans = max(ans,0);
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

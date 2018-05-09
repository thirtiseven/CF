#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n, m, cnt;
vector<int>v[200005];
int vis[200005];
void f(int u) {
	for (int i = 0; i < v[u].size(); i++) {
		if (vis[v[u][i]])continue;
		vis[v[u][i]] = 1;
		f(v[u][i]);
	}
}
bool dfs(int u, int root, int rt) {
	if (v[u].size() != 2) {
		for (int i = 0; i < v[u].size(); i++) {
			vis[v[u][i]] = 1;
			f(v[u][i]);
		}
		return false;
	}
	if (v[u][0] == root && v[u][1] == rt)return true;
	if (v[u][1] == root && v[u][0] == rt)return true;
	if (v[u][0] == root) {
		vis[v[u][1]] = 1;
		dfs(v[u][1], u, rt);
	}
	else {
		vis[v[u][0]] = 1;
		dfs(v[u][0], u, rt);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])continue;
		vis[i] = 1;
		if (dfs(i, 0, i))cnt++;
	}
	cout << cnt;
	return 0;
}
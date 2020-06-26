#include <iostream>
#include <vector>

const int maxn = 2e5+7;

int n, m;
int in[maxn], out[maxn];
std::vector<int> t[maxn];
int fa[maxn];
int k, v[maxn], x, y;
int cnt;

void dfs(int now, int p) {
	fa[now] = p;
	in[now] = cnt;
	cnt++;
	for (auto it: t[now]) {
		if (it != p) {
			dfs(it, now);
		}
 	}	
 	out[now] = cnt;
 	cnt++;
}

bool check(int x, int y) {
//	std::cout << x << ' ' << y << ' ';
	if (in[x] <= in[y] && out[x] >= out[y]) {
//		std::cout << "1\n";
		return true;
	}
	if (in[y] <= in[x] && out[y] >= out[x]) {
//		std::cout << "1\n";
		return true;
	}
//	std::cout << "2\n";
	return false;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	for (int i= 0; i < n-1; i++) {
		std::cin >> x >> y;
		t[x].push_back(y);
		t[y].push_back(x);
	}
	cnt = 0;
	dfs(1, -1);
	for (int i = 0; i < m; i++) {
		std::cin >> k;
		int maxx = 1, minn = cnt;
		for (int j = 0; j < k; j++) {
			std::cin >> v[j];
			if (v[j] != 1) v[j] = fa[v[j]];
			maxx = std::max(maxx, in[v[j]]);
			minn = std::min(minn, out[v[j]]);
		}
		if (maxx <= minn) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}
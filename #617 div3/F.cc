#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const int maxn = 5000+7;
const int inf = 1e8;

int n, m, aa, bb;
std::pair<int, int> x[maxn];
//std::map<std::pair<int, int>, int> val;
int val[maxn][maxn];
std::vector<int> t[maxn];
int a[maxn], b[maxn], g[maxn];

std::pair<bool, int> dfs1(int now, int fa, int end) {
	if (now == end) {
		return std::make_pair(1, val[now][fa]);
	}
	int minn = inf;
	bool check = 0;
	std::pair<bool, int> temp;
	for (auto it: t[now]) {
		if (it != fa) {
			temp = dfs1(it, now, end);  
			if (temp.first) {
				check = 1;
				minn = std::min(temp.second, val[now][it]);
			}
		}
 	}
	return std::make_pair(check, minn);
}

int query(int u, int v) {
	return dfs1(u, -1, v).second;
}

bool dfs2(int now, int fa, int end, int gate) {
	if (now == end) {
//		val[std::make_pair(now, fa)] = std::max(val[std::make_pair(now, fa)], gate);
//		val[std::make_pair(fa, now)] = std::max(val[std::make_pair(fa, now)], gate);
		val[now][fa] = val[fa][now] = std::max(val[fa][now], gate);
		return 1;
	}
	bool check = 0;
	for (auto it: t[now]) {
		if (it != fa) { 
			if (dfs2(it, now, end, gate)) {
				check = 1;
				val[now][it] = val[it][now] = std::max(val[now][it], gate);
			}
		}
 	}
	return check;
}

void modify(int u, int v, int x) {
	dfs2(u, -1, v, x);
}

int main(int argc, char *argval[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 0; i < n-1; i++) {
		std::cin >> aa >> bb;
		x[i] = std::make_pair(aa, bb);
		val[aa][bb] = val[bb][aa] = 1;
		t[aa].push_back(bb);
		t[bb].push_back(aa);
	}
	std::cin >> m;
	bool yes = 1;
	for (int i = 0; i < m; i++) {
		std::cin >> a[i] >> b[i] >> g[i];
		modify(a[i], b[i], g[i]);
	}
	for (int i = 0; i < m; i++) {
		if (query(a[i], b[i]) > g[i]) {
			yes = 0;
		}
	}
	if (yes) {
		for (int i = 0; i < n-1; i++) {
			std::cout << val[x[i].first][x[i].second] << ' ';
		}
		std::cout << '\n';
	} else {
		std::cout << "-1\n";
	}
}
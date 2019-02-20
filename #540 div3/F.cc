#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 3e5+7;

int n, a[maxn];
std::vector<int> t[maxn];

int fablue, fared;

int dfsblue(int now, int fa) {
	if (t[now].size() <= 2 && a[now] == 2) {
		fablue = now;
		return 1;
	}
	int tot = 0;
	for (auto it: t[now]) if (it != fa) {
		tot += dfsblue(it, now);
	}
	if (tot >= 1) {
		if (a[now] == 1) {
			std::cout << "0\n";
			exit(0);
		}
		fablue = now;
		return 1;
	}
	return 0;
}

int dfsred(int now, int fa) {
	if (t[now].size() <= 2 && a[now] == 1) {
		fared = now;
		return 1;
	}
	int tot = 0;
	for (auto it: t[now]) if (it != fa) {
		tot += dfsred(it, now);
	}
	if (tot >= 1) {
		if (a[now] == 2) {
			std::cout << "0\n";
			exit(0);
		}
		fared = now;
		return 1;
	}
	return 0;
}

void diss(int now, int fa, int ans) {
	if (now == fablue) {
		std::cout << ans << '\n';
		exit(0);
	}
	for (auto it: t[now]) if (it != fa) {
		diss(it, now, ans+1);
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int blue = 0, red = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			red = i;
		}
		if (a[i] == 2) {
			blue = i;
		}
		if (blue && red) break;
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		std::cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	dfsblue(red, -1);
	dfsred(blue, -1);
//	std::cout << red << " " << blue << " " << fared << " " << fablue << '\n';
	if (fared == fablue) {
		std::cout << "0\n";
		exit(0);
	}
	diss(fared, -1, 0);
}
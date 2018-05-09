#include <iostream>
#include <map>
#include <vector>

using ll = long long;
std::map<ll, int> mm;
ll ans[234];
std::vector<ll> vv;
ll n, a[234];

void dfs(int num, int m, int l, int r) {
	if (num == 0)return;
	if (mm.find(ans[m] * 2) != mm.end()) {
		mm[ans[m] * 2] = 0;
		ans[m + 1] = ans[m] * 2;
		dfs(num - 1, m+1, l, r+1);
	}
	if (mm.find(ans[m] / 2) != mm.end()) {
		mm[ans[m] / 2] = 0;
		ans[m - 1] = ans[m] / 2;
		dfs(num - 1, m - 1, l - 1, r);
	}
	if (mm.find(ans[m] / 3) != mm.end()) {
		mm[ans[m] / 3] = 0;
		ans[m + 1] = ans[m] / 3;
		dfs(num - 1, m + 1, l, r + 1);
	}
	if (mm.find(ans[m] * 3) != mm.end()) {
		mm[ans[m] * 3] = 0;
		ans[m - 1] = ans[m] * 3;
		dfs(num - 1, m - 1, l - 1, r);
	}
}


int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		mm[a[i]] = 1;
	}
	ll v = a[1];
	a[100] = a[1];
	mm[a[1]] = 0;
	dfs(n-1, 100, 100, 100);
	int flag = 0;
	for (int i = 1; ; i++) {
		if (flag && ans[i] == 0) break;
		if (ans[i]) flag = 1;
		else continue;
		std::cout << ans[i] << " ";
	}
}
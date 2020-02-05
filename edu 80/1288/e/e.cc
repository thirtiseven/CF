#include <iostream>

const int maxn = 6e5+7;

int n, m;
int bit[maxn], a[maxn];
int ans1[maxn], ans2[maxn];
int last[maxn];

void add(int i, int x) {
	for(;i <= n+m; i += i & -i)
		bit[i] += x;
}

int query(int i) {
	int ret = 0;
	for(; i; i -= i & -i) ret += bit[i];
	return ret;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ans1[i] = ans2[i] = i;
		last[i] = n - i + 1;
		add(last[i], 1);
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		ans1[a[i]] = 1;
		ans2[a[i]] = std::max(ans2[a[i]], query(n + m) - query(last[a[i]] - 1));
		add(last[a[i]], -1);
		last[a[i]] = n + i;
		add(last[a[i]], 1);
	}
	for (int i = 1; i <= n; i++) {
		ans2[i] = std::max(ans2[i], query(n + m) - query(last[i] - 1));
	}
	for (int i = 1; i <= n; i++) {
		std::cout << ans1[i] << ' ' << ans2[i] << '\n';
	}
}
#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int a[maxn], q[maxn], vis[maxn];

int main(int argc, char *argv[]) {  
	a[0] = 0;
	int n;
	std::cin >> n;
	for (int i = 1; i < n; i++) {
		std::cin >> q[i];
		a[i] = a[i-1] + q[i];
	}
	int add = maxn;
	for (int i = 0; i < n; i++) {
		add = std::min(a[i], add);
	}
	add--;
	for (int i = 0; i < n; i++) {
		a[i] -= add;
	}
	std::fill(vis, vis+maxn, 0);
	for (int i = 0; i < n; i++) {
		vis[a[i]] = 1;
	}
	bool yes = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			yes = 0;
		}
	}
	if (!yes) {
		std::cout << "-1";
	} else {
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << ' ';
		}
	}
}
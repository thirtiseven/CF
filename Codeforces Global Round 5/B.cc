#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int a[maxn], b[maxn], pos[maxn], vis[maxn], n;

int main(int argc, char *argv[]) {  
	std::fill(vis, vis+maxn, 0);
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	int ans = 0;
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] != a[now]) {
			vis[pos[b[i]]] = 1;
			ans++;
		} else {
			now++;
			while (vis[now]) {
				now++;
			}
		}
	}
	std::cout << ans << '\n';
}
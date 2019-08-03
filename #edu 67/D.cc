#include <iostream>
#include <algorithm>
#include <queue>

const int maxn = 3e5+7;
int a[maxn], b[maxn], maxx[maxn];
std::queue<int> num[maxn];

int main(int argc, char *argv[]) {  
	int q;
	std::cin >> q;
	while (q--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			while (!num[i].empty()) {
				num[i].pop();
			}
		}
		maxx[0] = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			maxx[i] = std::max(a[i], maxx[i-1]);
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
			num[b[i]].push(i);
		}
		int cnt = 0, xx;
		bool yes = 1;
		for (int i = 1; i <= n; i++) {
			xx = num[a[i]].front();
			if (xx > i) {
				if (maxx[xx] <= a[i]) {
					num[a[i]].pop();
				} else {
					yes = 0;
					break;
				}
			}
		}
		std::sort(a+1, a+1+n);
		std::sort(b+1, b+1+n);
		for (int i = 1; i <= n; i++) {
			if (a[i] != b[i]) {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}
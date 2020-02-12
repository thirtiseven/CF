#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int n, a[maxn];
int cnt[100];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::fill(cnt, cnt+100, 0); 
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		int x = a[i];
		int tot = 0;
		while (x) {
			cnt[tot] += x%2;
			x /= 2;
			tot++;
		}
	}
	int ans = -1;
	int res = -1;
	for (int i = 100; i >= 0; i--) {
		if (cnt[i] == 1) {
			ans = i;
			break;
		}
	}
//	std::cout << ans << '!';
	if (ans == -1) {
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << ' ';
		}
	} else {
		for (int i = 0; i < n; i++) {
			int x = a[i];
			int tot = 0;
			while (x) {
				if (tot == ans && x%2==1) {
					res = a[i];
					goto outside;
				}
				x /= 2;
				tot++;
			}
		}
		outside:
		std::cout << res << ' ';
		for (int i = 0; i < n; i++) {
			if (a[i] != res) {
				std::cout << a[i] << ' ';
			}
		}
	}
}
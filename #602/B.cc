#include <iostream>
#include <queue>

const int maxn = 1e5+7;

int T, n, p[maxn], ans[maxn];
std::queue<int> ava;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		int cur = 0;
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i];
			if (p[i] > cur) {
				ans[i] = p[i];
				for (int j = cur + 1; j < p[i]; j++) {
					ava.push(j);
				}
				cur = p[i];
			} else {
				if (ava.empty()) {
					yes = 0;
				} else {
					ans[i] = ava.front();
					ava.pop();
				}
			}
		}
		if (yes) {
			for (int i = 0; i < n; i++) {
				std::cout << ans[i] << ' ';
			}
			std::cout << "\n";
		} else {
			std::cout << "-1\n";
		}
		while (!ava.empty()) {
			ava.pop();
		}
	}
}
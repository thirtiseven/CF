#include <iostream>

const int maxn = 1234;

int a[maxn];

int main(int argc, char *argv[]) {  
	int n, r;
	std::cin >> n >> r;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	bool yes = 0;
	int ans = 0;
	int now = r;
	int pre = 0;
	int bor = 1;
	while (bor < n) {
//		std::cout << ans << " " << now << " " << pre << " " << bor << '\n';
		yes = 0;
		for (int i = now; i > pre; i--) {
			if (a[i]) {
				ans++;
				bor = i + r - 1;
				now = std::min(i + 2*r - 1, n);
				pre = i;
				yes = 1;
				break;
			}
		}
		if (yes == 0) {
			std::cout << "-1\n";
			exit(0);
		}
	}
	std::cout << ans << '\n';
}
#include <iostream>

const int maxn = 1e5+7;

int t, n, p[maxn];

bool check() {
	int maxx = 0;
	for (int i = n; i >= 1;) {
		if (p[i] > maxx) {
			int cnt = maxx+1;
			for (int j = i-(p[i]-maxx)+1; j <= i; j++) {
				if (p[j] != cnt) {
					return 0;
				}
				cnt++;
			}
			i -= ((p[i]-maxx));
			maxx = p[i];
		} else {
			i--;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> p[i];
		}
		if (check()) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
}
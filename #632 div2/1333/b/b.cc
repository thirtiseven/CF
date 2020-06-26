#include <iostream>

const int maxn = 1e5;
int t, n, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		int up = 0, down = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		if (a[0] != b[0]) {
			yes = 0;
		}
		if (a[0] == 1) {
			up = 1;
		} else if (a[0] == -1) {
			down = 1;
		}
		for (int i = 1; i < n; i++) {
			if (b[i] < a[i] && down == 0) {
				yes = 0;
				break;
			}
			if (b[i] > a[i] && up == 0) {
				yes = 0;
				break;
			}
			if (a[i] == 1) {
				up = 1;
			} else if (a[i] == -1) {
				down = 1;
			}
		}
		std::cout << (yes?"YES\n":"NO\n");
	}
}
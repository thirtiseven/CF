#include <iostream>
#include <string>

const int maxn = 2e5+7;

int n, ans[maxn];
std::string d;

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> d;
		bool yes = 1;
		for (char ch = '0'; ch <= '9'; ch++) {
			yes = 1;
			char cur = ch;
			for (int j = n-1; j >= 0; j--) {
				if (d[j] <= cur) {
					cur = d[j];
					ans[j] = 1;
				} else {
					ans[j] = 2;
				}
			}
			cur = ch;
			for (int j = 0; j < n; j++) {
				if (ans[j] == 2) {
					if (d[j] < cur) {
						yes = 0;
						break;
					}
					cur = d[j];
				}
			}
			if (yes) {
				break;
			}
		}
		if (yes) {
			for (int j = 0; j < n; j++) {
				std::cout << ans[j];
			}
			std::cout << '\n';
		} else {
			std::cout << "-\n";
		}
	}
}
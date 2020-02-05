#include <iostream>
#include <string>

const int maxn = 2e5+7;

int n;
std::string s;
int num[30], ans[maxn];

int x(char c) {
	return int(c-'a');
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::fill(num, num+30, 0);
	std::cin >> n >> s;
	int col = 0;
	for (int i = 0; i < n; i++) {
		bool yes = 0;
		for (int j = x(s[i]); j >= 0; j--) {
			if (num[j] > 0) {
				ans[i] = num[j];
				num[j] = 0;
				num[x(s[i])] = ans[i];
				yes = 1;
				break;
			}
		}
		if (!yes) {
			col++;
			num[x(s[i])] = col;
			ans[i] = col;
		}
//		std::cout << x(s[i]) << ' ' << yes << " ";
//		for (int i = 0; i < 26; i++) {
//			std::cout << num[i] << ' ';
//		}
//		std::cout << '\n';
	}
	if (col >= 3) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		for (int i = 0; i < n; i++) {
			std::cout << ans[i]-1;
		}
		std::cout << '\n';
	}
}
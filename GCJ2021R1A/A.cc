#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 123;

int T, n;
std::string X[maxn], backup;

bool cmp(std::string a, std::string b) {
	if (a.length() == b.length()) {
		return a > b;
	}
	return a.length() > b.length();
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> X[i];
		}
		int ans = 0;
		for (int i = 1; i < n; i++) {
			backup = X[i];
			int len =  X[i].length();
			if (X[i].length() > X[i-1].length()) {
				continue;
			} else if (cmp(X[i], X[i-1])) {
				continue;
			} else if (X[i].length() == X[i-1].length()) {
				X[i] += "0";
				ans++;
			} else {
				int all_same = 1, add_zero = 0;
				for (int j = 0; j < X[i-1].length(); j++) {
					if (j < len) {
						if (X[i][j] > X[i-1][j]) {
							all_same = 0;
						} else if (X[i][j] < X[i-1][j] && all_same == 1) {
							all_same = 0;
							add_zero = 1;
						}
					} else {
						if (all_same) {
							X[i] += X[i-1][j];
							backup += "0";
							ans++;
						} else {
							X[i] += "0";
							ans++;
						}
					}
				}
				if (add_zero) {
					X[i] += "0";
					ans++;
				}
				bool yes = 0;
				if (all_same) {
					for (int j = X[i].length()-1; j >= len; j--) {
						if (X[i][j] < '9') {
							X[i][j]++;
							yes = 1;
							break;
						}
					}
				}
				if (all_same && yes == 0) {
					backup += "0";
					ans++;
					X[i] = backup;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			std::cout << X[i] << " \n"[i==n-1];
		}
		std::cout << "Case #" << CAS << ": " << ans << '\n';
	}
}
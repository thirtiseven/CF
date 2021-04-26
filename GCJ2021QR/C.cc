#include <iostream>
#include <algorithm>
#include <vector>

int T, n, c;
std::vector<int> a;
int b[124];

bool check() {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		int j = i;
		for (int k = i; k <= n-1; k++) {
			if (b[k] < b[j]) {
				j = k;
			}
		}			
		std::reverse(b+i, b+j+1);
		ans += (j-i+1);
	}
	return ans == c;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int C = 1; C <= T; C++) {
		std::cin >> n >> c;
		a.clear();
		for (int i = 0; i < n; i++) {
			a.emplace_back(i+1);
		}
		bool yes = 0;
		do {
			if (check()) {
				yes = 1;
				break;
			}
		} while (std::next_permutation(a.begin(), a.end()));
		if (yes) {
			std::cout << "Case #" << C << ":"; 
			for (auto it: a) {
				std::cout << " " << it;
			}
			std::cout << '\n';
		} else {
			std::cout << "Case #" << C << ": IMPOSSIBLE\n";
		}
	}
}
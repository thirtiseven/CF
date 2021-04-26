#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 123;
int t, n, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		std::vector<int> temp;
		std::cout << a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i-1]) {
				std::cout << " " << a[i];
			} else {
				temp.emplace_back(a[i]);
			}
		}
		for (auto it: temp) {
			std::cout << " " << it;
		}
		std::cout << '\n';
	}
}
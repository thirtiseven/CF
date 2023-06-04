#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

const int maxn = 1e5+6;

int t, n, a[maxn];
std::vector<int> v;

int main(int argc, char *argv[]) {
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int sp = 0;
		v.clear();
		for (int i = 0; i < n-1; i++) {
			if (a[i] != a[i+1]) {
				sp++;
				v.push_back(i+1);
			}
		}
		std::cout << "V: ";
		for (auto it: v) {
			std::cout << it << ' ';
		}
		std::cout << '\n';
		if (a[n-1] == 1) {
			std::cout << "NO\n";
			continue;
		} else {
			std::cout << "YES\n";
		}
		for (int i = 0; i < n-sp; i++) {
			std::cout << "0 ";
		}
		for (auto it: v) {
			std::cout << it << ' ';
		}
		std::cout << '\n';
	}
}

//0
//
//0 0
//
//0 0 0
//
//1 1 1 0
//
//0 0 1 1 0
//
//1 0 0 1 1 0
//
//0 0 0 3 1 1 !

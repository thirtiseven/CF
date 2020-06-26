#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;

int T, n, p[maxn];
std::vector<int> s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i];
		}
		s.clear();
		s.push_back(p[0]);
		for (int i = 1; i < n-1; i++) {
			if (p[i] > p[i-1] && p[i] > p[i+1]) {
				s.push_back(p[i]);
			} else if (p[i] < p[i-1] && p[i] < p[i+1]) {
				s.push_back(p[i]);
			}
		}
		s.push_back(p[n-1]);
		std::cout << s.size() << '\n';
		for (auto it: s) {
			std::cout << it << ' ';
		}
		std::cout << '\n';
	}
}
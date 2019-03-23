#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 100008;
int n, a[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> m;
	int now = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			now++;
		} else {
			m.push_back(now);
			now = 1;
		}
	}
	m.push_back(now);
	int ans = 0;
	for (int i = 0; i < m.size()-1; i++) {
//		std::cerr << "!!\n";
		ans = std::max(ans, std::min(m[i], m[i+1]));
	}
	std::cout << ans*2;
}
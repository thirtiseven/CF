#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::pair<int, int>> x;

const int maxn = 10000+10;

int main(int argc, char *argv[]) {  
	int ans = 1;
	int n;
	std::pair<int, int> x[maxn];
	std::cin >> n;
	x[0] = std::make_pair(0, 0);	
	for (int i = 1; i <= n; i++) {
		std::cin >> x[i].first >> x[i].second;
		ans += std::max(0, std::min(x[i].first, x[i].second) - std::max(x[i-1].first, x[i-1].second) + 1);
		if (x[i-1].first == x[i-1].second) {
			ans--;
		}
	}
	std::cout << ans << '\n';
}
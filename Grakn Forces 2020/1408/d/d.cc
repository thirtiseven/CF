#include <iostream>
#include <algorithm>

const int maxn = 2012;

int n, m;
std::pair<int, int> robots[maxn], lights[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> robots[i].first >> robots[i].second;
	}
	for (int i = 0; i < m; i++) {
		std::cin >> lights[i].first >> lights[i].second;
	}
}
#include <iostream>
#include <algorithm>

const int maxn = 100007;
int a[7], n, b[maxn], maxx[maxn], minn[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	for (int i = 0; i < 6; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+6);
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
		maxx[i] = 0, minn[i] = 1e9;
		for (int j = 0; j < 6; j++) {
			maxx[i] = std::max(b[i] - a[j], maxx[i]);
			minn[i] = std::min(b[i] - a[j], minn[i]);
		}
	}
	int minnn = 1e9, maxxx = 0;
	for (int i = 0; i < n; i++) {
		minnn = std::min(maxx[i], minnn);
		maxxx = std::max(minn[i], maxxx);
	}
	std::cout << std::abs(minnn - maxxx);
}
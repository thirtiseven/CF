#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int main(int argc, char *argv[]) {  
	int n, w[maxn], h[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> w[i] >> h[i];
	}
	if (w[0] > h[0]) std::swap(w[0], h[0]);
	for (int i = 1; i < n; i++) {
		if (w[i] > h[i-1] && h[i] > h[i-1]) {
			std::cout << "NO";
			exit(0);
		} else if (w[i] > h[i] && w[i] <= h[i-1]) {
			std::swap(w[i], h[i]);
		} else if (h[i] > h[i-1]) {
			std::swap(w[i], h[i]);
		}
	}
	std::cout << "YES";
}
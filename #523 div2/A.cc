#include <iostream>
#include <algorithm>

const int maxn = 1234;

int main(int argc, char *argv[]) {  
	int n, a[maxn], t, cost = 10000000;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int now = 0;
	for (int i = 1; i <= 100; i++) {
		now = 0;
		for (int j = 0; j < n; j++) {
			now += std::min(std::min(std::abs(i-(a[j]-1)), std::abs(i-(a[j]+1))), std::abs(i-a[j]));
		}
		if (now < cost) {
			cost = now;
			t = i;
		}
	}
	std::cout << t << " " << cost;
}
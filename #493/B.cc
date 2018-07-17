#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int n, b, a[123];
std::vector<int> v;

int main(int argc, char *argv[]) {  
	std::cin >> n >> b;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]%2==0) {
			even++;
		} else {
			odd++;
		}
		if (even == odd && i != n-1) {
			v.push_back(std::abs(a[i+1]-a[i]));
		}
	}
	if (v.size() == 0) {
		std::cout << "0\n";
		return 0;
	}
	std::sort(v.begin(), v.end());
	int now = 0, cnt = 0;
	for (auto aa: v) {
		now += aa;
		cnt++;
		if (now > b) {
			cnt--;
			break;
		}
	}
	std::cout << cnt << '\n';
}
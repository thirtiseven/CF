#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, k, a[1234], num[1234];
	std::cin >> n >> k;
	std::fill(num, num+1234, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		num[a[i]]++;
	}
	int ans = 0;
	int cnt = (n+1)/2;
	for (int i = 1; i <= 1000; i++) {
		while (cnt && num[i] >= 2) {
			num[i] -= 2;
			ans += 2;
			cnt--;
		}
	}
	ans += cnt;
	std::cout << ans << '\n';
}
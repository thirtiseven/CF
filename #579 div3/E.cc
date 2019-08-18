#include <iostream>

const int maxn = 150003;

int main(int argc, char *argv[]) {  
	int n, a;
	int num[maxn];
	std::fill(num, num+maxn, 0);
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		num[a]++;
	}
	int ans = 0;
	for (int i = 1; i <= 150001; i++) {
		if (num[i-1] > 0) {
			num[i-1]--;
			ans++;
		} else if (num[i] > 0) {
			num[i]--;
			ans++;
		} else if (num[i+1] > 0) {
			num[i+1]--;
			ans++;
		}
	}
	std::cout << ans << '\n';
}
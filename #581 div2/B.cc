#include <iostream>

int main(int argc, char *argv[]) {  
	int n, l, r;
	std::cin >> n >> l >> r;
	int ans = 0;
	int now = 1;
	for (int i = 1; i <= l; i++) {
		ans += now;
		now *= 2;
	}
	int minn = ans;
	for (int i = l+1; i <= n; i++) {
		minn ++;
	}
	for (int i = l+1; i <= r && i <= n; i++) {
		ans += now;
		now *= 2;
	}
	now /= 2;
	for (int i = r+1; i <= n; i++) {
		ans += now;
	}
	std::cout << minn << ' ' << ans << '\n';
}
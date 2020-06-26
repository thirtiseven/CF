#include <iostream>
#include <algorithm>

int a[4];
int T;


int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a[0] >> a[1] >> a[2];
		std::sort(a, a+3);
		int ans = 0;
		for (int i = 0; i < 3; i++) {
			if (a[i] > 0) {
				ans++;
				a[i]--;
			}
		}
		std::sort(a, a+3);
		if (a[0] > 1 && a[1] > 1 && a[2] > 1) {
			ans += 3;
			a[0] -= 2;
			a[1] -= 2;
			a[2] -= 2;
		} else if (a[0] == 1 && a[1] == 1 && a[2] > 1) {
			ans += 2;
			a[0] -= 1;
			a[1] -= 1;
			a[2] -= 2;
		} else if (a[1] >= 1 && a[2] >= 1) {
			ans += 1;
			a[1] -= 1;
			a[2] -= 1;
		}
		std::sort(a, a+3);
		if (a[0] > 0 && a[1] > 0 && a[2] > 0) {
			ans++;
		}
		std::cout << ans << '\n';
	}
}
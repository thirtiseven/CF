#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 2e5+7;

int T;
std::string ans;
int n, a[maxn], pos[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		ans = "";
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			pos[a[i]-1] = i;
			ans += "1";
		}
		int l = pos[0], r = pos[0];
		for (int i = 1; i < n; i++) {
			if (pos[i] < l-1 || pos[i] > r+1) {
				ans[i] = '0';
			}
			l = std::min(l, pos[i]);
			r = std::max(r, pos[i]);
			if (r-l != i) {
				ans[i] = '0';
			}
//			std::cout << ans[i] << ' ' << l << ' ' << r << ' ' << r-l << '\n';
		}
		std::cout << ans << '\n';
	}
}
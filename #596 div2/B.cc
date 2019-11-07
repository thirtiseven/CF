#include <iostream>
#include <map>
#include <algorithm>

const int maxn = 2e5+7;
int a[maxn];

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int n, k, d;
		std::cin >> n >> k >> d;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::map<int, int> mp;
		for (int i = 0; i < d; i++) {
			mp[a[i]]++;
		}
		int ans = mp.size();
		for (int i = d; i < n; i++) {
			mp[a[i-d]]--;
			mp[a[i]]++;
			if (mp[a[i-d]] == 0) {
				mp.erase(a[i-d]);
			}
			ans = std::min(ans, int(mp.size()));
		}
		std::cout << ans << '\n';
		mp.clear();
	}
}
#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 102;

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	int a[maxn], b[maxn];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
	}
	int ans = 0;
	for (int j = 0; j < n; j++) {
		if (s[j] == '1') {
			ans++;
		}
	}
	for (int i = 0; i < 24000; i++) {
		for (int j = 0; j < n; j++) {
			if ((i+1) >= b[j] && ((i+1)-b[j])%a[j]==0) {
				s[j] = (s[j]=='0'?'1':'0');
			}
		}
		int ret = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				ret++;
			}
		}
		ans = std::max(ret, ans);
	}
	std::cout << ans << '\n';
}